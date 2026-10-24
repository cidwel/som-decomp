# Native frame-driven point and trail producer

C2A480 initializes the point targets, cadence and fractional velocities consumed by the verified C191E1/C2A407 Motion chain; effect kinds at least5 instead initialize finite trails. The real caller is JSL02A480 at C0F41D, selected for E060=C0 and negative frame flag DP05. C0F1F2..C0F207 installs D3 as the frame-geometry pointer bank for that actor state; script traversal separately uses D1. Target presentation supplies E06A/E0FC from D02AA2/D02AA6. This is not the hero casting direction table, which belongs to a different animation-bank context.

The complete five-body model covers C2A480/37, C2A4A5/396, C2A631/104, C2A699/3 and C2A69C/41, totaling581 new instruction bytes. The decoder skips negative control records, resolves the frame's pointer, scans literal and compressed geometry, decodes signed/scaled/mirrored point positions, preserves excess old points where applicable, and publishes signed quotient/remainder records using the actual hardware division ports. Frame duration determines the denominator; zero-divisor behavior is preserved in the independent delta helper. No script, frame, graphic or ROM payload is stored.

FF is a native nonlocal return: C2A699 PLY consumes the command handler's own JSR return word, then RTS returns to the caller of the frame decoder. The model preserves that path, including Y receiving the native A4B9 return word and the outer wrapper restoring X from DP14. C2A699 is an internal branch destination whose contract requires that active call frame, not an independently asserted ordinary callable routine.

Smoke3 and first full20 passed without model changes. Primary cases use six original target-presentation record classes at offsets8/16/24/32/40/48, repeated actor contexts, trail saturation, signed/zero/divisor-zero deltas, all four command width classes and a real FF terminator. The primary observed294/311 instruction starts. A separate smoke1/full6 supplement uses actual script positions and D3 geometry records for literal scanning, small coordinates, X/Y mirrors, an empty frame, and a finite metadata count below the frame's point count. It closes the17 missing starts without repeating the20 primary calls. The metadata clamp is a directed native body-ABI case; its occurrence in a live C0F1CF producer trajectory remains to be established with that consumer.

The unchanged20+6 captures observe all311/311 instruction starts and immediate widths. All five bodies assemble exactly;311 PC/width states and every dependency hash are preserved. Checks compare complete WRAM outside the observed stack, all nine CPU result fields, S/D/DB/arithmetic mode, graphics/audio/arithmetic peripherals, and the ordered4202..4206 arithmetic writes. No instruction hooks or helper bypasses are used. The native domain is D0/DB7E/M8/X16/binary, aligned actors, D1 script/D3 geometry pointers and finite original frame counts0..10; the signed-delta helper additionally verifies its explicit zero-divisor input. This establishes these source bodies and their composed ABI, not a complete gameplay animation trajectory or cycle timing.

Integration spec: `actor_visual_effect_point_producer_check:ActorVisualEffectPointProducer:actor-visual-effect-point-producer:actor_visual_effect_point_producer`. Additional genuine evidence: `actor_visual_effect_point_producer_guard` (6 calls). Source audit records the provenance-preserving union. No prior manifest interval overlaps these581 bytes.

Reusable API: `ActorVisualEffectPointProducer(rom,cpu).initialize_points()` / `.run(0xC2A480)`, `.point_frame()` for C2A4A5, `.point_delta()` for C2A631 and `.skip_command()` for C2A69C. `.result()` returns A/X/Y/C/N/Z/V/M/XF with a shared CPU/stack/peripheral context. Scripts are decoded at runtime from the local original ROM. The next assigned consumer is C0F1AE/25 + C0F1C7/8 + C0F1CF/732, with C1818F visual-script dependency being reconstructed separately by the boss agent.

## Frozen hashes

- `tools/actor_visual_effect_point_producer.py`: `a18dc92b4aa297c22c5186666430bae55193ef60a18e6c729f27e7e73f39d50e`
- `tools/actor_visual_effect_point_producer_check.py`: `0cf9dab7967bed948f209bcc54001ca86ba99f4c20793ba12d7bd4e5088b6505`
- `tools/actor_visual_effect_point_producer_guard.py`: `7cb6960b83ba15559d531006041b418cfcd945544bf4a6550f298a4c2e7fcb26`
- `data/actor_visual_effect_point_producer.json`: `ad9a77284e2ad666268f9e069e2adefb947357910b7080dda39c7b1499e9b102`
- `data/actor_visual_effect_point_producer.coverage.json`: `7f2bd96063be6d94c40417f41c273a8b8e6ecc76a43695f2c2d17cb5b85aaf13`
- `data/actor_visual_effect_point_producer_guard.json`: `725a786232ea0af748575a38a57a3ac6302ac713a2d229d048e895ea3730970c`
- `data/actor_visual_effect_point_producer_guard.coverage.json`: `f97a1b085a00e36ef77103d69bb1dcc30aa73b4aad20b35bb8fc3c07689d960b`
- `data/actor_visual_effect_point_producer.source_audit.json`: `4d77425eb1362f13f7de5399c83462e9ad8a6954e534806375a26edc20bdd37d`
