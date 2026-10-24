# Event/menu screen restoration coordinator

## Verified checkpoint — 2026-10-10

176 complete original calls, 81/81 own instruction starts and198 matching instruction bytes. The hardware adapter preserves multiplication operand readback as well as product state. Every new source body independently assembles exactly to the original ROM. Own captured widths and current proof/dependency hashes pass data/event_native_menu_source_audit.json. Full C01D97 interaction, asynchronous timing and rendered pixels remain open. Preparation notes below describe the earlier pre-verification state, superseded by this checkpoint.


[C] `tools/event_screen_restore.py` reconstructs both complete native bodies C1FF3A/49 and C1FF6B/149. Its sixteen model-only preflight cases cover both entries, all incoming width pairs and ordinary/boss paths. Its own original comparison is queued; neither198 instruction bytes nor a new completed event1F claim are credited yet.

FF3A switches DB0/M8, disables4200 and forces blank8F, saves the low byte of direct1F and callsFF6B. It then publishes E6=0F00/E4=0101, sets E2bit0, enables4200=B1, restores1F and restores the caller DB. Its final N/Z come from PLB, not the screen resource outputs. The incoming direct page is0; other direct pages are not silently treated as equivalent.

FF6B resets the actual HDMA/window/colour/OAM/scroll/IRQ ports in original write order. It runs the complete background configurationFD52, graphics/resource reloadC0C45E, sixteen-row map fillC0C9E6 and complete party HUD initializerC1E0D7. The graphics adapter carries all memory/DMA/VRAM/latch/hardware and CPU outputs, including the map resource loop's actual final comparison. The Mode7 branch retains CLI and matrix writes.

The negative bit of direct5C selects the complete boss restoreC20012/C2019E model, with real loader lists, palette DMA and character graphics. It uses the post-HUD widths and flags: PHP/PLP restoration belongs to that nested call, not to the entire FF6B body. Finally FF6B copies the word at direct27 into both0600 and7EDE00, returning M16.

`tools/event_screen_restore_proof.py` prepares176 directed complete comparisons: one representative of each actual graphics/header/special-mode tuple, all44 real boss restoration identities, and directed caller contexts for both entries. It keeps original callees intact. This avoids multiplying already checked resource dependencies across redundant caller worlds. Cases compare all memories, PPU/DMA/port sequences and final registers/context outside the instruction-observed stack. No NMI is delivered during forced blank; the final enable request is observed. Complete menu input, event1F dispatch and malformed map domains remain open.
