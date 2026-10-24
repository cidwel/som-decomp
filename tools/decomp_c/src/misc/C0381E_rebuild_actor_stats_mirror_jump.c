#include "som_c.h"

/* C0381E rebuild_actor_stats_mirror_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/rebuild_actor_stats_mirror_jump.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void rebuild_actor_stats_mirror_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    TAIL_CALL(c, 0xC04530, SOM_RTL); /* rebuild_actor_attributes_native */
}
SOM_REGISTER(0xC0381E, SOM_RTL, "gen", rebuild_actor_stats_mirror_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 3, 1)
