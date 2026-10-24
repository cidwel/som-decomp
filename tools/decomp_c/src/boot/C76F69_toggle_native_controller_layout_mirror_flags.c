#include "som_c.h"

/* C76F69 toggle_native_controller_layout_mirror_flags   [class B, 62 bytes, 27 instructions]
 * Source: src/rom/toggle_native_controller_layout_mirror_flags.s
 * Documented in docs/ui-native-controller-layout.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void toggle_native_controller_layout_mirror_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0xA220);
    RAM8(0xA22F + value) ^= 3;
    RAM16_SET(0xA171, 3);
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0x6C;
    uint16_t y1 = 0xB0;
    do {
        uint16_t value3 = RAM16(0x9000 + x1);
        RAM16_SET(0x9000 + x1, RAM16(0x9000 + y1) ^ 0xC000);
        RAM16_SET(0x9000 + y1, value3 ^ 0xC000);
        RAM16_SET(0xA171, (uint16_t)(RAM16(0xA171) - 1));
        a_hi1 = (value3 ^ 0xC000) >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 - 2);
    } while (RAM16(0xA171) != 0);
    uint8_t value5 = RAM8(0xA20A);
    RAM8(0xA20A) |= 2;
    r->a = (a_hi1 << 8) | 2;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->z = (value5 & 2) == 0;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76F69, SOM_RTL, "gen", toggle_native_controller_layout_mirror_flags, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 62, 27)
