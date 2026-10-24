#include "som_c.h"

/* C07F25 compact_latent_equipment_inventory_after_removed_slot   [class A, 30 bytes, 12 instructions]
 * Source: src/rom/compact_latent_equipment_inventory_after_removed_slot.s
 * Documented in docs/latent-inventory-compaction.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void compact_latent_equipment_inventory_after_removed_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    bool carry1 = carry;
    for (;;) {
        uint8_t value = RAM8(0xCC00 + (uint16_t)(x1 + 1));
        uint16_t value2 = RAM16(0x1851);
        if ((uint16_t)(x1 + 1) != value2) {
            RAM8(0xCBFF + (uint16_t)(x1 + 1)) = value;
            uint16_t x1_next = (uint16_t)(x1 + 1);
            bool carry1_next = (uint16_t)(x1 + 1) >= value2;
            x1 = x1_next;
            carry1 = carry1_next;
            continue;
        }
        uint16_t x1_next2 = (uint16_t)(x1 + 1);
        bool carry1_next2 = (uint16_t)(x1 + 1) >= value2;
        x1 = x1_next2;
        carry1 = carry1_next2;
        break;
    }
    RAM8(0xCBFF + x1) = 0xFF;
    r->a = 0;
    r->x = x1;
    r->y = y;
    r->c = carry1;
    r->z = 1;
    r->n = 0;
    r->v = overflow;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07F25, SOM_RTS, "gen", compact_latent_equipment_inventory_after_removed_slot, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 30, 12)
