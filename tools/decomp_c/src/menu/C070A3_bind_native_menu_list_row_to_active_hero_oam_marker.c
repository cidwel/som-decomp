#include "som_c.h"

/* C070A3 bind_native_menu_list_row_to_active_hero_oam_marker   [class B, 56 bytes, 32 instructions]
 * Source: src/rom/bind_native_menu_list_row_to_active_hero_oam_marker.s
 * Documented in docs/event-menu-navigation-icons.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void bind_native_menu_list_row_to_active_hero_oam_marker(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    BUS16_SET(c, (uint16_t)(0x000A + x), 0);
    uint16_t value;
    BUS16_OK(c, 0x18A0 + (uint16_t)(y << 1), value);
    RAM16_SET(0x1810, value);
    if ((value & 3) != 0) {
        uint16_t value2 = RAM16(0xE000 + (((uint8_t)((uint16_t)((value & 3) - 1) << 1) << 8) | ((uint16_t)((uint16_t)((value & 3) - 1) << 1) >> 8)));
        uint8_t a1;
        uint8_t a_hi1;
        if ((uint16_t)((value2 & 0xFF) - 1) == 0) {
            a1 = (uint8_t)((uint16_t)((uint16_t)((value & 3) - 1) << 2) + 0x082C);
            a_hi1 = (uint16_t)((uint16_t)((uint16_t)((value & 3) - 1) << 2) + 0x082C) >> 8;
        } else {
            a1 = 0;
            a_hi1 = 0;
        }
        BUS16_SET(c, (uint16_t)(0x000A + x), (a_hi1 << 8) | a1);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC070A3, SOM_RTS, "hand", bind_native_menu_list_row_to_active_hero_oam_marker, 0, L_X | L_Y, 4, 0, 0, 56, 32)
