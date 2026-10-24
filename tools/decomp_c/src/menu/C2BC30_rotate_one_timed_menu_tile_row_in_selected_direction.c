#include "som_c.h"

/* C2BC30 rotate_one_timed_menu_tile_row_in_selected_direction   [class C, 78 bytes, 42 instructions]
 * Source: src/rom/rotate_one_timed_menu_tile_row_in_selected_direction.s
 * Documented in docs/map-main-frame-menu-records.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: BXY.
 */
static void rotate_one_timed_menu_tile_row_in_selected_direction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t x = r->x;
    uint8_t value = RAM8(0xD20C + x);
    if (value != 0) {
        RAM16_SET(0x0002, RAM16(0xD20A + x));
        uint16_t value3 = RAM16(0xD204 + x);
        if (a >= 1) {
            uint8_t value4 = RAM8(0x0002);
            uint16_t value5 = RAM16(0x0600 + ((value3 >> 8 << 8) | ((uint8_t)value3 | value4)));
            uint8_t a_hi1 = value5 >> 8;
            uint16_t x1 = value;
            uint16_t y1 = (value3 >> 8 << 8) | ((uint8_t)value3 | value4);
            for (;;) {
                uint16_t value6 = RAM16(0x0602 + y1);
                RAM16_SET(0x0600 + y1, value6);
                a_hi1 = value6 >> 8;
                x1 = (uint16_t)(x1 - 1);
                y1 = (uint16_t)(y1 + 2);
                if (!(x1 != 0)) break;
            }
            RAM16_SET(0x0600 + y1, value5);
            r->a = value5;
            r->x = x1;
            r->y = y1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint8_t value7 = RAM8(0x0003);
        uint16_t value8 = RAM16(0x0600 + ((value3 >> 8 << 8) | ((uint8_t)value3 | value7)));
        uint8_t a_hi2 = value8 >> 8;
        uint16_t x2 = value;
        uint16_t y2 = (value3 >> 8 << 8) | ((uint8_t)value3 | value7);
        for (;;) {
            uint16_t value9 = RAM16(0x05FE + y2);
            RAM16_SET(0x0600 + y2, value9);
            a_hi2 = value9 >> 8;
            x2 = (uint16_t)(x2 - 1);
            y2 = (uint16_t)(y2 - 2);
            if (!(x2 != 0)) break;
        }
        RAM16_SET(0x0600 + y2, value8);
        r->a = value8;
        r->x = x2;
        r->y = y2;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2BC30, SOM_RTS, "gen", rotate_one_timed_menu_tile_row_in_selected_direction, 0, L_B | L_X | L_Y, 2, 1, 1, 78, 42)
