#include "som_c.h"

/* C03800 mirror_random_byte_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/mirror_random_byte_jump.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXY.
 */
static void mirror_random_byte_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    TAIL_CALL(c, 0xC03872, SOM_RTL); /* random_byte_with_preserved_direct_page */
}
SOM_REGISTER(0xC03800, SOM_RTL, "gen", mirror_random_byte_jump, 0, L_A | L_B | L_X | L_Y, 1, 1, 0, 3, 1)
