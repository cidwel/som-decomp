#include "som_c.h"

/* C02FEA move_native_personality_grid_cursor_right   [class B, 34 bytes, 14 instructions]
 * Source: src/rom/move_native_personality_grid_cursor_right.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void move_native_personality_grid_cursor_right(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2FEC, 0xC0325A); GUARD_JSR(c, sp_call, 0x2FEC); } /* compare_selected_pad_buttons_against_native_previous_buttons */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
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
    if (zero_ret) {
        m_flag2 = 1;
        x_flag2 = 0;
        a2 = (uint8_t)a_all;
        a_hi2 = a_all >> 8;
        x2 = x_ret;
        y2 = y;
        carry2 = carry_ret;
        zero2 = zero_ret;
        negative2 = negative_ret;
        overflow2 = overflow;
        data_bank2 = 0x7E;
        direct_page2 = 0;
    } else {
        uint8_t value = RAM8(0xA212);
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
        if ((value & 0x20) != 0) {
            m_flag = 1;
            x_flag = 0;
            a1 = value;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y;
            carry1 = carry_ret;
            zero1 = (value & 0x20) == 0;
            negative1 = value & 0x80;
            overflow1 = overflow;
            data_bank = 0x7E;
            direct_page = 0;
        } else {
            uint8_t value2 = RAM8(0xA136);
            RAM8(0xA136) = (uint8_t)(value2 + 1) & 0x0F;
            r->a = a_all >> 8 << 8 | ((uint8_t)(value2 + 1) & 0x0F);
            r->z = ((uint8_t)(value2 + 1) & 0x0F) == 0;
            r->n = (uint8_t)(value2 + 1) & 0x0F & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x3002, 0xC75217); GUARD_JSL(c, sp_call, 0x3002); } /* dispatch_native_name_page_party_icon_variant */
            uint8_t db_ret = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xA20A);
            BUS8_SET(c, (db_ret << 0x10) + 0xA20A, value3 | 4);
            r->a = (a_all2 >> 8 << 8) | 4;
            r->z = (value3 & 4) == 0;
            r->n = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x300A, 0xC01BAA); GUARD_JSR(c, sp_call, 0x300A); } /* external */
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            bool m_ret = r->mf;
            bool x_ret4 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t x_ret5 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret3 = r->c;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            bool overflow_ret2 = r->v;
            m_flag = m_ret;
            x_flag = x_ret4;
            a1 = (uint8_t)a_all3;
            a_hi1 = a_all3 >> 8;
            x1 = x_ret5;
            y1 = y_ret2;
            carry1 = carry_ret3;
            zero1 = zero_ret3;
            negative1 = negative_ret3;
            overflow1 = overflow_ret2;
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
SOM_REGISTER(0xC02FEA, SOM_RTS, "gen", move_native_personality_grid_cursor_right, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 34, 14)
