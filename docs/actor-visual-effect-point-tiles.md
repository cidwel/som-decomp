# Actor effect point tiles and three-cell merge

C0F9F1..C0FB8F is a complete 414-byte dependency of the actor frame renderer. It consumes packed coordinates, publishes attribute/tile words, returns directly for kind1/kind>=4, expands reflected point layouts for other kinds below4, and concatenates three tile streams for kind4. The kind4 branch snapshots the current tile stream, appends the two history streams and updates their tile indices while preserving attribute bits. C0FB8F belongs to the following worker and is excluded.

Integration spec: `actor_visual_effect_point_tiles_check:ActorVisualEffectPointTiles:actor-visual-effect-point-tiles:actor_visual_effect_point_tiles`. Additional genuine capture: `actor_visual_effect_point_tiles_guard`. Main entry is an internal RTS tail. Its reflection call uses an actual JSL frame and the frozen C1924C model; packed coordinate helpers come from frozen PointLayout558.

Smoke3 and the first full16 passed unchanged. The primary capture missed the immediate at C0FB6A (third-cell tile-boundary increment); a separate directed1 with tilebase120A crosses that boundary and passed. The genuine union covers219/219 own starts and widths,356 PC/M/X states. Both dependency manifests are unchanged; recovery assembles the full414-byte body exactly. No synthetic traces or repeated primary comparisons.

Contract: D0/DB7E/M8/X16/binary, inputX is actoroffset/2 (or a produced history offset for kind4), inputY is nonzero point count, DP14 is original actoroffset, and DP10/12 identify packed geometry. Six nonmerge kinds cover0/1/2/3/5/6, signed coordinate and orientation branches. Four primary merges plus the boundary supplement cover coherent nonzero list byte lengths divisible by4 and offsets0/32/64. A zero point/list count executes native underflow rather than a normal empty return and remains outside the producer contract. Generated packed-coordinate fixtures establish this internal ABI; the full renderer must separately establish live frame sources and visual-script context.

Checks compare full WRAM, CPU/result/context, graphics/audio/arithmetic peripherals and ordered arithmetic writes, with no instruction hooks. This does not close C0F1CF or the scheduler; those compositions are being reconstructed separately.

## Frozen evidence

- `tools/actor_visual_effect_point_tiles.py`: `f27c6f307c0b3fb19a971b6c81e2c00cb36a8d4141becefb7496c9b19f671093`
- `tools/actor_visual_effect_point_tiles_check.py`: `e6fcb0d68e63c34d8d08b2daf6dda2d23e50a347fc30cddb85e38f16a218cae5`
- `tools/actor_visual_effect_point_tiles_guard.py`: `e66804b8523646393590c6c784406cb3164970e16f14a23f90b4b57f9ca30b8c`
- `data/actor_visual_effect_point_tiles.json`: `df42902c8d4600267c111726998540017810e4718178a7825fe02751f50b9fba`
- `data/actor_visual_effect_point_tiles.coverage.json`: `314a534e3ed6de5e1b30e36bcfe79f54cc98713530660e17a7218a33c26776b2`
- `data/actor_visual_effect_point_tiles_guard.json`: `b9eca30b622c47d843675a10db6fbad98f8f9f92a8c1c1fc5711f2959bb61767`
- `data/actor_visual_effect_point_tiles_guard.coverage.json`: `699411c5ae9a48d9a809564e857ceb10fb59e461e4ef7ead4ff32d72ff4d25da`
- `data/actor_visual_effect_point_tiles.source_audit.json`: `048efd2f75ca68d4c3fa35ae48c65c60f4c93b167e08fade821224f0af8df1bf`
