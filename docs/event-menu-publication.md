# Native menu publication and slot counters

The new `event_menu_publication.py` reconstructs117 instruction bytes
in three complete bodies. C01E94 publishes requested menu tiles and sprites,
with the true page5 actor text/description transfers and two-byte actor colour
publication. It consumes bits2/4 ofA20A while preserving the actual BIT/TRB
status and ordered PPU/DMA effects. All callees are complete verified models.

C029FC counts eight live bytes equal to1, restoring the caller X through its
native RTL frame. C02A14 counts eight SRAM nibbles equal to1, reading the actual
runtime SRAM bus and preserving the native XBA counter/high-byte residue.
No save-game or graphics payload is persisted.

The original comparison passed 136 complete calls. All 55 instruction starts
were observed. Every memory/peripheral/register result and ordered video/audio
write was checked outside the actual occupied native stack. The bodies assemble
byte for byte against the ROM; the joint source build is the final credit gate.
Full C01D97 interaction, asynchronous console timing and rendered pixels remain open.
