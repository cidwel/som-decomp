#include "som_c.h"

/* C22A92 read_native_quarter_wave_and_saturate_peak   [class A, 20 bytes, 9 instructions]
 * Source: src/rom/read_native_quarter_wave_and_saturate_peak.s
 * Documented in docs/boss-native-death-particles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void read_native_quarter_wave_and_saturate_peak(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    if (a >= 0xF6) {
        r->a = 0x0100;
        r->x = a;
        r->c = a >= 0xF6;
        RETURN_RTS(c);
    }
    uint16_t value = BUS16(c, 0xD97DE0 + a);
    r->a = value & 0xFF;
    r->x = a;
    r->c = a >= 0xF6;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22A92, SOM_RTS, "gen", read_native_quarter_wave_and_saturate_peak, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 20, 9)
