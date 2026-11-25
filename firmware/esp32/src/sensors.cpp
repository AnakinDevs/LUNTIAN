#include "sensors.h"

// Safe integration stub. Add pulse timing, timeout rejection, filtering, and
// calibration only after the sensor model and verified pin map are provided.
void BinSensors::begin() { readings_ = BinReadings{}; }
void BinSensors::update(uint32_t) { /* no hardware configured */ }
const BinReadings& BinSensors::readings() const { return readings_; }
