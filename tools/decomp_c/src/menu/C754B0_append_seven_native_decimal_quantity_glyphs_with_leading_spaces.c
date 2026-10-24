#include "som_c.h"

/* C754B0 append_seven_native_decimal_quantity_glyphs_with_leading_spaces   [class B, 43 bytes, 27 instructions]
 * Source: src/rom/append_seven_native_decimal_quantity_glyphs_with_leading_spaces.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZV.
 */
static void append_seven_native_decimal_quantity_glyphs_with_leading_spaces(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint8_t a_54b5 = 0;
    uint8_t a_hi_54b5 = 0;
    uint16_t x_54b5 = 0;
    uint16_t y_54b5 = 0;
    bool overflow_54b5 = 0;
    uint16_t direct_page_54b5 = 0;
    uint8_t data_bank_54b5 = 0;
    uint8_t a_54c7 = 0;
    uint8_t a_hi_54c7 = 0;
    uint16_t x_54c7 = 0;
    uint16_t y_54c7 = 0;
    uint16_t direct_page_54c7 = 0;
    uint8_t data_bank_54c7 = 0;
    uint8_t a_54b52 = 0;
    uint8_t a_hi_54b52 = 0;
    uint8_t x_54b52 = 0;
    uint8_t y_54b52 = 0;
    bool overflow_54b52 = 0;
    uint16_t direct_page_54b52 = 0;
    uint8_t data_bank_54b52 = 0;
    uint8_t a_54c72 = 0;
    uint8_t a_hi_54c72 = 0;
    uint8_t x_54c72 = 0;
    uint8_t y_54c72 = 0;
    uint16_t direct_page_54c72 = 0;
    uint8_t data_bank_54c72 = 0;
    uint8_t a_54b53 = 0;
    uint8_t a_hi_54b53 = 0;
    uint8_t x_54b53 = 0;
    uint8_t y_54b53 = 0;
    bool overflow_54b53 = 0;
    uint16_t direct_page_54b53 = 0;
    uint8_t data_bank_54b53 = 0;
    uint8_t a_54b54 = 0;
    uint8_t a_hi_54b54 = 0;
    uint16_t x_54b54 = 0;
    uint16_t y_54b54 = 0;
    bool overflow_54b54 = 0;
    uint16_t direct_page_54b54 = 0;
    uint8_t data_bank_54b54 = 0;
    uint8_t a_54c73 = 0;
    uint8_t a_hi_54c73 = 0;
    uint8_t x_54c73 = 0;
    uint8_t y_54c73 = 0;
    uint16_t direct_page_54c73 = 0;
    uint8_t data_bank_54c73 = 0;
    uint8_t a_54c74 = 0;
    uint8_t a_hi_54c74 = 0;
    uint16_t x_54c74 = 0;
    uint16_t y_54c74 = 0;
    uint16_t direct_page_54c74 = 0;
    uint8_t data_bank_54c74 = 0;
    uint8_t a_54ca = 0;
    uint8_t a_hi_54ca = 0;
    uint16_t x_54ca = 0;
    uint16_t y_54ca = 0;
    uint16_t direct_page_54ca = 0;
    uint8_t data_bank_54ca = 0;
    uint8_t a_54ca2 = 0;
    uint8_t a_hi_54ca2 = 0;
    uint8_t x_54ca2 = 0;
    uint8_t y_54ca2 = 0;
    uint16_t direct_page_54ca2 = 0;
    uint8_t data_bank_54ca2 = 0;
    uint8_t a_54ca3 = 0;
    uint8_t a_hi_54ca3 = 0;
    uint8_t x_54ca3 = 0;
    uint8_t y_54ca3 = 0;
    uint16_t direct_page_54ca3 = 0;
    uint8_t data_bank_54ca3 = 0;
    uint8_t a_54ca4 = 0;
    uint8_t a_hi_54ca4 = 0;
    uint16_t x_54ca4 = 0;
    uint16_t y_54ca4 = 0;
    uint16_t direct_page_54ca4 = 0;
    uint8_t data_bank_54ca4 = 0;
    a_54b5 = 6;
    a_hi_54b5 = a_hi;
    x_54b5 = x;
    y_54b5 = 0;
    overflow_54b5 = overflow;
    direct_page_54b5 = dp;
    data_bank_54b5 = 0x7E;
    shared_54B5:;
    uint8_t value = BUS8_RDP(c, (data_bank_54b5 << 0x10) + 0xA136 + y_54b5);
    if (value != 0) {
        a_54c7 = value;
        a_hi_54c7 = a_54b5;
        x_54c7 = x_54b5;
        y_54c7 = (uint16_t)(y_54b5 + 1);
        direct_page_54c7 = direct_page_54b5;
        data_bank_54c7 = data_bank_54b5;
        goto shared_54C7;
    }
    r->a = (a_54b5 << 8) | value;
    r->x = x_54b5;
    r->y = (uint16_t)(y_54b5 + 1);
    r->c = value >= 0;
    r->v = overflow_54b5;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_54b5;
    r->dp = direct_page_54b5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x54C0, 0xC75389); GUARD_JSR(c, sp_call, 0x54C0); } /* append_native_saved_slot_text_space_token */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (m_ret) {
        if ((uint8_t)((a_all >> 8) - 1) != 0) {
            if (x_ret) {
                a_54b52 = (uint8_t)((a_all >> 8) - 1);
                a_hi_54b52 = (uint8_t)a_all;
                x_54b52 = (uint8_t)x_ret2;
                y_54b52 = (uint8_t)(y_54b5 + 1);
                overflow_54b52 = overflow_54b5;
                direct_page_54b52 = dp_ret;
                data_bank_54b52 = db_ret;
                goto shared_54B5_1;
            } else {
                a_54b5 = (uint8_t)((a_all >> 8) - 1);
                a_hi_54b5 = (uint8_t)a_all;
                x_54b5 = x_ret2;
                y_54b5 = (uint16_t)(y_54b5 + 1);
                direct_page_54b5 = dp_ret;
                data_bank_54b5 = db_ret;
                goto shared_54B5;
            }
        }
        if (x_ret) {
            a_54c72 = (uint8_t)a_all;
            a_hi_54c72 = (uint8_t)((a_all >> 8) - 1);
            x_54c72 = (uint8_t)x_ret2;
            y_54c72 = (uint8_t)(y_54b5 + 2);
            direct_page_54c72 = dp_ret;
            data_bank_54c72 = db_ret;
            goto shared_54C7_1;
        } else {
            a_54c7 = (uint8_t)a_all;
            a_hi_54c7 = (uint8_t)((a_all >> 8) - 1);
            x_54c7 = x_ret2;
            y_54c7 = (uint16_t)(y_54b5 + 2);
            direct_page_54c7 = dp_ret;
            data_bank_54c7 = db_ret;
            goto shared_54C7;
        }
    } else {
        if ((uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) - 1) != 0) {
            if (x_ret) {
                a_54b53 = (uint8_t)((((uint8_t)a_all << 8) | (a_all >> 8)) - 1);
                a_hi_54b53 = (uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) - 1) >> 8;
                x_54b53 = (uint8_t)x_ret2;
                y_54b53 = (uint8_t)(y_54b5 + 1);
                overflow_54b53 = overflow_54b5;
                direct_page_54b53 = dp_ret;
                data_bank_54b53 = db_ret;
                goto shared_54B5_2;
            } else {
                a_54b54 = (uint8_t)((((uint8_t)a_all << 8) | (a_all >> 8)) - 1);
                a_hi_54b54 = (uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) - 1) >> 8;
                x_54b54 = x_ret2;
                y_54b54 = (uint16_t)(y_54b5 + 1);
                overflow_54b54 = overflow_54b5;
                direct_page_54b54 = dp_ret;
                data_bank_54b54 = db_ret;
                goto shared_54B5_3;
            }
        }
        if (x_ret) {
            a_54c73 = (uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) - 1) >> 8;
            a_hi_54c73 = (uint8_t)((((uint8_t)a_all << 8) | (a_all >> 8)) - 1);
            x_54c73 = (uint8_t)x_ret2;
            y_54c73 = (uint8_t)(y_54b5 + 2);
            direct_page_54c73 = dp_ret;
            data_bank_54c73 = db_ret;
            goto shared_54C7_2;
        } else {
            a_54c74 = (uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) - 1) >> 8;
            a_hi_54c74 = (uint8_t)((((uint8_t)a_all << 8) | (a_all >> 8)) - 1);
            x_54c74 = x_ret2;
            y_54c74 = (uint16_t)(y_54b5 + 2);
            direct_page_54c74 = dp_ret;
            data_bank_54c74 = db_ret;
            goto shared_54C7_3;
        }
    }
    shared_54C7:;
    a_54ca = (uint8_t)(a_hi_54c7 + 1);
    a_hi_54ca = a_54c7;
    x_54ca = x_54c7;
    y_54ca = (uint16_t)(y_54c7 - 1);
    direct_page_54ca = direct_page_54c7;
    data_bank_54ca = data_bank_54c7;
    goto shared_54CA;
    shared_54B5_1:;
    uint8_t value2 = BUS8_RDP(c, (data_bank_54b52 << 0x10) + 0xA136 + y_54b52);
    if (value2 != 0) {
        a_54c72 = value2;
        a_hi_54c72 = a_54b52;
        x_54c72 = x_54b52;
        y_54c72 = (uint8_t)(y_54b52 + 1);
        direct_page_54c72 = direct_page_54b52;
        data_bank_54c72 = data_bank_54b52;
        goto shared_54C7_1;
    }
    r->a = (a_54b52 << 8) | value2;
    r->x = x_54b52;
    r->y = (uint8_t)(y_54b52 + 1);
    r->c = value2 >= 0;
    r->v = overflow_54b52;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_54b52;
    r->dp = direct_page_54b52;
    { const uint16_t sp_call = r->sp; JSR(c, 0x54C0, 0xC75389); GUARD_JSR(c, sp_call, 0x54C0); } /* append_native_saved_slot_text_space_token */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret4 = r->x;
    if (m_ret2) {
        if ((uint8_t)((a_all2 >> 8) - 1) != 0) {
            if (x_ret3) {
                a_54b52 = (uint8_t)((a_all2 >> 8) - 1);
                a_hi_54b52 = (uint8_t)a_all2;
                x_54b52 = (uint8_t)x_ret4;
                y_54b52 = (uint8_t)(y_54b52 + 1);
                direct_page_54b52 = dp_ret2;
                data_bank_54b52 = db_ret2;
                goto shared_54B5_1;
            } else {
                a_54b5 = (uint8_t)((a_all2 >> 8) - 1);
                a_hi_54b5 = (uint8_t)a_all2;
                x_54b5 = x_ret4;
                y_54b5 = (uint8_t)(y_54b52 + 1);
                overflow_54b5 = overflow_54b52;
                direct_page_54b5 = dp_ret2;
                data_bank_54b5 = db_ret2;
                goto shared_54B5;
            }
        }
        if (x_ret3) {
            a_54c72 = (uint8_t)a_all2;
            a_hi_54c72 = (uint8_t)((a_all2 >> 8) - 1);
            x_54c72 = (uint8_t)x_ret4;
            y_54c72 = (uint8_t)(y_54b52 + 2);
            direct_page_54c72 = dp_ret2;
            data_bank_54c72 = db_ret2;
            goto shared_54C7_1;
        } else {
            a_54c7 = (uint8_t)a_all2;
            a_hi_54c7 = (uint8_t)((a_all2 >> 8) - 1);
            x_54c7 = x_ret4;
            y_54c7 = (uint8_t)(y_54b52 + 1) + 1;
            direct_page_54c7 = dp_ret2;
            data_bank_54c7 = db_ret2;
            goto shared_54C7;
        }
    } else {
        if ((uint16_t)((((uint8_t)a_all2 << 8) | (a_all2 >> 8)) - 1) != 0) {
            if (x_ret3) {
                a_54b53 = (uint8_t)((((uint8_t)a_all2 << 8) | (a_all2 >> 8)) - 1);
                a_hi_54b53 = (uint16_t)((((uint8_t)a_all2 << 8) | (a_all2 >> 8)) - 1) >> 8;
                x_54b53 = (uint8_t)x_ret4;
                y_54b53 = (uint8_t)(y_54b52 + 1);
                overflow_54b53 = overflow_54b52;
                direct_page_54b53 = dp_ret2;
                data_bank_54b53 = db_ret2;
                goto shared_54B5_2;
            } else {
                a_54b54 = (uint8_t)((((uint8_t)a_all2 << 8) | (a_all2 >> 8)) - 1);
                a_hi_54b54 = (uint16_t)((((uint8_t)a_all2 << 8) | (a_all2 >> 8)) - 1) >> 8;
                x_54b54 = x_ret4;
                y_54b54 = (uint8_t)(y_54b52 + 1);
                overflow_54b54 = overflow_54b52;
                direct_page_54b54 = dp_ret2;
                data_bank_54b54 = db_ret2;
                goto shared_54B5_3;
            }
        }
        if (x_ret3) {
            a_54c73 = (uint16_t)((((uint8_t)a_all2 << 8) | (a_all2 >> 8)) - 1) >> 8;
            a_hi_54c73 = (uint8_t)((((uint8_t)a_all2 << 8) | (a_all2 >> 8)) - 1);
            x_54c73 = (uint8_t)x_ret4;
            y_54c73 = (uint8_t)(y_54b52 + 2);
            direct_page_54c73 = dp_ret2;
            data_bank_54c73 = db_ret2;
            goto shared_54C7_2;
        } else {
            a_54c74 = (uint16_t)((((uint8_t)a_all2 << 8) | (a_all2 >> 8)) - 1) >> 8;
            a_hi_54c74 = (uint8_t)((((uint8_t)a_all2 << 8) | (a_all2 >> 8)) - 1);
            x_54c74 = x_ret4;
            y_54c74 = (uint8_t)(y_54b52 + 1) + 1;
            direct_page_54c74 = dp_ret2;
            data_bank_54c74 = db_ret2;
            goto shared_54C7_3;
        }
    }
    shared_54C7_1:;
    a_54ca2 = (uint8_t)(a_hi_54c72 + 1);
    a_hi_54ca2 = a_54c72;
    x_54ca2 = x_54c72;
    y_54ca2 = (uint8_t)(y_54c72 - 1);
    direct_page_54ca2 = direct_page_54c72;
    data_bank_54ca2 = data_bank_54c72;
    goto shared_54CA_1;
    shared_54B5_2:;
    uint16_t value3 = BUS16_RDP(c, (data_bank_54b53 << 0x10) + 0xA136 + y_54b53);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_54B5_3:;
    uint16_t value4 = BUS16_RDP(c, (data_bank_54b54 << 0x10) + 0xA136 + y_54b54);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_54C7_2:;
    a_54ca3 = (uint8_t)(((a_54c73 << 8) | a_hi_54c73) + 1);
    a_hi_54ca3 = (uint16_t)(((a_54c73 << 8) | a_hi_54c73) + 1) >> 8;
    x_54ca3 = x_54c73;
    y_54ca3 = (uint8_t)(y_54c73 - 1);
    direct_page_54ca3 = direct_page_54c73;
    data_bank_54ca3 = data_bank_54c73;
    goto shared_54CA_2;
    shared_54C7_3:;
    a_54ca4 = (uint8_t)(((a_54c74 << 8) | a_hi_54c74) + 1);
    a_hi_54ca4 = (uint16_t)(((a_54c74 << 8) | a_hi_54c74) + 1) >> 8;
    x_54ca4 = x_54c74;
    y_54ca4 = (uint16_t)(y_54c74 - 1);
    direct_page_54ca4 = direct_page_54c74;
    data_bank_54ca4 = data_bank_54c74;
    goto shared_54CA_3;
    shared_54CA:;
    uint8_t value5 = BUS8_RDP(c, (data_bank_54ca << 0x10) + 0xA136 + y_54ca);
    BUS8_SET(c, (data_bank_54ca << 0x10) + 0x9C00 + x_54ca, (uint8_t)(value5 + 0xB5));
    if ((uint8_t)(a_54ca - 1) != 0) {
        a_54ca = (uint8_t)(a_54ca - 1);
        a_hi_54ca = (uint8_t)(value5 + 0xB5);
        x_54ca = (uint16_t)(x_54ca + 1);
        y_54ca = (uint16_t)(y_54ca + 1);
        goto shared_54CA;
    }
    r->a = ((uint8_t)(value5 + 0xB5) << 8) | (uint8_t)(a_54ca - 1);
    r->x = (uint16_t)(x_54ca + 1);
    r->y = (uint16_t)(y_54ca + 1);
    r->c = value5 + 0xB5 > 0xFF;
    r->z = (uint8_t)(a_54ca - 1) == 0;
    r->v = ((value5 ^ (uint8_t)(value5 + 0xB5)) & ((uint8_t)(value5 + 0xB5) ^ 0xB5) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_54ca;
    r->dp = direct_page_54ca;
    RETURN_RTS(c);
    shared_54CA_1:;
    uint8_t value6 = BUS8_RDP(c, (data_bank_54ca2 << 0x10) + 0xA136 + y_54ca2);
    BUS8_SET(c, (data_bank_54ca2 << 0x10) + 0x9C00 + x_54ca2, (uint8_t)(value6 + 0xB5));
    if ((uint8_t)(a_54ca2 - 1) != 0) {
        a_54ca2 = (uint8_t)(a_54ca2 - 1);
        a_hi_54ca2 = (uint8_t)(value6 + 0xB5);
        x_54ca2 = (uint8_t)(x_54ca2 + 1);
        y_54ca2 = (uint8_t)(y_54ca2 + 1);
        goto shared_54CA_1;
    }
    r->a = ((uint8_t)(value6 + 0xB5) << 8) | (uint8_t)(a_54ca2 - 1);
    r->x = (uint8_t)(x_54ca2 + 1);
    r->y = (uint8_t)(y_54ca2 + 1);
    r->c = value6 + 0xB5 > 0xFF;
    r->z = (uint8_t)(a_54ca2 - 1) == 0;
    r->v = ((value6 ^ (uint8_t)(value6 + 0xB5)) & ((uint8_t)(value6 + 0xB5) ^ 0xB5) & 0x80) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_54ca2;
    r->dp = direct_page_54ca2;
    RETURN_RTS(c);
    shared_54CA_2:;
    uint16_t value7 = BUS16_RDP(c, (data_bank_54ca3 << 0x10) + 0xA136 + y_54ca3);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_54CA_3:;
    uint16_t value8 = BUS16_RDP(c, (data_bank_54ca4 << 0x10) + 0xA136 + y_54ca4);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0xC754B0, SOM_RTS, "gen", append_seven_native_decimal_quantity_glyphs_with_leading_spaces, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 43, 27)
