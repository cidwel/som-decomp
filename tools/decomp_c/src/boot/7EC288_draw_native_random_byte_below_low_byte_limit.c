#include "som_c.h"

/* 7EC288 draw_native_random_byte_below_low_byte_limit   [class B, 81 bytes, 50 instructions]
 * Source: src/boot/draw_native_random_byte_below_low_byte_limit.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$02DB.  Callers read: ABXYCV.
 */
static void draw_native_random_byte_below_low_byte_limit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x02DB) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_c2a9 = 0;
    uint8_t a_hi_c2a9 = 0;
    uint16_t x_c2a9 = 0;
    uint16_t y_c2a9 = 0;
    bool carry_c2a9 = 0;
    bool overflow_c2a9 = 0;
    uint16_t direct_page_c2a9 = 0;
    uint8_t a_c2cd = 0;
    uint8_t a_hi_c2cd = 0;
    uint16_t x_c2cd = 0;
    uint16_t y_c2cd = 0;
    uint16_t direct_page_c2cd = 0;
    uint8_t data_bank_c2cd = 0;
    uint8_t a_c2be = 0;
    uint8_t a_hi_c2be = 0;
    uint16_t x_c2be = 0;
    uint16_t y_c2be = 0;
    bool overflow_c2be = 0;
    uint16_t direct_page_c2be = 0;
    uint8_t a_c2c4 = 0;
    uint8_t a_hi_c2c4 = 0;
    uint16_t x_c2c4 = 0;
    uint16_t y_c2c4 = 0;
    bool carry_c2c4 = 0;
    bool zero_c2c4 = 0;
    bool negative_c2c4 = 0;
    bool overflow_c2c4 = 0;
    uint16_t direct_page_c2c4 = 0;
    uint8_t data_bank_c2c4 = 0;
    uint8_t a_c2c42 = 0;
    uint8_t a_hi_c2c42 = 0;
    uint8_t x_c2c42 = 0;
    uint8_t y_c2c42 = 0;
    bool carry_c2c42 = 0;
    bool zero_c2c42 = 0;
    bool negative_c2c42 = 0;
    bool overflow_c2c42 = 0;
    uint16_t direct_page_c2c42 = 0;
    uint8_t data_bank_c2c42 = 0;
    uint8_t a_c2c43 = 0;
    uint8_t a_hi_c2c43 = 0;
    uint16_t x_c2c43 = 0;
    uint16_t y_c2c43 = 0;
    bool carry_c2c43 = 0;
    bool zero_c2c43 = 0;
    bool negative_c2c43 = 0;
    bool overflow_c2c43 = 0;
    uint16_t direct_page_c2c43 = 0;
    uint8_t data_bank_c2c43 = 0;
    uint8_t a_c2cd2 = 0;
    uint8_t a_hi_c2cd2 = 0;
    uint8_t x_c2cd2 = 0;
    uint8_t y_c2cd2 = 0;
    uint16_t direct_page_c2cd2 = 0;
    uint8_t data_bank_c2cd2 = 0;
    uint8_t a_c2cd3 = 0;
    uint8_t a_hi_c2cd3 = 0;
    uint16_t x_c2cd3 = 0;
    uint16_t y_c2cd3 = 0;
    uint16_t direct_page_c2cd3 = 0;
    uint8_t data_bank_c2cd3 = 0;
    uint8_t a_c2c44 = 0;
    uint8_t a_hi_c2c44 = 0;
    uint8_t x_c2c44 = 0;
    uint8_t y_c2c44 = 0;
    bool carry_c2c44 = 0;
    bool zero_c2c44 = 0;
    bool negative_c2c44 = 0;
    bool overflow_c2c44 = 0;
    uint16_t direct_page_c2c44 = 0;
    uint8_t data_bank_c2c44 = 0;
    uint8_t a_c2cd4 = 0;
    uint8_t a_hi_c2cd4 = 0;
    uint8_t x_c2cd4 = 0;
    uint8_t y_c2cd4 = 0;
    uint16_t direct_page_c2cd4 = 0;
    uint8_t data_bank_c2cd4 = 0;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xDB;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 9) = 0x7F;
    if ((value & 0xFF) != 0) {
        a_c2a9 = value & 0xFF;
        a_hi_c2a9 = 0;
        x_c2a9 = x;
        y_c2a9 = y;
        carry_c2a9 = (uint16_t)(sp0 - 5) >= 2;
        overflow_c2a9 = (((uint16_t)(sp0 - 5) ^ 2) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
        direct_page_c2a9 = (uint16_t)(sp0 - 7);
        goto shared_C2A9;
    }
    a_c2a9 = 0;
    a_hi_c2a9 = 1;
    x_c2a9 = x;
    y_c2a9 = y;
    carry_c2a9 = (uint16_t)(sp0 - 5) >= 2;
    overflow_c2a9 = (((uint16_t)(sp0 - 5) ^ 2) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    direct_page_c2a9 = (uint16_t)(sp0 - 7);
    shared_C2A9:;
    BUS16_SET(c, (uint16_t)(direct_page_c2a9 + 1), (a_hi_c2a9 << 8) | a_c2a9);
    if ((uint16_t)(((a_hi_c2a9 << 8) | a_c2a9) - 1) == 0) {
        a_c2cd = (uint8_t)(((a_hi_c2a9 << 8) | a_c2a9) - 1);
        a_hi_c2cd = (uint16_t)(((a_hi_c2a9 << 8) | a_c2a9) - 1) >> 8;
        x_c2cd = x_c2a9;
        y_c2cd = y_c2a9;
        direct_page_c2cd = direct_page_c2a9;
        data_bank_c2cd = 0x7F;
        goto shared_C2CD;
    }
    r->a = (uint16_t)(((a_hi_c2a9 << 8) | a_c2a9) - 1);
    r->x = (uint16_t)(((a_hi_c2a9 << 8) | a_c2a9) - 1);
    r->y = y_c2a9;
    r->c = carry_c2a9;
    r->z = (uint16_t)(((a_hi_c2a9 << 8) | a_c2a9) - 1) == 0;
    r->n = (uint16_t)(((a_hi_c2a9 << 8) | a_c2a9) - 1) & 0x8000;
    r->v = overflow_c2a9;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7F;
    r->dp = direct_page_c2a9;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC2B1, 0x7EC365); GUARD_JSR(c, sp_call, 0xC2B1); } /* find_native_highest_set_bit_or_byte_ff */
    r->sp += 8;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    a_c2be = 0xFF;
    a_hi_c2be = 1;
    x_c2be = x_ret;
    y_c2be = (uint16_t)(((uint16_t)(a_all - 8) ^ 0xFFFF) + 1);
    overflow_c2be = ((a_all ^ 8) & (a_all ^ (uint16_t)(a_all - 8)) & 0x8000) != 0;
    direct_page_c2be = direct_page_c2a9;
    goto shared_C2BE;
    shared_C2CD:;
    uint8_t value2 = RAM8(0x0000 + sp0 - 7);
    RAM8(0x0000 + sp0 - 3) = a_c2cd;
    uint8_t value6 = RAM8(0x0000 + sp0 - 3);
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi_c2cd << 8) | value6;
    r->x = x_c2cd;
    r->y = y_c2cd;
    r->c = value7 & 0x01;
    r->v = value7 & 0x40;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->db = value2;
    r->dp = (value9 << 8) | value8;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_C2BE:;
    if ((uint16_t)(y_c2be - 1) != 0) {
        uint8_t a_c2be_next = (uint8_t)(((a_hi_c2be << 8) | a_c2be) >> 1);
        uint8_t a_hi_c2be_next = ((a_hi_c2be << 8) | a_c2be) >> 1 >> 8;
        uint16_t y_c2be_next = (uint16_t)(y_c2be - 1);
        a_c2be = a_c2be_next;
        a_hi_c2be = a_hi_c2be_next;
        y_c2be = y_c2be_next;
        goto shared_C2BE;
    }
    BUS16_SET(c, (uint16_t)(direct_page_c2be + 3), ((a_hi_c2be << 8) | a_c2be) >> 1);
    a_c2c4 = (uint8_t)(((a_hi_c2be << 8) | a_c2be) >> 1);
    a_hi_c2c4 = ((a_hi_c2be << 8) | a_c2be) >> 1 >> 8;
    x_c2c4 = x_c2be;
    y_c2c4 = (uint16_t)(y_c2be - 1);
    carry_c2c4 = ((a_hi_c2be << 8) | a_c2be) & 0x01;
    zero_c2c4 = (uint16_t)(y_c2be - 1) == 0;
    negative_c2c4 = (uint16_t)(y_c2be - 1) & 0x8000;
    overflow_c2c4 = overflow_c2be;
    direct_page_c2c4 = direct_page_c2be;
    data_bank_c2c4 = 0x7F;
    goto shared_C2C4;
    shared_C2C4:;
    r->a = (a_hi_c2c4 << 8) | a_c2c4;
    r->x = x_c2c4;
    r->y = y_c2c4;
    r->c = carry_c2c4;
    r->z = zero_c2c4;
    r->n = negative_c2c4;
    r->v = overflow_c2c4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_c2c4;
    r->dp = direct_page_c2c4;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC2C6, 0x7EC25B); GUARD_JSR(c, sp_call, 0xC2C6); } /* advance_native_fifteen_byte_subtractive_random_ring */
    r->sp += 8;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret2 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret = r->y;
    bool overflow_ret2 = r->v;
    if (m_ret) {
        uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret + 3));
        uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        if (((uint8_t)a_all2 & value10) >= value11) {
            if (x_ret2) {
                a_c2c42 = (uint8_t)a_all2 & value10;
                a_hi_c2c42 = a_all2 >> 8;
                x_c2c42 = (uint8_t)x_ret3;
                y_c2c42 = (uint8_t)y_ret;
                carry_c2c42 = ((uint8_t)a_all2 & value10) >= value11;
                zero_c2c42 = ((uint8_t)a_all2 & value10) == value11;
                negative_c2c42 = (uint8_t)(((uint8_t)a_all2 & value10) - value11) & 0x80;
                overflow_c2c42 = overflow_ret2;
                direct_page_c2c42 = dp_ret;
                data_bank_c2c42 = db_ret;
                goto shared_C2C4_1;
            } else {
                a_c2c43 = (uint8_t)a_all2 & value10;
                a_hi_c2c43 = a_all2 >> 8;
                x_c2c43 = x_ret3;
                y_c2c43 = y_ret;
                carry_c2c43 = ((uint8_t)a_all2 & value10) >= value11;
                zero_c2c43 = ((uint8_t)a_all2 & value10) == value11;
                negative_c2c43 = (uint8_t)(((uint8_t)a_all2 & value10) - value11) & 0x80;
                overflow_c2c43 = overflow_ret2;
                direct_page_c2c43 = dp_ret;
                data_bank_c2c43 = db_ret;
                goto shared_C2C4_2;
            }
        }
        if (x_ret2) {
            a_c2cd2 = (uint8_t)a_all2 & value10;
            a_hi_c2cd2 = a_all2 >> 8;
            x_c2cd2 = (uint8_t)x_ret3;
            y_c2cd2 = (uint8_t)y_ret;
            direct_page_c2cd2 = dp_ret;
            data_bank_c2cd2 = db_ret;
            goto shared_C2CD_1;
        } else {
            a_c2cd3 = (uint8_t)a_all2 & value10;
            a_hi_c2cd3 = a_all2 >> 8;
            x_c2cd3 = x_ret3;
            y_c2cd3 = y_ret;
            direct_page_c2cd3 = dp_ret;
            data_bank_c2cd3 = db_ret;
            goto shared_C2CD_2;
        }
    } else {
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        if ((a_all2 & value12) >= value13) {
            if (x_ret2) {
                a_c2c44 = (uint8_t)(a_all2 & value12);
                a_hi_c2c44 = (a_all2 & value12) >> 8;
                x_c2c44 = (uint8_t)x_ret3;
                y_c2c44 = (uint8_t)y_ret;
                carry_c2c44 = (a_all2 & value12) >= value13;
                zero_c2c44 = (a_all2 & value12) == value13;
                negative_c2c44 = (uint16_t)((a_all2 & value12) - value13) & 0x8000;
                overflow_c2c44 = overflow_ret2;
                direct_page_c2c44 = dp_ret;
                data_bank_c2c44 = db_ret;
                goto shared_C2C4_3;
            } else {
                a_c2c4 = (uint8_t)(a_all2 & value12);
                a_hi_c2c4 = (a_all2 & value12) >> 8;
                x_c2c4 = x_ret3;
                y_c2c4 = y_ret;
                carry_c2c4 = (a_all2 & value12) >= value13;
                zero_c2c4 = (a_all2 & value12) == value13;
                negative_c2c4 = (uint16_t)((a_all2 & value12) - value13) & 0x8000;
                overflow_c2c4 = overflow_ret2;
                direct_page_c2c4 = dp_ret;
                data_bank_c2c4 = db_ret;
                goto shared_C2C4;
            }
        }
        if (x_ret2) {
            a_c2cd4 = (uint8_t)(a_all2 & value12);
            a_hi_c2cd4 = (a_all2 & value12) >> 8;
            x_c2cd4 = (uint8_t)x_ret3;
            y_c2cd4 = (uint8_t)y_ret;
            direct_page_c2cd4 = dp_ret;
            data_bank_c2cd4 = db_ret;
            goto shared_C2CD_3;
        } else {
            a_c2cd = (uint8_t)(a_all2 & value12);
            a_hi_c2cd = (a_all2 & value12) >> 8;
            x_c2cd = x_ret3;
            y_c2cd = y_ret;
            direct_page_c2cd = dp_ret;
            data_bank_c2cd = db_ret;
            goto shared_C2CD;
        }
    }
    shared_C2C4_1:;
    r->a = (a_hi_c2c42 << 8) | a_c2c42;
    r->x = x_c2c42;
    r->y = y_c2c42;
    r->c = carry_c2c42;
    r->z = zero_c2c42;
    r->n = negative_c2c42;
    r->v = overflow_c2c42;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_c2c42;
    r->dp = direct_page_c2c42;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC2C6, 0x7EC25B); GUARD_JSR(c, sp_call, 0xC2C6); } /* advance_native_fifteen_byte_subtractive_random_ring */
    r->sp += 8;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret4 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret5 = r->x;
    uint16_t y_ret2 = r->y;
    bool overflow_ret3 = r->v;
    if (m_ret2) {
        uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 3));
        uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
        if (((uint8_t)a_all3 & value14) >= value15) {
            if (x_ret4) {
                a_c2c42 = (uint8_t)a_all3 & value14;
                a_hi_c2c42 = a_all3 >> 8;
                x_c2c42 = (uint8_t)x_ret5;
                y_c2c42 = (uint8_t)y_ret2;
                carry_c2c42 = ((uint8_t)a_all3 & value14) >= value15;
                zero_c2c42 = ((uint8_t)a_all3 & value14) == value15;
                negative_c2c42 = (uint8_t)(((uint8_t)a_all3 & value14) - value15) & 0x80;
                overflow_c2c42 = overflow_ret3;
                direct_page_c2c42 = dp_ret2;
                data_bank_c2c42 = db_ret2;
                goto shared_C2C4_1;
            } else {
                a_c2c43 = (uint8_t)a_all3 & value14;
                a_hi_c2c43 = a_all3 >> 8;
                x_c2c43 = x_ret5;
                y_c2c43 = y_ret2;
                carry_c2c43 = ((uint8_t)a_all3 & value14) >= value15;
                zero_c2c43 = ((uint8_t)a_all3 & value14) == value15;
                negative_c2c43 = (uint8_t)(((uint8_t)a_all3 & value14) - value15) & 0x80;
                overflow_c2c43 = overflow_ret3;
                direct_page_c2c43 = dp_ret2;
                data_bank_c2c43 = db_ret2;
                goto shared_C2C4_2;
            }
        }
        if (x_ret4) {
            a_c2cd2 = (uint8_t)a_all3 & value14;
            a_hi_c2cd2 = a_all3 >> 8;
            x_c2cd2 = (uint8_t)x_ret5;
            y_c2cd2 = (uint8_t)y_ret2;
            direct_page_c2cd2 = dp_ret2;
            data_bank_c2cd2 = db_ret2;
            goto shared_C2CD_1;
        } else {
            a_c2cd3 = (uint8_t)a_all3 & value14;
            a_hi_c2cd3 = a_all3 >> 8;
            x_c2cd3 = x_ret5;
            y_c2cd3 = y_ret2;
            direct_page_c2cd3 = dp_ret2;
            data_bank_c2cd3 = db_ret2;
            goto shared_C2CD_2;
        }
    } else {
        uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 3));
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        if ((a_all3 & value16) >= value17) {
            if (x_ret4) {
                a_c2c44 = (uint8_t)(a_all3 & value16);
                a_hi_c2c44 = (a_all3 & value16) >> 8;
                x_c2c44 = (uint8_t)x_ret5;
                y_c2c44 = (uint8_t)y_ret2;
                carry_c2c44 = (a_all3 & value16) >= value17;
                zero_c2c44 = (a_all3 & value16) == value17;
                negative_c2c44 = (uint16_t)((a_all3 & value16) - value17) & 0x8000;
                overflow_c2c44 = overflow_ret3;
                direct_page_c2c44 = dp_ret2;
                data_bank_c2c44 = db_ret2;
                goto shared_C2C4_3;
            } else {
                a_c2c4 = (uint8_t)(a_all3 & value16);
                a_hi_c2c4 = (a_all3 & value16) >> 8;
                x_c2c4 = x_ret5;
                y_c2c4 = y_ret2;
                carry_c2c4 = (a_all3 & value16) >= value17;
                zero_c2c4 = (a_all3 & value16) == value17;
                negative_c2c4 = (uint16_t)((a_all3 & value16) - value17) & 0x8000;
                overflow_c2c4 = overflow_ret3;
                direct_page_c2c4 = dp_ret2;
                data_bank_c2c4 = db_ret2;
                goto shared_C2C4;
            }
        }
        if (x_ret4) {
            a_c2cd4 = (uint8_t)(a_all3 & value16);
            a_hi_c2cd4 = (a_all3 & value16) >> 8;
            x_c2cd4 = (uint8_t)x_ret5;
            y_c2cd4 = (uint8_t)y_ret2;
            direct_page_c2cd4 = dp_ret2;
            data_bank_c2cd4 = db_ret2;
            goto shared_C2CD_3;
        } else {
            a_c2cd = (uint8_t)(a_all3 & value16);
            a_hi_c2cd = (a_all3 & value16) >> 8;
            x_c2cd = x_ret5;
            y_c2cd = y_ret2;
            direct_page_c2cd = dp_ret2;
            data_bank_c2cd = db_ret2;
            goto shared_C2CD;
        }
    }
    shared_C2C4_2:;
    r->a = (a_hi_c2c43 << 8) | a_c2c43;
    r->x = x_c2c43;
    r->y = y_c2c43;
    r->c = carry_c2c43;
    r->z = zero_c2c43;
    r->n = negative_c2c43;
    r->v = overflow_c2c43;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_c2c43;
    r->dp = direct_page_c2c43;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC2C6, 0x7EC25B); GUARD_JSR(c, sp_call, 0xC2C6); } /* advance_native_fifteen_byte_subtractive_random_ring */
    r->sp += 8;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret6 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t x_ret7 = r->x;
    uint16_t y_ret3 = r->y;
    bool overflow_ret4 = r->v;
    if (m_ret3) {
        uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 3));
        uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
        if (((uint8_t)a_all4 & value18) >= value19) {
            if (x_ret6) {
                a_c2c42 = (uint8_t)a_all4 & value18;
                a_hi_c2c42 = a_all4 >> 8;
                x_c2c42 = (uint8_t)x_ret7;
                y_c2c42 = (uint8_t)y_ret3;
                carry_c2c42 = ((uint8_t)a_all4 & value18) >= value19;
                zero_c2c42 = ((uint8_t)a_all4 & value18) == value19;
                negative_c2c42 = (uint8_t)(((uint8_t)a_all4 & value18) - value19) & 0x80;
                overflow_c2c42 = overflow_ret4;
                direct_page_c2c42 = dp_ret3;
                data_bank_c2c42 = db_ret3;
                goto shared_C2C4_1;
            } else {
                a_c2c43 = (uint8_t)a_all4 & value18;
                a_hi_c2c43 = a_all4 >> 8;
                x_c2c43 = x_ret7;
                y_c2c43 = y_ret3;
                carry_c2c43 = ((uint8_t)a_all4 & value18) >= value19;
                zero_c2c43 = ((uint8_t)a_all4 & value18) == value19;
                negative_c2c43 = (uint8_t)(((uint8_t)a_all4 & value18) - value19) & 0x80;
                overflow_c2c43 = overflow_ret4;
                direct_page_c2c43 = dp_ret3;
                data_bank_c2c43 = db_ret3;
                goto shared_C2C4_2;
            }
        }
        if (x_ret6) {
            a_c2cd2 = (uint8_t)a_all4 & value18;
            a_hi_c2cd2 = a_all4 >> 8;
            x_c2cd2 = (uint8_t)x_ret7;
            y_c2cd2 = (uint8_t)y_ret3;
            direct_page_c2cd2 = dp_ret3;
            data_bank_c2cd2 = db_ret3;
            goto shared_C2CD_1;
        } else {
            a_c2cd3 = (uint8_t)a_all4 & value18;
            a_hi_c2cd3 = a_all4 >> 8;
            x_c2cd3 = x_ret7;
            y_c2cd3 = y_ret3;
            direct_page_c2cd3 = dp_ret3;
            data_bank_c2cd3 = db_ret3;
            goto shared_C2CD_2;
        }
    } else {
        uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 3));
        uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
        if ((a_all4 & value20) >= value21) {
            if (x_ret6) {
                a_c2c44 = (uint8_t)(a_all4 & value20);
                a_hi_c2c44 = (a_all4 & value20) >> 8;
                x_c2c44 = (uint8_t)x_ret7;
                y_c2c44 = (uint8_t)y_ret3;
                carry_c2c44 = (a_all4 & value20) >= value21;
                zero_c2c44 = (a_all4 & value20) == value21;
                negative_c2c44 = (uint16_t)((a_all4 & value20) - value21) & 0x8000;
                overflow_c2c44 = overflow_ret4;
                direct_page_c2c44 = dp_ret3;
                data_bank_c2c44 = db_ret3;
                goto shared_C2C4_3;
            } else {
                a_c2c4 = (uint8_t)(a_all4 & value20);
                a_hi_c2c4 = (a_all4 & value20) >> 8;
                x_c2c4 = x_ret7;
                y_c2c4 = y_ret3;
                carry_c2c4 = (a_all4 & value20) >= value21;
                zero_c2c4 = (a_all4 & value20) == value21;
                negative_c2c4 = (uint16_t)((a_all4 & value20) - value21) & 0x8000;
                overflow_c2c4 = overflow_ret4;
                direct_page_c2c4 = dp_ret3;
                data_bank_c2c4 = db_ret3;
                goto shared_C2C4;
            }
        }
        if (x_ret6) {
            a_c2cd4 = (uint8_t)(a_all4 & value20);
            a_hi_c2cd4 = (a_all4 & value20) >> 8;
            x_c2cd4 = (uint8_t)x_ret7;
            y_c2cd4 = (uint8_t)y_ret3;
            direct_page_c2cd4 = dp_ret3;
            data_bank_c2cd4 = db_ret3;
            goto shared_C2CD_3;
        } else {
            a_c2cd = (uint8_t)(a_all4 & value20);
            a_hi_c2cd = (a_all4 & value20) >> 8;
            x_c2cd = x_ret7;
            y_c2cd = y_ret3;
            direct_page_c2cd = dp_ret3;
            data_bank_c2cd = db_ret3;
            goto shared_C2CD;
        }
    }
    shared_C2CD_1:;
    uint8_t value22 = RAM8(0x0000 + sp0 - 7);
    RAM8(0x0000 + sp0 - 3) = a_c2cd2;
    uint8_t value26 = RAM8(0x0000 + sp0 - 3);
    uint8_t value27 = RAM8(0x0000 + sp0 - 2);
    uint8_t value28 = RAM8(0x0000 + sp0 - 1);
    uint8_t value29 = RAM8(0x0000 + sp0);
    r->a = (a_hi_c2cd2 << 8) | value26;
    r->x = x_c2cd2;
    r->y = y_c2cd2;
    r->c = value27 & 0x01;
    r->v = value27 & 0x40;
    r->mf = value27 & 0x20;
    r->xf = value27 & 0x10;
    r->db = value22;
    r->dp = (value29 << 8) | value28;
    r->i = value27 & 0x04;
    r->d = value27 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_C2CD_2:;
    uint8_t value30 = RAM8(0x0000 + sp0 - 7);
    RAM8(0x0000 + sp0 - 3) = a_c2cd3;
    uint8_t value34 = RAM8(0x0000 + sp0 - 3);
    uint8_t value35 = RAM8(0x0000 + sp0 - 2);
    uint8_t value36 = RAM8(0x0000 + sp0 - 1);
    uint8_t value37 = RAM8(0x0000 + sp0);
    r->a = (a_hi_c2cd3 << 8) | value34;
    r->x = x_c2cd3;
    r->y = y_c2cd3;
    r->c = value35 & 0x01;
    r->v = value35 & 0x40;
    r->mf = value35 & 0x20;
    r->xf = value35 & 0x10;
    r->db = value30;
    r->dp = (value37 << 8) | value36;
    r->i = value35 & 0x04;
    r->d = value35 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_C2C4_3:;
    r->a = (a_hi_c2c44 << 8) | a_c2c44;
    r->x = x_c2c44;
    r->y = y_c2c44;
    r->c = carry_c2c44;
    r->z = zero_c2c44;
    r->n = negative_c2c44;
    r->v = overflow_c2c44;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_c2c44;
    r->dp = direct_page_c2c44;
    r->sp -= 8;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC2C6, 0x7EC25B); GUARD_JSR(c, sp_call, 0xC2C6); } /* advance_native_fifteen_byte_subtractive_random_ring */
    r->sp += 8;
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret8 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret4 = r->y;
    bool overflow_ret5 = r->v;
    if (m_ret4) {
        uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 3));
        uint8_t value39 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
        if (((uint8_t)a_all5 & value38) >= value39) {
            if (x_ret8) {
                a_c2c42 = (uint8_t)a_all5 & value38;
                a_hi_c2c42 = a_all5 >> 8;
                x_c2c42 = (uint8_t)x_ret9;
                y_c2c42 = (uint8_t)y_ret4;
                carry_c2c42 = ((uint8_t)a_all5 & value38) >= value39;
                zero_c2c42 = ((uint8_t)a_all5 & value38) == value39;
                negative_c2c42 = (uint8_t)(((uint8_t)a_all5 & value38) - value39) & 0x80;
                overflow_c2c42 = overflow_ret5;
                direct_page_c2c42 = dp_ret4;
                data_bank_c2c42 = db_ret4;
                goto shared_C2C4_1;
            } else {
                a_c2c43 = (uint8_t)a_all5 & value38;
                a_hi_c2c43 = a_all5 >> 8;
                x_c2c43 = x_ret9;
                y_c2c43 = y_ret4;
                carry_c2c43 = ((uint8_t)a_all5 & value38) >= value39;
                zero_c2c43 = ((uint8_t)a_all5 & value38) == value39;
                negative_c2c43 = (uint8_t)(((uint8_t)a_all5 & value38) - value39) & 0x80;
                overflow_c2c43 = overflow_ret5;
                direct_page_c2c43 = dp_ret4;
                data_bank_c2c43 = db_ret4;
                goto shared_C2C4_2;
            }
        }
        if (x_ret8) {
            a_c2cd2 = (uint8_t)a_all5 & value38;
            a_hi_c2cd2 = a_all5 >> 8;
            x_c2cd2 = (uint8_t)x_ret9;
            y_c2cd2 = (uint8_t)y_ret4;
            direct_page_c2cd2 = dp_ret4;
            data_bank_c2cd2 = db_ret4;
            goto shared_C2CD_1;
        } else {
            a_c2cd3 = (uint8_t)a_all5 & value38;
            a_hi_c2cd3 = a_all5 >> 8;
            x_c2cd3 = x_ret9;
            y_c2cd3 = y_ret4;
            direct_page_c2cd3 = dp_ret4;
            data_bank_c2cd3 = db_ret4;
            goto shared_C2CD_2;
        }
    } else {
        uint16_t value40 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 3));
        uint16_t value41 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 1));
        if ((a_all5 & value40) >= value41) {
            if (x_ret8) {
                a_c2c44 = (uint8_t)(a_all5 & value40);
                a_hi_c2c44 = (a_all5 & value40) >> 8;
                x_c2c44 = (uint8_t)x_ret9;
                y_c2c44 = (uint8_t)y_ret4;
                carry_c2c44 = (a_all5 & value40) >= value41;
                zero_c2c44 = (a_all5 & value40) == value41;
                negative_c2c44 = (uint16_t)((a_all5 & value40) - value41) & 0x8000;
                overflow_c2c44 = overflow_ret5;
                direct_page_c2c44 = dp_ret4;
                data_bank_c2c44 = db_ret4;
                goto shared_C2C4_3;
            } else {
                a_c2c4 = (uint8_t)(a_all5 & value40);
                a_hi_c2c4 = (a_all5 & value40) >> 8;
                x_c2c4 = x_ret9;
                y_c2c4 = y_ret4;
                carry_c2c4 = (a_all5 & value40) >= value41;
                zero_c2c4 = (a_all5 & value40) == value41;
                negative_c2c4 = (uint16_t)((a_all5 & value40) - value41) & 0x8000;
                overflow_c2c4 = overflow_ret5;
                direct_page_c2c4 = dp_ret4;
                data_bank_c2c4 = db_ret4;
                goto shared_C2C4;
            }
        }
        if (x_ret8) {
            a_c2cd4 = (uint8_t)(a_all5 & value40);
            a_hi_c2cd4 = (a_all5 & value40) >> 8;
            x_c2cd4 = (uint8_t)x_ret9;
            y_c2cd4 = (uint8_t)y_ret4;
            direct_page_c2cd4 = dp_ret4;
            data_bank_c2cd4 = db_ret4;
            goto shared_C2CD_3;
        } else {
            a_c2cd = (uint8_t)(a_all5 & value40);
            a_hi_c2cd = (a_all5 & value40) >> 8;
            x_c2cd = x_ret9;
            y_c2cd = y_ret4;
            direct_page_c2cd = dp_ret4;
            data_bank_c2cd = db_ret4;
            goto shared_C2CD;
        }
    }
    shared_C2CD_3:;
    uint8_t value42 = RAM8(0x0000 + sp0 - 7);
    RAM8(0x0000 + sp0 - 3) = a_c2cd4;
    uint8_t value46 = RAM8(0x0000 + sp0 - 3);
    uint8_t value47 = RAM8(0x0000 + sp0 - 2);
    uint8_t value48 = RAM8(0x0000 + sp0 - 1);
    uint8_t value49 = RAM8(0x0000 + sp0);
    r->a = (a_hi_c2cd4 << 8) | value46;
    r->x = x_c2cd4;
    r->y = y_c2cd4;
    r->c = value47 & 0x01;
    r->v = value47 & 0x40;
    r->mf = value47 & 0x20;
    r->xf = value47 & 0x10;
    r->db = value42;
    r->dp = (value49 << 8) | value48;
    r->i = value47 & 0x04;
    r->d = value47 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC288, SOM_RTS, "gen", draw_native_random_byte_below_low_byte_limit, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 10, 0, 0, 81, 50)
