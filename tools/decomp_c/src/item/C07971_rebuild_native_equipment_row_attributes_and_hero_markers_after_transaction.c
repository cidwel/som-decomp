#include "som_c.h"

/* C07971 rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction   [class B, 86 bytes, 40 instructions]
 * Source: src/rom/rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x182A);
    RAM8(0x0000 + sp0) = value >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value;
    RAM16_SET(0x182C, RAM16(0x186A));
    RAM16_SET(0x182A, RAM16(0x186C));
    uint16_t value4 = RAM16(0x182C);
    uint16_t ring_category = RAM16(RING_CATEGORY);
    uint16_t ring_entry_count = RAM16(RING_ENTRY_COUNT);
    uint8_t a1;
    uint8_t a_hi1;
    if ((ring_category & 0xFF) == 3) {
        a1 = ring_entry_count & 0xFF;
        a_hi1 = 0;
    } else {
        a1 = (uint8_t)((ring_entry_count & 0xFF) - 1);
        a_hi1 = (uint16_t)((ring_entry_count & 0xFF) - 1) >> 8;
    }
    uint8_t a2 = a1;
    uint8_t a_hi2 = a_hi1;
    uint16_t x1 = value4;
    uint16_t y1 = ring_category & 0xFF;
    bool carry1 = (ring_category & 0xFF) >= 3;
    bool overflow1 = overflow;
    for (;;) {
        RAM8(0x0000 + sp0 - 2) = a_hi2;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)((a_hi2 << 8) | a2);
        uint16_t value5 = RAM16(0xCC00 + x1);
        r->a = value5;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x79A1, 0xD0D275); GUARD_JSL(c, sp_call, 0x79A1); } /* publish_native_inventory_row_attribute_public_wrapper */
        r->sp += 4;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint8_t value6 = RAM8(0x0000 + sp0 - 3);
        uint8_t value7 = RAM8(0x0000 + sp0 - 2);
        a2 = (uint8_t)(((value7 << 8) | value6) - 1);
        a_hi2 = (uint16_t)(((value7 << 8) | value6) - 1) >> 8;
        x1 = (uint16_t)(x_ret + 1);
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        if (!((uint16_t)(((value7 << 8) | value6) - 1) != 0)) break;
    }
    uint8_t a3 = RAM16(RING_ENTRY_COUNT) & 0xFF;
    uint8_t a_hi3 = 0;
    uint16_t x2 = 0x18C0;
    uint16_t y2 = 0;
    bool carry2 = carry1;
    bool overflow2 = overflow1;
    for (;;) {
        RAM8(0x0000 + sp0 - 2) = a_hi3;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)((a_hi3 << 8) | a3);
        r->a = (a_hi3 << 8) | a3;
        r->x = x2;
        r->y = y2;
        r->c = carry2;
        r->v = overflow2;
        r->mf = 0;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x79B6, 0xC070A3); GUARD_JSR(c, sp_call, 0x79B6); } /* bind_native_menu_list_row_to_active_hero_oam_marker */
        r->sp += 4;
        uint16_t x_ret2 = r->x;
        uint8_t value8 = RAM8(0x0000 + sp0 - 3);
        uint8_t value9 = RAM8(0x0000 + sp0 - 2);
        a3 = (uint8_t)(((value9 << 8) | value8) - 1);
        a_hi3 = (uint16_t)(((value9 << 8) | value8) - 1) >> 8;
        x2 = (uint16_t)(x_ret2 + 0x10);
        y2 = (uint16_t)(y2 + 1);
        carry2 = x_ret2 + 0x10 > 0xFFFF;
        overflow2 = ((x_ret2 ^ (uint16_t)(x_ret2 + 0x10)) & ((uint16_t)(x_ret2 + 0x10) ^ 0x10) & 0x8000) != 0;
        if (!((uint16_t)(((value9 << 8) | value8) - 1) != 0)) break;
    }
    uint8_t value10 = RAM8(0x0000 + sp0 - 1);
    uint8_t value11 = RAM8(0x0000 + sp0);
    RAM16_SET(0x182A, (value11 << 8) | value10);
    r->a = (value11 << 8) | value10;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07971, SOM_RTS, "gen", rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction, 0, L_B | L_X | L_Y | L_C | L_V, 4, 0, 0, 86, 40)
