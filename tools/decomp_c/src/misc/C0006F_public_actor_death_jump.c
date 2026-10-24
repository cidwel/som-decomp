#include "som_c.h"

/* C0006F public_actor_death_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_actor_death_jump.s
 * Documented in docs/boss-native-linked-public-death.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: YV.
 */
static void public_actor_death_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03857, SOM_RTL); /* actor_death_trampoline */
}
SOM_REGISTER(0xC0006F, SOM_RTL, "gen", public_actor_death_jump, 0, L_Y | L_V, 1, 0, 0, 3, 1)
