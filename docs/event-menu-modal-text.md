# Native modal menu text consumer

D0D5B5 reconstructs28 bytes: set the script and close an earlier dialogue, run the original dialogue coordinator, then wait for real vblank and menu text frames until the original active flag clears. Both original CA item6/7 notification scripts, closing an earlier dialogue and an immediate font terminator pass full native comparison. These routes consume no joypad reads; configured external button events therefore remain unused and are not claimed covered.

The valid input fixture composes frozen C00261 initialize_active_window (including original C00D8B geometry) and C00D7F request_window_transfer. They produce1D08=256 and1D1A=512. The earlier raw map/icon fixture carried uninitialized dialogue transfer lengths, permitting DMA to cross into saved call-stack bytes. Its failed runs remain separate diagnostics; they are not valid menu-window ABI evidence and receive no source credit. No VRAM normalization, DMA suppression or fabricated completion is used.

The new composition also preserves literal vblank return contexts C06948/C0694D and the modal wait call frames D5C4/6941. The checker seeds the same public caller frame before both executions. Frozen dependencies remain untouched.

Exact-seed replay1 passed, followed by the first full4 capture in the corrected produced domain. Full WRAM/CPU/context, VRAM and every peripheral match; all original NMI/RTI/render/audio consumers execute. Audit11/11 starts, exact boundaries/widths,230 dependencies unchanged. This proves the28-byte interior entry; it adds zero new source bytes because the existing D0D5B2/31 recovered body contains it. Higher consumable/weapon action consumers remain open until their own composed native comparison.

Integration spec: `event_menu_modal_text_check:EventMenuModalText:event-menu-modal-text:event_menu_modal_text`.

## Frozen hashes

- `tools/event_menu_modal_text.py`: `6a5bc3e258e811f2be8957fa498cea9d56ce5259477082d24ee89c26fe3a8db5`
- `tools/event_menu_modal_text_check.py`: `9fbf90f9ba551c1c10df583d21dd05d7057256cc4287b4e6c68bf28bb6e3d71f`
- `data/event_menu_modal_text.json`: `c1c66b7d3df3f3c1fdfa208687ffea28c20e49acd52460cc0c55ff4201a476ac`
- `data/event_menu_modal_text.coverage.json`: `31679b8c421b2e47436093e474eb6d23d5c5e478b41b9d21b663414e61a90652`
- `data/event_menu_modal_text.source_audit.json`: `214aace45f0eb61630e91ee5d7ff75e9f13a0d7e988a2ea46ce1714e4b96150e`

Integration credit: D0D5B5..D0D5D0 is wholly contained in the existing recovered D0D5B2/31 source `run_selected_menu_window_script_through_real_vblank_completion.s`. This independent complete composition strengthens the existing contract and adds **zero new source bytes**.
