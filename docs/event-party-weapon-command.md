# Group-command weapon refresh

Selectors8..11 of event command1F call the existing public three-hero weapon
refresh and return. The nine-byte body `C1EBCB..C1EBD3` compares the selector
with12, calls `C0005A` on this path and returns through the actual event frame.

256 complete original event caller comparisons cover all four selectors,
eight representative raw inventory values and eight slot/priority/status
contexts. All three native actor attribute rebuilds remain part of the
comparison. Both incoming M/X widths, D0/300/1234, DB00/7E/7F, binary arithmetic,
caller interrupt status and wrapping script cursors are checked. Full WRAM,
SRAM, CPU/context, arithmetic peripherals and audio agree outside the
instruction-observed consumed stack; there are no instruction hooks.

All four own instruction starts were observed. The independently assembled
source matches its exact original nine bytes. Existing weapon-refresh and
stat-rebuild sources receive no duplicate credit. Selectors12 and above,
arbitrary gameplay trajectories and the complete event interpreter remain open.

Evidence: `data/event_party_weapon_command.json` and
`data/event_party_weapon_command.source_audit.json`.
