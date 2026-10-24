#include "som_c.h"

/* C75F20 select_native_menu_icon_position_and_tile_cursor   [class B, 42 bytes, 27 instructions]
 * Source: src/rom/select_native_menu_icon_position_and_tile_cursor.s
 * Documented in docs/event-menu-page-sprites.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void select_native_menu_icon_position_and_tile_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint16_t value = BUS16(c, 0xC75FE7 + ((((a_hi << 8) | a) & 0xFF) << 1));
    RAM16_SET(0xA159, value);
    r->a = ((((a_hi << 8) | a) & 3) << 1) + 1 << 1 << 1 << 1 << 1;
    r->x = ((((a_hi << 8) | a) & 3) << 1 << 1 << 1 << 1) + 0x5FA7;
    r->y = ((((a_hi << 8) | a) & 3) << 1) + 1 << 1 << 1 << 1 << 1;
    r->v = ((((((a_hi << 8) | a) & 3) << 1 << 1 << 1 << 1) ^ ((((a_hi << 8) | a) & 3) << 1 << 1 << 1 << 1) + 0x5FA7) & (((((a_hi << 8) | a) & 3) << 1 << 1 << 1 << 1) + 0x5FA7 ^ 0x5FA7) & 0x8000) != 0;
    JSR(c, 0x5F48, 0xC76CEB); /* adjust_native_menu_icon_position_for_name_page */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75F20, SOM_RTS, "gen", select_native_menu_icon_position_and_tile_cursor, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 42, 27)
