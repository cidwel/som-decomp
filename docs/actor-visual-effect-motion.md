# Actor visual-effect cadence, motion and point trails

C191E1 updates the actor's effect cadence and two signed seven-bit position increments. The native hold byte delays motion until its signed countdown expires, then reloads that countdown. The effect flags select ordinary step counting, fractional point movement through C2A407, or a finite point trail through C2ACA8/C2ACAC.

C2A407 advances each byte-sized point by integer increments and accumulates fractional components against the supplied threshold, carrying one positive or negative pixel when the threshold is crossed. C2ACAC appends real coordinate pairs to the ten-slot ring, wraps its slot cursor and saturates the visible length at ten. On retirement it decreases the visible length, copies the remaining coordinate pairs and clears effect visibility when the final point expires. Both public and near entry contracts preserve the original width, flags, scratch and stack behavior.

Smoke3 and the first full20 passed with no model change during original comparison. Directed cases cover positive/negative/zero velocity, hold/reload, step wrap, zero/three point counts, positive and negative fractional crossing, non-crossing and zero threshold, trail slot wrap, saturation, final retirement and multi-point copying. Three aligned actor offsets cover hero and enemy records. Original calls and their entire dependency bodies execute without hooks; full WRAM outside observed native stack, CPU/context and peripherals match. The ABI is D0/DB7E/M8/X16/binary with finite point lists and produced trail lengths/slots. This does not claim the outer C1833A scheduler or E0 branch C18D80 is complete.

All194/194 own instruction starts and immediate widths are observed, with340 PC/width states and104 unchanged captured dependency hashes. Four sources assemble exactly, totaling398 instruction bytes: C191E1/107, C2A407/121, C2ACA8/4 and C2ACAC/166. C2A480 begins a different caller and remains open; the separate RTS at C2AD52 is excluded from this body.

Integration spec: `actor_visual_effect_motion_check:ActorVisualEffectMotion:actor-visual-effect-motion:actor_visual_effect_motion`.

Reusable API: `ActorVisualEffectMotion(rom,cpu).effect_motion()` or `.run(0xC191E1)`, followed by `.result()` for nine logical CPU register/flag/width fields. The CPU, scratch memory and real stack are shared. Direct helpers are `.fractional_points()` and `.point_trail()`; `.run(0xC2ACA8)` adds its literal near-call frame.

## Frozen hashes

- `tools/actor_visual_effect_motion.py`: `3c11414d1ed15c70f51e4d00f7a2ea14b9ace7fccc25b180ef59c6598d43d452`
- `tools/actor_visual_effect_motion_check.py`: `1da515421b57db88e0c68c86c5f4e2a8876387c8c3738ec35b2f3d68f16d949a`
- `data/actor_visual_effect_motion.json`: `e2cc4b31bccc68c382ee906a73e8cf47b9d08a36d8ecbc23a1f16c640fac5cfb`
- `data/actor_visual_effect_motion.coverage.json`: `b698a07c80fc14918c4af10c00bb41536ccd2b8f9de807519bfdd8661fc867cf`
- `data/actor_visual_effect_motion.source_audit.json`: `57ed4dc9dccc20cb97e4ba4b71eba636fe06701f6fa0f7ae8dfa4895c14d1dd5`
