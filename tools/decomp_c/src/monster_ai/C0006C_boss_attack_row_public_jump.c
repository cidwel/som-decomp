#include "som_c.h"

/* C0006C boss_attack_row_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/boss_attack_row_public_jump.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYCV.
 */
static void boss_attack_row_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03854, SOM_RTL); /* boss_attack_row_secondary_jump */
}
SOM_REGISTER(0xC0006C, SOM_RTL, "gen", boss_attack_row_public_jump, 0, L_B | L_Y | L_C | L_V, 1, 0, 0, 3, 1)
