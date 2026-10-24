#include "som_c.h"

/* CFFF2A read_native_multi5_auto_and_serial_controller_fields   [class D, 118 bytes, 58 instructions]
 * Source: src/rom/read_native_multi5_auto_and_serial_controller_fields.s
 * Documented in docs/game-controller-inputs.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void read_native_multi5_auto_and_serial_controller_fields(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM8(0x0001) = 0;
    uint8_t a_hi1 = a_hi;
    for (;;) {
        uint8_t value = BUS8(c, 0x004212);
        if (!((value & 1) != 0)) break;
    }
    uint8_t value2 = BUS8(c, 0x004219);
    RAM8(0x000B) = value2;
    uint8_t value3 = BUS8(c, 0x004218);
    RAM8(0x000A) = value3;
    RAM8(0x0010) = value3 & 0x0F;
    uint8_t value4 = BUS8(c, 0x004016);
    RAM8(0x0010) = (uint8_t)(RAM8(0x0010) << 1 | (value4 & 1));
    uint8_t value6 = BUS8(c, 0x00421B);
    RAM8(0x0009) = value6;
    uint8_t value7 = BUS8(c, 0x00421A);
    RAM8(0x0008) = value7;
    RAM8(0x000F) = value7 & 0x0F;
    uint8_t value8 = BUS8(c, 0x00421F);
    RAM8(0x0007) = value8;
    uint8_t value9 = BUS8(c, 0x00421E);
    RAM8(0x0006) = value9;
    RAM8(0x000E) = value9 & 0x0F;
    uint8_t value10 = BUS8(c, 0x004017);
    RAM8(0x000F) = (uint8_t)(RAM8(0x000F) << 1 | (value10 & 1));
    RAM8(0x000E) = (uint8_t)(RAM8(0x000E) << 1 | ((value10 >> 1) & 1));
    BUS8_SET(c, 0x004201, 0);
    uint8_t a_hi2 = a_hi1;
    uint8_t y1 = 0x10;
    for (;;) {
        uint8_t value13 = BUS8(c, 0x004017);
        RAM16_SET(0x0004, (uint16_t)(RAM16(0x0004) << 1 | (((a_hi2 << 8) | value13) & 1)));
        RAM16_SET(0x0002, (uint16_t)(RAM16(0x0002) << 1 | (((((a_hi2 << 8) | value13) >> 9 << 8) | (uint8_t)(((a_hi2 << 8) | value13) >> 1)) & 1)));
        a_hi2 = ((((a_hi2 << 8) | value13) >> 9 << 8) | (uint8_t)(((a_hi2 << 8) | value13) >> 1)) >> 9;
        y1 = (uint8_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    RAM8(0x000D) = RAM8(0x0004) & 0x0F;
    RAM8(0x000C) = RAM8(0x0002) & 0x0F;
    uint8_t value18 = BUS8(c, 0x004017);
    RAM8(0x000D) = (uint8_t)(RAM8(0x000D) << 1 | (value18 & 1));
    RAM8(0x000C) = (uint8_t)(RAM8(0x000C) << 1 | ((value18 >> 1) & 1));
    BUS8_SET(c, 0x004201, 0x80);
    r->x = (uint8_t)x;
    r->y = y1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCFFF2A, SOM_RTS, "gen", read_native_multi5_auto_and_serial_controller_fields, 0, L_X | L_Y, 1, 1, 0, 118, 58)
