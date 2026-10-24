#include "som_c.h"

/* C03824 refresh_actor_appearance_public_jump_mirror   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/refresh_actor_appearance_public_jump_mirror.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void refresh_actor_appearance_public_jump_mirror(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    TAIL_CALL(c, 0xC0457C, SOM_RTL); /* refresh_actor_appearance_native */
}
SOM_REGISTER(0xC03824, SOM_RTL, "gen", refresh_actor_appearance_public_jump_mirror, 0, 0, 1, 1, 0, 3, 1)
