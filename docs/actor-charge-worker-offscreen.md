# Charge worker offscreen retention

`actor_charge_worker_offscreen.ChargeWorkerOffscreen` reconstructs C0FC2E/94, the complete dependency reached from normal actor worker C0FBB0. It checks actor bit44, the event gate, selected actor and mode-specific counter thresholds, then compares signed screen coordinates with the native bounds: horizontal −64 through319 and vertical −64 through287. A record outside either bound is either deleted when E032 is set or marked with E043=1. The helper preserves its literal early-return widths and flags.

Smoke0 and the first full14 capture passed without hooks: **284 original steps, 43 PC/M/X states, 43/43 own instruction starts**, with all99 dependency hashes unchanged. Directed cases cover each gate, both thresholds4/10, all four signed borders and both positive outcomes. Full WRAM outside the observed stack, SRAM, CPU context and peripherals were compared.

Evidence is the immutable model/proof/report/coverage plus `data/actor_charge_worker_offscreen_audit.json`. Native domain is D=0, DB=7E, M=8, X=16, binary arithmetic and aligned actor offsets. This proves the callee's behavior; the enclosing charge worker and complete battle scheduling remain open. No assets or duplicate dependency bytes are credited.
