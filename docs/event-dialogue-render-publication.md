# Dialogue tile-map and graphics-buffer publication

`EventDialogueRenderPublication` reconstructs fifteen bodies totaling 639 instruction bytes. The staged coordinator C01175 includes its native interior continuation C0118B; the latter receives independent calls without extra source credit. C013A0 falls through or branches into the existing C013CD line-completion body, which is reused without another 48 bytes of credit. Manifest interval and model searches found no previous sources for the fifteen new intervals.

The model exchanges actual tile-map words, publishes paired glyph tiles, advances line counters, copies a single 32-byte tile or the full 896-byte font page, preserves the special state-2 512-byte transfer request, clears upload padding and copies both halves of each window row. Original phase tables determine graphics offsets and transfer sizes. The full glyph phase includes controller 7 window publication and every state 0/1/2/FF branch; it repeatedly advances native tile progress until phase 8 and then publishes phase 9. There is no empty callback or replacement of the progress loop.

A directed smoke case exposed a previously hidden dependency omission: native C0197C begins with STZ A181, whereas the earlier NumericWindow helper had only been checked with A181 zero. The new model overrides that helper with the missing literal store and then reuses its immutable implementation. NumericWindow and FontRows reports and tools remain unchanged; this is a stronger composed CPU contract, not extra source credit for C0197C.

The checker covers 6,144 original calls: fourteen helper entries in all 256 byte contexts, 2,048 full phase-6 calls across all byte contexts and four dialogue states/controller 0 or 7, and 512 independent calls to the interior phase-7 continuation. Line widths are 1/2/16/32; tile-map coordinates cover rows 1–8 and columns 0–31. Native ABI is D=0, DB=7E, M8/X16, binary. It compares full WRAM outside the observed native stack, CPU/status/S/D/DB, peripherals and audio acknowledgement state, with no hooks or interrupts and no persisted ROM or graphics payload.

The general dialogue coordinator, terminal line/window phases, controller polling and interactive menu/event 2E remain open. This batch completes graphics publication rather than claiming the complete text engine.

The corrected 21-case smoke and first full 6,144-call capture passed. Coverage contains 322 PC/M/X states and 115 dependency fingerprints. Observed stack watermarks are 1EF1, 1EF3, 1EF5, 1EF7, 1EF9, 1EFB, 1EFC, 1EFD and 1EFE. All fifteen complete bodies pass instruction-boundary and immediate-width recovery; tools, report and capture are frozen for independent assembly.

| Artifact | SHA-256 |
|---|---|
| tools/event_dialogue_render_publication.py | e44847d74d7d2e896b1f55bf751e9e37cd55106e6611db6b8484785733bb6022 |
| data/event_dialogue_render_publication.json | 4fb914782a33300e71f227b8f71a0ac13015ceaf54267c2c083a5dd9eaaa6741 |
| data/event_dialogue_render_publication.coverage.json | 327c8bfc6670331fc3051a21ad2617c4562fdc14c60dd09004fe509ae0fb40fa |
