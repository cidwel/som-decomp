# Fractional movement

C20A9A99bytes saves A at DPC3, adds the low fractional and high integer velocity to X position, and invokes complete terrain then party collision. Rejection subtracts the same low/high velocity, preserving borrow across the coordinate pair. It independently repeats that process for Y. Unlike C236FF, it does not invoke a slide retry after rollback.

The new model composes frozen AnimationMovement/TerrainMotion helpers rather than replacing either collision check. The prepared23 directed contexts cover low-word carry and borrow, zero and signed whole/fractional speeds, terrain rejection, party collision, world limits, height64 and negative party status. Native tile caches at7F0000 and properties7FB800 are explicit synthetic fixtures; their original loader provenance is not claimed. Model-only preflight passes.

Original comparison passed23calls on its first capture after one smoke case. All38own instruction starts and275PC/M/X states are covered;48dependency hashes were revalidated. Full WRAM outside the observed native stack, CPU/context and hardware/peripherals agree. Evidence is in `data/boss_fractional_motion_audit.json`; model/checker/report/coverage are frozen for source recovery.

Incoming X and DP87 select the same aligned boss actor, D0200/DB7E/M16/X16 and binary arithmetic. This is not a whole fight or frame.
