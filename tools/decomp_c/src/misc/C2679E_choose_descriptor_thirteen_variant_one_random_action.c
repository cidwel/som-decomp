#include "som_c.h"

/* C2679E choose_descriptor_thirteen_variant_one_random_action   [class A, 14 bytes, 7 instructions]
 * Source: src/rom/choose_descriptor_thirteen_variant_one_random_action.s
 * Documented in docs/boss-descriptor-thirteen.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_thirteen_variant_one_random_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 6;
    JSR(c, 0x67A3, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all = r->a;
    uint16_t value = BUS16(c, 0xDCE38A + (uint16_t)(a_all << 1));
    r->a = value;
    r->x = (uint16_t)(a_all << 1);
    r->c = 0;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2679E, SOM_RTS, "gen", choose_descriptor_thirteen_variant_one_random_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 7)
