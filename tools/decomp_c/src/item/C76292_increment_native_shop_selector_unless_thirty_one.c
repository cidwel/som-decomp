#include "som_c.h"

/* C76292 increment_native_shop_selector_unless_thirty_one   [class A, 19 bytes, 8 instructions]
 * Source: src/rom/increment_native_shop_selector_unless_thirty_one.s
 * Documented in docs/event-menu-shop-actions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void increment_native_shop_selector_unless_thirty_one(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xA1D1 + y);
    if ((uint8_t)(value + 1) != 0x20) {
        RAM8(0xA1D1 + y) = (uint8_t)(value + 1);
        r->a = (a_hi << 8) | (uint8_t)(value + 1);
        JSR(c, 0x629F, 0xC762B8); /* pack_three_native_shop_selectors_and_refresh_icon_oam */
        r->mf = 1;
        r->xf = 0;
        JSL(c, 0x62A3, 0xC02AF2); /* native_menu_change_sound_long_wrapper */
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76292, SOM_RTL, "gen", increment_native_shop_selector_unless_thirty_one, 0, 0, 1, 1, 0, 19, 8)
