#include "som_c.h"

/* C02293 render_native_menu_description_with_alternating_rows   [class B, 193 bytes, 81 instructions]
 * Source: src/rom/render_native_menu_description_with_alternating_rows.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYC.
 */
static void render_native_menu_description_with_alternating_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a_hi_22d2 = 0;
    uint16_t x_22d2 = 0;
    uint16_t y_22d2 = 0;
    bool carry_22d2 = 0;
    bool overflow_22d2 = 0;
    uint16_t direct_page_22d2 = 0;
    uint8_t data_bank_22d2 = 0;
    uint8_t a_hi_2351 = 0;
    uint16_t x_2351 = 0;
    uint16_t y_2351 = 0;
    bool carry_2351 = 0;
    uint8_t a_hi_2330 = 0;
    uint8_t y_2330 = 0;
    bool carry_2330 = 0;
    bool overflow_2330 = 0;
    uint16_t direct_page_2330 = 0;
    uint8_t data_bank_2330 = 0;
    uint8_t a_hi_23302 = 0;
    uint16_t y_23302 = 0;
    bool carry_23302 = 0;
    bool overflow_23302 = 0;
    uint16_t direct_page_23302 = 0;
    uint8_t data_bank_23302 = 0;
    uint8_t a_hi_234a = 0;
    uint8_t x_234a = 0;
    uint8_t y_234a = 0;
    bool carry_234a = 0;
    bool overflow_234a = 0;
    uint16_t direct_page_234a = 0;
    uint8_t data_bank_234a = 0;
    uint8_t a_hi_234a2 = 0;
    uint16_t x_234a2 = 0;
    uint16_t y_234a2 = 0;
    bool carry_234a2 = 0;
    bool overflow_234a2 = 0;
    uint16_t direct_page_234a2 = 0;
    uint8_t data_bank_234a2 = 0;
    uint8_t a_hi_22d22 = 0;
    uint8_t x_22d22 = 0;
    uint8_t y_22d22 = 0;
    bool carry_22d22 = 0;
    bool overflow_22d22 = 0;
    uint16_t direct_page_22d22 = 0;
    uint8_t data_bank_22d22 = 0;
    uint8_t a_hi_23512 = 0;
    uint8_t x_23512 = 0;
    uint8_t y_23512 = 0;
    bool carry_23512 = 0;
    uint16_t direct_page_2351 = 0;
    uint8_t data_bank_2351 = 0;
    uint8_t a_hi_23513 = 0;
    uint16_t x_23513 = 0;
    uint16_t y_23513 = 0;
    bool carry_23513 = 0;
    uint16_t direct_page_23512 = 0;
    uint8_t data_bank_23512 = 0;
    RAM8(0xA163) = 0;
    RAM8(0x1D03) = 0xC0;
    RAM16_SET(0xA1A0, 0);
    uint16_t value = RAM16(0xA20F);
    if ((value & 0xFF) != 0xFF) {
        RAM16_SET(0xA173, value & 0xFF);
        uint16_t value2 = RAM16(0xA173);
        uint16_t value3 = BUS16(c, 0xC033B6 + (uint16_t)(((value & 0xFF) << 1) + value2));
        RAM16_SET(0x1D02, value3);
        uint16_t value4 = BUS16(c, 0xC033B5 + (uint16_t)(((value & 0xFF) << 1) + value2));
        RAM16_SET(0x1D01, value4);
        RAM8(0xA1C5) = 0;
        RAM8(0xA212) &= 0xFE;
        a_hi_22d2 = value4 >> 8;
        x_22d2 = (uint16_t)(((value & 0xFF) << 1) + value2);
        y_22d2 = y;
        carry_22d2 = ((value & 0xFF) << 1) + value2 > 0xFFFF;
        overflow_22d2 = ((((value & 0xFF) << 1) ^ (uint16_t)(((value & 0xFF) << 1) + value2)) & (value2 ^ (uint16_t)(((value & 0xFF) << 1) + value2)) & 0x8000) != 0;
        direct_page_22d2 = 0;
        data_bank_22d2 = 0x7E;
        goto shared_22D2;
    }
    a_hi_2351 = 0;
    x_2351 = x;
    y_2351 = y;
    carry_2351 = (value & 0xFF) >= 0xFF;
    r->a = (a_hi_2351 << 8) | a;
    r->x = x_2351;
    r->y = y_2351;
    r->c = carry_2351;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
    shared_22D2:;
    RAM8(0x1D00) = 0;
    r->a = (a_hi_22d2 << 8) | 0;
    r->x = x_22d2;
    r->y = y_22d2;
    r->c = carry_22d2;
    r->z = 1;
    r->n = 0;
    r->v = overflow_22d2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_22d2;
    r->dp = direct_page_22d2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x22DA, 0xC02354); GUARD_JSR(c, sp_call, 0x22DA); } /* decode_native_menu_font_stream_and_expand_double_rows */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0xA217);
    RAM8(0x0000 + sp0) = value6 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value6;
    BUS16_SET(c, (db_ret << 0x10) + 0xA18C, (uint16_t)((uint16_t)(value6 << 3) + 0x6000));
    uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0xA20A);
    if ((value7 & 0x10) == 0) {
        uint8_t value8 = RAM8(0x0000 + sp0 - 1);
        uint8_t value9 = RAM8(0x0000 + sp0);
        BUS16_SET(c, (db_ret << 0x10) + 0xA217, (uint16_t)(((value9 << 8) | value8) + 0x38));
        uint16_t value10 = BUS16_RDP(c, (db_ret << 0x10) + 0xA1A0);
        BUS16_SET(c, (db_ret << 0x10) + 0xA1A0, (uint16_t)(value10 + 1));
        if (((uint16_t)(value10 + 1) & 1) == 0) {
            if (x_ret) {
                a_hi_2330 = 0;
                y_2330 = (uint8_t)y_ret;
                carry_2330 = ((value9 << 8) | value8) + 0x38 > 0xFFFF;
                overflow_2330 = ((((value9 << 8) | value8) ^ (uint16_t)(((value9 << 8) | value8) + 0x38)) & ((uint16_t)(((value9 << 8) | value8) + 0x38) ^ 0x38) & 0x8000) != 0;
                direct_page_2330 = dp_ret;
                data_bank_2330 = db_ret;
                goto shared_2330;
            } else {
                a_hi_23302 = 0;
                y_23302 = y_ret;
                carry_23302 = ((value9 << 8) | value8) + 0x38 > 0xFFFF;
                overflow_23302 = ((((value9 << 8) | value8) ^ (uint16_t)(((value9 << 8) | value8) + 0x38)) & ((uint16_t)(((value9 << 8) | value8) + 0x38) ^ 0x38) & 0x8000) != 0;
                direct_page_23302 = dp_ret;
                data_bank_23302 = db_ret;
                goto shared_2330_1;
            }
        }
        uint16_t value11 = BUS16_RDP(c, (db_ret << 0x10) + 0xA217);
        BUS16_SET(c, (db_ret << 0x10) + 0xA217, (uint16_t)(value11 + 8));
        if (x_ret) {
            a_hi_2330 = (uint16_t)(value11 + 8) >> 8;
            y_2330 = (uint8_t)y_ret;
            carry_2330 = value11 + 8 > 0xFFFF;
            overflow_2330 = ((value11 ^ (uint16_t)(value11 + 8)) & ((uint16_t)(value11 + 8) ^ 8) & 0x8000) != 0;
            direct_page_2330 = dp_ret;
            data_bank_2330 = db_ret;
            goto shared_2330;
        } else {
            a_hi_23302 = (uint16_t)(value11 + 8) >> 8;
            y_23302 = y_ret;
            carry_23302 = value11 + 8 > 0xFFFF;
            overflow_23302 = ((value11 ^ (uint16_t)(value11 + 8)) & ((uint16_t)(value11 + 8) ^ 8) & 0x8000) != 0;
            direct_page_23302 = dp_ret;
            data_bank_23302 = db_ret;
            goto shared_2330_1;
        }
    }
    uint8_t value12 = RAM8(0x0000 + sp0 - 1);
    uint8_t value13 = RAM8(0x0000 + sp0);
    if (x_ret) {
        BUS16_SET(c, (db_ret << 0x10) + 0xA217, (uint16_t)(((value13 << 8) | value12) + 0x40));
        uint16_t value14 = BUS16_RDP(c, (db_ret << 0x10) + 0xA1A0);
        BUS16_SET(c, (db_ret << 0x10) + 0xA1A0, (uint16_t)(value14 + 1));
        if (((uint16_t)(value14 + 1) & 1) != 0) {
            a_hi_2330 = 0;
            y_2330 = (uint8_t)y_ret;
            carry_2330 = ((value13 << 8) | value12) + 0x40 > 0xFFFF;
            overflow_2330 = ((((value13 << 8) | value12) ^ (uint16_t)(((value13 << 8) | value12) + 0x40)) & ((uint16_t)(((value13 << 8) | value12) + 0x40) ^ 0x40) & 0x8000) != 0;
            direct_page_2330 = dp_ret;
            data_bank_2330 = db_ret;
            goto shared_2330;
        }
        BUS16_SET(c, (db_ret << 0x10) + 0xA217, (uint8_t)((value13 << 8) | value12) + 0x14);
        a_hi_2330 = (uint8_t)((value13 << 8) | value12) + 0x14 >> 8;
        y_2330 = (uint8_t)y_ret;
        carry_2330 = (uint8_t)((value13 << 8) | value12) + 0x14 > 0xFFFF;
        overflow_2330 = (((uint8_t)((value13 << 8) | value12) ^ (uint8_t)((value13 << 8) | value12) + 0x14) & ((uint8_t)((value13 << 8) | value12) + 0x14 ^ 0x14) & 0x8000) != 0;
        direct_page_2330 = dp_ret;
        data_bank_2330 = db_ret;
        goto shared_2330;
    } else {
        BUS16_SET(c, (db_ret << 0x10) + 0xA217, (uint16_t)(((value13 << 8) | value12) + 0x40));
        uint16_t value15 = BUS16_RDP(c, (db_ret << 0x10) + 0xA1A0);
        BUS16_SET(c, (db_ret << 0x10) + 0xA1A0, (uint16_t)(value15 + 1));
        if (((uint16_t)(value15 + 1) & 1) != 0) {
            a_hi_23302 = 0;
            y_23302 = y_ret;
            carry_23302 = ((value13 << 8) | value12) + 0x40 > 0xFFFF;
            overflow_23302 = ((((value13 << 8) | value12) ^ (uint16_t)(((value13 << 8) | value12) + 0x40)) & ((uint16_t)(((value13 << 8) | value12) + 0x40) ^ 0x40) & 0x8000) != 0;
            direct_page_23302 = dp_ret;
            data_bank_23302 = db_ret;
            goto shared_2330_1;
        }
        BUS16_SET(c, (db_ret << 0x10) + 0xA217, (uint16_t)(((value13 << 8) | value12) + 0x14));
        a_hi_23302 = (uint16_t)(((value13 << 8) | value12) + 0x14) >> 8;
        y_23302 = y_ret;
        carry_23302 = ((value13 << 8) | value12) + 0x14 > 0xFFFF;
        overflow_23302 = ((((value13 << 8) | value12) ^ (uint16_t)(((value13 << 8) | value12) + 0x14)) & ((uint16_t)(((value13 << 8) | value12) + 0x14) ^ 0x14) & 0x8000) != 0;
        direct_page_23302 = dp_ret;
        data_bank_23302 = db_ret;
        goto shared_2330_1;
    }
    shared_2330:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_2330_1:;
    BUS16_SET(c, (data_bank_23302 << 0x10) + 0xA191, 0x0400);
    r->x = 0x0400;
    r->y = y_23302;
    r->c = carry_23302;
    r->z = 0;
    r->n = 0;
    r->v = overflow_23302;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_23302;
    r->dp = direct_page_23302;
    { const uint16_t sp_call = r->sp; JSR(c, 0x233A, 0xC023BA); GUARD_JSR(c, sp_call, 0x233A); } /* upload_native_menu_assembled_text_tiles */
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t a_all2 = r->a;
    uint8_t value16 = BUS8_RDP(c, (data_bank_23302 << 0x10) + 0xA163);
    BUS8_SET(c, (data_bank_23302 << 0x10) + 0xA163, (uint8_t)(value16 + 1));
    uint8_t value17 = BUS8_RDP(c, (data_bank_23302 << 0x10) + 0xA163);
    if (value17 != 0x10) {
        if (x_ret3) {
            a_hi_234a = a_all2 >> 8;
            x_234a = 0;
            y_234a = (uint8_t)y_23302;
            carry_234a = value17 >= 0x10;
            overflow_234a = overflow_23302;
            direct_page_234a = direct_page_23302;
            data_bank_234a = data_bank_23302;
            goto shared_234A;
        } else {
            a_hi_234a2 = a_all2 >> 8;
            x_234a2 = 0x0400;
            y_234a2 = y_23302;
            carry_234a2 = value17 >= 0x10;
            overflow_234a2 = overflow_23302;
            direct_page_234a2 = direct_page_23302;
            data_bank_234a2 = data_bank_23302;
            goto shared_234A_1;
        }
    }
    uint8_t value18 = BUS8_RDP(c, (data_bank_23302 << 0x10) + 0xA20A);
    BUS8_SET(c, (data_bank_23302 << 0x10) + 0xA20A, value18 & 0xEF);
    if (x_ret3) {
        a_hi_234a = a_all2 >> 8;
        x_234a = 0;
        y_234a = (uint8_t)y_23302;
        carry_234a = value17 >= 0x10;
        overflow_234a = overflow_23302;
        direct_page_234a = direct_page_23302;
        data_bank_234a = data_bank_23302;
        goto shared_234A;
    } else {
        a_hi_234a2 = a_all2 >> 8;
        x_234a2 = 0x0400;
        y_234a2 = y_23302;
        carry_234a2 = value17 >= 0x10;
        overflow_234a2 = overflow_23302;
        direct_page_234a2 = direct_page_23302;
        data_bank_234a2 = data_bank_23302;
        goto shared_234A_1;
    }
    shared_234A:;
    uint8_t value19 = BUS8_RDP(c, (data_bank_234a << 0x10) + 0xA212);
    if ((value19 & 1) == 0) {
        a_hi_22d22 = a_hi_234a;
        x_22d22 = x_234a;
        y_22d22 = y_234a;
        carry_22d22 = carry_234a;
        overflow_22d22 = overflow_234a;
        direct_page_22d22 = direct_page_234a;
        data_bank_22d22 = data_bank_234a;
        goto shared_22D2_1;
    }
    a_hi_23512 = a_hi_234a;
    x_23512 = x_234a;
    y_23512 = y_234a;
    carry_23512 = carry_234a;
    direct_page_2351 = direct_page_234a;
    data_bank_2351 = data_bank_234a;
    goto shared_2351_1;
    shared_234A_1:;
    uint8_t value20 = BUS8_RDP(c, (data_bank_234a2 << 0x10) + 0xA212);
    if ((value20 & 1) == 0) {
        a_hi_22d2 = a_hi_234a2;
        x_22d2 = x_234a2;
        y_22d2 = y_234a2;
        carry_22d2 = carry_234a2;
        overflow_22d2 = overflow_234a2;
        direct_page_22d2 = direct_page_234a2;
        data_bank_22d2 = data_bank_234a2;
        goto shared_22D2;
    }
    a_hi_23513 = a_hi_234a2;
    x_23513 = x_234a2;
    y_23513 = y_234a2;
    carry_23513 = carry_234a2;
    direct_page_23512 = direct_page_234a2;
    data_bank_23512 = data_bank_234a2;
    goto shared_2351_2;
    shared_22D2_1:;
    RAM8(0x1D00) = 0;
    r->a = (a_hi_22d22 << 8) | 0;
    r->x = x_22d22;
    r->y = y_22d22;
    r->c = carry_22d22;
    r->z = 1;
    r->n = 0;
    r->v = overflow_22d22;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_22d22;
    r->dp = direct_page_22d22;
    { const uint16_t sp_call = r->sp; JSR(c, 0x22DA, 0xC02354); GUARD_JSR(c, sp_call, 0x22DA); } /* decode_native_menu_font_stream_and_expand_double_rows */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool x_ret4 = r->xf;
    uint16_t y_ret2 = r->y;
    uint16_t value21 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA217);
    RAM8(0x0000 + sp0) = value21 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value21;
    BUS16_SET(c, (db_ret2 << 0x10) + 0xA18C, (uint16_t)((uint16_t)(value21 << 3) + 0x6000));
    uint16_t value22 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA20A);
    if ((value22 & 0x10) == 0) {
        uint8_t value23 = RAM8(0x0000 + sp0 - 1);
        uint8_t value24 = RAM8(0x0000 + sp0);
        BUS16_SET(c, (db_ret2 << 0x10) + 0xA217, (uint16_t)(((value24 << 8) | value23) + 0x38));
        uint16_t value25 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA1A0);
        BUS16_SET(c, (db_ret2 << 0x10) + 0xA1A0, (uint16_t)(value25 + 1));
        if (((uint16_t)(value25 + 1) & 1) == 0) {
            if (x_ret4) {
                a_hi_2330 = 0;
                y_2330 = (uint8_t)y_ret2;
                carry_2330 = ((value24 << 8) | value23) + 0x38 > 0xFFFF;
                overflow_2330 = ((((value24 << 8) | value23) ^ (uint16_t)(((value24 << 8) | value23) + 0x38)) & ((uint16_t)(((value24 << 8) | value23) + 0x38) ^ 0x38) & 0x8000) != 0;
                direct_page_2330 = dp_ret2;
                data_bank_2330 = db_ret2;
                goto shared_2330;
            } else {
                a_hi_23302 = 0;
                y_23302 = y_ret2;
                carry_23302 = ((value24 << 8) | value23) + 0x38 > 0xFFFF;
                overflow_23302 = ((((value24 << 8) | value23) ^ (uint16_t)(((value24 << 8) | value23) + 0x38)) & ((uint16_t)(((value24 << 8) | value23) + 0x38) ^ 0x38) & 0x8000) != 0;
                direct_page_23302 = dp_ret2;
                data_bank_23302 = db_ret2;
                goto shared_2330_1;
            }
        }
        uint16_t value26 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA217);
        BUS16_SET(c, (db_ret2 << 0x10) + 0xA217, (uint16_t)(value26 + 8));
        if (x_ret4) {
            a_hi_2330 = (uint16_t)(value26 + 8) >> 8;
            y_2330 = (uint8_t)y_ret2;
            carry_2330 = value26 + 8 > 0xFFFF;
            overflow_2330 = ((value26 ^ (uint16_t)(value26 + 8)) & ((uint16_t)(value26 + 8) ^ 8) & 0x8000) != 0;
            direct_page_2330 = dp_ret2;
            data_bank_2330 = db_ret2;
            goto shared_2330;
        } else {
            a_hi_23302 = (uint16_t)(value26 + 8) >> 8;
            y_23302 = y_ret2;
            carry_23302 = value26 + 8 > 0xFFFF;
            overflow_23302 = ((value26 ^ (uint16_t)(value26 + 8)) & ((uint16_t)(value26 + 8) ^ 8) & 0x8000) != 0;
            direct_page_23302 = dp_ret2;
            data_bank_23302 = db_ret2;
            goto shared_2330_1;
        }
    }
    uint8_t value27 = RAM8(0x0000 + sp0 - 1);
    uint8_t value28 = RAM8(0x0000 + sp0);
    if (x_ret4) {
        BUS16_SET(c, (db_ret2 << 0x10) + 0xA217, (uint16_t)(((value28 << 8) | value27) + 0x40));
        uint16_t value29 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA1A0);
        BUS16_SET(c, (db_ret2 << 0x10) + 0xA1A0, (uint16_t)(value29 + 1));
        if (((uint16_t)(value29 + 1) & 1) != 0) {
            a_hi_2330 = 0;
            y_2330 = (uint8_t)y_ret2;
            carry_2330 = ((value28 << 8) | value27) + 0x40 > 0xFFFF;
            overflow_2330 = ((((value28 << 8) | value27) ^ (uint16_t)(((value28 << 8) | value27) + 0x40)) & ((uint16_t)(((value28 << 8) | value27) + 0x40) ^ 0x40) & 0x8000) != 0;
            direct_page_2330 = dp_ret2;
            data_bank_2330 = db_ret2;
            goto shared_2330;
        }
        BUS16_SET(c, (db_ret2 << 0x10) + 0xA217, (uint8_t)((value28 << 8) | value27) + 0x14);
        a_hi_2330 = (uint8_t)((value28 << 8) | value27) + 0x14 >> 8;
        y_2330 = (uint8_t)y_ret2;
        carry_2330 = (uint8_t)((value28 << 8) | value27) + 0x14 > 0xFFFF;
        overflow_2330 = (((uint8_t)((value28 << 8) | value27) ^ (uint8_t)((value28 << 8) | value27) + 0x14) & ((uint8_t)((value28 << 8) | value27) + 0x14 ^ 0x14) & 0x8000) != 0;
        direct_page_2330 = dp_ret2;
        data_bank_2330 = db_ret2;
        goto shared_2330;
    } else {
        BUS16_SET(c, (db_ret2 << 0x10) + 0xA217, (uint16_t)(((value28 << 8) | value27) + 0x40));
        uint16_t value30 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA1A0);
        BUS16_SET(c, (db_ret2 << 0x10) + 0xA1A0, (uint16_t)(value30 + 1));
        if (((uint16_t)(value30 + 1) & 1) != 0) {
            a_hi_23302 = 0;
            y_23302 = y_ret2;
            carry_23302 = ((value28 << 8) | value27) + 0x40 > 0xFFFF;
            overflow_23302 = ((((value28 << 8) | value27) ^ (uint16_t)(((value28 << 8) | value27) + 0x40)) & ((uint16_t)(((value28 << 8) | value27) + 0x40) ^ 0x40) & 0x8000) != 0;
            direct_page_23302 = dp_ret2;
            data_bank_23302 = db_ret2;
            goto shared_2330_1;
        }
        BUS16_SET(c, (db_ret2 << 0x10) + 0xA217, (uint16_t)(((value28 << 8) | value27) + 0x14));
        a_hi_23302 = (uint16_t)(((value28 << 8) | value27) + 0x14) >> 8;
        y_23302 = y_ret2;
        carry_23302 = ((value28 << 8) | value27) + 0x14 > 0xFFFF;
        overflow_23302 = ((((value28 << 8) | value27) ^ (uint16_t)(((value28 << 8) | value27) + 0x14)) & ((uint16_t)(((value28 << 8) | value27) + 0x14) ^ 0x14) & 0x8000) != 0;
        direct_page_23302 = dp_ret2;
        data_bank_23302 = db_ret2;
        goto shared_2330_1;
    }
    shared_2351_1:;
    r->a = (a_hi_23512 << 8) | a;
    r->x = x_23512;
    r->y = y_23512;
    r->c = carry_23512;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_2351;
    r->dp = direct_page_2351;
    RETURN_RTS(c);
    shared_2351_2:;
    r->a = (a_hi_23513 << 8) | a;
    r->x = x_23513;
    r->y = y_23513;
    r->c = carry_23513;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_23512;
    r->dp = direct_page_23512;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02293, SOM_RTS, "gen", render_native_menu_description_with_alternating_rows, 0, L_B | L_X | L_Y | L_C, 2, 1, 0, 193, 81)
