#include "som_c.h"

/* D0D22F build_native_category_inventory_descriptor_rows   [class B, 52 bytes, 23 instructions]
 * Source: src/rom/build_native_category_inventory_descriptor_rows.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void build_native_category_inventory_descriptor_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    RAM8(0x0000 + sp0) = y >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xD235, 0xD0C800); GUARD_JSL(c, sp_call, 0xD235); } /* locate_menu_category_inventory_and_equipment_spans */
    r->sp += 2;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    RAM16_SET(0x182C, x_ret);
    RAM16_SET(0x182A, y_ret);
    RAM16_SET(0x183C, a_all);
    uint8_t value = RAM8(0x0000 + sp0 - 1);
    uint8_t value2 = RAM8(0x0000 + sp0);
    uint8_t a1 = 0x0B;
    uint8_t a_hi1 = 0;
    uint16_t x1 = x_ret;
    uint16_t y1 = (value2 << 8) | value;
    bool carry1 = carry_ret;
    bool zero1 = 0;
    bool negative1 = 0;
    bool overflow1 = overflow_ret;
    for (;;) {
        RAM8(0x0000 + sp0) = a_hi1;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi1 << 8) | a1);
        uint16_t value3 = RAM16(0xCC00 + x1);
        if ((value3 & 0xFF) == 0xFF) {
            if ((uint16_t)(((a_hi1 << 8) | a1) - 1) != 0) {
                uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) - 1);
                uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) - 1) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 1);
                bool carry1_next = (value3 & 0xFF) >= 0xFF;
                bool zero1_next = (uint16_t)(((a_hi1 << 8) | a1) - 1) == 0;
                bool negative1_next = (uint16_t)(((a_hi1 << 8) | a1) - 1) & 0x8000;
                a1 = a1_next;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                carry1 = carry1_next;
                zero1 = zero1_next;
                negative1 = negative1_next;
                continue;
            }
            uint8_t a1_next2 = (uint8_t)(((a_hi1 << 8) | a1) - 1);
            uint8_t a_hi1_next2 = (uint16_t)(((a_hi1 << 8) | a1) - 1) >> 8;
            uint16_t x1_next2 = (uint16_t)(x1 + 1);
            bool carry1_next2 = (value3 & 0xFF) >= 0xFF;
            bool zero1_next2 = (uint16_t)(((a_hi1 << 8) | a1) - 1) == 0;
            bool negative1_next2 = (uint16_t)(((a_hi1 << 8) | a1) - 1) & 0x8000;
            a1 = a1_next2;
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            carry1 = carry1_next2;
            zero1 = zero1_next2;
            negative1 = negative1_next2;
            break;
        }
        r->a = value3 & 0x3F;
        r->x = x1;
        r->y = y1;
        r->c = (value3 & 0xFF) >= 0xFF;
        r->z = (value3 & 0x3F) == 0;
        r->n = value3 & 0x3F & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD255, 0xD0D279); GUARD_JSR(c, sp_call, 0xD255); } /* publish_native_inventory_owner_and_rotated_selection_attribute */
        r->sp += 2;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint16_t value4 = RAM16(0x183C);
        r->a = (uint16_t)(a_all2 - value4);
        r->c = a_all2 >= value4;
        r->z = (uint16_t)(a_all2 - value4) == 0;
        r->n = (uint16_t)(a_all2 - value4) & 0x8000;
        r->v = ((a_all2 ^ value4) & (a_all2 ^ (uint16_t)(a_all2 - value4)) & 0x8000) != 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD25C, 0xD0D263); GUARD_JSR(c, sp_call, 0xD25C); } /* append_native_menu_descriptor_from_category_table */
        r->sp += 2;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret4 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        uint8_t value5 = RAM8(0x0000 + sp0 - 1);
        uint8_t value6 = RAM8(0x0000 + sp0);
        if ((uint16_t)(((value6 << 8) | value5) - 1) != 0) {
            a1 = (uint8_t)(((value6 << 8) | value5) - 1);
            a_hi1 = (uint16_t)(((value6 << 8) | value5) - 1) >> 8;
            x1 = (uint16_t)(x_ret4 + 1);
            y1 = y_ret3;
            carry1 = carry_ret3;
            zero1 = (uint16_t)(((value6 << 8) | value5) - 1) == 0;
            negative1 = (uint16_t)(((value6 << 8) | value5) - 1) & 0x8000;
            overflow1 = overflow_ret3;
            continue;
        }
        a1 = (uint8_t)(((value6 << 8) | value5) - 1);
        a_hi1 = (uint16_t)(((value6 << 8) | value5) - 1) >> 8;
        x1 = (uint16_t)(x_ret4 + 1);
        y1 = y_ret3;
        carry1 = carry_ret3;
        zero1 = (uint16_t)(((value6 << 8) | value5) - 1) == 0;
        negative1 = (uint16_t)(((value6 << 8) | value5) - 1) & 0x8000;
        overflow1 = overflow_ret3;
        break;
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
SOM_REGISTER(0xD0D22F, SOM_RTS, "gen", build_native_category_inventory_descriptor_rows, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 52, 23)
