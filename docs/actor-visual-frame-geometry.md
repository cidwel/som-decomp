# Actor frame geometry composition

The complete readable renderer reconstructs C0F1AE/25, C0F1C7/8 and C0F1CF/732: 765 new instruction bytes. The four genuine native captures contain 51 calls and 31,130 original instructions. Their union observes all 396 own instruction starts, with immediate widths sufficient to recover each source exactly. All captured dependency hashes remain unchanged; no original hooks are used.

| Entry | Bytes | Purpose | Own starts |
|---|---:|---|---:|
| C0F1AE | 25 | Publish secondary heroes with saved/restored data bank | 13/13 |
| C0F1C7 | 8 | Publish primary hero | 3/3 |
| C0F1CF | 732 | Expand frame tiles and points; publish collision rectangles | 380/380 |

The model preserves literal, repeated and incrementing tile expansion; signed and scaled geometry; native collision Y saturation; ordinary actor and C0/E0 effect routes; three-cell merging and trail decoding. It composes the frozen 972-byte point-layout/tile models, C2A480 point producer, complete Boss `VisualEffectScriptsEvents` and CastExecution dependencies through actual physical call frames. The event adapter preserves the C1E76D live-flag contract rather than substituting its public PHP/PLP alias.

Primary42 compares 21 directed ROM D4 resource/index inputs, entry gates, nine accepted enemy cast producers, one accepted kind4 producer and both hero aliases. Secondary-hero entry includes DB0/M16/X8 and restores its data bank. A ROM DBFF frame address covers the native low-byte pointer carry. Cast preparation applies the already reconstructed C2A2E8 motion reset before the real cast producer; kinds and pointers are not replaced after production.

Separate guard4 adds two hero cast80 producers, a fresh homing-hit C0 victim and native count15 rejection. The victim is reset before delivery and placed at120/100 before the hit; the rejected count comes from an unmodified ROM table input. Separate paths3 progresses that fresh victim across nine elapsed-timer boundaries, and exercises fixed-pose merge4/trail5 decoder inputs with original ROM descriptors and nonzero secondary lengths. Separate bounds2 observes explicit-height overflow at C0F44A and negative horizontal rectangle nibble at C0F469, using original frame13 and weapon0/frame90 data.

These fixed-pose, rejected-table and height-boundary examples establish explicit decoder ABI behavior. They do not assert that every chosen resource/index combination, fixed effect pose or height is produced by gameplay. Positive ordinary casts, enemy casts and fresh hit production are separately composed. The whole actor scheduler remains open.

Every comparison preserves complete WRAM outside the observed native stack writes, SRAM, nine logical CPU values, S/D/DB/status context, graphics/audio/arithmetic peripherals, raster and IRQ state, and ordered audio/arithmetic writes. The first full42 found an omitted palette multiplier transaction in trial30: native4202=164 and4203=10 while the inherited command model only changed final hardware state. A new local adapter preserves these writes without modifying frozen dependencies. Exact replay30 and the new full42 both pass. Subsequent captures are independent and immutable; no traces are synthesized or merged into the primary file.

Integration spec: `actor_visual_frame_geometry_check:ActorVisualFrameGeometry:actor-visual-frame-geometry:actor_visual_frame_geometry`.

Additional genuine captures: `actor_visual_frame_geometry_guard`, `actor_visual_frame_geometry_paths`, `actor_visual_frame_geometry_bounds`. `data/actor_visual_frame_geometry.source_audit.json` records each report/capture hash, instruction-start union and unchanged dependencies. Model SHA256: `cce6f0ebfdd7e7a9db795d88b0c9b939341b6a7d812e17ac6ac1abd711aceb4f`.

The next coherent frontier is the 575-byte actor animation step/reader family C0F4AB/C0F4CB/C0F8B3/C0F8EE/C0F90B, including real program calls and nonlocal PLA continuations. It remains unverified until its own original comparison and source audit close.
