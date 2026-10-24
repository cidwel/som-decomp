#include "som_c.h"

/* 018015 floating_combat_number_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/floating_combat_number_public_jump.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 * Entered by JSL from the boss contact code; the JMP continues in 018018, which ends with RTL.
 */
static void floating_combat_number_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    TAIL_CALL(c, 0x018018, SOM_RTL); /* create_floating_combat_number_with_saved_context */
}
SOM_REGISTER(0x018015, SOM_RTL, "hand", floating_combat_number_public_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)

/* The run time resolves a bank 01 address through som_norm ($01:8015 -> $C1:8015) and only registered
 * addresses are found, so the same body is registered under the normalised address as well. */
static void floating_combat_number_public_jump_c1(SomCtx *c) { floating_combat_number_public_jump(c); }
SOM_REGISTER(0xC18015, SOM_RTL, "hand", floating_combat_number_public_jump_c1, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)
