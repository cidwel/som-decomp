# Party-command save and cold restart

Two complete source bodies now cover the command's selector6 save/restore
path (`C1EBB2..C1EBC2`, 17 bytes) and selector7 cold-reset transfer
(`C1EBC3..C1EBCA`, eight bytes).

The save path passes the current word at `010E` to the real save-menu request,
then restores the screen through `FF3A` before returning. Its two complete
native event caller comparisons cover actual save writing and cancellation,
including the menu, SRAM, screen-resource rebuild and ordered hardware/input
effects. Their unchanged reports and captured instruction states are checked
against current dependency and ROM hashes. The recorded caller is native
D0/DB7E/M16/X16; arbitrary menu inputs and exception paths remain open.

The cold-reset path passes 1,536 original comparisons across both M/X widths,
all CNZV combinations, D0/300, DB00/7E/42, binary/decimal and interrupt status,
and wrapping event cursors. It consumes the opcode and selector, then jumps
to `00:8004`. It preserves the abandoned near-call frame at `1EFE`; it does
not execute an RTS. Complete WRAM, SRAM, CPU/context and hardware match without
stack exclusions or instruction hooks. Reset execution and the later bootstrap
remain separate contracts; this test ends at the actual control-transfer target.

All ten own instruction starts and immediate widths were observed. Both
mnemonic sources independently assemble to the exact 25 original bytes.
Existing menu/restoration callees receive no duplicate source credit. Other
party selectors and the full command/event/game coordinator remain unfinished.

Evidence: `data/event_party_cold_restart_transfer.json` and
`data/event_party_save_restart_source_audit.json`.
