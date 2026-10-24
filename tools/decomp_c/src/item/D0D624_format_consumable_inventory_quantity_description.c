#include "som_c.h"

/* D0D624 format_consumable_inventory_quantity_description   [class B, 75 bytes, 29 instructions]
 * Source: src/rom/format_consumable_inventory_quantity_description.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void format_consumable_inventory_quantity_description(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    { const uint16_t sp_call = r->sp; JSL(c, 0xD627, 0xC06BE2); GUARD_JSL(c, sp_call, 0xD627); } /* calculate_wrapped_native_menu_row_index */
    uint16_t a_all = r->a;
    bool overflow_ret = r->v;
    r->a = a_all & 0xFF;
    r->z = (a_all & 0xFF) == 0;
    r->n = a_all & 0xFF & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD62F, 0xD0D9BF); GUARD_JSR(c, sp_call, 0xD62F); } /* read_consumable_inventory_record */
    uint16_t a_all2 = r->a;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool m_flag2;
    bool x_flag2;
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool zero2;
    bool negative2;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if ((a_all2 & 0x1F) < 6) {
        RAM16_SET(0x19D4, 0x1A59);
        BUS16_SET(c, 0x19D6, 0xCD);
        r->a = 0xCD;
        r->x = 0x19D6;
        r->c = (a_all2 & 0x1F) >= 6;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD64E, 0xC06BE2); GUARD_JSL(c, sp_call, 0xD64E); } /* calculate_wrapped_native_menu_row_index */
        uint16_t a_all3 = r->a;
        r->a = a_all3 & 0xFF;
        r->z = (a_all3 & 0xFF) == 0;
        r->n = a_all3 & 0xFF & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD656, 0xD0D9B4); GUARD_JSR(c, sp_call, 0xD656); } /* read_consumable_inventory_quantity */
        uint16_t a_all4 = r->a;
        RAM8(0x0000 + sp0) = a_all4 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all4;
        RAM16_SET(0x1802, RAM16(0x1802) | 0x10);
        r->a = a_all4 & 0x0F;
        r->x = 0x19D7;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD669, 0xD0D7FD); GUARD_JSR(c, sp_call, 0xD669); } /* append_native_menu_digit_with_leading_zero_suppression */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t a_all5 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret3 = r->v;
        BUS8_SET(c, (uint16_t)(dp_ret + 1 + x_ret4), 0);
        m_flag2 = 1;
        x_flag2 = x_ret3;
        a2 = 0;
        a_hi2 = a_all5 >> 8;
        x2 = x_ret4;
        y2 = y_ret3;
        carry2 = carry_ret4;
        zero2 = 1;
        negative2 = 0;
        overflow2 = overflow_ret3;
        data_bank2 = db_ret;
        direct_page2 = dp_ret;
    } else {
        bool m_flag;
        bool x_flag;
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool zero1;
        bool negative1;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((a_all2 & 0x1F) < 0x0A) {
            m_flag = 0;
            x_flag = 0;
            a1 = a_all2 & 0x1F;
            a_hi1 = 0;
            x1 = x_ret;
            y1 = y_ret;
            carry1 = (a_all2 & 0x1F) >= 0x0A;
            zero1 = (a_all2 & 0x1F) == 0x0A;
            negative1 = (uint16_t)((a_all2 & 0x1F) - 0x0A) & 0x8000;
            overflow1 = overflow_ret;
            data_bank = 0;
            direct_page = 0;
        } else {
            RAM16_SET(0x19D4, 0x1A59);
            BUS16_SET(c, 0x19D6, 0xCD);
            r->a = 0xCD;
            r->x = 0x19D6;
            r->c = (a_all2 & 0x1F) >= 0x0A;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xD64E, 0xC06BE2); GUARD_JSL(c, sp_call, 0xD64E); } /* calculate_wrapped_native_menu_row_index */
            uint16_t a_all6 = r->a;
            r->a = a_all6 & 0xFF;
            r->z = (a_all6 & 0xFF) == 0;
            r->n = a_all6 & 0xFF & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD656, 0xD0D9B4); GUARD_JSR(c, sp_call, 0xD656); } /* read_consumable_inventory_quantity */
            uint16_t a_all7 = r->a;
            RAM8(0x0000 + sp0) = a_all7 >> 8;
            RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all7;
            RAM16_SET(0x1802, RAM16(0x1802) | 0x10);
            r->a = a_all7 & 0x0F;
            r->x = 0x19D7;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD669, 0xD0D7FD); GUARD_JSR(c, sp_call, 0xD669); } /* append_native_menu_digit_with_leading_zero_suppression */
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret6 = r->xf;
            uint16_t a_all8 = r->a;
            uint16_t x_ret7 = r->x;
            uint16_t y_ret5 = r->y;
            bool carry_ret7 = r->c;
            bool overflow_ret5 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret2 + 1 + x_ret7), 0);
            m_flag = 1;
            x_flag = x_ret6;
            a1 = 0;
            a_hi1 = a_all8 >> 8;
            x1 = x_ret7;
            y1 = y_ret5;
            carry1 = carry_ret7;
            zero1 = 1;
            negative1 = 0;
            overflow1 = overflow_ret5;
            data_bank = db_ret2;
            direct_page = dp_ret2;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = m_flag2;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D624, SOM_RTS, "gen", format_consumable_inventory_quantity_description, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 75, 29)
