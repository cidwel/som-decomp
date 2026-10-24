#include "som_c.h"

/* C26ECB enable_native_boss_bg2_subscreen_and_bg1_color_math   [class D, 32 bytes, 12 instructions]
 * Source: src/rom/enable_native_boss_bg2_subscreen_and_bg1_color_math.s
 * Documented in docs/boss-native-visual-callbacks.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void enable_native_boss_bg2_subscreen_and_bg1_color_math(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    BUS8_SET(c, 0x00212C, RAM8(0x0021) & 0xFD);
    BUS8_SET(c, 0x00212D, RAM8(0x0022) | 2);
    uint8_t value3 = RAM8(0x0023);
    BUS8_SET(c, 0x002131, value3 | 1);
    r->a = (a >> 8 << 8) | (value3 | 1);
    r->z = (value3 | 1) == 0;
    r->n = (value3 | 1) & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26ECB, SOM_RTS, "gen", enable_native_boss_bg2_subscreen_and_bg1_color_math, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 32, 12)
