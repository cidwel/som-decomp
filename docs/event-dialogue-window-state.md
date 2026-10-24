# Complete dialogue window construction

`EventDialogueWindowState` reconstructs all six ordinary and eleven controller-seven construction vectors in C00229 (56 bytes), the complete row-publication phase C002BD (139), and ten geometry/graphics/corner/border helpers. The twelve candidate bodies total 1,252 instruction bytes. Three new helper modules separate font/graphics initialization (260 bytes), corner expansion (283), and border/side painting (514). Existing renderer, cursor, geometry, palette publication, transfer and suspended-context dependencies are reused without duplicate source credit.

The implementation retains literal MVN memory propagation, original ROM style patterns and palettes, paired tilemap exchanges, all four corner-expansion steps, forward/reverse/flipped border rows, repeated side pairs, transfer requests and script/flag restoration. Controller-seven construction has eleven vectors; its phase table is distinct from the six-vector window-completion table. Every native vector is modeled, including repeated entry targets and the last increment-only/restoration phases.

The 31-case smoke and first complete 3,968-call capture passed unchanged. The domain comprises ten helpers ×128 contexts, four row-publication phases ×128, and seventeen construction vectors ×128. Original geometry states 0/1/2, eight styles and zero/nonzero CFF8 are retained. Reverse-row fixtures use the prior row endpoint produced by the forward phases. D=0, DB=7E, M8/X16 and binary arithmetic. Full WRAM outside the occupied native stack, CPU/status/S/D/DB, graphics/arithmetic peripherals and audio acknowledgement agree; there are no hooks or interrupts.

The normal side-painter ABI uses even heights. This follows the actual producers: C00113 normalizes A162 to 1 unless already 2; C0012C normalizes it to 0 unless 2; controller-seven C0017B selects 1; numeric suspension selects 2. Geometry C00D8B reads heights 6/2/2 from C77147 for these three states. C00C2A consumes two rows per normal invocation and preserves that parity. It is incorrect to describe arbitrary odd heights as normal returning calls.

The separate `event_dialogue_window_state_guard.py` smoke and 32-call capture both passed. Sixteen corner cases use A164=1..4 to observe all completion positions, including C00B19. Sixteen explicitly anomalous height-one side-painter cases observe C00CC2: its branch retains the PHX tile word, and RTS transfers to C0:(tileword+1) with S=1EFE instead of returning to the caller. The checker stops at that actual target, compares the complete resulting memory/CPU state and never executes an invented normal return. Observed anomalous targets are C00513, C00514, C08516 and C08518. These are fault-transfer observations outside the producer's normal ABI, not extra valid window states.

The primary has 1,128 PC/M/X states, 125 dependency fingerprints and stack watermarks 1EEF/1EF2..1EFB. The supplement has 177 states and 126 fingerprints. Combined evidence observes 532/532 instruction starts and passes immediate-width/boundary recovery for all twelve bodies. Primary and supplemental tools/reports/captures, including the three helper modules, are frozen. The supplement adds no duplicate instruction credit. Window closing, numeric selection, special text state 7D and the full interactive menu coordinator remain separate compositions.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_window_state.py | f496ed912513675f14ad7f05cb621b40899132d7f3a18824ef84dff3fe92f725 |
| tools/event_dialogue_window_initialization.py | b32996233ca0e9b0a1a562624fa25125275deb21bbfda1c41894e24c790f4d42 |
| tools/event_dialogue_window_corners.py | 715c14b178b40131cf7fdfa98fe49556fb6a3b768ce06dd8c883f5084b031c1b |
| tools/event_dialogue_window_borders.py | 5b5fd1ebb35b05462796ddc2db1c6c4feaaa1d3df69709d94cfde6143b1a71c4 |
| data/event_dialogue_window_state.json | be240fc54a2656735c938734038cabb05b5b295fa9d35b9b953cee940187e980 |
| data/event_dialogue_window_state.coverage.json | 844a776bd1ae293370168167e2933c44204cf4883f5daa49844bf4ad9283cf7a |
| tools/event_dialogue_window_state_guard.py | 74b982d9438f5631ad06d162762a290b0765f0debd4de1f574234b1464333350 |
| data/event_dialogue_window_state_guard.json | 7ce703e6de2cda3a89b87b1dfb5dee39e4048b987179b0110b4a6d9fb48daff5 |
| data/event_dialogue_window_state_guard.coverage.json | 6a8c42223798fd9e5889225b8873ee910c9d1e76f48d21e322e3c6a66ece8e2e |
