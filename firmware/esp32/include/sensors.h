#pragma once
#include <Arduino.h>

struct BinReadings {
  float organicCm = NAN;
  bool organicValid = false;
  float inorganicCm = NAN;
  bool inorganicValid = false;
};

class BinSensors {
 public:
  void begin();
  void update(uint32_t nowMs);
  const BinReadings& readings() const;
 private:
  BinReadings readings_;
};
