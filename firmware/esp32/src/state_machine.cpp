#include "state_machine.h"

void ProcessStateMachine::begin() {
  state_ = ProcessState::Idle;
  faultReason_ = "";
}

bool ProcessStateMachine::transitionAllowed(ProcessState next) const {
  if (state_ == ProcessState::Fault) return next == ProcessState::Idle;
  switch (state_) {
    case ProcessState::Idle: return next == ProcessState::Sorting;
    case ProcessState::Sorting: return next == ProcessState::BatchReady || next == ProcessState::Fault;
    case ProcessState::BatchReady: return next == ProcessState::ElevatorTransfer || next == ProcessState::Fault;
    case ProcessState::ElevatorTransfer: return next == ProcessState::Mixing || next == ProcessState::Fault;
    case ProcessState::Mixing: return next == ProcessState::SpinDrying || next == ProcessState::Fault;
    case ProcessState::SpinDrying: return next == ProcessState::Molding || next == ProcessState::Fault;
    case ProcessState::Molding: return next == ProcessState::Curing || next == ProcessState::Fault;
    case ProcessState::Curing: return next == ProcessState::Complete || next == ProcessState::Fault;
    case ProcessState::Complete: return next == ProcessState::Idle;
    case ProcessState::Fault: return next == ProcessState::Idle;
  }
  return false;
}

bool ProcessStateMachine::requestTransition(ProcessState next, bool prerequisitesSatisfied) {
  if (!prerequisitesSatisfied || !transitionAllowed(next)) return false;
  state_ = next;
  if (next == ProcessState::Idle) faultReason_ = "";
  return true;
}

void ProcessStateMachine::setFault(const char* reason) {
  state_ = ProcessState::Fault;
  faultReason_ = reason ? reason : "unspecified";
}

const char* ProcessStateMachine::name() const {
  switch (state_) {
    case ProcessState::Idle: return "idle";
    case ProcessState::Sorting: return "sorting";
    case ProcessState::BatchReady: return "batch_ready";
    case ProcessState::ElevatorTransfer: return "elevator_transfer";
    case ProcessState::Mixing: return "mixing";
    case ProcessState::SpinDrying: return "spin_drying";
    case ProcessState::Molding: return "molding";
    case ProcessState::Curing: return "curing";
    case ProcessState::Complete: return "complete";
    case ProcessState::Fault: return "fault";
  }
  return "unknown";
}

const char* ProcessStateMachine::faultReason() const { return faultReason_.c_str(); }
