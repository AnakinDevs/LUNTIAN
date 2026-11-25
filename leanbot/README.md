# Leanbot Integration

The research assigns Leanbot line-track navigation and robotic-arm handling: travel to a full bin, collect the waste box, transport it to the sorting station, and place waste onto the conveyor.

Mission lifecycle: requested -> accepted -> en_route -> arrived -> loading -> transporting -> delivered. Any active state may fail or be cancelled. Use unique mission IDs; do not treat a dashboard request as proof that a physical task completed.

The supplied research does not specify the Leanbot model/SDK, command transport, sensor map, or command syntax. Implement the adapter only after these are confirmed, including obstacle handling and safe-stop behavior.
