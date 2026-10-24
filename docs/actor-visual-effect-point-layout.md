# Native effect point layout and packed trail publication

Two complete dependencies of the actor frame renderer are reconstructed: C1924C..C1939C (336 bytes) reflects the nine-point layout into vertical, horizontal and combined copies; C2ABCA..C2ACA8 (222 bytes) decodes packed trail coordinates and publishes the first point through the previously reconstructed C2ACAC helper. No hooks replace any native calls.

Integration spec: `actor_visual_effect_point_layout_check:ActorVisualEffectPointLayout:actor-visual-effect-point-layout:actor_visual_effect_point_layout`. Both entries use RTL; the point-trail callee uses a real JSR frame. Proposed new physical source: 558 bytes. Neither interval overlaps current source; C2ACA8 is excluded because its existing four-byte wrapper belongs to Motion.

Smoke3 and the first full16 comparison passed without changes between captures. Comparison covers full WRAM, nine CPU fields, S/D/DB/decimal context, graphics/audio/arithmetic peripherals, and ordered arithmetic writes. Every own instruction start and immediate width is observed: 253/253 (137 reflection,116 trail), 296 PC/M/X states,105 dependency hashes unchanged. Both recovered bodies assemble exactly against ROM.

Native input contract: D0,DB7E,M8,X16,binary arithmetic and aligned actor offsets. Four reflection cases retain arbitrary packed coordinates and attributes; twelve trail cases cover counts1,2,3,4,5,9,10,11,12,16,20,21, all orientations, scaled/unscaled signed axes, offsets, tile-bank carry and ten-point tile wrap. Trails are nonempty: a zero count executes the original underflow loop rather than a normal empty return and is outside this produced decoder domain. Generated packed-coordinate fixtures validate the decoder ABI; live frame-source reachability is reserved for the full renderer composition.

Shared API: `ActorVisualEffectPointLayout(rom,cpu).expand_reflections()` / `.decode_trail()` / `.run(entry)`. The inherited `.geometry_coordinate()` and `.publish_point(base)` provide the literal packed-axis and tile progression used by the forthcoming C0F9F1/main renderer, preserving shared CPU and native stack writes. Helpers do not expand the claim to the full actor renderer or scheduler.

## Frozen evidence

- `tools/actor_visual_effect_point_layout.py`: `c076adfba5fd731697efcaa6839f1cbed4624351561effc8831035e9ec3b3a9e`
- `tools/actor_visual_effect_point_layout_check.py`: `08af78c2a92052995d3357b6d89eecb69b8790e687a2247fb29e8b12c6d4a3b0`
- `data/actor_visual_effect_point_layout.json`: `62bf3d839dbcfab13d2896e8723f2c15ce7e8f14ab9312046a9668e0fa7cc886`
- `data/actor_visual_effect_point_layout.coverage.json`: `9a52938d3b88c5a95143cafe94b18d3dd067cc06e14378c83951b1577f1fb378`
- `data/actor_visual_effect_point_layout.source_audit.json`: `53f3c5954422dfc53b47711c3bc0022f538dd52e59b6ac8e08a610ecab3487c9`
