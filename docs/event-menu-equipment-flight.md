# Native equipment exchange flights

D0DCBE completes an equipment exchange with two moving OAM records. It preserves the native guards, initialization, divide-by-51 fixed-point trajectories, per-frame controller polling and real vblank interrupts, screen-edge clamping, terminal hiding and audio requests. The seven bodies cover 363 candidate instruction bytes; the general/category-two caller remains open.

The first smoke of three cases and first full nine-case comparison passed. The fixtures run the frozen native equipment-swap producer, producing the ownership and exchange flags before the flight begins. They cover skipped type/flag, complete normal and top-edge flights, direct initialization, the final OAM row, zero displacement, the edge origin and pair integration. Incoming execution uses the producer's normalized D0/DB0 and binary arithmetic. Physical zero-pad events and real NMI/RTI are explicit; no callee hooks replace the original code.

CPU registers, flags, stack/context, WRAM and literal graphics, arithmetic, audio and input peripherals match. The independent source audit observes all 170/170 own instruction starts and widths, with 1542 captured PC/width states and 489 unchanged captured dependency hashes. Each of the seven numeric assembly bodies recovers exactly. No ROM or graphical payload is exported.

Integration spec: `event_menu_equipment_flight_check:EventMenuEquipmentFlight:event-menu-equipment-flight:event_menu_equipment_flight`.

## Frozen hashes

- `tools/event_menu_equipment_flight.py`: `805081dc1a0135ea56de50e3c8b53bd42136a0f60f391b9c2990ffc8c1141c8a`
- `tools/event_menu_equipment_flight_check.py`: `97e5a8f5059616023c0eb02bbd6416628ffb28c0f6b0d9e7331e2843ddfa914e`
- `data/event_menu_equipment_flight.json`: `d675af48c140efccb4627392bb55717836d5430f311c59e416d41a4aa85a668b`
- `data/event_menu_equipment_flight.coverage.json`: `b1fa3e911c1d096142e7bccd95d77356197e9b2e649acd8253a87a18973fa1b5`
- `data/event_menu_equipment_flight.source_audit.json`: `1baf77cfe4bc7c53797409f7d88cf5d6c9b4babfa0bccdf5dc2679992c05760d`
