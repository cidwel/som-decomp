#include "som_c.h"

/* C039CF add_or_spend_party_gold_with_saved_context   [class B, 107 bytes, 57 instructions]
 * Source: src/rom/add_or_spend_party_gold_with_saved_context.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=any DB=$7E D=any.  Callers read: YCV.
 */
static void add_or_spend_party_gold_with_saved_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, -1)) return;
    const uint8_t x_entry = r->xf;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    if (x == 0x37) {
        RAM16_SET(BATTLE_TEMP_AE, a);
        uint16_t inventory_gold = RAM16(INVENTORY_GOLD);
        uint16_t battle_temp_ae = RAM16(BATTLE_TEMP_AE);
        RAM16_SET(BATTLE_TEMP_A6, (uint16_t)(inventory_gold - battle_temp_ae));
        uint8_t value = RAM8(0xCC6C);
        if (value >= (inventory_gold >= battle_temp_ae ^ 1)) {
            RAM8(0xCC6C) = (uint8_t)(value - (inventory_gold >= battle_temp_ae ^ 1));
            RAM8(INVENTORY_GOLD) = RAM8(BATTLE_TEMP_A6);
            RAM8(0xCC6B) = RAM8(0x03A7);
        } else {
            RAM8(0xCF0F) = 1;
        }
        RETURN_RTL(c);
    }
    uint16_t inventory_gold2 = RAM16(INVENTORY_GOLD);
    RAM16_SET(0x03D0, (uint16_t)(a + inventory_gold2));
    uint8_t value3 = RAM8(0xCC6C);
    RAM8(0x03D2) = (uint8_t)(value3 + (a + inventory_gold2 > 0xFFFF));
    r->v = ((uint8_t)(value3 + (a + inventory_gold2 > 0xFFFF)) & (value3 ^ (uint8_t)(value3 + (a + inventory_gold2 > 0xFFFF))) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->dp = 0x0300;
    r->sp -= 4;
    JSR(c, 0x39FA, 0xC039A4); /* cap_combat_24bit_value_at_9999999 */
    r->sp += 4;
    RAM16_SET(INVENTORY_GOLD, RAM16(0x03D0));
    RAM8(0xCC6C) = RAM8(0x03D2);
    r->c = carry;
    r->v = overflow;
    r->mf = 0;
    r->xf = x_entry;
    r->dp = dp;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC039CF, SOM_RTL, "gen", add_or_spend_party_gold_with_saved_context, 0, L_Y | L_C | L_V, 6, 0, -1, 107, 57)
