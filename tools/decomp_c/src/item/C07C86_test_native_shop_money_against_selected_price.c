#include "som_c.h"

/* C07C86 test_native_shop_money_against_selected_price   [class B, 31 bytes, 16 instructions]
 * Source: src/rom/test_native_shop_money_against_selected_price.s
 * Documented in docs/event-menu-shop-currency.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYV.
 */
static void test_native_shop_money_against_selected_price(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t inventory_gold = RAM16(INVENTORY_GOLD);
    uint16_t x2;
    if (inventory_gold >= a) {
        x2 = 0;
    } else {
        uint8_t value = RAM8(0xCC6C);
        uint16_t x1;
        if ((uint8_t)(value - 1) != 0xFF) {
            x1 = 0;
        } else {
            x1 = 1;
        }
        x2 = x1;
    }
    r->x = x2;
    r->v = ((inventory_gold ^ a) & (inventory_gold ^ (uint16_t)(inventory_gold - a)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07C86, SOM_RTS, "gen", test_native_shop_money_against_selected_price, 0, L_A | L_B | L_X | L_Y | L_V, 2, 0, 0, 31, 16)
