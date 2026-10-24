#include "som_c.h"

/* C24E35 replace_previous_body_segment_shape   [class A, 26 bytes, 12 instructions]
 * Source: src/rom/replace_previous_body_segment_shape.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXY.
 */
static void replace_previous_body_segment_shape(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x00B2 + x);
    uint16_t x1;
    if (value == 0) {
        x1 = x;
    } else {
        uint8_t value3 = BUS8(c, 0xDCE633 + ((value >> 8 << 8) | ((RAM8(0x0000 + y) & 0x0F) >> 1)));
        RAM8(0x0000 + y) = value3;
        x1 = RAM16(0x0287);
    }
    r->a = (value >> 8 << 8) | (uint8_t)a;
    r->x = x1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24E35, SOM_RTS, "gen", replace_previous_body_segment_shape, 0, L_B | L_X | L_Y, 1, 0, 0, 26, 12)
