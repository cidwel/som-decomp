#include "som_c.h"

/* C07C7B resolve_native_shop_item_price_and_test_money_preserving_item   [class A, 11 bytes, 6 instructions]
 * Source: src/rom/resolve_native_shop_item_price_and_test_money_preserving_item.s
 * Documented in docs/event-menu-shop-price-lookup.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYV.
 */
static void resolve_native_shop_item_price_and_test_money_preserving_item(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    r->sp -= 2;
    JSR(c, 0x7C80, 0xC07CA5); /* resolve_native_shop_item_price_from_descending_category_table */
    r->sp += 2;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x7C83, 0xC07C86); /* test_native_shop_money_against_selected_price */
    r->sp += 2;
    r->a = a;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07C7B, SOM_RTS, "gen", resolve_native_shop_item_price_and_test_money_preserving_item, 0, L_A | L_B | L_X | L_Y | L_V, 2, 0, 0, 11, 6)
