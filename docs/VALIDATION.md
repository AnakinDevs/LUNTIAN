# Verification and Validation Plan

These are proposed tests derived from the research objectives. No test is claimed to have passed.

| Area | Test | Evidence to record |
|---|---|---|
| Bin monitoring | Compare ultrasonic distance with reference at multiple fill levels | raw distance, calibrated level, error, invalid samples |
| IoT | Disconnect/reconnect Wi-Fi | delivery rate, outage, reconnect time |
| Leanbot | Exercise mission request through delivered/failed states | mission ID, timestamps, interventions |
| AI | Test the team's selected material classes under varied lighting | confusion matrix, per-class precision/recall, unknown rate |
| Counting | Pass known item counts | expected/observed counts, duplicate events |
| Sorting | Pass each supported class through divider | correct placement, misroutes, jams |
| Elevator | Verify five-item threshold, conveyor pause, transfer confirmation | count, pause, transfer result |
| Moisture | Compare soil sensor with a reference method | sensor/reference readings, pump events |
| Drying/curing | Record moisture observations, mass, temperature, humidity, time | batch ID and time-series |
| Digital Twin | Check live/stale state, history, faults | event IDs, timestamps, stale alerts |

## Metrics
- Classification: confusion matrix, accuracy, precision, recall, unknown/abstention rate.
- Sorting: correctly placed items / all evaluated items.
- Counting: absolute count error and duplicate detection rate.
- Transport: mission success rate, completion time, intervention count.
- Monitoring: telemetry delivery rate, update latency, stale-state detection.
- Product evaluation: dimensions, mass, moisture observations, integrity, and suitability tests selected by the research team.

Set numeric acceptance thresholds before formal testing. Keep raw data, test conditions, software/hardware versions, and failed trials.
