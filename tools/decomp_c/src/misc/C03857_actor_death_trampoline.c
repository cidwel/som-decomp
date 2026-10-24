#include "som_c.h"

/* C03857 actor_death_trampoline   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/actor_death_trampoline.s
 * Documented in docs/boss-native-linked-public-death.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: YV.
 */
static void actor_death_trampoline(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC04177, SOM_RTL); /* actor_death_public_context_and_reward_cleanup_wrapper */
}
SOM_REGISTER(0xC03857, SOM_RTL, "gen", actor_death_trampoline, 0, L_Y | L_V, 1, 0, 0, 3, 1)
