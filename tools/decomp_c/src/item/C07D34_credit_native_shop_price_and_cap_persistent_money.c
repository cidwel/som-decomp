#include "som_c.h"

/* C07D34 credit_native_shop_price_and_cap_persistent_money   [class B, 79 bytes, 33 instructions]
 * Source: src/rom/credit_native_shop_price_and_cap_persistent_money.s
 * Documented in docs/event-menu-shop-currency.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void credit_native_shop_price_and_cap_persistent_money(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x1822);
    uint16_t inventory_gold = RAM16(INVENTORY_GOLD);
    RAM16_SET(INVENTORY_GOLD, (uint16_t)(inventory_gold + value));
    if (inventory_gold + value > 0xFFFF) {
        RAM8(0xCC6C) = (uint8_t)(RAM8(0xCC6C) + 1);
    }
    uint8_t value3 = RAM8(0xCC6C);
    uint8_t a_hi3;
    bool carry2;
    if (value3 < 0x98) {
        a_hi3 = (uint16_t)(inventory_gold + value) >> 8;
        carry2 = value3 >= 0x98;
    } else {
        uint8_t a_hi2;
        bool carry1;
        if (value3 != 0x98) {
            RAM8(0xCC6C) = 0x98;
            RAM16_SET(INVENTORY_GOLD, 0x967F);
            a_hi2 = 0x96;
            carry1 = value3 >= 0x98;
        } else {
            uint16_t inventory_gold2 = RAM16(INVENTORY_GOLD);
            uint8_t a_hi1;
            if (inventory_gold2 < 0x967F) {
                a_hi1 = inventory_gold2 >> 8;
            } else {
                RAM8(0xCC6C) = 0x98;
                RAM16_SET(INVENTORY_GOLD, 0x967F);
                a_hi1 = 0x96;
            }
            a_hi2 = a_hi1;
            carry1 = inventory_gold2 >= 0x967F;
        }
        a_hi3 = a_hi2;
        carry2 = carry1;
    }
    r->a = value;
    r->x = 0;
    r->c = carry2;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->v = ((inventory_gold ^ (uint16_t)(inventory_gold + value)) & (value ^ (uint16_t)(inventory_gold + value)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07D34, SOM_RTS, "gen", credit_native_shop_price_and_cap_persistent_money, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 0, 0, 79, 33)
