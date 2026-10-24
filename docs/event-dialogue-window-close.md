# Native dialogue window closing

`EventDialogueWindowClose` reconstructs the complete five ordinary and two controller-seven closing vectors, plus six helper bodies. The seven candidate instruction ranges total 590 bytes: C00611/25, C006DA/16, C006EA/246, C007E0/100, C00844/90, C0089E/37 and C008C3/76. They do not overlap existing manifest sources. Construction, renderer, tile exchanges, geometry and suspended-context restoration are reused without duplicate credit.

The implementation retains initial and continued collapse, opposing row/corner motion, the native 32-byte blank-tile MVN, original style/palette handling, transfer requests, controller-seven object clearing, script flags and suspended window restoration. The dispatcher selects from its actual five-entry ordinary or two-entry controller-seven table; every vector is modeled.

The unchanged 13-case smoke and first full 1,664-call comparison passed. The domain comprises six helpers ×128 contexts and seven dispatcher vectors ×128 contexts, producer geometry 0/1/2 with even heights 6/2/2, original styles, zero/nonzero CFF8 and initial/continued collapse. Native D=0, DB=7E, M8/X16, binary arithmetic. The checker compares full WRAM outside the occupied stack, CPU/status/S/D/DB, graphics/arithmetic peripherals and audio acknowledgement; no hooks or interrupts are used. Stack watermarks: 1EF1/1EF3/1EF5/1EF7/1EF8/1EFA/1EFC/1EFE.

All seven instruction ranges pass source recovery for immediate widths and boundaries. The primary records 406 PC/M/X states and executes 231/232 instruction starts. C0089A is INC A15E when the corner count reaches zero; RTS is C0089D. The unchanged separate smoke2 and sixteen-call guard capture with A164=5..8 verifies continued collapse. Its scope string contains a stale RTS label; no completion coverage is inferred from that label. A further unchanged smoke1 and four-call completion capture with A164=1..4 observes C0089A with M8/X16 at all four completion positions. Combined evidence executes 232/232 starts. All primary and supplemental tools/reports/captures are frozen. The complete candidate instruction ranges total 590 bytes; neither supplement adds independent or duplicate credit. Numeric selection, scrolling state7D and the whole interactive coordinator remain separate compositions.

| Frozen primary artifact | SHA-256 |
|---|---|
| tools/event_dialogue_window_close.py | 486755d4403f538c5394e53d4dbe8e33eed438b87d8ce6d27e7add23409e5428 |
| data/event_dialogue_window_close.json | 6c18b43c55900c03c7d2a4088d71a92035489d9a84232259547818da0fd5884a |
| data/event_dialogue_window_close.coverage.json | 8bdc2d2ca1e329c92a7b25dda3fc09b787e9e58f26cd2ed21cea6251f5605573 |
| tools/event_dialogue_window_close_guard.py | 478533a33afc20fde8885b7f9b53d9c15425f18db0d4aa12fb82900876d3ff10 |
| data/event_dialogue_window_close_guard.json | d6cba7df51721329a632a18579d295352a14fbe7d6434f1ad154eb642c17005c |
| data/event_dialogue_window_close_guard.coverage.json | 3b842845ad9ff70354e3424d674d810fca25f5ef81da0cab255800e2ed323165 |
| tools/event_dialogue_window_close_complete.py | e43c9b0a1ca0c7e4ddc963ed57f7a513059d0c296044d7901f215ff2ccc03f22 |
| data/event_dialogue_window_close_complete.json | 410558d60bb87d4f9bc1dc19478fedce4867bd0ce90c6ef6fe8d0fbd33a315be |
| data/event_dialogue_window_close_complete.coverage.json | c5e9ee6b540e007d5b9a183422e1d5cfbff1fcd5e15f7b43aed92f7a18edf8e6 |
