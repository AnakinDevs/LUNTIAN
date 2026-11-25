# AI Vision Integration

Research basis: smartphone camera mounted above the conveyor, connected through Iriun Webcam; AI identifies selected organic/inorganic items and maintains separate counts.

The research does not name an inference framework, model, class list, execution host, or confidence threshold. This directory defines the contract rather than pretending those choices are known.

A detection event should include schema version, unique event ID, camera ID, stable item track ID, class, confidence, and timestamp. Only team-approved classes are accepted. Unknown/low-confidence results must be rejected or sent for review, not guessed. Deduplicate by track ID and an explicit object-exit/rearm condition so multiple frames do not inflate counts.

Before commanding the divider, validate camera calibration, belt speed, inference latency, item-to-gate travel time, actuator feedback, and a safe stop/reject path.
