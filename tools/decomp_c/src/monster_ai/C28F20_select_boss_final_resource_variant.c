#include "som_c.h"

/* C28F20 select_boss_final_resource_variant   [class A, 19 bytes, 8 instructions]
 * Source: src/rom/select_boss_final_resource_variant.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void select_boss_final_resource_variant(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    if (RAM16(0xE6B6) != 0) {
        r->a = 0x18;
        JSR(c, 0x8F31, 0xC225AD); /* prepare_boss_resource_vram_high_expansion */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0x19;
    JSR(c, 0x8F2A, 0xC225AD); /* prepare_boss_resource_vram_high_expansion */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28F20, SOM_RTS, "gen", select_boss_final_resource_variant, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 19, 8)
