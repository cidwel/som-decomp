#include "som_c.h"

/* C078C3 change_native_consumable_quantity_and_compact_depleted_inventory   [class A, 69 bytes, 33 instructions]
 * Source: src/rom/change_native_consumable_quantity_and_compact_depleted_inventory.s
 * Documented in docs/event-menu-action-rows.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void change_native_consumable_quantity_and_compact_depleted_inventory(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t y1;
    if (!(a & 0x80)) {
        y1 = 0x20;
    } else {
        y1 = 0xE0;
    }
    uint8_t inventory_consumables = RAM8(INVENTORY_CONSUMABLES + x);
    RAM8(INVENTORY_CONSUMABLES + x) = ((uint8_t)((a_hi << 8) | inventory_consumables) & 0x1F) | ((uint8_t)(inventory_consumables + y1) & 0xE0);
    uint8_t a_hi2;
    uint8_t x2;
    if (((((uint8_t)((a_hi << 8) | inventory_consumables) & 0x1F) | ((uint8_t)(inventory_consumables + y1) & 0xE0)) & 0xE0) != 0) {
        a_hi2 = a_hi;
        x2 = x;
    } else {
        uint8_t a_hi1 = a_hi;
        uint8_t x1 = x;
        for (;;) {
            if (x1 < 0x0B) {
                RAM8(INVENTORY_CONSUMABLES + x1) = RAM8(0xCC49 + x1);
                x1 = (uint8_t)(x1 + 1);
                continue;
            }
            break;
        }
        RAM8(INVENTORY_CONSUMABLES + x1) = 0xFF;
        RAM8(0x1873)--;
        if (RAM8(0x1873) & 0x80) {
            RAM8(0x1873) = 0;
        }
        a_hi2 = a_hi1;
        x2 = x1;
    }
    r->a = (a_hi2 << 8) | a;
    r->x = x2;
    r->y = (uint8_t)(inventory_consumables + y1) & 0xE0;
    r->c = carry;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC078C3, SOM_RTL, "gen", change_native_consumable_quantity_and_compact_depleted_inventory, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 1, 69, 33)
