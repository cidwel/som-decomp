#include "som_c.h"

/* C00018 public_random_byte_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_random_byte_jump.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXY.
 */
static void public_random_byte_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    TAIL_CALL(c, 0xC03800, SOM_RTL); /* mirror_random_byte_jump */
}
SOM_REGISTER(0xC00018, SOM_RTL, "gen", public_random_byte_jump, 0, L_A | L_B | L_X | L_Y, 1, 1, 0, 3, 1)
