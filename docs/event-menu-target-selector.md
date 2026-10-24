# Native interactive target selection

D0DB58 (188 bytes) runs the complete controller selection loop; D0DC14 (48) advances the cursor and skips unavailable entries; D0DC44 (48) publishes single/multiple blinking markers; D0DC74 (74) publishes one marker. C070DB adds the real four-byte public palette-attribute alias. Total candidate instruction source:362 bytes, excluding any prior source overlap found by integration.

The new CPU bus supplies explicit physical autojoypad events on4218 reads. Real controller bodies, vblank/NMI/RTI, text rendering and AudioACK execute without hooks. Fourteen calls cover confirm/cancel (including the actual ring rebuild/settle), held confirmation, directional movement, skips/wraps, multi/single/hostile targets, flipped marker geometry, empty marker and the palette alias. Two separate complete-call supplements cover first and first-two targets unavailable. Raw all-unavailable cursor contexts are excluded by the preceding target-eligibility producer; no artificial return is provided for that original looping context.

Initial smoke exposed a composition error in frozen TextTick: native D0D3D8 branches directly to the dialogue runner after script preparation, even when1D04 was previously inactive. The new selector overrides that consumer with the literal branch behavior; the frozen dependency is unchanged and receives no additional source credit. Corrected smoke2 and first full14 pass; supplemental2 passes first capture. Full WRAM, CPU/context and peripherals match.

Union audit observes158/158 instruction starts with exact widths and boundaries. Primary226 and supplemental227 dependencies remain unchanged. Reset propagation remains the real inherited boot transfer; this directed capture does not add a new hotkey-reset scenario. The higher category action coordinator remains open.

Integration spec: `event_menu_target_selector_check:EventMenuTargetSelector:event-menu-target-selector:event_menu_target_selector`. Supplemental validator: `event_menu_target_selector_guard.py`.

## Frozen hashes

- `tools/event_menu_target_selector.py`: `42579f61025b1cf401d727c4037c1f99d45242f47d02280089676026eeb9d2b2`
- `tools/event_menu_target_selector_check.py`: `341847930daba682b3ecbe233f9a3116a0d4d714e2fe54864cf9fd915a03c4c1`
- `tools/event_menu_target_selector_guard.py`: `cf1d36077bc4841f7aee3282e53b33a8a7c27ed936f1c37d5a349d8fe0858705`
- `data/event_menu_target_selector.json`: `72c7bc83c99fbfabe5bd22680429c3a0862d8ce141f0b1a147781b0edd8e41dd`
- `data/event_menu_target_selector.coverage.json`: `66749bd4a5a89167a34a079f0de2506c9da401fdd62c15aa5e75a97ef7553272`
- `data/event_menu_target_selector.source_audit.json`: `d4c1bd6f7a6527b2f3fa611986ec2788c8574d11d94be13d8d5f5c0ef98db836`
- `data/event_menu_target_selector_guard.json`: `b1150f4ca8086be3a0f2680c89531be9384afa5183f1ab2dc0ab54095cc67454`
- `data/event_menu_target_selector_guard.coverage.json`: `7823f63bace8a94e57a82f2d41dcca9bb084c75bbf80e1b3edffc09783943997`
- `data/event_menu_target_selector.complete_source_audit.json`: `f07ebc1efcaa245a42210b89ea828334cf74de16f496b0abd4008bc7ddd19dee`
