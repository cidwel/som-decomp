#include "som_c.h"

/* C07D0D deduct_native_shop_price_from_persistent_money   [class A, 39 bytes, 18 instructions]
 * Source: src/rom/deduct_native_shop_price_from_persistent_money.s
 * Documented in docs/event-menu-shop-currency.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void deduct_native_shop_price_from_persistent_money(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x1822);
    uint16_t inventory_gold = RAM16(INVENTORY_GOLD);
    RAM16_SET(INVENTORY_GOLD, (uint16_t)(inventory_gold - value));
    if (inventory_gold < value) {
        RAM8(0xCC6C) = (uint8_t)(RAM8(0xCC6C) - 1);
    }
    r->a = value;
    r->x = 0;
    r->c = inventory_gold >= value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->v = ((inventory_gold ^ value) & (inventory_gold ^ (uint16_t)(inventory_gold - value)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07D0D, SOM_RTS, "gen", deduct_native_shop_price_from_persistent_money, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 0, 0, 39, 18)
