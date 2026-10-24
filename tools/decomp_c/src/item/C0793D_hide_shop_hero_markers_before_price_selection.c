#include "som_c.h"

/* C0793D hide_shop_hero_markers_before_price_selection   [class A, 13 bytes, 5 instructions]
 * Source: src/rom/hide_shop_hero_markers_before_price_selection.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void hide_shop_hero_markers_before_price_selection(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x082C, 0xE800);
    RAM16_SET(0x0830, 0xE800);
    RAM16_SET(0x0834, 0xE800);
    r->a = 0xE800;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0793D, SOM_RTL, "gen", hide_shop_hero_markers_before_price_selection, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 13, 5)
