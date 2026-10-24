#include "som_c.h"

/* C2B453 multiply_signed_ui_coordinate_using_two_native_byte_products   [class B, 73 bytes, 40 instructions]
 * Source: src/rom/multiply_signed_ui_coordinate_using_two_native_byte_products.s
 * Documented in docs/ui-native-ui-frame-projection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void multiply_signed_ui_coordinate_using_two_native_byte_products(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool negative = r->n;
    if (!negative) {
        RAM8(0x4203) = (uint8_t)x;
        RAM8(0x0301) = 0;
        RAM8(0x0300) = RAM8(0x4217);
        RAM8(0x4203) = x >> 8;
        r->x = (uint16_t)(RAM16(0x0300) + RAM16(0x4216));
        RETURN_RTS(c);
    }
    RAM8(0x4203) = (uint8_t)(((uint8_t)x ^ 0xFF) + 1);
    RAM8(0x0301) = 0;
    RAM8(0x0300) = RAM8(0x4217);
    RAM8(0x4203) = (uint8_t)(((x >> 8) ^ 0xFF) + (((uint8_t)x ^ 0xFF) + 1 > 0xFF));
    r->x = (uint16_t)(((uint16_t)(RAM16(0x0300) + RAM16(0x4216)) ^ 0xFFFF) + 1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2B453, SOM_RTS, "gen", multiply_signed_ui_coordinate_using_two_native_byte_products, 0, L_X | L_Y, 2, 1, 0, 73, 40)
