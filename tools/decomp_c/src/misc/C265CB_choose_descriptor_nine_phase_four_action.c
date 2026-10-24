#include "som_c.h"

/* C265CB choose_descriptor_nine_phase_four_action   [class A, 14 bytes, 7 instructions]
 * Source: src/rom/choose_descriptor_nine_phase_four_action.s
 * Documented in docs/boss-descriptor-nine.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_nine_phase_four_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    r->a = 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x65D0, 0xC2300B); GUARD_JSR(c, sp_call, 0x65D0); } /* draw_boss_frame_random_number */
    uint16_t a_all = r->a;
    uint16_t value = BUS16(c, 0xDCE344 + (uint16_t)(a_all << 1));
    r->a = value;
    r->x = (uint16_t)(a_all << 1);
    r->c = 0;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC265CB, SOM_RTS, "gen", choose_descriptor_nine_phase_four_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 14, 7)
