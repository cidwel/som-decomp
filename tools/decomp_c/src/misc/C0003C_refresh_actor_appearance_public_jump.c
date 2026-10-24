#include "som_c.h"

/* C0003C refresh_actor_appearance_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/refresh_actor_appearance_public_jump.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void refresh_actor_appearance_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    TAIL_CALL(c, 0xC03824, SOM_RTL); /* refresh_actor_appearance_public_jump_mirror */
}
SOM_REGISTER(0xC0003C, SOM_RTL, "gen", refresh_actor_appearance_public_jump, 0, 0, 1, 1, 0, 3, 1)
