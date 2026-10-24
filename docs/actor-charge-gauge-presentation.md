# Native charge gauge presentation

`actor_charge_gauge_presentation.ChargeGaugePresentation` reconstructs C0EBB6/251, C0ECB1/64, C0ECF1/23 and C1C9F1/19, totalling **357 candidate instruction bytes**. This is the real gauge/flash dependency of hero worker C0EB36; its glyph converter and division helper are exercised through complete gauge calls.

The model updates the native sprite attribute word, actor phase63 and deferred charge counter, seeds the existing attack palette at phase40, or clears the five gauge glyphs at phase rollover. Its active branch uses the hardware multiplier and divider to compute the percentage, converts it to three native glyph selectors, publishes the two literal palette words to normal or shadow buffers, and invokes the existing attack-palette preparation when required. The deferred notification path preserves the internal C0BB11 tail's writes to DP95 and0118/0119. That existing tail and palette callees add no new source credit.

C1C9F1 is a full long-return entry. Its bit8 gate and palette seed continue into the already reconstructed C1CA49 tail, without a fake success adapter. Palette/glyph assets are read at runtime and are not exported or credited.

Smoke0 passed. The first full run found that the checker had incorrectly constructed a near-return frame for the direct C1C9F1 entry; its native RTL read the missing bank byte. The checker frame was corrected, exact trial13 passed, and the final full15 capture passed without changing model semantics.

Accepted evidence: **15 calls, 1,889 original steps, 277 PC/M/X states, 162/162 own instruction starts**, all101 dependencies unchanged. Full WRAM outside the observed native stack, SRAM, CPU context and peripherals were compared, executing the original instructions without hooks. The accepted model, checker, report and coverage are frozen; the audit records their hashes.

The directed domain is D=0, DB=7E, M=8, X=16, binary arithmetic with aligned actors, valid palette buffers and frame-correlated F4. It covers decimal boundaries, frame gating, phase40/F0, normal/shadow palette buffers, palette preparation, deferred notification and both seed-entry outcomes. Entire C0EB36/C0FBB0 workers and non-counter visual effect families remain open until their full composition is verified. Independent physical source recovery remains the integrator's check.
