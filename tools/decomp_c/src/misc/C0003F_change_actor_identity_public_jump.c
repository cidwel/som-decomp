#include "som_c.h"

/* C0003F change_actor_identity_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/change_actor_identity_public_jump.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void change_actor_identity_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03827, SOM_RTL); /* change_actor_identity_public_jump_mirror */
}
SOM_REGISTER(0xC0003F, SOM_RTL, "gen", change_actor_identity_public_jump, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
