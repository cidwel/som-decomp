#include "som_c.h"

/* C76125 copy_native_shop_item_tile_row_and_eight_background_rows   [class B, 75 bytes, 41 instructions]
 * Source: src/rom/copy_native_shop_item_tile_row_and_eight_background_rows.s
 * Documented in docs/event-menu-shop-records.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void copy_native_shop_item_tile_row_and_eight_background_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA24E);
    uint16_t value2 = RAM16(0xA24F + (((a_hi << 8) | value) & 0xFF));
    uint8_t a1 = 0x10;
    uint8_t a_hi1 = (((value2 & 0xFF) << 8) | 0) >> 1 >> 8;
    uint16_t x1 = (((value2 & 0xFF) << 8) | 0) >> 1;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t value3 = BUS8(c, 0xD2D480 + x1);
        RAM8(0x9000 + y1) = value3;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value3;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    RAM8(0xA176) = 8;
    uint8_t a_hi2 = (((((a_hi << 8) | value) & 0xFF) << 8) | 0) >> 1 >> 8;
    uint16_t x2 = (((((a_hi << 8) | value) & 0xFF) << 8) | 0) >> 1;
    uint16_t y2 = y1;
    do {
        uint8_t a2 = 0x10;
        uint8_t a_hi3 = a_hi2;
        uint16_t x3 = x2;
        uint16_t y3 = y2;
        for (;;) {
            uint8_t value4 = BUS8(c, 0xD2D080 + x3);
            RAM8(0x9000 + y3) = value4;
            a2 = (uint8_t)(a2 - 1);
            a_hi3 = value4;
            x3 = (uint16_t)(x3 + 1);
            y3 = (uint16_t)(y3 + 1);
            if (!(a2 != 0)) break;
        }
        RAM8(0xA176)--;
        a_hi2 = a_hi3;
        x2 = x3;
        y2 = y3;
    } while (RAM8(0xA176) != 0);
    r->a = (a_hi2 << 8) | a;
    r->x = x2;
    r->y = y2;
    r->c = (((((a_hi << 8) | value) & 0xFF) << 8) | 0) & 0x01;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76125, SOM_RTS, "gen", copy_native_shop_item_tile_row_and_eight_background_rows, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 75, 41)
