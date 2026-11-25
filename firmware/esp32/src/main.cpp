#include <Arduino.h>
#include <ArduinoJson.h>
#include "config.h"
#include "sensors.h"
#include "state_machine.h"

static BinSensors sensors;
static ProcessStateMachine process;
static uint32_t lastTelemetryMs = 0;

static void publishTelemetry(const BinReadings& r) {
  JsonDocument doc;
  doc["schema_version"] = 1;
  doc["event_id"] = String(LUNTIAN_DEVICE_ID) + "-" + String(millis());
  doc["device_id"] = LUNTIAN_DEVICE_ID;
  doc["event_type"] = "bin.telemetry";
  doc["timestamp_ms"] = millis();
  JsonObject payload = doc["payload"].to<JsonObject>();
  payload["organic_cm"] = isfinite(r.organicCm) ? r.organicCm : -1.0f;
  payload["organic_valid"] = r.organicValid;
  payload["inorganic_cm"] = isfinite(r.inorganicCm) ? r.inorganicCm : -1.0f;
  payload["inorganic_valid"] = r.inorganicValid;
  payload["process_state"] = process.name();
  serializeJson(doc, Serial);
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  sensors.begin();
  process.begin();
  Serial.println("{\"event_type\":\"device.heartbeat\",\"status\":\"safe-boot\",\"actuators_enabled\":false}");
}

void loop() {
  const uint32_t now = millis();
  sensors.update(now);
  if (now - lastTelemetryMs >= LUNTIAN_TELEMETRY_INTERVAL_MS) {
    lastTelemetryMs = now;
    publishTelemetry(sensors.readings());
  }
  // Actuator control remains disabled pending verified hardware/interlocks.
  delay(10);
}
