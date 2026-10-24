#include "som_c.h"

/* C26059 advance_descriptor_five_hp_ratio_phase   [class A, 26 bytes, 11 instructions]
 * Source: src/rom/advance_descriptor_five_hp_ratio_phase.s
 * Documented in docs/boss-descriptor-five.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_descriptor_five_hp_ratio_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x605D, 0xC209B4); /* compute_capped_boss_maximum_over_current_hp_ratio */
    uint16_t a_all = r->a;
    if (a_all >= 2) {
        uint16_t value2 = RAM16(0x0287);
        RAM16_SET(0x007E + value2, 1);
        r->a = 0xDD63;
        r->x = value2;
        r->c = a_all >= 2;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0xDD60;
    r->c = a_all >= 2;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26059, SOM_RTS, "gen", advance_descriptor_five_hp_ratio_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 26, 11)
