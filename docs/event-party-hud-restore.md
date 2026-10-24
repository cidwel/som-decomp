# Complete party HUD restoration

`EventPartyHudRestore` reconstructs C1E0DB, a 30-byte coordinator that resets the party HUD workspace, waits for a real NMI, clears the tilemap and places the party frames, waits for another real NMI, then writes HP numbers and publishes the three character icons. All five HUD dependencies and the native wait helper are existing complete reconstructions, reused without additional byte credit.

The initial reset precedes the coordinator's DB=0 setup. The composition therefore preserves actual bank semantics: the workspace reset writes through the incoming DB, then subsequent HUD operations use DB=0, and the original DB is restored on return. In particular, DB=7F resets the corresponding upper WRAM workspace rather than the lower-bank HUD records. The already stable reset model is unchanged; this composition supplies its previously implicit bank addressing contract.

The first full 432-call comparison passed after the small smoke corrected the icon dispatcher's final M8 state and the initial reset's bank addressing. The domain covers all 27 party activation combinations, HUD enabled/disabled, all four palette flag combinations, both M/X widths, all C/N/Z/V states and DB=0/7E/7F/42. D=0 and binary mode are explicit. The native NMI/RTI handler executes twice in every call, with an explicit two-event budget and no instruction hooks or wait-byte replacement.

The comparison includes all WRAM outside the observed stack, all CPU registers and flags plus D/DB/stack context, and the complete PPU/arithmetic peripheral state. All calls matched, totaling 864 original NMI/RTI events. The stack watermark is 1EEC, the capture contains 455 PC/M/X states, and all 43 dependency fingerprints match. The coordinator passes instruction-boundary and immediate-width recovery for all 30 bytes. Full event opcode 29 remains pending the radial transition and final composition.

| Artifact | SHA-256 |
|---|---|
| tools/event_party_hud_restore.py | d1339f57eef3029b11e546381cb4e0147fdb390417ebc108f6568eddc41cd2de |
| data/event_party_hud_restore.json | d5ddde6fca3ec73e961fac90e80fcea24356800df18bf60e9dad22d27f4d4e24 |
| data/event_party_hud_restore.coverage.json | 171cc36ddbe11ee0e3553e3714851f7a2eac1c2327ceb5a7782686a136e6e12c |
