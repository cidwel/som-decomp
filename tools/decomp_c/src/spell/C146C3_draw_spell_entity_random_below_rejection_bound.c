#include "som_c.h"

/* C146C3 draw_spell_entity_random_below_rejection_bound   [class B, 69 bytes, 41 instructions]
 * Source: src/rom/draw_spell_entity_random_below_rejection_bound.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$01DA.  Callers read: ABYCV.
 */
static void draw_spell_entity_random_below_rejection_bound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01DA) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_46d9 = 0;
    uint8_t a_hi_46d9 = 0;
    uint16_t y_46d9 = 0;
    bool carry_46d9 = 0;
    bool overflow_46d9 = 0;
    uint16_t direct_page_46d9 = 0;
    uint8_t a_46fd = 0;
    uint8_t a_hi_46fd = 0;
    uint16_t y_46fd = 0;
    uint16_t direct_page_46fd = 0;
    uint8_t data_bank_46fd = 0;
    uint8_t a_46ee = 0;
    uint8_t a_hi_46ee = 0;
    uint16_t x_46ee = 0;
    uint16_t y_46ee = 0;
    bool overflow_46ee = 0;
    uint16_t direct_page_46ee = 0;
    uint8_t a_46f4 = 0;
    uint8_t a_hi_46f4 = 0;
    uint16_t x_46f4 = 0;
    uint16_t y_46f4 = 0;
    bool carry_46f4 = 0;
    bool zero_46f4 = 0;
    bool negative_46f4 = 0;
    bool overflow_46f4 = 0;
    uint16_t direct_page_46f4 = 0;
    uint8_t data_bank_46f4 = 0;
    uint8_t a_46f42 = 0;
    uint8_t a_hi_46f42 = 0;
    uint8_t x_46f42 = 0;
    uint8_t y_46f42 = 0;
    bool carry_46f42 = 0;
    bool zero_46f42 = 0;
    bool negative_46f42 = 0;
    bool overflow_46f42 = 0;
    uint16_t direct_page_46f42 = 0;
    uint8_t data_bank_46f42 = 0;
    uint8_t a_46f43 = 0;
    uint8_t a_hi_46f43 = 0;
    uint16_t x_46f43 = 0;
    uint16_t y_46f43 = 0;
    bool carry_46f43 = 0;
    bool zero_46f43 = 0;
    bool negative_46f43 = 0;
    bool overflow_46f43 = 0;
    uint16_t direct_page_46f43 = 0;
    uint8_t data_bank_46f43 = 0;
    uint8_t a_46fd2 = 0;
    uint8_t a_hi_46fd2 = 0;
    uint8_t y_46fd2 = 0;
    uint16_t direct_page_46fd2 = 0;
    uint8_t data_bank_46fd2 = 0;
    uint8_t a_46fd3 = 0;
    uint8_t a_hi_46fd3 = 0;
    uint16_t y_46fd3 = 0;
    uint16_t direct_page_46fd3 = 0;
    uint8_t data_bank_46fd3 = 0;
    uint8_t a_46f44 = 0;
    uint8_t a_hi_46f44 = 0;
    uint8_t x_46f44 = 0;
    uint8_t y_46f44 = 0;
    bool carry_46f44 = 0;
    bool zero_46f44 = 0;
    bool negative_46f44 = 0;
    bool overflow_46f44 = 0;
    uint16_t direct_page_46f44 = 0;
    uint8_t data_bank_46f44 = 0;
    uint8_t a_46fd4 = 0;
    uint8_t a_hi_46fd4 = 0;
    uint8_t y_46fd4 = 0;
    uint16_t direct_page_46fd4 = 0;
    uint8_t data_bank_46fd4 = 0;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0xDA;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    if ((value & 0xFF) != 0) {
        a_46d9 = value & 0xFF;
        a_hi_46d9 = 0;
        y_46d9 = y;
        carry_46d9 = (uint16_t)(sp0 - 5) >= 2;
        overflow_46d9 = (((uint16_t)(sp0 - 5) ^ 2) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
        direct_page_46d9 = (uint16_t)(sp0 - 7);
        goto shared_46D9;
    }
    a_46d9 = 0;
    a_hi_46d9 = 1;
    y_46d9 = y;
    carry_46d9 = (uint16_t)(sp0 - 5) >= 2;
    overflow_46d9 = (((uint16_t)(sp0 - 5) ^ 2) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    direct_page_46d9 = (uint16_t)(sp0 - 7);
    shared_46D9:;
    BUS16_SET(c, (uint16_t)(direct_page_46d9 + 1), (a_hi_46d9 << 8) | a_46d9);
    if ((uint16_t)(((a_hi_46d9 << 8) | a_46d9) - 1) == 0) {
        a_46fd = (uint8_t)(((a_hi_46d9 << 8) | a_46d9) - 1);
        a_hi_46fd = (uint16_t)(((a_hi_46d9 << 8) | a_46d9) - 1) >> 8;
        y_46fd = y_46d9;
        direct_page_46fd = direct_page_46d9;
        data_bank_46fd = 0x7E;
        goto shared_46FD;
    }
    r->a = (uint16_t)(((a_hi_46d9 << 8) | a_46d9) - 1);
    r->x = (uint16_t)(((a_hi_46d9 << 8) | a_46d9) - 1);
    r->y = y_46d9;
    r->c = carry_46d9;
    r->z = (uint16_t)(((a_hi_46d9 << 8) | a_46d9) - 1) == 0;
    r->n = (uint16_t)(((a_hi_46d9 << 8) | a_46d9) - 1) & 0x8000;
    r->v = overflow_46d9;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = direct_page_46d9;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x46E1, 0xC14720); GUARD_JSR(c, sp_call, 0x46E1); } /* find_highest_set_entity_flag_bit */
    r->sp += 7;
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    a_46ee = 0xFF;
    a_hi_46ee = 1;
    x_46ee = x_ret;
    y_46ee = (uint16_t)(((uint16_t)(a_all - 8) ^ 0xFFFF) + 1);
    overflow_46ee = ((a_all ^ 8) & (a_all ^ (uint16_t)(a_all - 8)) & 0x8000) != 0;
    direct_page_46ee = direct_page_46d9;
    goto shared_46EE;
    shared_46FD:;
    RAM8(0x0000 + sp0 - 3) = a_46fd;
    uint8_t value5 = RAM8(0x0000 + sp0 - 3);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->a = (a_hi_46fd << 8) | value5;
    r->y = y_46fd;
    r->c = value6 & 0x01;
    r->v = value6 & 0x40;
    r->mf = value6 & 0x20;
    r->xf = value6 & 0x10;
    r->db = data_bank_46fd;
    r->dp = (value8 << 8) | value7;
    r->i = value6 & 0x04;
    r->d = value6 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_46EE:;
    if ((uint16_t)(y_46ee - 1) != 0) {
        uint8_t a_46ee_next = (uint8_t)(((a_hi_46ee << 8) | a_46ee) >> 1);
        uint8_t a_hi_46ee_next = ((a_hi_46ee << 8) | a_46ee) >> 1 >> 8;
        uint16_t y_46ee_next = (uint16_t)(y_46ee - 1);
        a_46ee = a_46ee_next;
        a_hi_46ee = a_hi_46ee_next;
        y_46ee = y_46ee_next;
        goto shared_46EE;
    }
    BUS16_SET(c, (uint16_t)(direct_page_46ee + 3), ((a_hi_46ee << 8) | a_46ee) >> 1);
    a_46f4 = (uint8_t)(((a_hi_46ee << 8) | a_46ee) >> 1);
    a_hi_46f4 = ((a_hi_46ee << 8) | a_46ee) >> 1 >> 8;
    x_46f4 = x_46ee;
    y_46f4 = (uint16_t)(y_46ee - 1);
    carry_46f4 = ((a_hi_46ee << 8) | a_46ee) & 0x01;
    zero_46f4 = (uint16_t)(y_46ee - 1) == 0;
    negative_46f4 = (uint16_t)(y_46ee - 1) & 0x8000;
    overflow_46f4 = overflow_46ee;
    direct_page_46f4 = direct_page_46ee;
    data_bank_46f4 = 0x7E;
    goto shared_46F4;
    shared_46F4:;
    r->a = (a_hi_46f4 << 8) | a_46f4;
    r->x = x_46f4;
    r->y = y_46f4;
    r->c = carry_46f4;
    r->z = zero_46f4;
    r->n = negative_46f4;
    r->v = overflow_46f4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_46f4;
    r->dp = direct_page_46f4;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x46F6, 0xC146B0); GUARD_JSR(c, sp_call, 0x46F6); } /* draw_spell_entity_random_byte */
    r->sp += 7;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret2 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret = r->y;
    bool overflow_ret2 = r->v;
    if (m_ret) {
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret + 3));
        uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        if (((uint8_t)a_all2 & value9) >= value10) {
            if (x_ret2) {
                a_46f42 = (uint8_t)a_all2 & value9;
                a_hi_46f42 = a_all2 >> 8;
                x_46f42 = (uint8_t)x_ret3;
                y_46f42 = (uint8_t)y_ret;
                carry_46f42 = ((uint8_t)a_all2 & value9) >= value10;
                zero_46f42 = ((uint8_t)a_all2 & value9) == value10;
                negative_46f42 = (uint8_t)(((uint8_t)a_all2 & value9) - value10) & 0x80;
                overflow_46f42 = overflow_ret2;
                direct_page_46f42 = dp_ret;
                data_bank_46f42 = db_ret;
                goto shared_46F4_1;
            } else {
                a_46f43 = (uint8_t)a_all2 & value9;
                a_hi_46f43 = a_all2 >> 8;
                x_46f43 = x_ret3;
                y_46f43 = y_ret;
                carry_46f43 = ((uint8_t)a_all2 & value9) >= value10;
                zero_46f43 = ((uint8_t)a_all2 & value9) == value10;
                negative_46f43 = (uint8_t)(((uint8_t)a_all2 & value9) - value10) & 0x80;
                overflow_46f43 = overflow_ret2;
                direct_page_46f43 = dp_ret;
                data_bank_46f43 = db_ret;
                goto shared_46F4_2;
            }
        }
        if (x_ret2) {
            a_46fd2 = (uint8_t)a_all2 & value9;
            a_hi_46fd2 = a_all2 >> 8;
            y_46fd2 = (uint8_t)y_ret;
            direct_page_46fd2 = dp_ret;
            data_bank_46fd2 = db_ret;
            goto shared_46FD_1;
        } else {
            a_46fd3 = (uint8_t)a_all2 & value9;
            a_hi_46fd3 = a_all2 >> 8;
            y_46fd3 = y_ret;
            direct_page_46fd3 = dp_ret;
            data_bank_46fd3 = db_ret;
            goto shared_46FD_2;
        }
    } else {
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        if ((a_all2 & value11) >= value12) {
            if (x_ret2) {
                a_46f44 = (uint8_t)(a_all2 & value11);
                a_hi_46f44 = (a_all2 & value11) >> 8;
                x_46f44 = (uint8_t)x_ret3;
                y_46f44 = (uint8_t)y_ret;
                carry_46f44 = (a_all2 & value11) >= value12;
                zero_46f44 = (a_all2 & value11) == value12;
                negative_46f44 = (uint16_t)((a_all2 & value11) - value12) & 0x8000;
                overflow_46f44 = overflow_ret2;
                direct_page_46f44 = dp_ret;
                data_bank_46f44 = db_ret;
                goto shared_46F4_3;
            } else {
                a_46f4 = (uint8_t)(a_all2 & value11);
                a_hi_46f4 = (a_all2 & value11) >> 8;
                x_46f4 = x_ret3;
                y_46f4 = y_ret;
                carry_46f4 = (a_all2 & value11) >= value12;
                zero_46f4 = (a_all2 & value11) == value12;
                negative_46f4 = (uint16_t)((a_all2 & value11) - value12) & 0x8000;
                overflow_46f4 = overflow_ret2;
                direct_page_46f4 = dp_ret;
                data_bank_46f4 = db_ret;
                goto shared_46F4;
            }
        }
        if (x_ret2) {
            a_46fd4 = (uint8_t)(a_all2 & value11);
            a_hi_46fd4 = (a_all2 & value11) >> 8;
            y_46fd4 = (uint8_t)y_ret;
            direct_page_46fd4 = dp_ret;
            data_bank_46fd4 = db_ret;
            goto shared_46FD_3;
        } else {
            a_46fd = (uint8_t)(a_all2 & value11);
            a_hi_46fd = (a_all2 & value11) >> 8;
            y_46fd = y_ret;
            direct_page_46fd = dp_ret;
            data_bank_46fd = db_ret;
            goto shared_46FD;
        }
    }
    shared_46F4_1:;
    r->a = (a_hi_46f42 << 8) | a_46f42;
    r->x = x_46f42;
    r->y = y_46f42;
    r->c = carry_46f42;
    r->z = zero_46f42;
    r->n = negative_46f42;
    r->v = overflow_46f42;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_46f42;
    r->dp = direct_page_46f42;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x46F6, 0xC146B0); GUARD_JSR(c, sp_call, 0x46F6); } /* draw_spell_entity_random_byte */
    r->sp += 7;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret4 = r->xf;
    uint16_t a_all3 = r->a;
    uint16_t x_ret5 = r->x;
    uint16_t y_ret2 = r->y;
    bool overflow_ret3 = r->v;
    if (m_ret2) {
        uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 3));
        uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
        if (((uint8_t)a_all3 & value13) >= value14) {
            if (x_ret4) {
                a_46f42 = (uint8_t)a_all3 & value13;
                a_hi_46f42 = a_all3 >> 8;
                x_46f42 = (uint8_t)x_ret5;
                y_46f42 = (uint8_t)y_ret2;
                carry_46f42 = ((uint8_t)a_all3 & value13) >= value14;
                zero_46f42 = ((uint8_t)a_all3 & value13) == value14;
                negative_46f42 = (uint8_t)(((uint8_t)a_all3 & value13) - value14) & 0x80;
                overflow_46f42 = overflow_ret3;
                direct_page_46f42 = dp_ret2;
                data_bank_46f42 = db_ret2;
                goto shared_46F4_1;
            } else {
                a_46f43 = (uint8_t)a_all3 & value13;
                a_hi_46f43 = a_all3 >> 8;
                x_46f43 = x_ret5;
                y_46f43 = y_ret2;
                carry_46f43 = ((uint8_t)a_all3 & value13) >= value14;
                zero_46f43 = ((uint8_t)a_all3 & value13) == value14;
                negative_46f43 = (uint8_t)(((uint8_t)a_all3 & value13) - value14) & 0x80;
                overflow_46f43 = overflow_ret3;
                direct_page_46f43 = dp_ret2;
                data_bank_46f43 = db_ret2;
                goto shared_46F4_2;
            }
        }
        if (x_ret4) {
            a_46fd2 = (uint8_t)a_all3 & value13;
            a_hi_46fd2 = a_all3 >> 8;
            y_46fd2 = (uint8_t)y_ret2;
            direct_page_46fd2 = dp_ret2;
            data_bank_46fd2 = db_ret2;
            goto shared_46FD_1;
        } else {
            a_46fd3 = (uint8_t)a_all3 & value13;
            a_hi_46fd3 = a_all3 >> 8;
            y_46fd3 = y_ret2;
            direct_page_46fd3 = dp_ret2;
            data_bank_46fd3 = db_ret2;
            goto shared_46FD_2;
        }
    } else {
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 3));
        uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        if ((a_all3 & value15) >= value16) {
            if (x_ret4) {
                a_46f44 = (uint8_t)(a_all3 & value15);
                a_hi_46f44 = (a_all3 & value15) >> 8;
                x_46f44 = (uint8_t)x_ret5;
                y_46f44 = (uint8_t)y_ret2;
                carry_46f44 = (a_all3 & value15) >= value16;
                zero_46f44 = (a_all3 & value15) == value16;
                negative_46f44 = (uint16_t)((a_all3 & value15) - value16) & 0x8000;
                overflow_46f44 = overflow_ret3;
                direct_page_46f44 = dp_ret2;
                data_bank_46f44 = db_ret2;
                goto shared_46F4_3;
            } else {
                a_46f4 = (uint8_t)(a_all3 & value15);
                a_hi_46f4 = (a_all3 & value15) >> 8;
                x_46f4 = x_ret5;
                y_46f4 = y_ret2;
                carry_46f4 = (a_all3 & value15) >= value16;
                zero_46f4 = (a_all3 & value15) == value16;
                negative_46f4 = (uint16_t)((a_all3 & value15) - value16) & 0x8000;
                overflow_46f4 = overflow_ret3;
                direct_page_46f4 = dp_ret2;
                data_bank_46f4 = db_ret2;
                goto shared_46F4;
            }
        }
        if (x_ret4) {
            a_46fd4 = (uint8_t)(a_all3 & value15);
            a_hi_46fd4 = (a_all3 & value15) >> 8;
            y_46fd4 = (uint8_t)y_ret2;
            direct_page_46fd4 = dp_ret2;
            data_bank_46fd4 = db_ret2;
            goto shared_46FD_3;
        } else {
            a_46fd = (uint8_t)(a_all3 & value15);
            a_hi_46fd = (a_all3 & value15) >> 8;
            y_46fd = y_ret2;
            direct_page_46fd = dp_ret2;
            data_bank_46fd = db_ret2;
            goto shared_46FD;
        }
    }
    shared_46F4_2:;
    r->a = (a_hi_46f43 << 8) | a_46f43;
    r->x = x_46f43;
    r->y = y_46f43;
    r->c = carry_46f43;
    r->z = zero_46f43;
    r->n = negative_46f43;
    r->v = overflow_46f43;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_46f43;
    r->dp = direct_page_46f43;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x46F6, 0xC146B0); GUARD_JSR(c, sp_call, 0x46F6); } /* draw_spell_entity_random_byte */
    r->sp += 7;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret6 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t x_ret7 = r->x;
    uint16_t y_ret3 = r->y;
    bool overflow_ret4 = r->v;
    if (m_ret3) {
        uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 3));
        uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
        if (((uint8_t)a_all4 & value17) >= value18) {
            if (x_ret6) {
                a_46f42 = (uint8_t)a_all4 & value17;
                a_hi_46f42 = a_all4 >> 8;
                x_46f42 = (uint8_t)x_ret7;
                y_46f42 = (uint8_t)y_ret3;
                carry_46f42 = ((uint8_t)a_all4 & value17) >= value18;
                zero_46f42 = ((uint8_t)a_all4 & value17) == value18;
                negative_46f42 = (uint8_t)(((uint8_t)a_all4 & value17) - value18) & 0x80;
                overflow_46f42 = overflow_ret4;
                direct_page_46f42 = dp_ret3;
                data_bank_46f42 = db_ret3;
                goto shared_46F4_1;
            } else {
                a_46f43 = (uint8_t)a_all4 & value17;
                a_hi_46f43 = a_all4 >> 8;
                x_46f43 = x_ret7;
                y_46f43 = y_ret3;
                carry_46f43 = ((uint8_t)a_all4 & value17) >= value18;
                zero_46f43 = ((uint8_t)a_all4 & value17) == value18;
                negative_46f43 = (uint8_t)(((uint8_t)a_all4 & value17) - value18) & 0x80;
                overflow_46f43 = overflow_ret4;
                direct_page_46f43 = dp_ret3;
                data_bank_46f43 = db_ret3;
                goto shared_46F4_2;
            }
        }
        if (x_ret6) {
            a_46fd2 = (uint8_t)a_all4 & value17;
            a_hi_46fd2 = a_all4 >> 8;
            y_46fd2 = (uint8_t)y_ret3;
            direct_page_46fd2 = dp_ret3;
            data_bank_46fd2 = db_ret3;
            goto shared_46FD_1;
        } else {
            a_46fd3 = (uint8_t)a_all4 & value17;
            a_hi_46fd3 = a_all4 >> 8;
            y_46fd3 = y_ret3;
            direct_page_46fd3 = dp_ret3;
            data_bank_46fd3 = db_ret3;
            goto shared_46FD_2;
        }
    } else {
        uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 3));
        uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
        if ((a_all4 & value19) >= value20) {
            if (x_ret6) {
                a_46f44 = (uint8_t)(a_all4 & value19);
                a_hi_46f44 = (a_all4 & value19) >> 8;
                x_46f44 = (uint8_t)x_ret7;
                y_46f44 = (uint8_t)y_ret3;
                carry_46f44 = (a_all4 & value19) >= value20;
                zero_46f44 = (a_all4 & value19) == value20;
                negative_46f44 = (uint16_t)((a_all4 & value19) - value20) & 0x8000;
                overflow_46f44 = overflow_ret4;
                direct_page_46f44 = dp_ret3;
                data_bank_46f44 = db_ret3;
                goto shared_46F4_3;
            } else {
                a_46f4 = (uint8_t)(a_all4 & value19);
                a_hi_46f4 = (a_all4 & value19) >> 8;
                x_46f4 = x_ret7;
                y_46f4 = y_ret3;
                carry_46f4 = (a_all4 & value19) >= value20;
                zero_46f4 = (a_all4 & value19) == value20;
                negative_46f4 = (uint16_t)((a_all4 & value19) - value20) & 0x8000;
                overflow_46f4 = overflow_ret4;
                direct_page_46f4 = dp_ret3;
                data_bank_46f4 = db_ret3;
                goto shared_46F4;
            }
        }
        if (x_ret6) {
            a_46fd4 = (uint8_t)(a_all4 & value19);
            a_hi_46fd4 = (a_all4 & value19) >> 8;
            y_46fd4 = (uint8_t)y_ret3;
            direct_page_46fd4 = dp_ret3;
            data_bank_46fd4 = db_ret3;
            goto shared_46FD_3;
        } else {
            a_46fd = (uint8_t)(a_all4 & value19);
            a_hi_46fd = (a_all4 & value19) >> 8;
            y_46fd = y_ret3;
            direct_page_46fd = dp_ret3;
            data_bank_46fd = db_ret3;
            goto shared_46FD;
        }
    }
    shared_46FD_1:;
    RAM8(0x0000 + sp0 - 3) = a_46fd2;
    uint8_t value24 = RAM8(0x0000 + sp0 - 3);
    uint8_t value25 = RAM8(0x0000 + sp0 - 2);
    uint8_t value26 = RAM8(0x0000 + sp0 - 1);
    uint8_t value27 = RAM8(0x0000 + sp0);
    r->a = (a_hi_46fd2 << 8) | value24;
    r->y = y_46fd2;
    r->c = value25 & 0x01;
    r->v = value25 & 0x40;
    r->mf = value25 & 0x20;
    r->xf = value25 & 0x10;
    r->db = data_bank_46fd2;
    r->dp = (value27 << 8) | value26;
    r->i = value25 & 0x04;
    r->d = value25 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_46FD_2:;
    RAM8(0x0000 + sp0 - 3) = a_46fd3;
    uint8_t value31 = RAM8(0x0000 + sp0 - 3);
    uint8_t value32 = RAM8(0x0000 + sp0 - 2);
    uint8_t value33 = RAM8(0x0000 + sp0 - 1);
    uint8_t value34 = RAM8(0x0000 + sp0);
    r->a = (a_hi_46fd3 << 8) | value31;
    r->y = y_46fd3;
    r->c = value32 & 0x01;
    r->v = value32 & 0x40;
    r->mf = value32 & 0x20;
    r->xf = value32 & 0x10;
    r->db = data_bank_46fd3;
    r->dp = (value34 << 8) | value33;
    r->i = value32 & 0x04;
    r->d = value32 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_46F4_3:;
    r->a = (a_hi_46f44 << 8) | a_46f44;
    r->x = x_46f44;
    r->y = y_46f44;
    r->c = carry_46f44;
    r->z = zero_46f44;
    r->n = negative_46f44;
    r->v = overflow_46f44;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_46f44;
    r->dp = direct_page_46f44;
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x46F6, 0xC146B0); GUARD_JSR(c, sp_call, 0x46F6); } /* draw_spell_entity_random_byte */
    r->sp += 7;
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret8 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret4 = r->y;
    bool overflow_ret5 = r->v;
    if (m_ret4) {
        uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 3));
        uint8_t value36 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
        if (((uint8_t)a_all5 & value35) >= value36) {
            if (x_ret8) {
                a_46f42 = (uint8_t)a_all5 & value35;
                a_hi_46f42 = a_all5 >> 8;
                x_46f42 = (uint8_t)x_ret9;
                y_46f42 = (uint8_t)y_ret4;
                carry_46f42 = ((uint8_t)a_all5 & value35) >= value36;
                zero_46f42 = ((uint8_t)a_all5 & value35) == value36;
                negative_46f42 = (uint8_t)(((uint8_t)a_all5 & value35) - value36) & 0x80;
                overflow_46f42 = overflow_ret5;
                direct_page_46f42 = dp_ret4;
                data_bank_46f42 = db_ret4;
                goto shared_46F4_1;
            } else {
                a_46f43 = (uint8_t)a_all5 & value35;
                a_hi_46f43 = a_all5 >> 8;
                x_46f43 = x_ret9;
                y_46f43 = y_ret4;
                carry_46f43 = ((uint8_t)a_all5 & value35) >= value36;
                zero_46f43 = ((uint8_t)a_all5 & value35) == value36;
                negative_46f43 = (uint8_t)(((uint8_t)a_all5 & value35) - value36) & 0x80;
                overflow_46f43 = overflow_ret5;
                direct_page_46f43 = dp_ret4;
                data_bank_46f43 = db_ret4;
                goto shared_46F4_2;
            }
        }
        if (x_ret8) {
            a_46fd2 = (uint8_t)a_all5 & value35;
            a_hi_46fd2 = a_all5 >> 8;
            y_46fd2 = (uint8_t)y_ret4;
            direct_page_46fd2 = dp_ret4;
            data_bank_46fd2 = db_ret4;
            goto shared_46FD_1;
        } else {
            a_46fd3 = (uint8_t)a_all5 & value35;
            a_hi_46fd3 = a_all5 >> 8;
            y_46fd3 = y_ret4;
            direct_page_46fd3 = dp_ret4;
            data_bank_46fd3 = db_ret4;
            goto shared_46FD_2;
        }
    } else {
        uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 3));
        uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 1));
        if ((a_all5 & value37) >= value38) {
            if (x_ret8) {
                a_46f44 = (uint8_t)(a_all5 & value37);
                a_hi_46f44 = (a_all5 & value37) >> 8;
                x_46f44 = (uint8_t)x_ret9;
                y_46f44 = (uint8_t)y_ret4;
                carry_46f44 = (a_all5 & value37) >= value38;
                zero_46f44 = (a_all5 & value37) == value38;
                negative_46f44 = (uint16_t)((a_all5 & value37) - value38) & 0x8000;
                overflow_46f44 = overflow_ret5;
                direct_page_46f44 = dp_ret4;
                data_bank_46f44 = db_ret4;
                goto shared_46F4_3;
            } else {
                a_46f4 = (uint8_t)(a_all5 & value37);
                a_hi_46f4 = (a_all5 & value37) >> 8;
                x_46f4 = x_ret9;
                y_46f4 = y_ret4;
                carry_46f4 = (a_all5 & value37) >= value38;
                zero_46f4 = (a_all5 & value37) == value38;
                negative_46f4 = (uint16_t)((a_all5 & value37) - value38) & 0x8000;
                overflow_46f4 = overflow_ret5;
                direct_page_46f4 = dp_ret4;
                data_bank_46f4 = db_ret4;
                goto shared_46F4;
            }
        }
        if (x_ret8) {
            a_46fd4 = (uint8_t)(a_all5 & value37);
            a_hi_46fd4 = (a_all5 & value37) >> 8;
            y_46fd4 = (uint8_t)y_ret4;
            direct_page_46fd4 = dp_ret4;
            data_bank_46fd4 = db_ret4;
            goto shared_46FD_3;
        } else {
            a_46fd = (uint8_t)(a_all5 & value37);
            a_hi_46fd = (a_all5 & value37) >> 8;
            y_46fd = y_ret4;
            direct_page_46fd = dp_ret4;
            data_bank_46fd = db_ret4;
            goto shared_46FD;
        }
    }
    shared_46FD_3:;
    RAM8(0x0000 + sp0 - 3) = a_46fd4;
    uint8_t value42 = RAM8(0x0000 + sp0 - 3);
    uint8_t value43 = RAM8(0x0000 + sp0 - 2);
    uint8_t value44 = RAM8(0x0000 + sp0 - 1);
    uint8_t value45 = RAM8(0x0000 + sp0);
    r->a = (a_hi_46fd4 << 8) | value42;
    r->y = y_46fd4;
    r->c = value43 & 0x01;
    r->v = value43 & 0x40;
    r->mf = value43 & 0x20;
    r->xf = value43 & 0x10;
    r->db = data_bank_46fd4;
    r->dp = (value45 << 8) | value44;
    r->i = value43 & 0x04;
    r->d = value43 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC146C3, SOM_RTS, "gen", draw_spell_entity_random_below_rejection_bound, 0, L_A | L_B | L_Y | L_C | L_V, 7, 1, 0, 69, 41)
