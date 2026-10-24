# Native party-command selector five

[V] `tools/event_party_noop.py` closes the complete `$C1EB63` entry for operand
five: advance the sixteen-bit event cursor twice, compare the selector and
return. The model preserves the accumulator high byte, overflow, decimal and
interrupt flags, both index widths, direct page and data bank. Cursor wrap is
literal sixteen-bit wrap. Other selectors remain open.

The 1,920 original calls compare every WRAM byte, including the exact two-byte
near-call stack frame, SRAM, hardware state and final CPU registers. There are
no hooks. Direct pages zero and `$0300`, three data banks, both accumulator/index
widths, all CNZV combinations and five cursor boundary values are covered.
All eleven instruction starts and their expected entry widths are observed.
Evidence and dependency hashes are in `data/event_party_noop.json`.

Three disjoint source spans recover 21 instruction bytes. Conditional branches
to other selectors retain their original targets; those target bodies receive
no credit from this proof. Exact assembly is checked by `make verify-source`.
