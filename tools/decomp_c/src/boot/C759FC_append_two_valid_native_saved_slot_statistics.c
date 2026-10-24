#include "som_c.h"

/* C759FC append_two_valid_native_saved_slot_statistics   [class B, 34 bytes, 14 instructions]
 * Source: src/rom/append_two_valid_native_saved_slot_statistics.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void append_two_valid_native_saved_slot_statistics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi_5a1d = 0;
    uint16_t x_5a1d = 0;
    uint16_t y_5a1d = 0;
    bool carry_5a1d = 0;
    bool overflow_5a1d = 0;
    uint8_t data_bank_5a1d = 0;
    uint8_t a_hi_5a1d2 = 0;
    uint8_t x_5a1d2 = 0;
    uint8_t y_5a1d2 = 0;
    bool carry_5a1d2 = 0;
    bool overflow_5a1d2 = 0;
    uint8_t data_bank_5a1d2 = 0;
    uint8_t a_hi_5a1d3 = 0;
    uint8_t x_5a1d3 = 0;
    uint8_t y_5a1d3 = 0;
    bool carry_5a1d3 = 0;
    bool overflow_5a1d3 = 0;
    uint8_t data_bank_5a1d3 = 0;
    uint8_t a_hi_5a1d4 = 0;
    uint16_t x_5a1d4 = 0;
    uint16_t y_5a1d4 = 0;
    bool carry_5a1d4 = 0;
    bool overflow_5a1d4 = 0;
    uint8_t data_bank_5a1d4 = 0;
    uint8_t value = RAM8(0xA216);
    if ((value & 3) == 3) {
        a_hi_5a1d = a_hi;
        x_5a1d = x;
        y_5a1d = y;
        carry_5a1d = (value & 3) >= 3;
        overflow_5a1d = overflow;
        data_bank_5a1d = 0x7E;
        goto shared_5A1D;
    }
    r->a = a_hi << 8 | (value & 3);
    r->c = (value & 3) >= 3;
    r->z = (value & 3) == 3;
    r->n = (uint8_t)((value & 3) - 3) & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5A07, 0xC75B48); GUARD_JSR(c, sp_call, 0x5A07); } /* read_native_saved_slot_character_first_statistic */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5A0A, 0xC75D17); GUARD_JSR(c, sp_call, 0x5A0A); } /* format_five_native_saved_slot_decimal_digits_via_hardware_division */
    uint8_t db_ret = r->db;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5A0D, 0xC75A1E); GUARD_JSR(c, sp_call, 0x5A0D); } /* append_three_native_saved_slot_decimal_digits */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret3 = r->y;
    BUS8_SET(c, (db_ret << 0x10) + 0x9C00 + x_ret4, 0xC1);
    if (x_ret3) {
        r->a = (a_all3 >> 8 << 8) | 0xC1;
        r->x = (uint8_t)((uint8_t)x_ret4 + 1);
        r->y = (uint8_t)y_ret3;
        r->z = (uint8_t)((uint8_t)x_ret4 + 1) == 0;
        r->n = (uint8_t)((uint8_t)x_ret4 + 1) & 0x80;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5A16, 0xC75B67); GUARD_JSR(c, sp_call, 0x5A16); } /* read_native_saved_slot_character_second_statistic */
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5A19, 0xC75D17); GUARD_JSR(c, sp_call, 0x5A19); } /* format_five_native_saved_slot_decimal_digits_via_hardware_division */
        uint8_t db_ret2 = r->db;
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5A1C, 0xC75A1E); GUARD_JSR(c, sp_call, 0x5A1C); } /* append_three_native_saved_slot_decimal_digits */
        bool m_ret = r->mf;
        bool x_ret7 = r->xf;
        uint16_t a_all6 = r->a;
        uint16_t x_ret8 = r->x;
        uint16_t y_ret6 = r->y;
        bool carry_ret6 = r->c;
        bool overflow_ret6 = r->v;
        if (m_ret) {
            if (x_ret7) {
                a_hi_5a1d2 = a_all6 >> 8;
                x_5a1d2 = (uint8_t)x_ret8;
                y_5a1d2 = (uint8_t)y_ret6;
                carry_5a1d2 = carry_ret6;
                overflow_5a1d2 = overflow_ret6;
                data_bank_5a1d2 = db_ret2;
                goto shared_5A1D_1;
            } else {
                a_hi_5a1d = a_all6 >> 8;
                x_5a1d = x_ret8;
                y_5a1d = y_ret6;
                carry_5a1d = carry_ret6;
                overflow_5a1d = overflow_ret6;
                data_bank_5a1d = db_ret2;
                goto shared_5A1D;
            }
        } else {
            if (x_ret7) {
                a_hi_5a1d3 = a_all6 >> 8;
                x_5a1d3 = (uint8_t)x_ret8;
                y_5a1d3 = (uint8_t)y_ret6;
                carry_5a1d3 = carry_ret6;
                overflow_5a1d3 = overflow_ret6;
                data_bank_5a1d3 = db_ret2;
                goto shared_5A1D_2;
            } else {
                a_hi_5a1d4 = a_all6 >> 8;
                x_5a1d4 = x_ret8;
                y_5a1d4 = y_ret6;
                carry_5a1d4 = carry_ret6;
                overflow_5a1d4 = overflow_ret6;
                data_bank_5a1d4 = db_ret2;
                goto shared_5A1D_3;
            }
        }
    } else {
        r->a = (a_all3 >> 8 << 8) | 0xC1;
        r->x = (uint16_t)(x_ret4 + 1);
        r->z = (uint16_t)(x_ret4 + 1) == 0;
        r->n = (uint16_t)(x_ret4 + 1) & 0x8000;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5A16, 0xC75B67); GUARD_JSR(c, sp_call, 0x5A16); } /* read_native_saved_slot_character_second_statistic */
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5A19, 0xC75D17); GUARD_JSR(c, sp_call, 0x5A19); } /* format_five_native_saved_slot_decimal_digits_via_hardware_division */
        uint8_t db_ret3 = r->db;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5A1C, 0xC75A1E); GUARD_JSR(c, sp_call, 0x5A1C); } /* append_three_native_saved_slot_decimal_digits */
        bool m_ret2 = r->mf;
        bool x_ret11 = r->xf;
        uint16_t a_all9 = r->a;
        uint16_t x_ret12 = r->x;
        uint16_t y_ret9 = r->y;
        bool carry_ret9 = r->c;
        bool overflow_ret9 = r->v;
        if (m_ret2) {
            if (x_ret11) {
                a_hi_5a1d2 = a_all9 >> 8;
                x_5a1d2 = (uint8_t)x_ret12;
                y_5a1d2 = (uint8_t)y_ret9;
                carry_5a1d2 = carry_ret9;
                overflow_5a1d2 = overflow_ret9;
                data_bank_5a1d2 = db_ret3;
                goto shared_5A1D_1;
            } else {
                a_hi_5a1d = a_all9 >> 8;
                x_5a1d = x_ret12;
                y_5a1d = y_ret9;
                carry_5a1d = carry_ret9;
                overflow_5a1d = overflow_ret9;
                data_bank_5a1d = db_ret3;
                goto shared_5A1D;
            }
        } else {
            if (x_ret11) {
                a_hi_5a1d3 = a_all9 >> 8;
                x_5a1d3 = (uint8_t)x_ret12;
                y_5a1d3 = (uint8_t)y_ret9;
                carry_5a1d3 = carry_ret9;
                overflow_5a1d3 = overflow_ret9;
                data_bank_5a1d3 = db_ret3;
                goto shared_5A1D_2;
            } else {
                a_hi_5a1d4 = a_all9 >> 8;
                x_5a1d4 = x_ret12;
                y_5a1d4 = y_ret9;
                carry_5a1d4 = carry_ret9;
                overflow_5a1d4 = overflow_ret9;
                data_bank_5a1d4 = db_ret3;
                goto shared_5A1D_3;
            }
        }
    }
    shared_5A1D:;
    r->a = (a_hi_5a1d << 8) | a;
    r->x = x_5a1d;
    r->y = y_5a1d;
    r->c = carry_5a1d;
    r->v = overflow_5a1d;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_5a1d;
    r->dp = 0;
    RETURN_RTS(c);
    shared_5A1D_1:;
    r->a = (a_hi_5a1d2 << 8) | a;
    r->x = x_5a1d2;
    r->y = y_5a1d2;
    r->c = carry_5a1d2;
    r->v = overflow_5a1d2;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_5a1d2;
    r->dp = 0;
    RETURN_RTS(c);
    shared_5A1D_2:;
    r->a = (a_hi_5a1d3 << 8) | a;
    r->x = x_5a1d3;
    r->y = y_5a1d3;
    r->c = carry_5a1d3;
    r->v = overflow_5a1d3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_5a1d3;
    r->dp = 0;
    RETURN_RTS(c);
    shared_5A1D_3:;
    r->a = (a_hi_5a1d4 << 8) | a;
    r->x = x_5a1d4;
    r->y = y_5a1d4;
    r->c = carry_5a1d4;
    r->v = overflow_5a1d4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_5a1d4;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC759FC, SOM_RTS, "gen", append_two_valid_native_saved_slot_statistics, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 34, 14)
