# Cast queue initialization

C038CE is a144-byte routine called through public C00045/C0382D. It clears four sixteen-word utility arrays0380/03A0/03C0/03E0, then99words fromFE00. The original A supplies the sixteen-bit random seed; zero substitutes7524.

Its shift register tests bits4001 and feeds their exclusive-or into bit15 before shifting. Values are emitted only when the shifted value has bit0 set; fifteen emitted bytes populate03F1..03FF. If their combined OR is notFF, the original repeats the full batch with the continuing seed. Finally03F0 is cleared. This is variable-length generation rather than a fixed count of random steps.

The new model and checker preserve those loops. An iteration limit raises a diagnostic error without accepting shortened output. Model-only preflight covers sixteen contexts: seeds0/1/85/4000/4001/7524/8000/FFFF, M16/X16 and M8/X8, D0/1234, native DB7E and binary arithmetic. Seed85 requires two batches and116 steps, so retry is an explicit positive case. Final N/Z derive from restored D: the original restores P before PLB and PLD, which then update flags.

Original comparison passed sixteen calls on its first capture after one smoke case. All72 own instruction starts are covered, including the retry-producing seed85. Full WRAM outside the observed native stack, CPU registers/status and D/DB/S, and peripherals agree. Final hashes and revalidated dependencies are in `data/boss_cast_queue_initialize_audit.json`; model/checker/reports are frozen. The144 instruction bytes await root's independent source recovery.

The public C2001B wrapper will be composed separately with the already verified C23057 random table initializer. Its first PHA occurs before REP30, so its valid caller contract must retain M16 rather than claim arbitrary incoming accumulator width. This proof establishes initialization, not a full subsequent random consumer or fight.
