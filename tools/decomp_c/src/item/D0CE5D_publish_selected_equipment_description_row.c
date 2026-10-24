#include "som_c.h"
#include "som_hand_b.h"

/* D0CE5D publish_selected_equipment_description_row   [class B, 130 bytes, 69 instructions]
 * Source: src/rom/publish_selected_equipment_description_row.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void publish_selected_equipment_description_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->mf = 1; /* REP #$30, SEP #$20 */
    r->xf = 0;
    uint8_t ring_owner = RAM8(RING_OWNER) & 1;
    r->a = (r->a & 0xFF00) | ring_owner;
    if (ring_owner) {
        JSL_CHK(c, 0xCE6B, 0xD0D0B0); /* locate_selected_weapon_with_nonzero_level */
    } else {
        JSL_CHK(c, 0xCE95, 0xD0D0DA); /* locate_selected_armor_with_nonzero_level */
    }
    uint8_t index = (uint8_t)r->x; /* TXA, AND #$FF, TAX */
    r->x = index;
    uint8_t row = (uint8_t)(index << 1);
    uint8_t stacked = row;
    row = (uint8_t)(row << 1);
    stacked = (uint8_t)(row + stacked); /* 6 * index, kept on the stack */
    uint8_t kind = RAM8(0x1878 + index);
    uint8_t a;
    if (ring_owner) {
        if (stacked >= 0x2A) stacked = (uint8_t)(stacked - 6);
        a = (uint8_t)(((kind >> 4) & 3) + 3);
    } else {
        a = kind & 3;
    }
    uint8_t sum = (uint8_t)(a + stacked);
    r->v = ((a ^ sum) & (stacked ^ sum) & 0x80) != 0;
    RAM8(0x1839) = sum;
    RAM8(0x19F1) = sum;
    RAM8(0x1846) = index;
    uint16_t offset = (uint16_t)(sum << 6);
    RAM8(0x1843) = BUS8(c, 0xD02ADF + offset);
    RAM8(0x1842) = BUS8(c, 0xD02AD8 + offset);
    r->a = (uint16_t)((offset & 0xFF00) | sum);
    r->x = offset;
    r->c = 0;
    hand_nz8(r, sum);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0CE5D, SOM_RTL, "hand", publish_selected_equipment_description_row, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 130, 69)
