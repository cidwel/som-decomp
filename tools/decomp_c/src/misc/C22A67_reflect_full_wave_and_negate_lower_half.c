#include "som_c.h"

/* C22A67 reflect_full_wave_and_negate_lower_half   [class A, 20 bytes, 9 instructions]
 * Source: src/rom/reflect_full_wave_and_negate_lower_half.s
 * Documented in docs/boss-native-death-particles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void reflect_full_wave_and_negate_lower_half(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    if (a >= 0x0200) {
        r->a = a & 0x01FF;
        JSR(c, 0x2A75, 0xC22A7B); /* reflect_angle_into_quarter_wave */
        uint16_t a_all = r->a;
        r->a = (uint16_t)((a_all ^ 0xFFFF) + 1);
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    JSR(c, 0x2A6E, 0xC22A7B); /* reflect_angle_into_quarter_wave */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22A67, SOM_RTS, "gen", reflect_full_wave_and_negate_lower_half, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 20, 9)
