#include "som_c.h"

/* C02E3D move_spell_item_slot_right_with_first_slot_wrap   [class B, 40 bytes, 16 instructions]
 * Source: src/rom/move_spell_item_slot_right_with_first_slot_wrap.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void move_spell_item_slot_right_with_first_slot_wrap(SomCtx *c)
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
    uint8_t a3;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool zero3;
    bool negative3;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if ((value & 0x40) == 0) {
        m_flag2 = 1;
        x_flag2 = 0;
        a3 = value;
        a_hi2 = a_hi;
        x2 = x;
        y2 = y;
        carry2 = carry;
        zero3 = (value & 0x40) == 0;
        negative3 = value & 0x80;
        overflow2 = overflow;
        data_bank2 = 0x7E;
        direct_page2 = 0;
    } else {
        r->a = (a_hi << 8) | value;
        r->z = (value & 0x40) == 0;
        r->n = value & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2E46, 0xC03269); GUARD_JSR(c, sp_call, 0x2E46); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
        uint8_t value3 = RAM8(0xA204 + x_ret);
        bool m_flag;
        bool x_flag;
        uint8_t a2;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool zero2;
        bool negative2;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if (value2 == value3) {
            m_flag = 1;
            x_flag = 0;
            a2 = value2;
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y;
            carry1 = value2 >= value3;
            zero2 = value2 == value3;
            negative2 = (uint8_t)(value2 - value3) & 0x80;
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
            { const uint16_t sp_call = r->sp; JSL(c, 0x2E51, 0xC757D5); GUARD_JSL(c, sp_call, 0x2E51); } /* clear_native_saved_slot_rectangle_highlight */
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            uint8_t value4 = RAM8(0xA211);
            uint8_t value5 = RAM8(0xA200);
            uint8_t a1;
            bool zero1;
            bool negative1;
            if ((uint8_t)(value4 + 1) != value5) {
                a1 = (uint8_t)(value4 + 1);
                zero1 = (uint8_t)(value4 + 1) == value5;
                negative1 = (uint8_t)((uint8_t)(value4 + 1) - value5) & 0x80;
            } else {
                a1 = 0;
                zero1 = 1;
                negative1 = 0;
            }
            RAM8(0xA211) = a1;
            r->a = (a_all2 >> 8 << 8) | a1;
            r->c = (uint8_t)(value4 + 1) >= value5;
            r->z = zero1;
            r->n = negative1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2E63, 0xC757DC); GUARD_JSL(c, sp_call, 0x2E63); } /* highlight_native_saved_slot_rectangle_and_request_publication */
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
            a2 = (uint8_t)a_all3;
            a_hi1 = a_all3 >> 8;
            x1 = x_ret5;
            y1 = y_ret2;
            carry1 = carry_ret3;
            zero2 = zero_ret3;
            negative2 = negative_ret3;
            overflow1 = overflow_ret2;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a3 = a2;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        carry2 = carry1;
        zero3 = zero2;
        negative3 = negative2;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    r->a = (a_hi2 << 8) | a3;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = zero3;
    r->n = negative3;
    r->v = overflow2;
    r->mf = m_flag2;
    r->xf = x_flag2;
    r->db = data_bank2;
    r->dp = direct_page2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02E3D, SOM_RTS, "gen", move_spell_item_slot_right_with_first_slot_wrap, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 40, 16)
