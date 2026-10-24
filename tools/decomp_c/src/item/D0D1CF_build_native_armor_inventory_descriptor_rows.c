#include "som_c.h"

/* D0D1CF build_native_armor_inventory_descriptor_rows   [class B, 44 bytes, 18 instructions]
 * Source: src/rom/build_native_armor_inventory_descriptor_rows.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void build_native_armor_inventory_descriptor_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x182A, 0x63);
    RAM16_SET(0x182C, 0x54);
    uint8_t a1 = 8;
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0x54;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = 0;
    bool negative1 = 0;
    bool overflow1 = overflow;
    for (;;) {
        RAM8(0x0000 + sp0) = a_hi1;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi1 << 8) | a1);
        uint16_t value = RAM16(0xCC00 + x1);
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if ((value & 0xFF) == 0xFF) {
            a_hi2 = 0;
            x2 = x1;
            y2 = y1;
            carry2 = (value & 0xFF) >= 0xFF;
            overflow2 = overflow1;
        } else {
            r->a = value & 0xFF;
            r->x = x1;
            r->y = y1;
            r->c = (value & 0xFF) >= 0xFF;
            r->z = (value & 0xFF) == 0xFF;
            r->n = (uint16_t)((value & 0xFF) - 0xFF) & 0x8000;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0;
            r->dp = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD1EE, 0xD0D1FB); GUARD_JSL(c, sp_call, 0xD1EE); } /* offset_armor_inventory_description_by_position */
            r->sp += 2;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD1F1, 0xD0D279); GUARD_JSR(c, sp_call, 0xD1F1); } /* publish_native_inventory_owner_and_rotated_selection_attribute */
            r->sp += 2;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD1F4, 0xD0D263); GUARD_JSR(c, sp_call, 0xD1F4); } /* append_native_menu_descriptor_from_category_table */
            r->sp += 2;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all3 = r->a;
            uint16_t x_ret4 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            a_hi2 = a_all3 >> 8;
            x2 = x_ret4;
            y2 = y_ret2;
            carry2 = carry_ret3;
            overflow2 = overflow_ret3;
        }
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        a1 = (uint8_t)(((value3 << 8) | value2) - 1);
        a_hi1 = (uint16_t)(((value3 << 8) | value2) - 1) >> 8;
        x1 = (uint16_t)(x2 + 1);
        y1 = y2;
        carry1 = carry2;
        zero1 = (uint16_t)(((value3 << 8) | value2) - 1) == 0;
        negative1 = (uint16_t)(((value3 << 8) | value2) - 1) & 0x8000;
        overflow1 = overflow2;
        if (!((uint16_t)(((value3 << 8) | value2) - 1) != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D1CF, SOM_RTS, "gen", build_native_armor_inventory_descriptor_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 44, 18)
