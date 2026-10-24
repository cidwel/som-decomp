# Original right-pair pointer-zero loop

`map_graphics_right_pair_contract.run` models C1C195, its C1C357 helper and
C1C486 tail on native binary D0/DB7F calls. The caller supplies the ordinary
near return frame. The model retains the actual BNE pointer-zero condition;
X stays15, rather than becoming a fabricated decrementing loop counter.

The helper computes all three pointers with chained ADC carry, writes rows
in their original descending order, and preserves every private push/pop.
The optional helper limit yields the actual C1C199 loop-head state instead
of inventing a return for bounded observations.

Twelve independent calls compare full CPU17, all CPU attributes except the
instruction counter, WRAM/SRAM, loader-PPU state, base hardware and exact
private stack. Ten aligned calls return; two8401 calls stop after1100
complete helpers. Total2,312,986 original instructions, no hooks/scratch
exclusions. Inputs0040/8000/8400/FF80/FFC0/8401 andP03/F7 are synthetic
caller contexts. No arbitrary bank/direct/alias, whole type11 initialization,
physical timing, interrupt or rendered-frame claim. No new source bytes.

Evidence: `data/map_graphics_right_pair_contract_proof_20261013.json`.
The primary catalogue status and historical bounded observations stay intact;
this is an additive standalone contract.
