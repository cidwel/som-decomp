#include "som_c.h"

/* C0318E append_selected_native_name_glyph   [class C, 84 bytes, 32 instructions]
 * Source: src/rom/append_selected_native_name_glyph.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void append_selected_native_name_glyph(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_31b5 = 0;
    uint8_t a_hi_31b5 = 0;
    uint16_t x_31b5 = 0;
    uint16_t y_31b5 = 0;
    bool carry_31b5 = 0;
    bool zero_31b5 = 0;
    bool negative_31b5 = 0;
    bool overflow_31b5 = 0;
    uint16_t direct_page_31b5 = 0;
    uint8_t data_bank_31b5 = 0;
    uint8_t a_31b52 = 0;
    uint8_t a_hi_31b52 = 0;
    uint8_t x_31b52 = 0;
    uint8_t y_31b52 = 0;
    bool carry_31b52 = 0;
    bool zero_31b52 = 0;
    bool negative_31b52 = 0;
    bool overflow_31b52 = 0;
    uint16_t direct_page_31b52 = 0;
    uint8_t data_bank_31b52 = 0;
    uint8_t a_31b53 = 0;
    uint8_t a_hi_31b53 = 0;
    uint8_t x_31b53 = 0;
    uint8_t y_31b53 = 0;
    bool carry_31b53 = 0;
    bool zero_31b53 = 0;
    bool negative_31b53 = 0;
    bool overflow_31b53 = 0;
    uint16_t direct_page_31b53 = 0;
    uint8_t data_bank_31b53 = 0;
    uint8_t a_31b54 = 0;
    uint8_t a_hi_31b54 = 0;
    uint16_t x_31b54 = 0;
    uint16_t y_31b54 = 0;
    bool carry_31b54 = 0;
    bool zero_31b54 = 0;
    bool negative_31b54 = 0;
    bool overflow_31b54 = 0;
    uint16_t direct_page_31b54 = 0;
    uint8_t data_bank_31b54 = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3190, 0xC03269); GUARD_JSR(c, sp_call, 0x3190); } /* derive_native_menu_selected_pad_offset_preserving_accumulator_byte */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    uint8_t value = RAM8(0xA204 + x_ret);
    if ((value & 0x80) != 0) {
        a_31b5 = value & 0x80;
        a_hi_31b5 = a_all >> 8;
        x_31b5 = x_ret;
        y_31b5 = y;
        carry_31b5 = carry_ret;
        zero_31b5 = (value & 0x80) == 0;
        negative_31b5 = value & 0x80 & 0x80;
        overflow_31b5 = overflow;
        direct_page_31b5 = dp;
        data_bank_31b5 = 0x7E;
        goto shared_31B5;
    }
    uint8_t value2 = RAM8(0xA1CC);
    if (value2 == 6) {
        a_31b5 = value2;
        a_hi_31b5 = a_all >> 8;
        x_31b5 = x_ret;
        y_31b5 = y;
        carry_31b5 = value2 >= 6;
        zero_31b5 = value2 == 6;
        negative_31b5 = (uint8_t)(value2 - 6) & 0x80;
        overflow_31b5 = overflow;
        direct_page_31b5 = dp;
        data_bank_31b5 = 0x7E;
        goto shared_31B5;
    }
    r->a = (a_all >> 8 << 8) | value2;
    r->c = value2 >= 6;
    r->z = value2 == 6;
    r->n = (uint8_t)(value2 - 6) & 0x80;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x31A2, 0xC750E0); GUARD_JSL(c, sp_call, 0x31A2); } /* select_native_name_entry_tile_at_cursor */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    bool carry_ret2 = r->c;
    bool zero_ret2 = r->z;
    bool negative_ret2 = r->n;
    bool overflow_ret = r->v;
    if (carry_ret2) {
        a_31b5 = (uint8_t)a_all2;
        a_hi_31b5 = a_all2 >> 8;
        x_31b5 = x_ret2;
        y_31b5 = y;
        carry_31b5 = carry_ret2;
        zero_31b5 = zero_ret2;
        negative_31b5 = negative_ret2;
        overflow_31b5 = overflow_ret;
        direct_page_31b5 = dp;
        data_bank_31b5 = 0x7E;
        goto shared_31B5;
    }
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x31A8, 0xC75124); GUARD_JSL(c, sp_call, 0x31A8); } /* external */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    if (m_ret) {
        uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret << 0x10) + 0xA157, (uint8_t)(value3 + 1));
        uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xA157);
        BUS8_SET(c, (db_ret << 0x10) + 0xA157, (uint8_t)(value4 + 1));
        uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0xA1CC);
        BUS8_SET(c, (db_ret << 0x10) + 0xA1CC, (uint8_t)(value5 + 1));
        r->z = (uint8_t)(value5 + 1) == 0;
        r->n = (uint8_t)(value5 + 1) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x31B4, 0xC01BA5); GUARD_JSR(c, sp_call, 0x31B4); } /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
        uint8_t db_ret2 = r->db;
        bool m_ret2 = r->mf;
        bool x_ret5 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t x_ret6 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret4 = r->c;
        bool zero_ret4 = r->z;
        bool negative_ret4 = r->n;
        bool overflow_ret3 = r->v;
        if (m_ret2) {
            if (x_ret5) {
                a_31b52 = (uint8_t)a_all4;
                a_hi_31b52 = a_all4 >> 8;
                x_31b52 = (uint8_t)x_ret6;
                y_31b52 = (uint8_t)y_ret;
                carry_31b52 = carry_ret4;
                zero_31b52 = zero_ret4;
                negative_31b52 = negative_ret4;
                overflow_31b52 = overflow_ret3;
                direct_page_31b52 = dp_ret;
                data_bank_31b52 = db_ret2;
                goto shared_31B5_1;
            } else {
                a_31b5 = (uint8_t)a_all4;
                a_hi_31b5 = a_all4 >> 8;
                x_31b5 = x_ret6;
                y_31b5 = y_ret;
                carry_31b5 = carry_ret4;
                zero_31b5 = zero_ret4;
                negative_31b5 = negative_ret4;
                overflow_31b5 = overflow_ret3;
                direct_page_31b5 = dp_ret;
                data_bank_31b5 = db_ret2;
                goto shared_31B5;
            }
        } else {
            if (x_ret5) {
                a_31b53 = (uint8_t)a_all4;
                a_hi_31b53 = a_all4 >> 8;
                x_31b53 = (uint8_t)x_ret6;
                y_31b53 = (uint8_t)y_ret;
                carry_31b53 = carry_ret4;
                zero_31b53 = zero_ret4;
                negative_31b53 = negative_ret4;
                overflow_31b53 = overflow_ret3;
                direct_page_31b53 = dp_ret;
                data_bank_31b53 = db_ret2;
                goto shared_31B5_2;
            } else {
                a_31b54 = (uint8_t)a_all4;
                a_hi_31b54 = a_all4 >> 8;
                x_31b54 = x_ret6;
                y_31b54 = y_ret;
                carry_31b54 = carry_ret4;
                zero_31b54 = zero_ret4;
                negative_31b54 = negative_ret4;
                overflow_31b54 = overflow_ret3;
                direct_page_31b54 = dp_ret;
                data_bank_31b54 = db_ret2;
                goto shared_31B5_3;
            }
        }
    } else {
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret << 0x10) + 0xA157, (uint16_t)(value6 + 1));
        uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0xA157);
        BUS16_RMW_SET(c, (db_ret << 0x10) + 0xA157, (uint16_t)(value7 + 1));
        uint16_t value8 = BUS16_RDP(c, (db_ret << 0x10) + 0xA1CC);
        BUS16_RMW_SET(c, (db_ret << 0x10) + 0xA1CC, (uint16_t)(value8 + 1));
        r->z = (uint16_t)(value8 + 1) == 0;
        r->n = (uint16_t)(value8 + 1) & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x31B4, 0xC01BA5); GUARD_JSR(c, sp_call, 0x31B4); } /* preserve_accumulator_byte_and_request_fixed_local_audio_presets */
        uint8_t db_ret3 = r->db;
        bool m_ret3 = r->mf;
        bool x_ret7 = r->xf;
        uint16_t a_all5 = r->a;
        uint16_t x_ret8 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret5 = r->c;
        bool zero_ret5 = r->z;
        bool negative_ret5 = r->n;
        bool overflow_ret4 = r->v;
        if (m_ret3) {
            if (x_ret7) {
                a_31b52 = (uint8_t)a_all5;
                a_hi_31b52 = a_all5 >> 8;
                x_31b52 = (uint8_t)x_ret8;
                y_31b52 = (uint8_t)y_ret2;
                carry_31b52 = carry_ret5;
                zero_31b52 = zero_ret5;
                negative_31b52 = negative_ret5;
                overflow_31b52 = overflow_ret4;
                direct_page_31b52 = dp_ret;
                data_bank_31b52 = db_ret3;
                goto shared_31B5_1;
            } else {
                a_31b5 = (uint8_t)a_all5;
                a_hi_31b5 = a_all5 >> 8;
                x_31b5 = x_ret8;
                y_31b5 = y_ret2;
                carry_31b5 = carry_ret5;
                zero_31b5 = zero_ret5;
                negative_31b5 = negative_ret5;
                overflow_31b5 = overflow_ret4;
                direct_page_31b5 = dp_ret;
                data_bank_31b5 = db_ret3;
                goto shared_31B5;
            }
        } else {
            if (x_ret7) {
                a_31b53 = (uint8_t)a_all5;
                a_hi_31b53 = a_all5 >> 8;
                x_31b53 = (uint8_t)x_ret8;
                y_31b53 = (uint8_t)y_ret2;
                carry_31b53 = carry_ret5;
                zero_31b53 = zero_ret5;
                negative_31b53 = negative_ret5;
                overflow_31b53 = overflow_ret4;
                direct_page_31b53 = dp_ret;
                data_bank_31b53 = db_ret3;
                goto shared_31B5_2;
            } else {
                a_31b54 = (uint8_t)a_all5;
                a_hi_31b54 = a_all5 >> 8;
                x_31b54 = x_ret8;
                y_31b54 = y_ret2;
                carry_31b54 = carry_ret5;
                zero_31b54 = zero_ret5;
                negative_31b54 = negative_ret5;
                overflow_31b54 = overflow_ret4;
                direct_page_31b54 = dp_ret;
                data_bank_31b54 = db_ret3;
                goto shared_31B5_3;
            }
        }
    }
    shared_31B5:;
    r->a = (a_hi_31b5 << 8) | a_31b5;
    r->x = x_31b5;
    r->y = y_31b5;
    r->c = carry_31b5;
    r->z = zero_31b5;
    r->n = negative_31b5;
    r->v = overflow_31b5;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_31b5;
    r->dp = direct_page_31b5;
    RETURN_RTS(c);
    shared_31B5_1:;
    r->a = (a_hi_31b52 << 8) | a_31b52;
    r->x = x_31b52;
    r->y = y_31b52;
    r->c = carry_31b52;
    r->z = zero_31b52;
    r->n = negative_31b52;
    r->v = overflow_31b52;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_31b52;
    r->dp = direct_page_31b52;
    RETURN_RTS(c);
    shared_31B5_2:;
    r->a = (a_hi_31b53 << 8) | a_31b53;
    r->x = x_31b53;
    r->y = y_31b53;
    r->c = carry_31b53;
    r->z = zero_31b53;
    r->n = negative_31b53;
    r->v = overflow_31b53;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_31b53;
    r->dp = direct_page_31b53;
    RETURN_RTS(c);
    shared_31B5_3:;
    r->a = (a_hi_31b54 << 8) | a_31b54;
    r->x = x_31b54;
    r->y = y_31b54;
    r->c = carry_31b54;
    r->z = zero_31b54;
    r->n = negative_31b54;
    r->v = overflow_31b54;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_31b54;
    r->dp = direct_page_31b54;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0318E, SOM_RTS, "gen", append_selected_native_name_glyph, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 84, 32)
