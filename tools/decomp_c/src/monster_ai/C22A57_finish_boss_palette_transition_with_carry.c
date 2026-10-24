#include "som_c.h"

/* C22A57 finish_boss_palette_transition_with_carry   [class A, 2 bytes, 2 instructions]
 * Source: src/rom/finish_boss_palette_transition_with_carry.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void finish_boss_palette_transition_with_carry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    r->c = true; /* SEC */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22A57, SOM_RTS, "hand", finish_boss_palette_transition_with_carry, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 2, 2)
