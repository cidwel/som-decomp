# Native menu target eligibility

D0DA60 (65 bytes) builds the three-actor target list and count; D0DAA1 (183 bytes) tests each actor and advances both cursors. Geometry and active-state guards, hero ownership, hostile graphic flags, cure/revive restrictions, weapon 33 and special graphics 54/55 retain the original byte/word arithmetic and CPU flag behavior. A single eligible target replaces the multi-target selector with FFFE.

Smoke3 and the first complete22-call capture passed without model changes. Each public original call executes three original private tests. The audit observes106/106 instruction starts with exact widths and boundaries; all222 dependency hashes remain unchanged. Full WRAM, CPU/context and peripherals match without hooks or saved ROM/assets. Interactive target selection D0DB58 remains open; this evidence does not claim the complete menu.

Integration spec: `event_menu_target_eligibility_check:EventMenuTargetEligibility:event-menu-target-eligibility:event_menu_target_eligibility`.

## Frozen hashes

- `tools/event_menu_target_eligibility.py`: `66458b2aaaed472c39983a75e6991a0cd44414188143a1d961af2aa283692300`
- `tools/event_menu_target_eligibility_check.py`: `2793fc194508ed367fc9ccdca0a7962eb3b5171a8d8912a4467d7eea1bbbf37e`
- `data/event_menu_target_eligibility.json`: `c61dbe3acca2e2c452c8e80c09c1c626e442cb49414022fac672964ee3948594`
- `data/event_menu_target_eligibility.coverage.json`: `aa0a45a07d04095b0fbcf9cdd59ba7b31f1cec0982bc8203a4d33644a23e58e5`
- `data/event_menu_target_eligibility.source_audit.json`: `dfdee5f50f36841a601e69d7d56a6edab6af3fa1bb3cab47ca146d2e828ce267`
