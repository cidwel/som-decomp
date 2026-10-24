# Literal C2 leaves without established gameplay callers

The model `boss_unused_native_leaves.UnusedNativeLeaves` reconstructs five complete bodies: C244A2/6, C265E7/6, C260AD/10, C265D9/2 and C265DB/1. These total 25 instruction bytes. No gameplay dispatcher caller has been established; this is a literal byte reconstruction and runtime contract, not a claim that these paths occur in a fight.

The two motion leaves read direct-page C5, call the complete existing C20A47 terrain/party-collision/slide implementation and return. Their tested C5 value is zero. C260AD reads the actor AB word, doubles it, transfers it to X and reads the near script-root word from DCE292. C265D9 clears carry; C265DB returns without changing it. No missing callee was replaced by a stub.

The directed checker executed 24 original calls without hooks: twelve motion cases, eight AB selectors 0..7, and both carry values at both return leaves. It passed on its first original capture: **2,794 original steps, 179 PC/M/X states, 14/14 own instruction starts**, with all 130 dependencies revalidated. Full WRAM excluding the observed stack footprint, SRAM, CPU/context, peripherals and ordered audio writes were compared.

The native domain is D=0200, DB=7E, M=16, X=16, binary arithmetic, aligned pool actor selected by DP87 and the existing helper's valid synthetic tile cache. This does not prove arbitrary C5 values, malformed caches, arbitrary AB selectors or gameplay reachability. The proof includes the original callee execution, but those existing callee bytes add no new source credit.

`boss_unused_native_leaves_numeric.py` generates a separate typed proposal for DCE292/16: eight u16 near script-root pointers. All eight lookups passed and the explicit word source independently assembled to the original 16 bytes with ca65/ld65. The script bodies and graphical assets are not copied or credited. The numeric source and manifest proposal are isolated under data; integration and physical overlap checks remain separate.

Evidence: `data/boss_unused_native_leaves_proof.json`, `.coverage.json`, `_audit.json`, `_numeric.json` and `_numeric_manifest_proposal.json`. The accepted model, checker and capture are frozen.
