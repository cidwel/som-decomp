#include "som_c.h"

/* C76170 render_native_shop_item_tile_frame   [class B, 230 bytes, 110 instructions]
 * Source: src/rom/render_native_shop_item_tile_frame.s
 * Documented in docs/event-menu-shop-tiles.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void render_native_shop_item_tile_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA24E);
    RAM16_SET(0xA173, value << 1);
    uint16_t value2 = RAM16(0xA173);
    RAM8(0xA171) = 7;
    uint8_t a_hi1 = (uint16_t)((value << 1 << 1 << 1 << 1 << 1) - value2) >> 8;
    uint16_t x1 = (uint16_t)((value << 1 << 1 << 1 << 1 << 1) - value2);
    uint16_t y1 = 0x0182;
    do {
        uint8_t value3 = BUS8(c, 0xC77169 + x1);
        RAM8(0x9000 + y1) = (uint8_t)((uint8_t)((uint8_t)(value3 - 0x10) << 1) + 0x40);
        RAM8(0x90C0 + y1) = (uint8_t)((uint8_t)((uint8_t)(value3 - 0x10) << 1) + 0x40);
        uint8_t value4 = BUS8(c, 0xC7716A + x1);
        RAM8(0x9001 + y1) = (value4 & 0xE0) | 0x38;
        RAM8(0x90C1 + y1) = ((value4 & 0xE0) | 0x38) ^ 0x80;
        RAM8(0xA171)--;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 2);
    } while (RAM8(0xA171) != 0);
    RAM8(0xA171) = 8;
    uint8_t a_hi2 = a_hi1;
    uint16_t x2 = x1;
    uint16_t y2 = y1;
    do {
        uint8_t value5 = BUS8(c, 0xC77169 + x2);
        RAM8(0x9000 + y2) = (uint8_t)((uint8_t)((uint8_t)(value5 - 0x10) << 1) + 0x40);
        RAM8(0x90C0 + y2) = (uint8_t)((uint8_t)((uint8_t)(value5 - 0x10) << 1) + 0x40);
        uint8_t value6 = BUS8(c, 0xC7716A + x2);
        RAM8(0x9001 + y2) = ((value6 & 0xE0) | 0x38) ^ 0x40;
        RAM8(0x90C1 + y2) = ((value6 & 0xE0) | 0x38) ^ 0x40 ^ 0x80;
        RAM8(0xA171)--;
        x2 = (uint16_t)(x2 - 2);
        y2 = (uint16_t)(y2 + 2);
    } while (RAM8(0xA171) != 0);
    uint8_t value7 = RAM8(0xA24E);
    uint8_t value8 = BUS8(c, 0xC77259 + (uint8_t)(value7 << 3));
    RAM8(0x9000 + 0x01C2) = (uint8_t)((uint8_t)((uint8_t)(value8 - 0x10) << 1) + 0x40);
    RAM8(0x901C + 0x01C2) = (uint8_t)((uint8_t)((uint8_t)(value8 - 0x10) << 1) + 0x40);
    RAM8(0x9040 + 0x01C2) = (uint8_t)((uint8_t)((uint8_t)(value8 - 0x10) << 1) + 0x40);
    RAM8(0x905C + 0x01C2) = (uint8_t)((uint8_t)((uint8_t)(value8 - 0x10) << 1) + 0x40);
    uint8_t value9 = BUS8(c, 0xC7725A + (uint8_t)(value7 << 3));
    RAM8(0x9001 + 0x01C2) = (value9 & 0xE0) | 0x38;
    RAM8(0x901D + 0x01C2) = ((value9 & 0xE0) | 0x38) ^ 0x40;
    RAM8(0x905D + 0x01C2) = ((value9 & 0xE0) | 0x38) ^ 0x40 ^ 0x80;
    RAM8(0x9041 + 0x01C2) = ((value9 & 0xE0) | 0x38) ^ 0x40 ^ 0x80 ^ 0x40;
    RAM16_SET(0xA175, 2);
    uint8_t a1 = 2;
    uint8_t a_hi3 = 0;
    uint16_t x3 = 0x01C4;
    bool carry1 = (uint8_t)((uint8_t)(value8 - 0x10) << 1) + 0x40 > 0xFF;
    bool zero1 = 0;
    bool overflow1 = (((uint8_t)((uint8_t)(value8 - 0x10) << 1) ^ (uint8_t)((uint8_t)((uint8_t)(value8 - 0x10) << 1) + 0x40)) & ((uint8_t)((uint8_t)((uint8_t)(value8 - 0x10) << 1) + 0x40) ^ 0x40) & 0x80) != 0;
    do {
        RAM16_SET(0xA171, 0x0D);
        uint8_t a_hi4 = 0;
        uint16_t x4 = x3;
        do {
            RAM16_SET(0x9000 + x4, 0x3C3E);
            RAM16_SET(0xA171, (uint16_t)(RAM16(0xA171) - 1));
            a_hi4 = 0x3C;
            x4 = (uint16_t)(x4 + 2);
        } while (RAM16(0xA171) != 0);
        RAM16_SET(0xA175, (uint16_t)(RAM16(0xA175) - 1));
        a1 = (uint8_t)(x4 + 0x26);
        a_hi3 = (uint16_t)(x4 + 0x26) >> 8;
        x3 = (uint16_t)(x4 + 0x26);
        carry1 = x4 + 0x26 > 0xFFFF;
        zero1 = RAM16(0xA175) == 0;
        overflow1 = ((x4 ^ (uint16_t)(x4 + 0x26)) & ((uint16_t)(x4 + 0x26) ^ 0x26) & 0x8000) != 0;
    } while (RAM16(0xA175) != 0);
    r->a = (a_hi3 << 8) | a1;
    r->x = x3;
    r->y = 0x01C2;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76170, SOM_RTL, "gen", render_native_shop_item_tile_frame, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 230, 110)
