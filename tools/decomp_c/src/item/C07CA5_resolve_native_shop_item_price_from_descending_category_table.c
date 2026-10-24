#include "som_c.h"

/* C07CA5 resolve_native_shop_item_price_from_descending_category_table   [class B, 47 bytes, 24 instructions]
 * Source: src/rom/resolve_native_shop_item_price_from_descending_category_table.s
 * Documented in docs/event-menu-shop-price-lookup.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYV.
 */
static void resolve_native_shop_item_price_from_descending_category_table(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t x1 = 0xFB84;
    for (;;) {
        uint16_t value = BUS16(c, 0xD80000 + x1);
        if ((a & 0xFF) < value) {
            x1 = (uint16_t)(x1 + 6);
            continue;
        }
        break;
    }
    uint16_t value2 = BUS16(c, 0xD80000 + x1);
    uint16_t value3 = BUS16(c, 0xD80004 + x1);
    uint16_t value4 = BUS16(c, 0xD80000 + (uint16_t)(value3 + (uint16_t)((uint16_t)((a & 0xFF) - value2) << 1)));
    r->a = value4;
    r->x = (uint16_t)(value3 + (uint16_t)((uint16_t)((a & 0xFF) - value2) << 1));
    r->v = ((value3 ^ (uint16_t)(value3 + (uint16_t)((uint16_t)((a & 0xFF) - value2) << 1))) & ((uint16_t)((uint16_t)((a & 0xFF) - value2) << 1) ^ (uint16_t)(value3 + (uint16_t)((uint16_t)((a & 0xFF) - value2) << 1))) & 0x8000) != 0;
    JSL(c, 0x7CD2, 0xC07CD4); /* adjust_menu_price_for_shop_and_inventory_modes */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07CA5, SOM_RTS, "gen", resolve_native_shop_item_price_from_descending_category_table, 0, L_A | L_B | L_X | L_Y | L_V, 2, 0, 0, 47, 24)
