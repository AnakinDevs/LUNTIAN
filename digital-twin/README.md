# Digital Twin Integration

Research describes a virtual monitoring platform for available system information and updates.

Minimum views:
- Bin levels, sensor validity, and last-update time.
- Leanbot mission state and fault status.
- Organic/inorganic counts and classifier confidence/unknown count.
- Conveyor, divider, and elevator status when feedback exists.
- Fertilizer stage and batch status.
- Temperature/humidity observations and batch history.
- Device online/stale indicators.

Backend requirements: validate events against the shared schema; store event history separately from latest state; distinguish command requested, device acknowledgement, and measured completion; authenticate control actions; default to read-only monitoring. Framework, database, hosting, and transport remain undecided because the research does not specify them.
