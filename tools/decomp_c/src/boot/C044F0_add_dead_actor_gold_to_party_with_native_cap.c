#include "som_c.h"

/* C044F0 add_dead_actor_gold_to_party_with_native_cap   [class A, 40 bytes, 18 instructions]
 * Source: src/rom/add_dead_actor_gold_to_party_with_native_cap.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void add_dead_actor_gold_to_party_with_native_cap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    uint16_t value = RAM16(0xE1C8 + battle_defender_ptr);
    uint16_t inventory_gold = RAM16(INVENTORY_GOLD);
    RAM16_SET(0x03D0, (uint16_t)(value + inventory_gold));
    uint8_t value2 = RAM8(0xCC6C);
    RAM8(0x03D2) = (uint8_t)(value2 + (value + inventory_gold > 0xFFFF));
    r->x = battle_defender_ptr;
    r->v = ((uint8_t)(value2 + (value + inventory_gold > 0xFFFF)) & (value2 ^ (uint8_t)(value2 + (value + inventory_gold > 0xFFFF))) & 0x80) != 0;
    JSR(c, 0x4508, 0xC039A4); /* cap_combat_24bit_value_at_9999999 */
    uint16_t value3 = RAM16(0x03D0);
    RAM16_SET(INVENTORY_GOLD, value3);
    RAM8(0xCC6C) = RAM8(0x03D2);
    r->a = (r->a & 0x00FF) | ((value3 >> 8) << 8);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC044F0, SOM_RTS, "gen", add_dead_actor_gold_to_party_with_native_cap, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 40, 18)
