#include "som_c.h"

/* C02626 consume_native_menu_attribute_rectangle   [class A, 28 bytes, 13 instructions]
 * Source: src/rom/consume_native_menu_attribute_rectangle.s
 * Documented in docs/event-menu-page-records.md
 * Entry: M=8 bit X=16 bit DB=$C7 D=$0000.  Callers read: ABXYCZNV.
 */
static void consume_native_menu_attribute_rectangle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0xC7, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = BUS16(c, 0xC70000 + y);
    uint8_t value2 = BUS8(c, 0xC70000 + (uint16_t)(y + 2));
    RAM8(0xA198) = value2;
    r->x = value;
    r->y = 0x77C7;
    r->sp -= 2;
    JSR(c, 0x2639, 0xC0272B); /* expand_native_menu_counted_rom_tile_rectangle */
    r->sp += 2;
    RAM8(0xA198) = 0;
    SET_A8(r, 0);
    r->y = (uint16_t)(y + 3);
    r->z = (uint16_t)(y + 3) == 0;
    r->n = (uint16_t)(y + 3) & 0x8000;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02626, SOM_RTS, "gen", consume_native_menu_attribute_rectangle, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 28, 13)
