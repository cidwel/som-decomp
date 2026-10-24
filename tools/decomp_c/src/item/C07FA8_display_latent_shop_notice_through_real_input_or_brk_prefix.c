#include "som_c.h"

/* C07FA8 display_latent_shop_notice_through_real_input_or_brk_prefix   [class B, 74 bytes, 29 instructions]
 * Source: src/rom/display_latent_shop_notice_through_real_input_or_brk_prefix.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void display_latent_shop_notice_through_real_input_or_brk_prefix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t a_hi_7fb9 = 0;
    uint16_t x_7fb9 = 0;
    uint16_t y_7fb9 = 0;
    bool carry_7fb9 = 0;
    bool overflow_7fb9 = 0;
    uint8_t a_7fc9 = 0;
    uint8_t a_hi_7fc9 = 0;
    uint8_t x_7fc9 = 0;
    uint8_t y_7fc9 = 0;
    bool carry_7fc9 = 0;
    bool zero_7fc9 = 0;
    bool negative_7fc9 = 0;
    bool overflow_7fc9 = 0;
    uint16_t direct_page_7fc9 = 0;
    uint8_t data_bank_7fc9 = 0;
    uint8_t a_7fc92 = 0;
    uint8_t a_hi_7fc92 = 0;
    uint16_t x_7fc92 = 0;
    uint16_t y_7fc92 = 0;
    bool carry_7fc92 = 0;
    bool zero_7fc92 = 0;
    bool negative_7fc92 = 0;
    bool overflow_7fc92 = 0;
    uint16_t direct_page_7fc92 = 0;
    uint8_t data_bank_7fc92 = 0;
    uint8_t a_7fc93 = 0;
    uint8_t a_hi_7fc93 = 0;
    uint8_t x_7fc93 = 0;
    uint8_t y_7fc93 = 0;
    bool carry_7fc93 = 0;
    bool zero_7fc93 = 0;
    bool negative_7fc93 = 0;
    bool overflow_7fc93 = 0;
    uint16_t direct_page_7fc93 = 0;
    uint8_t data_bank_7fc93 = 0;
    uint8_t a_7fc94 = 0;
    uint8_t a_hi_7fc94 = 0;
    uint16_t x_7fc94 = 0;
    uint16_t y_7fc94 = 0;
    bool carry_7fc94 = 0;
    bool zero_7fc94 = 0;
    bool negative_7fc94 = 0;
    bool overflow_7fc94 = 0;
    uint16_t direct_page_7fc94 = 0;
    uint8_t data_bank_7fc94 = 0;
    uint8_t a_7fd7 = 0;
    uint8_t a_hi_7fd7 = 0;
    uint8_t x_7fd7 = 0;
    uint8_t y_7fd7 = 0;
    bool carry_7fd7 = 0;
    bool zero_7fd7 = 0;
    bool negative_7fd7 = 0;
    bool overflow_7fd7 = 0;
    uint16_t direct_page_7fd7 = 0;
    uint8_t data_bank_7fd7 = 0;
    uint8_t a_7fd72 = 0;
    uint8_t a_hi_7fd72 = 0;
    uint16_t x_7fd72 = 0;
    uint16_t y_7fd72 = 0;
    bool carry_7fd72 = 0;
    bool zero_7fd72 = 0;
    bool negative_7fd72 = 0;
    bool overflow_7fd72 = 0;
    uint16_t direct_page_7fd72 = 0;
    uint8_t data_bank_7fd72 = 0;
    uint8_t a_hi_7ff1 = 0;
    uint8_t x_7ff1 = 0;
    uint8_t y_7ff1 = 0;
    bool carry_7ff1 = 0;
    bool overflow_7ff1 = 0;
    uint16_t direct_page_7ff1 = 0;
    uint8_t data_bank_7ff1 = 0;
    uint8_t a_hi_7ff12 = 0;
    uint16_t x_7ff12 = 0;
    uint16_t y_7ff12 = 0;
    bool carry_7ff12 = 0;
    bool overflow_7ff12 = 0;
    uint16_t direct_page_7ff12 = 0;
    uint8_t data_bank_7ff12 = 0;
    uint8_t a_hi_7ff13 = 0;
    uint8_t x_7ff13 = 0;
    uint8_t y_7ff13 = 0;
    bool carry_7ff13 = 0;
    bool overflow_7ff13 = 0;
    uint16_t direct_page_7ff13 = 0;
    uint8_t data_bank_7ff13 = 0;
    uint8_t a_hi_7ff14 = 0;
    uint16_t x_7ff14 = 0;
    uint16_t y_7ff14 = 0;
    bool carry_7ff14 = 0;
    bool overflow_7ff14 = 0;
    uint16_t direct_page_7ff14 = 0;
    uint8_t data_bank_7ff14 = 0;
    uint8_t value = RAM8(0x1D04);
    if ((value & 1) == 0) {
        a_hi_7fb9 = a_hi;
        x_7fb9 = x;
        y_7fb9 = y;
        carry_7fb9 = carry;
        overflow_7fb9 = value & 0x40;
        goto shared_7FB9;
    }
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    r->a = (a_hi << 8) | 1;
    r->z = (value & 1) == 0;
    r->n = value & 0x80;
    r->v = value & 0x40;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7FB7, 0xC00095); GUARD_JSL(c, sp_call, 0x7FB7); } /* close_dialogue_public_jump */
    r->sp += 2;
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    a_hi_7fb9 = a_all >> 8;
    x_7fb9 = (value3 << 8) | value2;
    y_7fb9 = y;
    carry_7fb9 = carry_ret;
    overflow_7fb9 = overflow_ret;
    shared_7FB9:;
    RAM8(0x1D03) = 0xD9;
    RAM16_SET(0x1D01, x_7fb9);
    r->a = (a_hi_7fb9 << 8) | 0xD9;
    r->x = x_7fb9;
    r->y = y_7fb9;
    r->c = carry_7fb9;
    r->z = 0;
    r->n = 1;
    r->v = overflow_7fb9;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7FC4, 0xC00092); GUARD_JSL(c, sp_call, 0x7FC4); } /* run_native_dialogue_public_jump */
    { const uint16_t sp_call = r->sp; JSL(c, 0x7FC8, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7FC8); } /* external */
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret4 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret5 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret3 = r->c;
    bool zero_ret3 = r->z;
    bool negative_ret3 = r->n;
    bool overflow_ret3 = r->v;
    if (m_ret2) {
        if (x_ret4) {
            a_7fc9 = (uint8_t)a_all3;
            a_hi_7fc9 = a_all3 >> 8;
            x_7fc9 = (uint8_t)x_ret5;
            y_7fc9 = (uint8_t)y_ret2;
            carry_7fc9 = carry_ret3;
            zero_7fc9 = zero_ret3;
            negative_7fc9 = negative_ret3;
            overflow_7fc9 = overflow_ret3;
            direct_page_7fc9 = dp_ret2;
            data_bank_7fc9 = db_ret2;
            goto shared_7FC9;
        } else {
            a_7fc92 = (uint8_t)a_all3;
            a_hi_7fc92 = a_all3 >> 8;
            x_7fc92 = x_ret5;
            y_7fc92 = y_ret2;
            carry_7fc92 = carry_ret3;
            zero_7fc92 = zero_ret3;
            negative_7fc92 = negative_ret3;
            overflow_7fc92 = overflow_ret3;
            direct_page_7fc92 = dp_ret2;
            data_bank_7fc92 = db_ret2;
            goto shared_7FC9_1;
        }
    } else {
        if (x_ret4) {
            a_7fc93 = (uint8_t)a_all3;
            a_hi_7fc93 = a_all3 >> 8;
            x_7fc93 = (uint8_t)x_ret5;
            y_7fc93 = (uint8_t)y_ret2;
            carry_7fc93 = carry_ret3;
            zero_7fc93 = zero_ret3;
            negative_7fc93 = negative_ret3;
            overflow_7fc93 = overflow_ret3;
            direct_page_7fc93 = dp_ret2;
            data_bank_7fc93 = db_ret2;
            goto shared_7FC9_2;
        } else {
            a_7fc94 = (uint8_t)a_all3;
            a_hi_7fc94 = a_all3 >> 8;
            x_7fc94 = x_ret5;
            y_7fc94 = y_ret2;
            carry_7fc94 = carry_ret3;
            zero_7fc94 = zero_ret3;
            negative_7fc94 = negative_ret3;
            overflow_7fc94 = overflow_ret3;
            direct_page_7fc94 = dp_ret2;
            data_bank_7fc94 = db_ret2;
            goto shared_7FC9_3;
        }
    }
    shared_7FC9:;
    r->a = (a_hi_7fc9 << 8) | a_7fc9;
    r->x = x_7fc9;
    r->y = y_7fc9;
    r->c = carry_7fc9;
    r->z = zero_7fc9;
    r->n = negative_7fc9;
    r->v = overflow_7fc9;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7fc9;
    r->dp = direct_page_7fc9;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7FCE, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7FCE); } /* external */
    { const uint16_t sp_call = r->sp; JSR(c, 0x7FD1, 0xC07F93); GUARD_JSR(c, sp_call, 0x7FD1); } /* tick_latent_shop_input_or_enter_literal_brk */
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    bool x_ret8 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret4 = r->y;
    bool carry_ret5 = r->c;
    bool negative_ret5 = r->n;
    bool overflow_ret5 = r->v;
    if ((a_all5 & 0xCFC0) != 0) {
        if (x_ret8) {
            a_7fc93 = (uint8_t)a_all5;
            a_hi_7fc93 = a_all5 >> 8;
            x_7fc93 = (uint8_t)x_ret9;
            y_7fc93 = (uint8_t)y_ret4;
            carry_7fc93 = carry_ret5;
            zero_7fc93 = (a_all5 & 0xCFC0) == 0;
            negative_7fc93 = negative_ret5;
            overflow_7fc93 = overflow_ret5;
            direct_page_7fc93 = dp_ret4;
            data_bank_7fc93 = db_ret4;
            goto shared_7FC9_2;
        } else {
            a_7fc94 = (uint8_t)a_all5;
            a_hi_7fc94 = a_all5 >> 8;
            x_7fc94 = x_ret9;
            y_7fc94 = y_ret4;
            carry_7fc94 = carry_ret5;
            zero_7fc94 = (a_all5 & 0xCFC0) == 0;
            negative_7fc94 = negative_ret5;
            overflow_7fc94 = overflow_ret5;
            direct_page_7fc94 = dp_ret4;
            data_bank_7fc94 = db_ret4;
            goto shared_7FC9_3;
        }
    }
    if (x_ret8) {
        a_7fd7 = (uint8_t)a_all5;
        a_hi_7fd7 = a_all5 >> 8;
        x_7fd7 = (uint8_t)x_ret9;
        y_7fd7 = (uint8_t)y_ret4;
        carry_7fd7 = carry_ret5;
        zero_7fd7 = (a_all5 & 0xCFC0) == 0;
        negative_7fd7 = negative_ret5;
        overflow_7fd7 = overflow_ret5;
        direct_page_7fd7 = dp_ret4;
        data_bank_7fd7 = db_ret4;
        goto shared_7FD7;
    } else {
        a_7fd72 = (uint8_t)a_all5;
        a_hi_7fd72 = a_all5 >> 8;
        x_7fd72 = x_ret9;
        y_7fd72 = y_ret4;
        carry_7fd72 = carry_ret5;
        zero_7fd72 = (a_all5 & 0xCFC0) == 0;
        negative_7fd72 = negative_ret5;
        overflow_7fd72 = overflow_ret5;
        direct_page_7fd72 = dp_ret4;
        data_bank_7fd72 = db_ret4;
        goto shared_7FD7_1;
    }
    shared_7FC9_1:;
    r->a = (a_hi_7fc92 << 8) | a_7fc92;
    r->x = x_7fc92;
    r->y = y_7fc92;
    r->c = carry_7fc92;
    r->z = zero_7fc92;
    r->n = negative_7fc92;
    r->v = overflow_7fc92;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7fc92;
    r->dp = direct_page_7fc92;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7FCE, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7FCE); } /* external */
    { const uint16_t sp_call = r->sp; JSR(c, 0x7FD1, 0xC07F93); GUARD_JSR(c, sp_call, 0x7FD1); } /* tick_latent_shop_input_or_enter_literal_brk */
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    bool x_ret12 = r->xf;
    uint16_t a_all7 = r->a;
    uint16_t x_ret13 = r->x;
    uint16_t y_ret6 = r->y;
    bool carry_ret7 = r->c;
    bool negative_ret7 = r->n;
    bool overflow_ret7 = r->v;
    if ((a_all7 & 0xCFC0) != 0) {
        if (x_ret12) {
            a_7fc93 = (uint8_t)a_all7;
            a_hi_7fc93 = a_all7 >> 8;
            x_7fc93 = (uint8_t)x_ret13;
            y_7fc93 = (uint8_t)y_ret6;
            carry_7fc93 = carry_ret7;
            zero_7fc93 = (a_all7 & 0xCFC0) == 0;
            negative_7fc93 = negative_ret7;
            overflow_7fc93 = overflow_ret7;
            direct_page_7fc93 = dp_ret6;
            data_bank_7fc93 = db_ret6;
            goto shared_7FC9_2;
        } else {
            a_7fc94 = (uint8_t)a_all7;
            a_hi_7fc94 = a_all7 >> 8;
            x_7fc94 = x_ret13;
            y_7fc94 = y_ret6;
            carry_7fc94 = carry_ret7;
            zero_7fc94 = (a_all7 & 0xCFC0) == 0;
            negative_7fc94 = negative_ret7;
            overflow_7fc94 = overflow_ret7;
            direct_page_7fc94 = dp_ret6;
            data_bank_7fc94 = db_ret6;
            goto shared_7FC9_3;
        }
    }
    if (x_ret12) {
        a_7fd7 = (uint8_t)a_all7;
        a_hi_7fd7 = a_all7 >> 8;
        x_7fd7 = (uint8_t)x_ret13;
        y_7fd7 = (uint8_t)y_ret6;
        carry_7fd7 = carry_ret7;
        zero_7fd7 = (a_all7 & 0xCFC0) == 0;
        negative_7fd7 = negative_ret7;
        overflow_7fd7 = overflow_ret7;
        direct_page_7fd7 = dp_ret6;
        data_bank_7fd7 = db_ret6;
        goto shared_7FD7;
    } else {
        a_7fd72 = (uint8_t)a_all7;
        a_hi_7fd72 = a_all7 >> 8;
        x_7fd72 = x_ret13;
        y_7fd72 = y_ret6;
        carry_7fd72 = carry_ret7;
        zero_7fd72 = (a_all7 & 0xCFC0) == 0;
        negative_7fd72 = negative_ret7;
        overflow_7fd72 = overflow_ret7;
        direct_page_7fd72 = dp_ret6;
        data_bank_7fd72 = db_ret6;
        goto shared_7FD7_1;
    }
    shared_7FC9_2:;
    r->a = (a_hi_7fc93 << 8) | a_7fc93;
    r->x = x_7fc93;
    r->y = y_7fc93;
    r->c = carry_7fc93;
    r->z = zero_7fc93;
    r->n = negative_7fc93;
    r->v = overflow_7fc93;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7fc93;
    r->dp = direct_page_7fc93;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7FCE, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7FCE); } /* external */
    { const uint16_t sp_call = r->sp; JSR(c, 0x7FD1, 0xC07F93); GUARD_JSR(c, sp_call, 0x7FD1); } /* tick_latent_shop_input_or_enter_literal_brk */
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret8 = r->db;
    bool x_ret16 = r->xf;
    uint16_t a_all9 = r->a;
    uint16_t x_ret17 = r->x;
    uint16_t y_ret8 = r->y;
    bool carry_ret9 = r->c;
    bool negative_ret9 = r->n;
    bool overflow_ret9 = r->v;
    if ((a_all9 & 0xCFC0) != 0) {
        if (x_ret16) {
            a_7fc93 = (uint8_t)a_all9;
            a_hi_7fc93 = a_all9 >> 8;
            x_7fc93 = (uint8_t)x_ret17;
            y_7fc93 = (uint8_t)y_ret8;
            carry_7fc93 = carry_ret9;
            zero_7fc93 = (a_all9 & 0xCFC0) == 0;
            negative_7fc93 = negative_ret9;
            overflow_7fc93 = overflow_ret9;
            direct_page_7fc93 = dp_ret8;
            data_bank_7fc93 = db_ret8;
            goto shared_7FC9_2;
        } else {
            a_7fc94 = (uint8_t)a_all9;
            a_hi_7fc94 = a_all9 >> 8;
            x_7fc94 = x_ret17;
            y_7fc94 = y_ret8;
            carry_7fc94 = carry_ret9;
            zero_7fc94 = (a_all9 & 0xCFC0) == 0;
            negative_7fc94 = negative_ret9;
            overflow_7fc94 = overflow_ret9;
            direct_page_7fc94 = dp_ret8;
            data_bank_7fc94 = db_ret8;
            goto shared_7FC9_3;
        }
    }
    if (x_ret16) {
        a_7fd7 = (uint8_t)a_all9;
        a_hi_7fd7 = a_all9 >> 8;
        x_7fd7 = (uint8_t)x_ret17;
        y_7fd7 = (uint8_t)y_ret8;
        carry_7fd7 = carry_ret9;
        zero_7fd7 = (a_all9 & 0xCFC0) == 0;
        negative_7fd7 = negative_ret9;
        overflow_7fd7 = overflow_ret9;
        direct_page_7fd7 = dp_ret8;
        data_bank_7fd7 = db_ret8;
        goto shared_7FD7;
    } else {
        a_7fd72 = (uint8_t)a_all9;
        a_hi_7fd72 = a_all9 >> 8;
        x_7fd72 = x_ret17;
        y_7fd72 = y_ret8;
        carry_7fd72 = carry_ret9;
        zero_7fd72 = (a_all9 & 0xCFC0) == 0;
        negative_7fd72 = negative_ret9;
        overflow_7fd72 = overflow_ret9;
        direct_page_7fd72 = dp_ret8;
        data_bank_7fd72 = db_ret8;
        goto shared_7FD7_1;
    }
    shared_7FC9_3:;
    r->a = (a_hi_7fc94 << 8) | a_7fc94;
    r->x = x_7fc94;
    r->y = y_7fc94;
    r->c = carry_7fc94;
    r->z = zero_7fc94;
    r->n = negative_7fc94;
    r->v = overflow_7fc94;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7fc94;
    r->dp = direct_page_7fc94;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7FCE, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7FCE); } /* external */
    { const uint16_t sp_call = r->sp; JSR(c, 0x7FD1, 0xC07F93); GUARD_JSR(c, sp_call, 0x7FD1); } /* tick_latent_shop_input_or_enter_literal_brk */
    uint16_t dp_ret10 = r->dp;
    uint8_t db_ret10 = r->db;
    bool x_ret20 = r->xf;
    uint16_t a_all11 = r->a;
    uint16_t x_ret21 = r->x;
    uint16_t y_ret10 = r->y;
    bool carry_ret11 = r->c;
    bool negative_ret11 = r->n;
    bool overflow_ret11 = r->v;
    if ((a_all11 & 0xCFC0) != 0) {
        if (x_ret20) {
            a_7fc93 = (uint8_t)a_all11;
            a_hi_7fc93 = a_all11 >> 8;
            x_7fc93 = (uint8_t)x_ret21;
            y_7fc93 = (uint8_t)y_ret10;
            carry_7fc93 = carry_ret11;
            zero_7fc93 = (a_all11 & 0xCFC0) == 0;
            negative_7fc93 = negative_ret11;
            overflow_7fc93 = overflow_ret11;
            direct_page_7fc93 = dp_ret10;
            data_bank_7fc93 = db_ret10;
            goto shared_7FC9_2;
        } else {
            a_7fc94 = (uint8_t)a_all11;
            a_hi_7fc94 = a_all11 >> 8;
            x_7fc94 = x_ret21;
            y_7fc94 = y_ret10;
            carry_7fc94 = carry_ret11;
            zero_7fc94 = (a_all11 & 0xCFC0) == 0;
            negative_7fc94 = negative_ret11;
            overflow_7fc94 = overflow_ret11;
            direct_page_7fc94 = dp_ret10;
            data_bank_7fc94 = db_ret10;
            goto shared_7FC9_3;
        }
    }
    if (x_ret20) {
        a_7fd7 = (uint8_t)a_all11;
        a_hi_7fd7 = a_all11 >> 8;
        x_7fd7 = (uint8_t)x_ret21;
        y_7fd7 = (uint8_t)y_ret10;
        carry_7fd7 = carry_ret11;
        zero_7fd7 = (a_all11 & 0xCFC0) == 0;
        negative_7fd7 = negative_ret11;
        overflow_7fd7 = overflow_ret11;
        direct_page_7fd7 = dp_ret10;
        data_bank_7fd7 = db_ret10;
        goto shared_7FD7;
    } else {
        a_7fd72 = (uint8_t)a_all11;
        a_hi_7fd72 = a_all11 >> 8;
        x_7fd72 = x_ret21;
        y_7fd72 = y_ret10;
        carry_7fd72 = carry_ret11;
        zero_7fd72 = (a_all11 & 0xCFC0) == 0;
        negative_7fd72 = negative_ret11;
        overflow_7fd72 = overflow_ret11;
        direct_page_7fd72 = dp_ret10;
        data_bank_7fd72 = db_ret10;
        goto shared_7FD7_1;
    }
    shared_7FD7:;
    r->a = (a_hi_7fd7 << 8) | a_7fd7;
    r->x = x_7fd7;
    r->y = y_7fd7;
    r->c = carry_7fd7;
    r->z = zero_7fd7;
    r->n = negative_7fd7;
    r->v = overflow_7fd7;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_7fd7;
    r->dp = direct_page_7fd7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7FD9, 0xC07F93); GUARD_JSR(c, sp_call, 0x7FD9); } /* tick_latent_shop_input_or_enter_literal_brk */
    uint16_t dp_ret11 = r->dp;
    uint8_t db_ret11 = r->db;
    bool x_ret22 = r->xf;
    uint16_t a_all12 = r->a;
    uint16_t x_ret23 = r->x;
    uint16_t y_ret11 = r->y;
    bool carry_ret12 = r->c;
    bool negative_ret12 = r->n;
    bool overflow_ret12 = r->v;
    if ((a_all12 & 0xCFC0) == 0) {
        if (x_ret22) {
            a_7fd7 = (uint8_t)a_all12;
            a_hi_7fd7 = a_all12 >> 8;
            x_7fd7 = (uint8_t)x_ret23;
            y_7fd7 = (uint8_t)y_ret11;
            carry_7fd7 = carry_ret12;
            zero_7fd7 = (a_all12 & 0xCFC0) == 0;
            negative_7fd7 = negative_ret12;
            overflow_7fd7 = overflow_ret12;
            direct_page_7fd7 = dp_ret11;
            data_bank_7fd7 = db_ret11;
            goto shared_7FD7;
        } else {
            a_7fd72 = (uint8_t)a_all12;
            a_hi_7fd72 = a_all12 >> 8;
            x_7fd72 = x_ret23;
            y_7fd72 = y_ret11;
            carry_7fd72 = carry_ret12;
            zero_7fd72 = (a_all12 & 0xCFC0) == 0;
            negative_7fd72 = negative_ret12;
            overflow_7fd72 = overflow_ret12;
            direct_page_7fd72 = dp_ret11;
            data_bank_7fd72 = db_ret11;
            goto shared_7FD7_1;
        }
    }
    uint8_t value4 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x1804);
    if ((value4 & 0x80) != 0) {
        if (x_ret22) {
            a_hi_7ff1 = a_all12 >> 8;
            x_7ff1 = (uint8_t)x_ret23;
            y_7ff1 = (uint8_t)y_ret11;
            carry_7ff1 = carry_ret12;
            overflow_7ff1 = value4 & 0x40;
            direct_page_7ff1 = dp_ret11;
            data_bank_7ff1 = db_ret11;
            goto shared_7FF1;
        } else {
            a_hi_7ff12 = a_all12 >> 8;
            x_7ff12 = x_ret23;
            y_7ff12 = y_ret11;
            carry_7ff12 = carry_ret12;
            overflow_7ff12 = value4 & 0x40;
            direct_page_7ff12 = dp_ret11;
            data_bank_7ff12 = db_ret11;
            goto shared_7FF1_1;
        }
    }
    uint8_t value5 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x1802);
    BUS8_SET(c, (db_ret11 << 0x10) + 0x1802, value5 | 4);
    r->a = (a_all12 >> 8 << 8) | 4;
    r->z = (value5 & 4) == 0;
    r->n = 0;
    r->v = value4 & 0x40;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7FF0, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7FF0); } /* external */
    uint16_t dp_ret12 = r->dp;
    uint8_t db_ret12 = r->db;
    bool m_ret7 = r->mf;
    bool x_ret24 = r->xf;
    uint16_t a_all13 = r->a;
    uint16_t x_ret25 = r->x;
    uint16_t y_ret12 = r->y;
    bool carry_ret13 = r->c;
    bool overflow_ret13 = r->v;
    if (m_ret7) {
        if (x_ret24) {
            a_hi_7ff1 = a_all13 >> 8;
            x_7ff1 = (uint8_t)x_ret25;
            y_7ff1 = (uint8_t)y_ret12;
            carry_7ff1 = carry_ret13;
            overflow_7ff1 = overflow_ret13;
            direct_page_7ff1 = dp_ret12;
            data_bank_7ff1 = db_ret12;
            goto shared_7FF1;
        } else {
            a_hi_7ff12 = a_all13 >> 8;
            x_7ff12 = x_ret25;
            y_7ff12 = y_ret12;
            carry_7ff12 = carry_ret13;
            overflow_7ff12 = overflow_ret13;
            direct_page_7ff12 = dp_ret12;
            data_bank_7ff12 = db_ret12;
            goto shared_7FF1_1;
        }
    } else {
        if (x_ret24) {
            a_hi_7ff13 = a_all13 >> 8;
            x_7ff13 = (uint8_t)x_ret25;
            y_7ff13 = (uint8_t)y_ret12;
            carry_7ff13 = carry_ret13;
            overflow_7ff13 = overflow_ret13;
            direct_page_7ff13 = dp_ret12;
            data_bank_7ff13 = db_ret12;
            goto shared_7FF1_2;
        } else {
            a_hi_7ff14 = a_all13 >> 8;
            x_7ff14 = x_ret25;
            y_7ff14 = y_ret12;
            carry_7ff14 = carry_ret13;
            overflow_7ff14 = overflow_ret13;
            direct_page_7ff14 = dp_ret12;
            data_bank_7ff14 = db_ret12;
            goto shared_7FF1_3;
        }
    }
    shared_7FD7_1:;
    r->a = (a_hi_7fd72 << 8) | a_7fd72;
    r->x = x_7fd72;
    r->y = y_7fd72;
    r->c = carry_7fd72;
    r->z = zero_7fd72;
    r->n = negative_7fd72;
    r->v = overflow_7fd72;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7fd72;
    r->dp = direct_page_7fd72;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7FD9, 0xC07F93); GUARD_JSR(c, sp_call, 0x7FD9); } /* tick_latent_shop_input_or_enter_literal_brk */
    uint16_t dp_ret13 = r->dp;
    uint8_t db_ret13 = r->db;
    bool x_ret26 = r->xf;
    uint16_t a_all14 = r->a;
    uint16_t x_ret27 = r->x;
    uint16_t y_ret13 = r->y;
    bool carry_ret14 = r->c;
    bool negative_ret14 = r->n;
    bool overflow_ret14 = r->v;
    if ((a_all14 & 0xCFC0) == 0) {
        if (x_ret26) {
            a_7fd7 = (uint8_t)a_all14;
            a_hi_7fd7 = a_all14 >> 8;
            x_7fd7 = (uint8_t)x_ret27;
            y_7fd7 = (uint8_t)y_ret13;
            carry_7fd7 = carry_ret14;
            zero_7fd7 = (a_all14 & 0xCFC0) == 0;
            negative_7fd7 = negative_ret14;
            overflow_7fd7 = overflow_ret14;
            direct_page_7fd7 = dp_ret13;
            data_bank_7fd7 = db_ret13;
            goto shared_7FD7;
        } else {
            a_7fd72 = (uint8_t)a_all14;
            a_hi_7fd72 = a_all14 >> 8;
            x_7fd72 = x_ret27;
            y_7fd72 = y_ret13;
            carry_7fd72 = carry_ret14;
            zero_7fd72 = (a_all14 & 0xCFC0) == 0;
            negative_7fd72 = negative_ret14;
            overflow_7fd72 = overflow_ret14;
            direct_page_7fd72 = dp_ret13;
            data_bank_7fd72 = db_ret13;
            goto shared_7FD7_1;
        }
    }
    uint8_t value6 = BUS8_RDP(c, (db_ret13 << 0x10) + 0x1804);
    if ((value6 & 0x80) != 0) {
        if (x_ret26) {
            a_hi_7ff1 = a_all14 >> 8;
            x_7ff1 = (uint8_t)x_ret27;
            y_7ff1 = (uint8_t)y_ret13;
            carry_7ff1 = carry_ret14;
            overflow_7ff1 = value6 & 0x40;
            direct_page_7ff1 = dp_ret13;
            data_bank_7ff1 = db_ret13;
            goto shared_7FF1;
        } else {
            a_hi_7ff12 = a_all14 >> 8;
            x_7ff12 = x_ret27;
            y_7ff12 = y_ret13;
            carry_7ff12 = carry_ret14;
            overflow_7ff12 = value6 & 0x40;
            direct_page_7ff12 = dp_ret13;
            data_bank_7ff12 = db_ret13;
            goto shared_7FF1_1;
        }
    }
    uint8_t value7 = BUS8_RDP(c, (db_ret13 << 0x10) + 0x1802);
    BUS8_SET(c, (db_ret13 << 0x10) + 0x1802, value7 | 4);
    r->a = (a_all14 >> 8 << 8) | 4;
    r->z = (value7 & 4) == 0;
    r->n = 0;
    r->v = value6 & 0x40;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7FF0, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7FF0); } /* external */
    uint16_t dp_ret14 = r->dp;
    uint8_t db_ret14 = r->db;
    bool m_ret8 = r->mf;
    bool x_ret28 = r->xf;
    uint16_t a_all15 = r->a;
    uint16_t x_ret29 = r->x;
    uint16_t y_ret14 = r->y;
    bool carry_ret15 = r->c;
    bool overflow_ret15 = r->v;
    if (m_ret8) {
        if (x_ret28) {
            a_hi_7ff1 = a_all15 >> 8;
            x_7ff1 = (uint8_t)x_ret29;
            y_7ff1 = (uint8_t)y_ret14;
            carry_7ff1 = carry_ret15;
            overflow_7ff1 = overflow_ret15;
            direct_page_7ff1 = dp_ret14;
            data_bank_7ff1 = db_ret14;
            goto shared_7FF1;
        } else {
            a_hi_7ff12 = a_all15 >> 8;
            x_7ff12 = x_ret29;
            y_7ff12 = y_ret14;
            carry_7ff12 = carry_ret15;
            overflow_7ff12 = overflow_ret15;
            direct_page_7ff12 = dp_ret14;
            data_bank_7ff12 = db_ret14;
            goto shared_7FF1_1;
        }
    } else {
        if (x_ret28) {
            a_hi_7ff13 = a_all15 >> 8;
            x_7ff13 = (uint8_t)x_ret29;
            y_7ff13 = (uint8_t)y_ret14;
            carry_7ff13 = carry_ret15;
            overflow_7ff13 = overflow_ret15;
            direct_page_7ff13 = dp_ret14;
            data_bank_7ff13 = db_ret14;
            goto shared_7FF1_2;
        } else {
            a_hi_7ff14 = a_all15 >> 8;
            x_7ff14 = x_ret29;
            y_7ff14 = y_ret14;
            carry_7ff14 = carry_ret15;
            overflow_7ff14 = overflow_ret15;
            direct_page_7ff14 = dp_ret14;
            data_bank_7ff14 = db_ret14;
            goto shared_7FF1_3;
        }
    }
    shared_7FF1:;
    r->a = (a_hi_7ff1 << 8) | a;
    r->x = x_7ff1;
    r->y = y_7ff1;
    r->c = carry_7ff1;
    r->v = overflow_7ff1;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_7ff1;
    r->dp = direct_page_7ff1;
    RETURN_RTS(c);
    shared_7FF1_1:;
    r->a = (a_hi_7ff12 << 8) | a;
    r->x = x_7ff12;
    r->y = y_7ff12;
    r->c = carry_7ff12;
    r->v = overflow_7ff12;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_7ff12;
    r->dp = direct_page_7ff12;
    RETURN_RTS(c);
    shared_7FF1_2:;
    r->a = (a_hi_7ff13 << 8) | a;
    r->x = x_7ff13;
    r->y = y_7ff13;
    r->c = carry_7ff13;
    r->v = overflow_7ff13;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_7ff13;
    r->dp = direct_page_7ff13;
    RETURN_RTS(c);
    shared_7FF1_3:;
    r->a = (a_hi_7ff14 << 8) | a;
    r->x = x_7ff14;
    r->y = y_7ff14;
    r->c = carry_7ff14;
    r->v = overflow_7ff14;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7ff14;
    r->dp = direct_page_7ff14;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07FA8, SOM_RTS, "gen", display_latent_shop_notice_through_real_input_or_brk_prefix, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 74, 29)
