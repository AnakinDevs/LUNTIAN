# LUNTIAN System Architecture

## Research scope
The design follows the supplied research: identify, count, and separate selected organic/inorganic items; transport collection boxes; process selected organic material into potential fertilizer cubes; and display system information through a Digital Twin.

## Logical flow
```text
Ultrasonic bin sensors -> ESP32 -> Wi-Fi telemetry -> Digital Twin
                                      |
                                full-bin event
                                      v
                         Leanbot line following + arm
                                      |
                               sorting conveyor
                                      v
Smartphone + Iriun Webcam -> AI classification/counting
                                      |
                              servo-actuated divider
                              /                 \
                       inorganic              organic
                           |                    |
                    separate bin         box elevator (5)
                                                |
                                  mixing + moisture control
                                                |
                                           spin drying
                                                |
                                    molding + compaction
                                                |
                                          ejection
                                                |
                                  curing + humidity monitor
                                                |
                                      batch-complete event
```

## Service boundaries
- **ESP32 collection node:** reads ultrasonic sensors, validates readings, publishes device telemetry. No actuator outputs are enabled in this baseline.
- **Leanbot adapter:** owns navigation, obstacle handling, arm actions, and mission acknowledgement. The exact Leanbot SDK/API must be confirmed.
- **Vision service:** consumes the Iriun camera stream, emits per-item class/confidence/track ID, and deduplicates repeated frames.
- **Machine process controller:** owns conveyor, divider, elevator, mixing, drying, molding, and curing stages. Each stage requires feedback and interlocks before actuation.
- **Digital Twin:** stores event history and a current-state projection; it must distinguish command requested, acknowledgement, and measured completion.

## Reliability rules
1. Use versioned messages, unique event IDs, timestamps, and validated payload ranges.
2. Treat stale sensor data as unavailable, not as a valid reading.
3. A low-confidence/unknown AI detection must not be silently classified.
4. Deduplicate detections by object track ID and an explicit item-exit/rearm condition.
5. Pause conveyor before elevator transfer; resume only after transfer completion is confirmed.
6. Network loss must not defeat local safety controls. Emergency stop must be independent of Wi-Fi/software.
7. Record faults, resets, manual interventions, and batch completion in an audit trail.

## State ownership
| Data | Owner |
|---|---|
| Bin readings and sensor health | ESP32 |
| Leanbot navigation/arm status | Leanbot |
| Item class, confidence, track, count | Vision service |
| Machine actuator feedback | Machine controller |
| Fertilizer stage and batch state | Process controller |
| Aggregated status/event history | Digital Twin |

## Open integration decisions
The research does not identify exact ESP32 board/pins, ultrasonic model, motor drivers, actuator feedback, AI model/classes, Leanbot command API, dashboard framework, database, or network transport. These must be confirmed against the built prototype before implementation.
