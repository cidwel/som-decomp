#include "som_c.h"

/* D0D8DE calculate_menu_item_price_preserving_register_context   [class C, 10 bytes, 8 instructions]
 * Source: src/rom/calculate_menu_item_price_preserving_register_context.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYV.
 */
static void calculate_menu_item_price_preserving_register_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    r->sp -= 5;
    JSR(c, 0xD8E3, 0xD0D8E8); /* calculate_complete_native_menu_item_price */
    r->sp += 5;
    r->x = x;
    r->y = y;
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D8DE, SOM_RTS, "gen", calculate_menu_item_price_preserving_register_context, 0, L_A | L_B | L_X | L_Y | L_V, 5, 0, 0, 10, 8)
