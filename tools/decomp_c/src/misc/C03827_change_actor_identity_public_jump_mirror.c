#include "som_c.h"

/* C03827 change_actor_identity_public_jump_mirror   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/change_actor_identity_public_jump_mirror.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void change_actor_identity_public_jump_mirror(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC055EC, SOM_RTL); /* change_actor_identity_and_attributes */
}
SOM_REGISTER(0xC03827, SOM_RTL, "gen", change_actor_identity_public_jump_mirror, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 3, 1)
