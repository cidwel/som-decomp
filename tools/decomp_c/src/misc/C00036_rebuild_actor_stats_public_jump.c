#include "som_c.h"

/* C00036 rebuild_actor_stats_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/rebuild_actor_stats_public_jump.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void rebuild_actor_stats_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    TAIL_CALL(c, 0xC0381E, SOM_RTL); /* rebuild_actor_stats_mirror_jump */
}
SOM_REGISTER(0xC00036, SOM_RTL, "gen", rebuild_actor_stats_public_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 3, 1)
