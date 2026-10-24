#include "som_c.h"

/* C02DAD move_spell_item_slot_up_with_two_column_wrap   [class B, 53 bytes, 24 instructions]
 * Source: src/rom/move_spell_item_slot_up_with_two_column_wrap.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void move_spell_item_slot_up_with_two_column_wrap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA20A);
    bool m_flag2;
    bool x_flag2;
    uint8_t a4;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry3;
    bool zero4;
    bool negative4;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if ((value & 0x40) == 0) {
        m_flag2 = 1;
        x_flag2 = 0;
        a4 = value;
        a_hi2 = a_hi;
        x2 = x;
        y2 = y;
        carry3 = carry;
        zero4 = (value & 0x40) == 0;
        negative4 = value & 0x80;
        overflow2 = overflow;
        data_bank2 = 0x7E;
        direct_page2 = 0;
    } else {
        r->a = (a_hi << 8) | value;
        r->z = (value & 0x40) == 0;
        r->n = value & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2DB6, 0xC03269); GUARD_JSR(c, sp_call, 0x2DB6); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
        uint8_t value3 = RAM8(0xA204 + x_ret);
        bool m_flag;
        bool x_flag;
        uint8_t a3;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry2;
        bool zero3;
        bool negative3;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if (value2 == value3) {
            m_flag = 1;
            x_flag = 0;
            a3 = value2;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y;
            carry2 = value2 >= value3;
            zero3 = value2 == value3;
            negative3 = (uint8_t)(value2 - value3) & 0x80;
            overflow1 = overflow;
            data_bank = 0x7E;
            direct_page = 0;
        } else {
            r->a = (a_all >> 8 << 8) | value2;
            r->c = value2 >= value3;
            r->z = value2 == value3;
            r->n = (uint8_t)(value2 - value3) & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2DC1, 0xC757D5); GUARD_JSL(c, sp_call, 0x2DC1); } /* clear_native_saved_slot_rectangle_highlight */
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            uint8_t value4 = RAM8(0xA211);
            uint8_t a2;
            bool carry1;
            bool zero2;
            bool negative2;
            if (value4 == 0) {
                uint8_t value5 = RAM8(0xA200);
                a2 = (uint8_t)(value5 - 1);
                carry1 = carry_ret2;
                zero2 = (uint8_t)(value5 - 1) == 0;
                negative2 = (uint8_t)(value5 - 1) & 0x80;
            } else {
                uint8_t a1;
                bool zero1;
                bool negative1;
                if (value4 == 1) {
                    uint8_t value6 = RAM8(0xA200);
                    a1 = (uint8_t)(value6 - 2);
                    zero1 = (uint8_t)(value6 - 2) == 0;
                    negative1 = (uint8_t)(value6 - 2) & 0x80;
                } else {
                    a1 = (uint8_t)(value4 - 2);
                    zero1 = (uint8_t)(value4 - 2) == 0;
                    negative1 = (uint8_t)(value4 - 2) & 0x80;
                }
                a2 = a1;
                carry1 = value4 >= 1;
                zero2 = zero1;
                negative2 = negative1;
            }
            RAM8(0xA211) = a2;
            r->a = (a_all2 >> 8 << 8) | a2;
            r->c = carry1;
            r->z = zero2;
            r->n = negative2;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2DE0, 0xC757DC); GUARD_JSL(c, sp_call, 0x2DE0); } /* highlight_native_saved_slot_rectangle_and_request_publication */
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
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
            a3 = (uint8_t)a_all3;
            a_hi1 = a_all3 >> 8;
            x1 = x_ret5;
            y1 = y_ret2;
            carry2 = carry_ret3;
            zero3 = zero_ret3;
            negative3 = negative_ret3;
            overflow1 = overflow_ret2;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a4 = a3;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry3 = carry2;
        zero4 = zero3;
        negative4 = negative3;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->a = (a_hi2 << 8) | a4;
    r->x = x2;
    r->y = y2;
    r->c = carry3;
    r->z = zero4;
    r->n = negative4;
    r->v = overflow2;
    r->mf = m_flag2;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02DAD, SOM_RTS, "gen", move_spell_item_slot_up_with_two_column_wrap, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 53, 24)
