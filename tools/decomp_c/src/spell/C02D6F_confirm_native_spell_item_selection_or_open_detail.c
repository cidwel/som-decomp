#include "som_c.h"

/* C02D6F confirm_native_spell_item_selection_or_open_detail   [class B, 62 bytes, 25 instructions]
 * Source: src/rom/confirm_native_spell_item_selection_or_open_detail.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void confirm_native_spell_item_selection_or_open_detail(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_2dac = 0;
    uint8_t a_hi_2dac = 0;
    uint16_t x_2dac = 0;
    uint16_t y_2dac = 0;
    bool carry_2dac = 0;
    bool zero_2dac = 0;
    bool negative_2dac = 0;
    bool overflow_2dac = 0;
    uint16_t direct_page_2dac = 0;
    uint8_t data_bank_2dac = 0;
    uint8_t a_2dac2 = 0;
    uint8_t a_hi_2dac2 = 0;
    uint8_t x_2dac2 = 0;
    uint8_t y_2dac2 = 0;
    bool carry_2dac2 = 0;
    bool zero_2dac2 = 0;
    bool negative_2dac2 = 0;
    bool overflow_2dac2 = 0;
    uint16_t direct_page_2dac2 = 0;
    uint8_t data_bank_2dac2 = 0;
    uint8_t a_2dac3 = 0;
    uint8_t a_hi_2dac3 = 0;
    uint8_t x_2dac3 = 0;
    uint8_t y_2dac3 = 0;
    bool carry_2dac3 = 0;
    bool zero_2dac3 = 0;
    bool negative_2dac3 = 0;
    bool overflow_2dac3 = 0;
    uint16_t direct_page_2dac3 = 0;
    uint8_t data_bank_2dac3 = 0;
    uint8_t a_2dac4 = 0;
    uint8_t a_hi_2dac4 = 0;
    uint16_t x_2dac4 = 0;
    uint16_t y_2dac4 = 0;
    bool carry_2dac4 = 0;
    bool zero_2dac4 = 0;
    bool negative_2dac4 = 0;
    bool overflow_2dac4 = 0;
    uint16_t direct_page_2dac4 = 0;
    uint8_t data_bank_2dac4 = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2D71, 0xC03269); GUARD_JSR(c, sp_call, 0x2D71); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    uint8_t value = BUS8_RDP(c, (uint16_t)(x_ret + 0x43));
    uint8_t value2 = RAM8(0xA204 + x_ret);
    if (value == value2) {
        a_2dac = value;
        a_hi_2dac = a_all >> 8;
        x_2dac = x_ret;
        y_2dac = y;
        carry_2dac = value >= value2;
        zero_2dac = value == value2;
        negative_2dac = (uint8_t)(value - value2) & 0x80;
        overflow_2dac = overflow;
        direct_page_2dac = 0;
        data_bank_2dac = 0x7E;
        goto shared_2DAC;
    }
    uint8_t value3 = RAM8(0xA212);
    if ((value3 & 8) != 0) {
        r->a = (a_all >> 8 << 8) | 8;
        r->c = value >= value2;
        r->z = (value3 & 8) == 0;
        r->n = value3 & 0x80;
        r->v = value3 & 0x40;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2DA7, 0xC01BA5); GUARD_JSR(c, sp_call, 0x2DA7); } /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
        { const uint16_t sp_call = r->sp; JSL(c, 0x2DAB, 0xC76401); GUARD_JSL(c, sp_call, 0x2DAB); } /* dispatch_native_spell_or_item_detail_publication */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret3 = r->c;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        bool overflow_ret2 = r->v;
        if (m_ret2) {
            if (x_ret4) {
                a_2dac2 = (uint8_t)a_all3;
                a_hi_2dac2 = a_all3 >> 8;
                x_2dac2 = (uint8_t)x_ret5;
                y_2dac2 = (uint8_t)y_ret2;
                carry_2dac2 = carry_ret3;
                zero_2dac2 = zero_ret3;
                negative_2dac2 = negative_ret3;
                overflow_2dac2 = overflow_ret2;
                direct_page_2dac2 = dp_ret;
                data_bank_2dac2 = db_ret2;
                goto shared_2DAC_1;
            } else {
                a_2dac = (uint8_t)a_all3;
                a_hi_2dac = a_all3 >> 8;
                x_2dac = x_ret5;
                y_2dac = y_ret2;
                carry_2dac = carry_ret3;
                zero_2dac = zero_ret3;
                negative_2dac = negative_ret3;
                overflow_2dac = overflow_ret2;
                direct_page_2dac = dp_ret;
                data_bank_2dac = db_ret2;
                goto shared_2DAC;
            }
        } else {
            if (x_ret4) {
                a_2dac3 = (uint8_t)a_all3;
                a_hi_2dac3 = a_all3 >> 8;
                x_2dac3 = (uint8_t)x_ret5;
                y_2dac3 = (uint8_t)y_ret2;
                carry_2dac3 = carry_ret3;
                zero_2dac3 = zero_ret3;
                negative_2dac3 = negative_ret3;
                overflow_2dac3 = overflow_ret2;
                direct_page_2dac3 = dp_ret;
                data_bank_2dac3 = db_ret2;
                goto shared_2DAC_2;
            } else {
                a_2dac4 = (uint8_t)a_all3;
                a_hi_2dac4 = a_all3 >> 8;
                x_2dac4 = x_ret5;
                y_2dac4 = y_ret2;
                carry_2dac4 = carry_ret3;
                zero_2dac4 = zero_ret3;
                negative_2dac4 = negative_ret3;
                overflow_2dac4 = overflow_ret2;
                direct_page_2dac4 = dp_ret;
                data_bank_2dac4 = db_ret2;
                goto shared_2DAC_3;
            }
        }
    }
    RAM8(0xA212) |= 8;
    uint8_t value5 = RAM8(0xA20A);
    if ((value5 & 0x40) != 0) {
        a_2dac = value5 & 0x40;
        a_hi_2dac = a_all >> 8;
        x_2dac = x_ret;
        y_2dac = y;
        carry_2dac = value >= value2;
        zero_2dac = (value5 & 0x40) == 0;
        negative_2dac = value5 & 0x40 & 0x80;
        overflow_2dac = value3 & 0x40;
        direct_page_2dac = 0;
        data_bank_2dac = 0x7E;
        goto shared_2DAC;
    }
    RAM8(0x0000 + sp0) = RAM8(0xA202);
    RAM8(0xA202) = 6;
    r->a = (a_all >> 8 << 8) | 6;
    r->c = value >= value2;
    r->z = 0;
    r->n = 0;
    r->v = value3 & 0x40;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2D96, 0xC757DC); GUARD_JSL(c, sp_call, 0x2D96); } /* highlight_native_saved_slot_rectangle_and_request_publication */
    r->sp += 1;
    uint16_t dp_ret2 = r->dp;
    bool m_ret3 = r->mf;
    uint16_t a_all4 = r->a;
    if (m_ret3) {
        uint8_t value7 = RAM8(0x0000 + sp0);
        r->a = (a_all4 >> 8 << 8) | value7;
        r->z = value7 == 0;
        r->n = value7 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2D9A, 0xC01BA5); GUARD_JSR(c, sp_call, 0x2D9A); } /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
        uint8_t db_ret4 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret8 = r->xf;
        uint16_t a_all5 = r->a;
        uint16_t x_ret9 = r->x;
        uint16_t y_ret4 = r->y;
        bool carry_ret5 = r->c;
        bool overflow_ret4 = r->v;
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA202, (uint8_t)a_all5);
        uint8_t value8 = BUS8_RDP(c, (db_ret4 << 0x10) + 0xA20A);
        BUS8_SET(c, (db_ret4 << 0x10) + 0xA20A, value8 | 0x40);
        if (x_ret8) {
            a_2dac2 = 0x40;
            a_hi_2dac2 = a_all5 >> 8;
            x_2dac2 = (uint8_t)x_ret9;
            y_2dac2 = (uint8_t)y_ret4;
            carry_2dac2 = carry_ret5;
            zero_2dac2 = (value8 & 0x40) == 0;
            negative_2dac2 = 0;
            overflow_2dac2 = overflow_ret4;
            direct_page_2dac2 = dp_ret2;
            data_bank_2dac2 = db_ret4;
            goto shared_2DAC_1;
        } else {
            a_2dac = 0x40;
            a_hi_2dac = a_all5 >> 8;
            x_2dac = x_ret9;
            y_2dac = y_ret4;
            carry_2dac = carry_ret5;
            zero_2dac = (value8 & 0x40) == 0;
            negative_2dac = 0;
            overflow_2dac = overflow_ret4;
            direct_page_2dac = dp_ret2;
            data_bank_2dac = db_ret4;
            goto shared_2DAC;
        }
    } else {
        c->fail = 3;
        return;
    }
    shared_2DAC:;
    r->a = (a_hi_2dac << 8) | a_2dac;
    r->x = x_2dac;
    r->y = y_2dac;
    r->c = carry_2dac;
    r->z = zero_2dac;
    r->n = negative_2dac;
    r->v = overflow_2dac;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_2dac;
    r->dp = direct_page_2dac;
    RETURN_RTS(c);
    shared_2DAC_1:;
    r->a = (a_hi_2dac2 << 8) | a_2dac2;
    r->x = x_2dac2;
    r->y = y_2dac2;
    r->c = carry_2dac2;
    r->z = zero_2dac2;
    r->n = negative_2dac2;
    r->v = overflow_2dac2;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_2dac2;
    r->dp = direct_page_2dac2;
    RETURN_RTS(c);
    shared_2DAC_2:;
    r->a = (a_hi_2dac3 << 8) | a_2dac3;
    r->x = x_2dac3;
    r->y = y_2dac3;
    r->c = carry_2dac3;
    r->z = zero_2dac3;
    r->n = negative_2dac3;
    r->v = overflow_2dac3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_2dac3;
    r->dp = direct_page_2dac3;
    RETURN_RTS(c);
    shared_2DAC_3:;
    r->a = (a_hi_2dac4 << 8) | a_2dac4;
    r->x = x_2dac4;
    r->y = y_2dac4;
    r->c = carry_2dac4;
    r->z = zero_2dac4;
    r->n = negative_2dac4;
    r->v = overflow_2dac4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_2dac4;
    r->dp = direct_page_2dac4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02D6F, SOM_RTS, "gen", confirm_native_spell_item_selection_or_open_detail, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 62, 25)
