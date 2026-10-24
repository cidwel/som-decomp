#include "som_c.h"

/* C02697 consume_native_menu_rectangle_76f5   [class A, 14 bytes, 8 instructions]
 * Source: src/rom/consume_native_menu_rectangle_76f5.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$C7 D=$0000.  Callers read: BYCV.
 */
static void consume_native_menu_rectangle_76f5(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0xC7, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = BUS16(c, 0xC70000 + y);
    r->x = value;
    r->y = 0x76F5;
    r->sp -= 2;
    JSR(c, 0x26A2, 0xC0272B); /* expand_native_menu_counted_rom_tile_rectangle */
    r->sp += 2;
    r->y = (uint16_t)(y + 2);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02697, SOM_RTS, "gen", consume_native_menu_rectangle_76f5, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 14, 8)
