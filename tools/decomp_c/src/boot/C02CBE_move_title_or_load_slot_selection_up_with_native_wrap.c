#include "som_c.h"

/* C02CBE move_title_or_load_slot_selection_up_with_native_wrap   [class B, 105 bytes, 43 instructions]
 * Source: src/rom/move_title_or_load_slot_selection_up_with_native_wrap.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void move_title_or_load_slot_selection_up_with_native_wrap(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2CC0, 0xC03269); GUARD_JSR(c, sp_call, 0x2CC0); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + 0x43 + x_ret));
    uint8_t value2 = RAM8(0xA204 + x_ret);
    bool m_flag4;
    bool x_flag4;
    uint8_t a6;
    uint8_t a_hi4;
    uint16_t x4;
    uint16_t y4;
    bool carry4;
    bool zero6;
    bool negative6;
    bool overflow4;
    uint8_t data_bank4;
    uint16_t direct_page4;
    if (value == value2) {
        m_flag4 = 1;
        x_flag4 = 0;
        a6 = value;
        a_hi4 = a_all >> 8;
        x4 = x_ret;
        y4 = y;
        carry4 = value >= value2;
        zero6 = value == value2;
        negative6 = (uint8_t)(value - value2) & 0x80;
        overflow4 = overflow;
        data_bank4 = 0x7E;
        direct_page4 = dp;
    } else {
        bool m_flag3;
        bool x_flag3;
        uint8_t a5;
        uint8_t a_hi3;
        uint16_t x3;
        uint16_t y3;
        bool carry3;
        bool zero5;
        bool negative5;
        bool overflow3;
        uint8_t data_bank3;
        uint16_t direct_page3;
        if ((value & 0xF0) != 0) {
            m_flag3 = 1;
            x_flag3 = 0;
            a5 = value & 0xF0;
            a_hi3 = a_all >> 8;
            x3 = x_ret;
            y3 = y;
            carry3 = value >= value2;
            zero5 = (value & 0xF0) == 0;
            negative5 = value & 0xF0 & 0x80;
            overflow3 = overflow;
            data_bank3 = 0x7E;
            direct_page3 = dp;
        } else {
            uint8_t value3 = RAM8(0xA202);
            bool m_flag2;
            bool x_flag2;
            uint8_t a4;
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            bool carry2;
            bool zero4;
            bool negative4;
            bool overflow2;
            uint8_t data_bank2;
            uint16_t direct_page2;
            if (value3 != 0) {
                r->a = (a_all >> 8 << 8) | value3;
                r->c = value3 >= 0;
                r->z = value3 == 0;
                r->n = value3 & 0x80;
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0x2CDE, 0xC757D5); GUARD_JSL(c, sp_call, 0x2CDE); } /* clear_native_saved_slot_rectangle_highlight */
                if (r->mf != 1) { c->fail = 3; return; }
                uint16_t a_all2 = r->a;
                uint8_t value4 = RAM8(0xA211);
                uint8_t a1;
                bool zero1;
                bool negative1;
                if ((uint8_t)(value4 - 1) != 0xFF) {
                    a1 = (uint8_t)(value4 - 1);
                    zero1 = (uint8_t)(value4 - 1) == 0xFF;
                    negative1 = (uint8_t)(value4 - 0x0100) & 0x80;
                } else {
                    uint8_t value5 = RAM8(0xA200);
                    a1 = (uint8_t)(value5 - 1);
                    zero1 = (uint8_t)(value5 - 1) == 0;
                    negative1 = (uint8_t)(value5 - 1) & 0x80;
                }
                RAM8(0xA211) = a1;
                r->a = (a_all2 >> 8 << 8) | a1;
                r->c = (uint8_t)(value4 - 1) >= 0xFF;
                r->z = zero1;
                r->n = negative1;
                { const uint16_t sp_call = r->sp; JSL(c, 0x2CF1, 0xC757DC); GUARD_JSL(c, sp_call, 0x2CF1); } /* highlight_native_saved_slot_rectangle_and_request_publication */
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
                m_flag2 = m_ret;
                x_flag2 = x_ret4;
                a4 = (uint8_t)a_all3;
                a_hi2 = a_all3 >> 8;
                x2 = x_ret5;
                y2 = y_ret2;
                carry2 = carry_ret3;
                zero4 = zero_ret3;
                negative4 = negative_ret3;
                overflow2 = overflow_ret2;
                data_bank2 = db_ret;
                direct_page2 = dp_ret;
            } else {
                uint8_t value6 = RAM8(0xA215);
                bool m_flag;
                bool x_flag;
                uint8_t a3;
                uint8_t a_hi1;
                uint16_t x1;
                uint16_t y1;
                bool carry1;
                bool zero3;
                bool negative3;
                bool overflow1;
                uint8_t data_bank;
                uint16_t direct_page;
                if ((uint8_t)(value6 + 1) == 0) {
                    m_flag = 1;
                    x_flag = 0;
                    a3 = (uint8_t)(value6 + 1);
                    a_hi1 = a_all >> 8;
                    x1 = x_ret;
                    y1 = y;
                    carry1 = value3 >= 0;
                    zero3 = (uint8_t)(value6 + 1) == 0;
                    negative3 = (uint8_t)(value6 + 1) & 0x80;
                    overflow1 = overflow;
                    data_bank = 0x7E;
                    direct_page = dp;
                } else {
                    r->a = (a_all >> 8 << 8) | (uint8_t)(value6 + 1);
                    r->c = value3 >= 0;
                    r->z = (uint8_t)(value6 + 1) == 0;
                    r->n = (uint8_t)(value6 + 1) & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSL(c, 0x2CDE, 0xC757D5); GUARD_JSL(c, sp_call, 0x2CDE); } /* clear_native_saved_slot_rectangle_highlight */
                    if (r->mf != 1) { c->fail = 3; return; }
                    uint16_t a_all4 = r->a;
                    uint8_t value7 = RAM8(0xA211);
                    uint8_t a2;
                    bool zero2;
                    bool negative2;
                    if ((uint8_t)(value7 - 1) != 0xFF) {
                        a2 = (uint8_t)(value7 - 1);
                        zero2 = (uint8_t)(value7 - 1) == 0xFF;
                        negative2 = (uint8_t)(value7 - 0x0100) & 0x80;
                    } else {
                        uint8_t value8 = RAM8(0xA200);
                        a2 = (uint8_t)(value8 - 1);
                        zero2 = (uint8_t)(value8 - 1) == 0;
                        negative2 = (uint8_t)(value8 - 1) & 0x80;
                    }
                    RAM8(0xA211) = a2;
                    r->a = (a_all4 >> 8 << 8) | a2;
                    r->c = (uint8_t)(value7 - 1) >= 0xFF;
                    r->z = zero2;
                    r->n = negative2;
                    { const uint16_t sp_call = r->sp; JSL(c, 0x2CF1, 0xC757DC); GUARD_JSL(c, sp_call, 0x2CF1); } /* highlight_native_saved_slot_rectangle_and_request_publication */
                    uint16_t dp_ret2 = r->dp;
                    uint8_t db_ret2 = r->db;
                    bool m_ret2 = r->mf;
                    bool x_ret8 = r->xf;
                    uint16_t a_all5 = r->a;
                    uint16_t x_ret9 = r->x;
                    uint16_t y_ret4 = r->y;
                    bool carry_ret5 = r->c;
                    bool zero_ret5 = r->z;
                    bool negative_ret5 = r->n;
                    bool overflow_ret4 = r->v;
                    m_flag = m_ret2;
                    x_flag = x_ret8;
                    a3 = (uint8_t)a_all5;
                    a_hi1 = a_all5 >> 8;
                    x1 = x_ret9;
                    y1 = y_ret4;
                    carry1 = carry_ret5;
                    zero3 = zero_ret5;
                    negative3 = negative_ret5;
                    overflow1 = overflow_ret4;
                    data_bank = db_ret2;
                    direct_page = dp_ret2;
                }
                m_flag2 = m_flag;
                x_flag2 = x_flag;
                a4 = a3;
                a_hi2 = a_hi1;
                x2 = x1;
                y2 = y1;
                carry2 = carry1;
                zero4 = zero3;
                negative4 = negative3;
                overflow2 = overflow1;
                data_bank2 = data_bank;
                direct_page2 = direct_page;
            }
            m_flag3 = m_flag2;
            x_flag3 = x_flag2;
            a5 = a4;
            a_hi3 = a_hi2;
            x3 = x2;
            y3 = y2;
            carry3 = carry2;
            zero5 = zero4;
            negative5 = negative4;
            overflow3 = overflow2;
            data_bank3 = data_bank2;
            direct_page3 = direct_page2;
        }
        m_flag4 = m_flag3;
        x_flag4 = x_flag3;
        a6 = a5;
        a_hi4 = a_hi3;
        x4 = x3;
        y4 = y3;
        carry4 = carry3;
        zero6 = zero5;
        negative6 = negative5;
        overflow4 = overflow3;
        data_bank4 = data_bank3;
        direct_page4 = direct_page3;
    }
    r->a = (a_hi4 << 8) | a6;
    r->x = x4;
    r->y = y4;
    r->c = carry4;
    r->z = zero6;
    r->n = negative6;
    r->v = overflow4;
    r->mf = m_flag4;
    r->xf = x_flag4;
    r->db = data_bank4;
    r->dp = direct_page4;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02CBE, SOM_RTS, "gen", move_title_or_load_slot_selection_up_with_native_wrap, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 105, 43)
