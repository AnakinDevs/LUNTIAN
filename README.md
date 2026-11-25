# LUNTIAN
**Leveraging Urban Networks for Technological Innovation and Automated Nutrition**

Research-aligned software foundation for the LUNTIAN school prototype: ESP32 bin monitoring, Leanbot collection-box transport, smartphone/Iriun Webcam AI segregation, servo divider, five-item box-elevator batch, organic-material processing, and Digital Twin monitoring.

## Workflow
1. ESP32 reads ultrasonic bin sensors and publishes Wi-Fi telemetry.
2. A full-bin event requests a Leanbot mission; Leanbot follows its line track, collects the box with its robotic arm, and delivers it to the sorting station.
3. A smartphone camera using Iriun Webcam supplies conveyor images to the AI classifier. Supported items are classified as organic or inorganic, counted, and routed by a servo divider.
4. At the research's five-item batch threshold, pause the conveyor, transfer the batch using the box elevator, confirm completion, then resume.
5. Process selected organic material through moisture conditioning/mixing, spin drying, molding, compaction, ejection, and curing.
6. Publish telemetry and process events to the Digital Twin.

## Structure
- `firmware/esp32`: sensor telemetry and guarded process-state foundation
- `ai`: vision/classification integration contract
- `leanbot`: mission integration contract
- `digital-twin`: dashboard/backend requirements
- `shared/protocol`: versioned event schema
- `tests`: standard C++ protocol contract test
- `docs`: architecture, hardware, and validation

## Run
Install PlatformIO and run `pio run` in `firmware/esp32`.
Build and run the C++ protocol contract test from the repository root:

```sh
cmake -S tests -B build/tests
cmake --build build/tests
./build/tests/luntian_protocol_contract_test
```

The test uses standard C++ and CMake; it does not require Python.

## Safety and scope
The supplied research does not define a verified pin map, driver models, actuator feedback, camera model/classes, Leanbot API, or dashboard stack. These are not guessed. Baseline firmware intentionally does not energize actuators. Confirm wiring, electrical ratings, guards, limit feedback, and an independent emergency stop before hardware commissioning. Fertilizer output is a potential product; software does not certify its quality or safety.

Research basis: RESEARCH - Project LUNTIAN.pdf and the Stepper example in Code.pdf. The latter specifies a 2048-step example, 10 RPM, and constructor pins 18,12,19,13 (commented IN1/IN3/IN2/IN4); it is treated as a reference sketch, not verified machine wiring.
