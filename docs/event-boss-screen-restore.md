# Complete boss screen restoration

`tools/event_boss_screen_restore.py` composes the complete native restoration entry with the existing readable boss loader, palette DMA and newly verified character reload. `data/event_boss_screen_restore_proof.json` records8,544 passing original calls; its own capture observes every instruction start and fixes all immediate widths. All three bodies and44 numeric restoration pointers independently assemble byte for byte; the checkpoint credits94 instruction bytes and88 typed data bytes.

| Entry | Bytes | Behavior |
|---|---:|---|
| C20012 | 3 | Same-bank JMP to long-return restoration |
| C2019E | 69 | Save caller status/context, restore boss resources, palettes and character graphics |
| C201E3 | 22 | Reload nonzero palette ids from slots beginning at C5 |

The outer entry saves PHP/PHD/PHB, sets DB7E/D0200/M16/X16, publishes C7 to0364 and selects one of44 real restoration lists from C20146 using boss identity54..7F. These are the restoration pointers, rather than the initialization table at C200EE. Their44 words add88 typed bytes; neither table payloads nor graphics/scripts are exported.

The lists execute complete loader commands1D/11/01/1B/1E/12/1C. The reused VM expands graphics into WRAM/VRAM and performs real DMA, including the actual native8F20 resource variant. No command is bypassed or replaced with a return. Existing instruction sources and their dependencies receive no duplicate credit.

C201E3 scans each palette slot from C5 through15. A zero low id skips the loader; nonzero ids run the full C226AC WRAM-port DMA. PHX/PLX restores the scan index after the palette loader replaces X. The loop reads words then masks00FF, so adjacent high bytes do not extend an id. It finishes X16/C1/N0/Z1; A and Y depend on the last accepted row, and V is cleared by palette-address addition when a row is loaded. The proof separately covers every256 low ids and16 normal starts in two contexts.

After the palette scan, C2019E clears EE00/F000 only when the corresponding descriptor equals3D34, then executes the complete77-slot DBF900 reload. PLB/PLD/PLP restores the caller's D/DB and C/N/Z/V/M/X; restoring X8 truncates X/Y. Flags temporarily produced by PLB/PLD do not survive final PLP. The restored A/X/Y remain the actual graphics-call outputs.

The proof includes all44 lists, both long entries and four caller contexts, active/skipped character slots, hidden-child matches/nonmatches, both resource-callback variants and C7values0/1/8000/FFFF. Full WRAM outside observed native stack, SRAM/VRAM/CGRAM/DMA/hardware/port latches, CPU results and context agree. Domains are binary native mode, forced blank/VMAIN80, valid real restore identities and palette start0..15. Decimal/emulation mode, malformed identities/starts, FF6B, the menu and complete event1F remain open.
