#include "som_c.h"

/* C07E95 display_native_shop_message_wait_release_and_new_button_then_refresh   [class B, 74 bytes, 29 instructions]
 * Source: src/rom/display_native_shop_message_wait_release_and_new_button_then_refresh.s
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCV.
 */
static void display_native_shop_message_wait_release_and_new_button_then_refresh(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const uint8_t db = r->db;
    uint8_t a_hi_7ea6 = 0;
    uint16_t x_7ea6 = 0;
    uint16_t y_7ea6 = 0;
    bool carry_7ea6 = 0;
    bool overflow_7ea6 = 0;
    uint8_t a_7eb6 = 0;
    uint8_t a_hi_7eb6 = 0;
    uint8_t x_7eb6 = 0;
    uint8_t y_7eb6 = 0;
    bool carry_7eb6 = 0;
    bool zero_7eb6 = 0;
    bool negative_7eb6 = 0;
    bool overflow_7eb6 = 0;
    uint16_t direct_page_7eb6 = 0;
    uint8_t data_bank_7eb6 = 0;
    uint8_t a_7eb62 = 0;
    uint8_t a_hi_7eb62 = 0;
    uint16_t x_7eb62 = 0;
    uint16_t y_7eb62 = 0;
    bool carry_7eb62 = 0;
    bool zero_7eb62 = 0;
    bool negative_7eb62 = 0;
    bool overflow_7eb62 = 0;
    uint16_t direct_page_7eb62 = 0;
    uint8_t data_bank_7eb62 = 0;
    uint8_t a_7eb63 = 0;
    uint8_t a_hi_7eb63 = 0;
    uint8_t x_7eb63 = 0;
    uint8_t y_7eb63 = 0;
    bool carry_7eb63 = 0;
    bool zero_7eb63 = 0;
    bool negative_7eb63 = 0;
    bool overflow_7eb63 = 0;
    uint16_t direct_page_7eb63 = 0;
    uint8_t data_bank_7eb63 = 0;
    uint8_t a_7eb64 = 0;
    uint8_t a_hi_7eb64 = 0;
    uint16_t x_7eb64 = 0;
    uint16_t y_7eb64 = 0;
    bool carry_7eb64 = 0;
    bool zero_7eb64 = 0;
    bool negative_7eb64 = 0;
    bool overflow_7eb64 = 0;
    uint16_t direct_page_7eb64 = 0;
    uint8_t data_bank_7eb64 = 0;
    uint8_t a_7ec4 = 0;
    uint8_t a_hi_7ec4 = 0;
    uint8_t x_7ec4 = 0;
    uint8_t y_7ec4 = 0;
    bool carry_7ec4 = 0;
    bool zero_7ec4 = 0;
    bool negative_7ec4 = 0;
    bool overflow_7ec4 = 0;
    uint16_t direct_page_7ec4 = 0;
    uint8_t data_bank_7ec4 = 0;
    uint8_t a_7ec42 = 0;
    uint8_t a_hi_7ec42 = 0;
    uint16_t x_7ec42 = 0;
    uint16_t y_7ec42 = 0;
    bool carry_7ec42 = 0;
    bool zero_7ec42 = 0;
    bool negative_7ec42 = 0;
    bool overflow_7ec42 = 0;
    uint16_t direct_page_7ec42 = 0;
    uint8_t data_bank_7ec42 = 0;
    uint8_t a_7ede = 0;
    uint8_t a_hi_7ede = 0;
    uint8_t x_7ede = 0;
    uint8_t y_7ede = 0;
    bool carry_7ede = 0;
    bool overflow_7ede = 0;
    uint16_t direct_page_7ede = 0;
    uint8_t data_bank_7ede = 0;
    uint8_t a_7ede2 = 0;
    uint8_t a_hi_7ede2 = 0;
    uint16_t x_7ede2 = 0;
    uint16_t y_7ede2 = 0;
    bool carry_7ede2 = 0;
    bool overflow_7ede2 = 0;
    uint16_t direct_page_7ede2 = 0;
    uint8_t data_bank_7ede2 = 0;
    uint8_t a_7ede3 = 0;
    uint8_t a_hi_7ede3 = 0;
    uint8_t x_7ede3 = 0;
    uint8_t y_7ede3 = 0;
    bool carry_7ede3 = 0;
    bool overflow_7ede3 = 0;
    uint16_t direct_page_7ede3 = 0;
    uint8_t data_bank_7ede3 = 0;
    uint8_t a_7ede4 = 0;
    uint8_t a_hi_7ede4 = 0;
    uint16_t x_7ede4 = 0;
    uint16_t y_7ede4 = 0;
    bool carry_7ede4 = 0;
    bool overflow_7ede4 = 0;
    uint16_t direct_page_7ede4 = 0;
    uint8_t data_bank_7ede4 = 0;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1D04);
    if ((value & 1) == 0) {
        a_hi_7ea6 = a >> 8;
        x_7ea6 = x;
        y_7ea6 = y;
        carry_7ea6 = carry;
        overflow_7ea6 = value & 0x40;
        goto shared_7EA6;
    }
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    r->a = (a >> 8 << 8) | 1;
    r->z = (value & 1) == 0;
    r->n = value & 0x80;
    r->v = value & 0x40;
    r->mf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7EA4, 0xC00095); GUARD_JSL(c, sp_call, 0x7EA4); } /* close_dialogue_public_jump */
    r->sp += 2;
    uint16_t a_all = r->a;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    a_hi_7ea6 = a_all >> 8;
    x_7ea6 = (value3 << 8) | value2;
    y_7ea6 = y;
    carry_7ea6 = carry_ret;
    overflow_7ea6 = overflow_ret;
    shared_7EA6:;
    BUS8_SET(c, (db << 0x10) + 0x1D03, 0xD9);
    BUS16_SET(c, (db << 0x10) + 0x1D01, x_7ea6);
    r->a = (a_hi_7ea6 << 8) | 0xD9;
    r->x = x_7ea6;
    r->y = y_7ea6;
    r->c = carry_7ea6;
    r->z = 0;
    r->n = 1;
    r->v = overflow_7ea6;
    r->mf = 1;
    r->xf = 0;
    r->db = db;
    r->dp = dp;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7EB1, 0xC00092); GUARD_JSL(c, sp_call, 0x7EB1); } /* run_native_dialogue_public_jump */
    { const uint16_t sp_call = r->sp; JSL(c, 0x7EB5, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7EB5); } /* external */
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
            a_7eb6 = (uint8_t)a_all3;
            a_hi_7eb6 = a_all3 >> 8;
            x_7eb6 = (uint8_t)x_ret5;
            y_7eb6 = (uint8_t)y_ret2;
            carry_7eb6 = carry_ret3;
            zero_7eb6 = zero_ret3;
            negative_7eb6 = negative_ret3;
            overflow_7eb6 = overflow_ret3;
            direct_page_7eb6 = dp_ret2;
            data_bank_7eb6 = db_ret2;
            goto shared_7EB6;
        } else {
            a_7eb62 = (uint8_t)a_all3;
            a_hi_7eb62 = a_all3 >> 8;
            x_7eb62 = x_ret5;
            y_7eb62 = y_ret2;
            carry_7eb62 = carry_ret3;
            zero_7eb62 = zero_ret3;
            negative_7eb62 = negative_ret3;
            overflow_7eb62 = overflow_ret3;
            direct_page_7eb62 = dp_ret2;
            data_bank_7eb62 = db_ret2;
            goto shared_7EB6_1;
        }
    } else {
        if (x_ret4) {
            a_7eb63 = (uint8_t)a_all3;
            a_hi_7eb63 = a_all3 >> 8;
            x_7eb63 = (uint8_t)x_ret5;
            y_7eb63 = (uint8_t)y_ret2;
            carry_7eb63 = carry_ret3;
            zero_7eb63 = zero_ret3;
            negative_7eb63 = negative_ret3;
            overflow_7eb63 = overflow_ret3;
            direct_page_7eb63 = dp_ret2;
            data_bank_7eb63 = db_ret2;
            goto shared_7EB6_2;
        } else {
            a_7eb64 = (uint8_t)a_all3;
            a_hi_7eb64 = a_all3 >> 8;
            x_7eb64 = x_ret5;
            y_7eb64 = y_ret2;
            carry_7eb64 = carry_ret3;
            zero_7eb64 = zero_ret3;
            negative_7eb64 = negative_ret3;
            overflow_7eb64 = overflow_ret3;
            direct_page_7eb64 = dp_ret2;
            data_bank_7eb64 = db_ret2;
            goto shared_7EB6_3;
        }
    }
    shared_7EB6:;
    r->a = (a_hi_7eb6 << 8) | a_7eb6;
    r->x = x_7eb6;
    r->y = y_7eb6;
    r->c = carry_7eb6;
    r->z = zero_7eb6;
    r->n = negative_7eb6;
    r->v = overflow_7eb6;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7eb6;
    r->dp = direct_page_7eb6;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7EBB, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7EBB); } /* external */
    { const uint16_t sp_call = r->sp; JSR(c, 0x7EBE, 0xC07E80); GUARD_JSR(c, sp_call, 0x7EBE); } /* advance_native_shop_vblank_input_and_active_ring_phase */
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
            a_7eb63 = (uint8_t)a_all5;
            a_hi_7eb63 = a_all5 >> 8;
            x_7eb63 = (uint8_t)x_ret9;
            y_7eb63 = (uint8_t)y_ret4;
            carry_7eb63 = carry_ret5;
            zero_7eb63 = (a_all5 & 0xCFC0) == 0;
            negative_7eb63 = negative_ret5;
            overflow_7eb63 = overflow_ret5;
            direct_page_7eb63 = dp_ret4;
            data_bank_7eb63 = db_ret4;
            goto shared_7EB6_2;
        } else {
            a_7eb64 = (uint8_t)a_all5;
            a_hi_7eb64 = a_all5 >> 8;
            x_7eb64 = x_ret9;
            y_7eb64 = y_ret4;
            carry_7eb64 = carry_ret5;
            zero_7eb64 = (a_all5 & 0xCFC0) == 0;
            negative_7eb64 = negative_ret5;
            overflow_7eb64 = overflow_ret5;
            direct_page_7eb64 = dp_ret4;
            data_bank_7eb64 = db_ret4;
            goto shared_7EB6_3;
        }
    }
    if (x_ret8) {
        a_7ec4 = (uint8_t)a_all5;
        a_hi_7ec4 = a_all5 >> 8;
        x_7ec4 = (uint8_t)x_ret9;
        y_7ec4 = (uint8_t)y_ret4;
        carry_7ec4 = carry_ret5;
        zero_7ec4 = (a_all5 & 0xCFC0) == 0;
        negative_7ec4 = negative_ret5;
        overflow_7ec4 = overflow_ret5;
        direct_page_7ec4 = dp_ret4;
        data_bank_7ec4 = db_ret4;
        goto shared_7EC4;
    } else {
        a_7ec42 = (uint8_t)a_all5;
        a_hi_7ec42 = a_all5 >> 8;
        x_7ec42 = x_ret9;
        y_7ec42 = y_ret4;
        carry_7ec42 = carry_ret5;
        zero_7ec42 = (a_all5 & 0xCFC0) == 0;
        negative_7ec42 = negative_ret5;
        overflow_7ec42 = overflow_ret5;
        direct_page_7ec42 = dp_ret4;
        data_bank_7ec42 = db_ret4;
        goto shared_7EC4_1;
    }
    shared_7EB6_1:;
    r->a = (a_hi_7eb62 << 8) | a_7eb62;
    r->x = x_7eb62;
    r->y = y_7eb62;
    r->c = carry_7eb62;
    r->z = zero_7eb62;
    r->n = negative_7eb62;
    r->v = overflow_7eb62;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7eb62;
    r->dp = direct_page_7eb62;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7EBB, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7EBB); } /* external */
    { const uint16_t sp_call = r->sp; JSR(c, 0x7EBE, 0xC07E80); GUARD_JSR(c, sp_call, 0x7EBE); } /* advance_native_shop_vblank_input_and_active_ring_phase */
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
            a_7eb63 = (uint8_t)a_all7;
            a_hi_7eb63 = a_all7 >> 8;
            x_7eb63 = (uint8_t)x_ret13;
            y_7eb63 = (uint8_t)y_ret6;
            carry_7eb63 = carry_ret7;
            zero_7eb63 = (a_all7 & 0xCFC0) == 0;
            negative_7eb63 = negative_ret7;
            overflow_7eb63 = overflow_ret7;
            direct_page_7eb63 = dp_ret6;
            data_bank_7eb63 = db_ret6;
            goto shared_7EB6_2;
        } else {
            a_7eb64 = (uint8_t)a_all7;
            a_hi_7eb64 = a_all7 >> 8;
            x_7eb64 = x_ret13;
            y_7eb64 = y_ret6;
            carry_7eb64 = carry_ret7;
            zero_7eb64 = (a_all7 & 0xCFC0) == 0;
            negative_7eb64 = negative_ret7;
            overflow_7eb64 = overflow_ret7;
            direct_page_7eb64 = dp_ret6;
            data_bank_7eb64 = db_ret6;
            goto shared_7EB6_3;
        }
    }
    if (x_ret12) {
        a_7ec4 = (uint8_t)a_all7;
        a_hi_7ec4 = a_all7 >> 8;
        x_7ec4 = (uint8_t)x_ret13;
        y_7ec4 = (uint8_t)y_ret6;
        carry_7ec4 = carry_ret7;
        zero_7ec4 = (a_all7 & 0xCFC0) == 0;
        negative_7ec4 = negative_ret7;
        overflow_7ec4 = overflow_ret7;
        direct_page_7ec4 = dp_ret6;
        data_bank_7ec4 = db_ret6;
        goto shared_7EC4;
    } else {
        a_7ec42 = (uint8_t)a_all7;
        a_hi_7ec42 = a_all7 >> 8;
        x_7ec42 = x_ret13;
        y_7ec42 = y_ret6;
        carry_7ec42 = carry_ret7;
        zero_7ec42 = (a_all7 & 0xCFC0) == 0;
        negative_7ec42 = negative_ret7;
        overflow_7ec42 = overflow_ret7;
        direct_page_7ec42 = dp_ret6;
        data_bank_7ec42 = db_ret6;
        goto shared_7EC4_1;
    }
    shared_7EB6_2:;
    r->a = (a_hi_7eb63 << 8) | a_7eb63;
    r->x = x_7eb63;
    r->y = y_7eb63;
    r->c = carry_7eb63;
    r->z = zero_7eb63;
    r->n = negative_7eb63;
    r->v = overflow_7eb63;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7eb63;
    r->dp = direct_page_7eb63;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7EBB, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7EBB); } /* external */
    { const uint16_t sp_call = r->sp; JSR(c, 0x7EBE, 0xC07E80); GUARD_JSR(c, sp_call, 0x7EBE); } /* advance_native_shop_vblank_input_and_active_ring_phase */
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
            a_7eb63 = (uint8_t)a_all9;
            a_hi_7eb63 = a_all9 >> 8;
            x_7eb63 = (uint8_t)x_ret17;
            y_7eb63 = (uint8_t)y_ret8;
            carry_7eb63 = carry_ret9;
            zero_7eb63 = (a_all9 & 0xCFC0) == 0;
            negative_7eb63 = negative_ret9;
            overflow_7eb63 = overflow_ret9;
            direct_page_7eb63 = dp_ret8;
            data_bank_7eb63 = db_ret8;
            goto shared_7EB6_2;
        } else {
            a_7eb64 = (uint8_t)a_all9;
            a_hi_7eb64 = a_all9 >> 8;
            x_7eb64 = x_ret17;
            y_7eb64 = y_ret8;
            carry_7eb64 = carry_ret9;
            zero_7eb64 = (a_all9 & 0xCFC0) == 0;
            negative_7eb64 = negative_ret9;
            overflow_7eb64 = overflow_ret9;
            direct_page_7eb64 = dp_ret8;
            data_bank_7eb64 = db_ret8;
            goto shared_7EB6_3;
        }
    }
    if (x_ret16) {
        a_7ec4 = (uint8_t)a_all9;
        a_hi_7ec4 = a_all9 >> 8;
        x_7ec4 = (uint8_t)x_ret17;
        y_7ec4 = (uint8_t)y_ret8;
        carry_7ec4 = carry_ret9;
        zero_7ec4 = (a_all9 & 0xCFC0) == 0;
        negative_7ec4 = negative_ret9;
        overflow_7ec4 = overflow_ret9;
        direct_page_7ec4 = dp_ret8;
        data_bank_7ec4 = db_ret8;
        goto shared_7EC4;
    } else {
        a_7ec42 = (uint8_t)a_all9;
        a_hi_7ec42 = a_all9 >> 8;
        x_7ec42 = x_ret17;
        y_7ec42 = y_ret8;
        carry_7ec42 = carry_ret9;
        zero_7ec42 = (a_all9 & 0xCFC0) == 0;
        negative_7ec42 = negative_ret9;
        overflow_7ec42 = overflow_ret9;
        direct_page_7ec42 = dp_ret8;
        data_bank_7ec42 = db_ret8;
        goto shared_7EC4_1;
    }
    shared_7EB6_3:;
    r->a = (a_hi_7eb64 << 8) | a_7eb64;
    r->x = x_7eb64;
    r->y = y_7eb64;
    r->c = carry_7eb64;
    r->z = zero_7eb64;
    r->n = negative_7eb64;
    r->v = overflow_7eb64;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7eb64;
    r->dp = direct_page_7eb64;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7EBB, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7EBB); } /* external */
    { const uint16_t sp_call = r->sp; JSR(c, 0x7EBE, 0xC07E80); GUARD_JSR(c, sp_call, 0x7EBE); } /* advance_native_shop_vblank_input_and_active_ring_phase */
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
            a_7eb63 = (uint8_t)a_all11;
            a_hi_7eb63 = a_all11 >> 8;
            x_7eb63 = (uint8_t)x_ret21;
            y_7eb63 = (uint8_t)y_ret10;
            carry_7eb63 = carry_ret11;
            zero_7eb63 = (a_all11 & 0xCFC0) == 0;
            negative_7eb63 = negative_ret11;
            overflow_7eb63 = overflow_ret11;
            direct_page_7eb63 = dp_ret10;
            data_bank_7eb63 = db_ret10;
            goto shared_7EB6_2;
        } else {
            a_7eb64 = (uint8_t)a_all11;
            a_hi_7eb64 = a_all11 >> 8;
            x_7eb64 = x_ret21;
            y_7eb64 = y_ret10;
            carry_7eb64 = carry_ret11;
            zero_7eb64 = (a_all11 & 0xCFC0) == 0;
            negative_7eb64 = negative_ret11;
            overflow_7eb64 = overflow_ret11;
            direct_page_7eb64 = dp_ret10;
            data_bank_7eb64 = db_ret10;
            goto shared_7EB6_3;
        }
    }
    if (x_ret20) {
        a_7ec4 = (uint8_t)a_all11;
        a_hi_7ec4 = a_all11 >> 8;
        x_7ec4 = (uint8_t)x_ret21;
        y_7ec4 = (uint8_t)y_ret10;
        carry_7ec4 = carry_ret11;
        zero_7ec4 = (a_all11 & 0xCFC0) == 0;
        negative_7ec4 = negative_ret11;
        overflow_7ec4 = overflow_ret11;
        direct_page_7ec4 = dp_ret10;
        data_bank_7ec4 = db_ret10;
        goto shared_7EC4;
    } else {
        a_7ec42 = (uint8_t)a_all11;
        a_hi_7ec42 = a_all11 >> 8;
        x_7ec42 = x_ret21;
        y_7ec42 = y_ret10;
        carry_7ec42 = carry_ret11;
        zero_7ec42 = (a_all11 & 0xCFC0) == 0;
        negative_7ec42 = negative_ret11;
        overflow_7ec42 = overflow_ret11;
        direct_page_7ec42 = dp_ret10;
        data_bank_7ec42 = db_ret10;
        goto shared_7EC4_1;
    }
    shared_7EC4:;
    r->a = (a_hi_7ec4 << 8) | a_7ec4;
    r->x = x_7ec4;
    r->y = y_7ec4;
    r->c = carry_7ec4;
    r->z = zero_7ec4;
    r->n = negative_7ec4;
    r->v = overflow_7ec4;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_7ec4;
    r->dp = direct_page_7ec4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7EC6, 0xC07E80); GUARD_JSR(c, sp_call, 0x7EC6); } /* advance_native_shop_vblank_input_and_active_ring_phase */
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
            a_7ec4 = (uint8_t)a_all12;
            a_hi_7ec4 = a_all12 >> 8;
            x_7ec4 = (uint8_t)x_ret23;
            y_7ec4 = (uint8_t)y_ret11;
            carry_7ec4 = carry_ret12;
            zero_7ec4 = (a_all12 & 0xCFC0) == 0;
            negative_7ec4 = negative_ret12;
            overflow_7ec4 = overflow_ret12;
            direct_page_7ec4 = dp_ret11;
            data_bank_7ec4 = db_ret11;
            goto shared_7EC4;
        } else {
            a_7ec42 = (uint8_t)a_all12;
            a_hi_7ec42 = a_all12 >> 8;
            x_7ec42 = x_ret23;
            y_7ec42 = y_ret11;
            carry_7ec42 = carry_ret12;
            zero_7ec42 = (a_all12 & 0xCFC0) == 0;
            negative_7ec42 = negative_ret12;
            overflow_7ec42 = overflow_ret12;
            direct_page_7ec42 = dp_ret11;
            data_bank_7ec42 = db_ret11;
            goto shared_7EC4_1;
        }
    }
    uint8_t value4 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x1804);
    if ((value4 & 0x80) != 0) {
        if (x_ret22) {
            a_7ede = 0x80;
            a_hi_7ede = a_all12 >> 8;
            x_7ede = (uint8_t)x_ret23;
            y_7ede = (uint8_t)y_ret11;
            carry_7ede = carry_ret12;
            overflow_7ede = value4 & 0x40;
            direct_page_7ede = dp_ret11;
            data_bank_7ede = db_ret11;
            goto shared_7EDE;
        } else {
            a_7ede2 = 0x80;
            a_hi_7ede2 = a_all12 >> 8;
            x_7ede2 = x_ret23;
            y_7ede2 = y_ret11;
            carry_7ede2 = carry_ret12;
            overflow_7ede2 = value4 & 0x40;
            direct_page_7ede2 = dp_ret11;
            data_bank_7ede2 = db_ret11;
            goto shared_7EDE_1;
        }
    }
    uint8_t value5 = BUS8_RDP(c, (db_ret11 << 0x10) + 0x1802);
    BUS8_SET(c, (db_ret11 << 0x10) + 0x1802, value5 | 4);
    r->a = (a_all12 >> 8 << 8) | 4;
    r->z = (value5 & 4) == 0;
    r->n = 0;
    r->v = value4 & 0x40;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7EDD, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7EDD); } /* external */
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
            a_7ede = (uint8_t)a_all13;
            a_hi_7ede = a_all13 >> 8;
            x_7ede = (uint8_t)x_ret25;
            y_7ede = (uint8_t)y_ret12;
            carry_7ede = carry_ret13;
            overflow_7ede = overflow_ret13;
            direct_page_7ede = dp_ret12;
            data_bank_7ede = db_ret12;
            goto shared_7EDE;
        } else {
            a_7ede2 = (uint8_t)a_all13;
            a_hi_7ede2 = a_all13 >> 8;
            x_7ede2 = x_ret25;
            y_7ede2 = y_ret12;
            carry_7ede2 = carry_ret13;
            overflow_7ede2 = overflow_ret13;
            direct_page_7ede2 = dp_ret12;
            data_bank_7ede2 = db_ret12;
            goto shared_7EDE_1;
        }
    } else {
        if (x_ret24) {
            a_7ede3 = (uint8_t)a_all13;
            a_hi_7ede3 = a_all13 >> 8;
            x_7ede3 = (uint8_t)x_ret25;
            y_7ede3 = (uint8_t)y_ret12;
            carry_7ede3 = carry_ret13;
            overflow_7ede3 = overflow_ret13;
            direct_page_7ede3 = dp_ret12;
            data_bank_7ede3 = db_ret12;
            goto shared_7EDE_2;
        } else {
            a_7ede4 = (uint8_t)a_all13;
            a_hi_7ede4 = a_all13 >> 8;
            x_7ede4 = x_ret25;
            y_7ede4 = y_ret12;
            carry_7ede4 = carry_ret13;
            overflow_7ede4 = overflow_ret13;
            direct_page_7ede4 = dp_ret12;
            data_bank_7ede4 = db_ret12;
            goto shared_7EDE_3;
        }
    }
    shared_7EC4_1:;
    r->a = (a_hi_7ec42 << 8) | a_7ec42;
    r->x = x_7ec42;
    r->y = y_7ec42;
    r->c = carry_7ec42;
    r->z = zero_7ec42;
    r->n = negative_7ec42;
    r->v = overflow_7ec42;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7ec42;
    r->dp = direct_page_7ec42;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7EC6, 0xC07E80); GUARD_JSR(c, sp_call, 0x7EC6); } /* advance_native_shop_vblank_input_and_active_ring_phase */
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
            a_7ec4 = (uint8_t)a_all14;
            a_hi_7ec4 = a_all14 >> 8;
            x_7ec4 = (uint8_t)x_ret27;
            y_7ec4 = (uint8_t)y_ret13;
            carry_7ec4 = carry_ret14;
            zero_7ec4 = (a_all14 & 0xCFC0) == 0;
            negative_7ec4 = negative_ret14;
            overflow_7ec4 = overflow_ret14;
            direct_page_7ec4 = dp_ret13;
            data_bank_7ec4 = db_ret13;
            goto shared_7EC4;
        } else {
            a_7ec42 = (uint8_t)a_all14;
            a_hi_7ec42 = a_all14 >> 8;
            x_7ec42 = x_ret27;
            y_7ec42 = y_ret13;
            carry_7ec42 = carry_ret14;
            zero_7ec42 = (a_all14 & 0xCFC0) == 0;
            negative_7ec42 = negative_ret14;
            overflow_7ec42 = overflow_ret14;
            direct_page_7ec42 = dp_ret13;
            data_bank_7ec42 = db_ret13;
            goto shared_7EC4_1;
        }
    }
    uint8_t value6 = BUS8_RDP(c, (db_ret13 << 0x10) + 0x1804);
    if ((value6 & 0x80) != 0) {
        if (x_ret26) {
            a_7ede = 0x80;
            a_hi_7ede = a_all14 >> 8;
            x_7ede = (uint8_t)x_ret27;
            y_7ede = (uint8_t)y_ret13;
            carry_7ede = carry_ret14;
            overflow_7ede = value6 & 0x40;
            direct_page_7ede = dp_ret13;
            data_bank_7ede = db_ret13;
            goto shared_7EDE;
        } else {
            a_7ede2 = 0x80;
            a_hi_7ede2 = a_all14 >> 8;
            x_7ede2 = x_ret27;
            y_7ede2 = y_ret13;
            carry_7ede2 = carry_ret14;
            overflow_7ede2 = value6 & 0x40;
            direct_page_7ede2 = dp_ret13;
            data_bank_7ede2 = db_ret13;
            goto shared_7EDE_1;
        }
    }
    uint8_t value7 = BUS8_RDP(c, (db_ret13 << 0x10) + 0x1802);
    BUS8_SET(c, (db_ret13 << 0x10) + 0x1802, value7 | 4);
    r->a = (a_all14 >> 8 << 8) | 4;
    r->z = (value7 & 4) == 0;
    r->n = 0;
    r->v = value6 & 0x40;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7EDD, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7EDD); } /* external */
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
            a_7ede = (uint8_t)a_all15;
            a_hi_7ede = a_all15 >> 8;
            x_7ede = (uint8_t)x_ret29;
            y_7ede = (uint8_t)y_ret14;
            carry_7ede = carry_ret15;
            overflow_7ede = overflow_ret15;
            direct_page_7ede = dp_ret14;
            data_bank_7ede = db_ret14;
            goto shared_7EDE;
        } else {
            a_7ede2 = (uint8_t)a_all15;
            a_hi_7ede2 = a_all15 >> 8;
            x_7ede2 = x_ret29;
            y_7ede2 = y_ret14;
            carry_7ede2 = carry_ret15;
            overflow_7ede2 = overflow_ret15;
            direct_page_7ede2 = dp_ret14;
            data_bank_7ede2 = db_ret14;
            goto shared_7EDE_1;
        }
    } else {
        if (x_ret28) {
            a_7ede3 = (uint8_t)a_all15;
            a_hi_7ede3 = a_all15 >> 8;
            x_7ede3 = (uint8_t)x_ret29;
            y_7ede3 = (uint8_t)y_ret14;
            carry_7ede3 = carry_ret15;
            overflow_7ede3 = overflow_ret15;
            direct_page_7ede3 = dp_ret14;
            data_bank_7ede3 = db_ret14;
            goto shared_7EDE_2;
        } else {
            a_7ede4 = (uint8_t)a_all15;
            a_hi_7ede4 = a_all15 >> 8;
            x_7ede4 = x_ret29;
            y_7ede4 = y_ret14;
            carry_7ede4 = carry_ret15;
            overflow_7ede4 = overflow_ret15;
            direct_page_7ede4 = dp_ret14;
            data_bank_7ede4 = db_ret14;
            goto shared_7EDE_3;
        }
    }
    shared_7EDE:;
    r->a = (a_hi_7ede << 8) | a_7ede;
    r->x = x_7ede;
    r->y = y_7ede;
    r->c = carry_7ede;
    r->v = overflow_7ede;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_7ede;
    r->dp = direct_page_7ede;
    RETURN_RTS(c);
    shared_7EDE_1:;
    r->a = (a_hi_7ede2 << 8) | a_7ede2;
    r->x = x_7ede2;
    r->y = y_7ede2;
    r->c = carry_7ede2;
    r->v = overflow_7ede2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_7ede2;
    r->dp = direct_page_7ede2;
    RETURN_RTS(c);
    shared_7EDE_2:;
    r->a = (a_hi_7ede3 << 8) | a_7ede3;
    r->x = x_7ede3;
    r->y = y_7ede3;
    r->c = carry_7ede3;
    r->v = overflow_7ede3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_7ede3;
    r->dp = direct_page_7ede3;
    RETURN_RTS(c);
    shared_7EDE_3:;
    r->a = (a_hi_7ede4 << 8) | a_7ede4;
    r->x = x_7ede4;
    r->y = y_7ede4;
    r->c = carry_7ede4;
    r->v = overflow_7ede4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_7ede4;
    r->dp = direct_page_7ede4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07E95, SOM_RTS, "gen", display_native_shop_message_wait_release_and_new_button_then_refresh, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, -1, 0, 74, 29)
