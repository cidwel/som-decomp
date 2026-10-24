#include "som_c.h"
#include "som_hand.h"

/* C06481 query_native_item_slot_description_index_with_saved_context   [class C, 35 bytes, 21 instructions]
 * Source: src/rom/query_native_item_slot_description_index_with_saved_context.s
 * Documented in docs/ui-native-spell-item-api.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void query_native_item_slot_description_index_with_saved_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp; /* PHX PHY PHP PHB PHD: eight real stack bytes */
    RAM8(sp0 - 0) = r->x >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->x;
    RAM8(sp0 - 2) = r->y >> 8;
    RAM8(sp0 - 3) = (uint8_t)r->y;
    RAM8(sp0 - 4) = (r->n << 7) | (r->v << 6) | (r->mf << 5) | (r->xf << 4) | (r->d << 3) | (r->i << 2) | (r->z << 1) | r->c;
    RAM8(sp0 - 5) = r->db;
    RAM8(sp0 - 6) = r->dp >> 8;
    RAM8(sp0 - 7) = (uint8_t)r->dp;
    const uint8_t y = (uint8_t)r->y;
    r->sp -= 8;
    JSL(c, 0x6489, 0xC064A4); /* normalize_menu_native_direct_page_and_bank: D = 0, DB = 0 */
    r->sp += 8;
    r->mf = 1; /* sep #$30 */
    r->xf = 1;
    r->x &= 0xFF;
    r->y &= 0xFF;
    RAM8(RING_CATEGORY) = 3;
    const uint16_t sum = y + 0x54;
    const uint8_t idx = (uint8_t)sum;
    const uint8_t value = RAM8(0xCC00 + idx);
    r->a = (r->a & 0xFF00) | value;
    r->x = idx;
    r->y = y;
    r->c = sum > 0xFF;
    r->v = ((y ^ idx) & (0x54 ^ idx) & 0x80) != 0;
    r->z = value == 0;
    r->n = value & 0x80;
    r->sp -= 8;
    JSL(c, 0x649D, 0xD0D1FB); /* offset_armor_inventory_description_by_position */
    r->sp += 8;
    r->dp = RAM8(sp0 - 7) | (RAM8(sp0 - 6) << 8); /* PLD */
    r->db = RAM8(sp0 - 5); /* PLB */
    som_pull_p(c, sp0 - 4); /* PLP */
    r->y = RAM16(sp0 - 3); /* PLY */
    r->x = RAM16(sp0 - 1); /* PLX */
    r->z = r->x == 0;
    r->n = r->x & 0x8000;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC06481, SOM_RTL, "hand", query_native_item_slot_description_index_with_saved_context, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 8, -1, 0, 35, 21)
