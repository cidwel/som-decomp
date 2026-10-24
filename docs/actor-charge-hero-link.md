# Linked hero preparation before charge frames

`actor_charge_hero_link.ChargeHeroLink` reconstructs C0F025/153 and the three 34-byte helper pairs starting C0F0BE, C0F0E0 and C0F102: **255 instruction bytes**. This is the actual preparation called by C0EB18 before its three hero workers, not an invented caller for isolated leaves.

The preparation clears each hero's E067 byte and selects two pair comparisons according to D5. F1 and each candidate's E02C byte control whether a comparison runs. The helpers check the selected hero's active byte and compare the literal **low bytes** of E002 and E004. A difference executes two byte PLA operations, discarding the helper return address before RTS returns directly to F025's caller. The model expresses this transfer as an early return with the exact final byte pulled from the known F0xx call sites. It does not offer the helpers as standalone RTS functions.

When comparison permits completion, the routine clears DP4E, selects the hero from DPD4, broadcasts fields10,0B,8E to the three heroes, and clears each E006 word only when DPFF is zero. Its early exit deliberately retains the linking gate and skips those copies. High-byte differences in coordinates do not change the literal comparison's outcome.

Smoke1 exercised the native unwind and passed; the first complete33 original capture also passed. Evidence: **1,339 original instructions, 111 PC/M/X states, 110/110 own instruction starts**, and all99 dependency hashes unchanged. The original instructions executed without hooks. Full WRAM outside the observed stack footprint, SRAM, CPU context and peripherals matched.

Directed cases cover three D5 selections, first and second pair horizontal/vertical mismatches, inactive and negative candidates, busy bypass, forced comparison, DPFF cleanup bypass and equal low bytes with differing high bytes. Native context is D=0, DB=7E, M=8, X=16, binary arithmetic and aligned hero offsets0/200/400. Complete actor-worker and frame scheduling composition remains a separate open proof.

The accepted model, checker, report and capture are frozen. `data/actor_charge_hero_link_audit.json` records spans, coverage and hashes. No numeric tables/assets or existing dependencies add duplicate credit; independent source recovery checks the physical255 bytes separately.
