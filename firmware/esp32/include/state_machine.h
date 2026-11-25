#pragma once
#include <Arduino.h>

enum class ProcessState : uint8_t {
  Idle, Sorting, BatchReady, ElevatorTransfer, Mixing,
  SpinDrying, Molding, Curing, Complete, Fault
};

class ProcessStateMachine {
 public:
  void begin();
  bool requestTransition(ProcessState next, bool prerequisitesSatisfied);
  void setFault(const char* reason);
  const char* name() const;
  const char* faultReason() const;
 private:
  bool transitionAllowed(ProcessState next) const;
  ProcessState state_ = ProcessState::Idle;
  String faultReason_;
};
