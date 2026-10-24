# Native ring phase and controller-release waits

Seven bodies cover84 bytes: C06896 waits for both confirm/cancel to release while advancing the real ring; C068EA opens and settles publicly; C068F1 waits until phase0; C068FF clears the packed flag then falls through to C06906 full construction; C06914 restores the actor category; C06922 polls until cancel releases. All loops retain their original exit conditions, use native frame/input consumers and propagate actual reset transfers.

Smoke2 and first full8 passed unchanged. Public open executes the complete constructor and multiple native vblank/RTI frames until phase0, with direct phase0/1 waits, packed clear/open, saved category and released inputs. The returning capture uses explicit zero autojoypad/serial input; it does not imply forced termination for indefinitely held input or claim new reset coverage. Frozen controller reset proof supplies that dependency contract. Audit35/35 instruction starts, all seven source boundaries and immediate widths exact,222 dependency hashes unchanged.

Full original callees, WRAM outside observed stack, CPU/context and graphics/audio/input/arithmetic peripherals match. No hooks, invented guards, ROM or asset payloads. Main action/category consumers remain open.

Integration spec: `event_menu_ring_waits_check:EventMenuRingWaits:event-menu-ring-waits:event_menu_ring_waits`.

## Frozen primary hashes

- `tools/event_menu_ring_waits.py`: `195c52e455a1780211b1964cfc8bd5d524cfe438f3b98dc648e21cca7e38db1f`
- `tools/event_menu_ring_waits_check.py`: `7e3cce6c7cdb32215a2a411592500657858458dcdf24b03e4ed11b888a8abf60`
- `data/event_menu_ring_waits.json`: `f256b9dfc6eafcc7521392f9063707b4b7a07902d9d00b7ec578358a3e5ebb2c`
- `data/event_menu_ring_waits.coverage.json`: `575d5750ae1b4ef24b4c957709923068777a122f0c2e4d995e7bc0bffbccf45d`
- `data/event_menu_ring_waits.source_audit.json`: `d12ba2f27e5aac7f9b189702b78844b1385f1290bb161e313dac3f3643785260`
