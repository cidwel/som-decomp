#include "som_c.h"

/* C265DD load_boss_palette_38_into_slot_fifteen   [class A, 10 bytes, 4 instructions]
 * Source: src/rom/load_boss_palette_38_into_slot_fifteen.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void load_boss_palette_38_into_slot_fifteen(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 0x38;
    r->x = 0x0F;
    JSR(c, 0x65E5, 0xC226F9); /* copy_boss_palette_with_cpu_words */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC265DD, SOM_RTS, "gen", load_boss_palette_38_into_slot_fifteen, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 10, 4)
