#include "som_c.h"

/* C22A7B reflect_angle_into_quarter_wave   [class A, 23 bytes, 10 instructions]
 * Source: src/rom/reflect_angle_into_quarter_wave.s
 * Documented in docs/boss-native-death-particles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void reflect_angle_into_quarter_wave(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    if (a >= 0xFF) {
        RAM16_SET(0x0266, a);
        uint16_t value = RAM16(0x0266);
        r->a = (uint16_t)(0x0200 - value);
        r->v = ((value ^ 0x0200) & ((uint16_t)(0x0200 - value) ^ 0x0200) & 0x8000) != 0;
        JSR(c, 0x2A90, 0xC22A92); /* read_native_quarter_wave_and_saturate_peak */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    JSR(c, 0x2A82, 0xC22A92); /* read_native_quarter_wave_and_saturate_peak */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22A7B, SOM_RTS, "gen", reflect_angle_into_quarter_wave, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 23, 10)
