# Hardware Integration Checklist

## Components named in the research
ESP32; solar-assisted battery power concept; ultrasonic bin sensors; Wi-Fi; Leanbot line track and robotic arm; smartphone camera using Iriun Webcam; conveyor; servo divider; box elevator; DC mixer; soil-moisture sensor; water pump; spin-drying drum; mold; linear compaction actuator; ejector; scraper; temperature/humidity sensor; relay; exhaust fan; LCD. A separate Code.pdf provides a stepper example.

## Do not guess these details
- Exact board and safe GPIO assignments.
- Sensor supply/output voltages and ESP32 input compatibility.
- Driver model, current rating, power supply, isolation, fusing, and motor protection.
- Mechanical end stops/position feedback for moving axes.
- Emergency-stop circuit that removes actuator energy independently of software.
- Guards around belts, gears, rotating drums, presses, and pinch points.
- Battery chemistry, charge controller, panel specifications, and wiring protection.
- Safe default state for each relay, pump, fan, and motor driver.

Never power motors from ESP32 GPIO. Keep actuator power separate from logic power where the electrical design requires it.

## Stepper sketch from Code.pdf
The supplied example uses Arduino `Stepper.h`, 2048 steps/revolution, constructor pins `18, 12, 19, 13`, commented as IN1/IN3/IN2/IN4, and 10 RPM. This is a reference bench sketch, not verified final machine wiring. Confirm motor, driver, coil sequence, supply, and load before use.

## Commissioning gates
1. Inspect wiring with actuator power disconnected.
2. Verify logic supply and sensor readings only.
3. Calibrate sensor readings against physical references and reject timeouts.
4. Validate emergency stop and power-loss behavior with outputs disconnected.
5. Under qualified supervision, test one guarded actuator at a time with verified limit feedback.
6. Test faults, timeouts, restart behavior, and network loss.
7. Run integrated tests at reduced load/speed and retain results.
8. Enable normal operation only after documented acceptance checks pass.
