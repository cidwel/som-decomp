#include "som_c.h"

/* 7E98AF run_native_title_nine_sprite_particle_until_offscreen   [class B, 94 bytes, 47 instructions]
 * Source: src/boot/run_native_title_nine_sprite_particle_until_offscreen.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void run_native_title_nine_sprite_particle_until_offscreen(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_hi_98ce = 0;
    uint8_t y_98ce = 0;
    bool carry_98ce = 0;
    bool zero_98ce = 0;
    bool negative_98ce = 0;
    bool overflow_98ce = 0;
    uint16_t direct_page_98ce = 0;
    uint8_t data_bank_98ce = 0;
    uint8_t a_hi_98ce2 = 0;
    uint16_t y_98ce2 = 0;
    bool carry_98ce2 = 0;
    bool zero_98ce2 = 0;
    bool negative_98ce2 = 0;
    bool overflow_98ce2 = 0;
    uint16_t direct_page_98ce2 = 0;
    uint8_t data_bank_98ce2 = 0;
    uint8_t a_hi_98ce3 = 0;
    uint8_t y_98ce3 = 0;
    bool carry_98ce3 = 0;
    bool zero_98ce3 = 0;
    bool negative_98ce3 = 0;
    bool overflow_98ce3 = 0;
    uint16_t direct_page_98ce3 = 0;
    uint8_t data_bank_98ce3 = 0;
    uint8_t a_hi_98ce4 = 0;
    uint16_t y_98ce4 = 0;
    bool carry_98ce4 = 0;
    bool zero_98ce4 = 0;
    bool negative_98ce4 = 0;
    bool overflow_98ce4 = 0;
    uint16_t direct_page_98ce4 = 0;
    uint8_t data_bank_98ce4 = 0;
    uint8_t a_hi_98f0 = 0;
    uint8_t x_98f0 = 0;
    uint8_t y_98f0 = 0;
    uint16_t direct_page_98f0 = 0;
    uint8_t data_bank_98f0 = 0;
    uint8_t a_hi_98f02 = 0;
    uint16_t x_98f02 = 0;
    uint16_t y_98f02 = 0;
    uint16_t direct_page_98f02 = 0;
    uint8_t data_bank_98f02 = 0;
    uint8_t a_98ec = 0;
    uint8_t a_hi_98ec = 0;
    uint8_t x_98ec = 0;
    uint8_t y_98ec = 0;
    uint16_t direct_page_98ec = 0;
    uint8_t data_bank_98ec = 0;
    uint8_t a_98ec2 = 0;
    uint8_t a_hi_98ec2 = 0;
    uint16_t x_98ec2 = 0;
    uint16_t y_98ec2 = 0;
    uint16_t direct_page_98ec2 = 0;
    uint8_t data_bank_98ec2 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->a = (a_hi << 8) | 0x7F;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->db = 0x7F;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98BE, 0x7EAD41); GUARD_JSR(c, sp_call, 0x98BE); } /* select_native_task_stack_page_as_direct_page */
    r->sp += 4;
    r->a = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98C4, 0x7EC288); GUARD_JSR(c, sp_call, 0x98C4); } /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 4;
    bool x_ret = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret = r->y;
    if (x_ret) {
        r->x = (uint8_t)a_all2;
        r->y = (uint8_t)y_ret;
        r->z = (uint8_t)a_all2 == 0;
        r->n = (uint8_t)a_all2 & 0x80;
        r->xf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x98C8, 0x7EABE7); GUARD_JSR(c, sp_call, 0x98C8); } /* receive_with_supplied_delay */
        r->sp += 4;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x98CB, 0x7E9808); GUARD_JSR(c, sp_call, 0x98CB); } /* initialize_nine_native_title_particle_sprites_and_random_velocity */
        r->sp += 4;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret3 = r->mf;
        bool x_ret5 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t y_ret3 = r->y;
        bool carry_ret4 = r->c;
        bool zero_ret4 = r->z;
        bool negative_ret4 = r->n;
        bool overflow_ret4 = r->v;
        if (m_ret3) {
            BUS8_SET(c, (uint16_t)(dp_ret3 + 0x1E), 0);
            if (x_ret5) {
                a_hi_98ce = a_all4 >> 8;
                y_98ce = (uint8_t)y_ret3;
                carry_98ce = carry_ret4;
                zero_98ce = zero_ret4;
                negative_98ce = negative_ret4;
                overflow_98ce = overflow_ret4;
                direct_page_98ce = dp_ret3;
                data_bank_98ce = db_ret2;
                goto shared_98CE;
            } else {
                a_hi_98ce2 = a_all4 >> 8;
                y_98ce2 = y_ret3;
                carry_98ce2 = carry_ret4;
                zero_98ce2 = zero_ret4;
                negative_98ce2 = negative_ret4;
                overflow_98ce2 = overflow_ret4;
                direct_page_98ce2 = dp_ret3;
                data_bank_98ce2 = db_ret2;
                goto shared_98CE_1;
            }
        } else {
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x1E), 0);
            if (x_ret5) {
                a_hi_98ce3 = a_all4 >> 8;
                y_98ce3 = (uint8_t)y_ret3;
                carry_98ce3 = carry_ret4;
                zero_98ce3 = zero_ret4;
                negative_98ce3 = negative_ret4;
                overflow_98ce3 = overflow_ret4;
                direct_page_98ce3 = dp_ret3;
                data_bank_98ce3 = db_ret2;
                goto shared_98CE_2;
            } else {
                a_hi_98ce4 = a_all4 >> 8;
                y_98ce4 = y_ret3;
                carry_98ce4 = carry_ret4;
                zero_98ce4 = zero_ret4;
                negative_98ce4 = negative_ret4;
                overflow_98ce4 = overflow_ret4;
                direct_page_98ce4 = dp_ret3;
                data_bank_98ce4 = db_ret2;
                goto shared_98CE_3;
            }
        }
    } else {
        r->x = a_all2;
        r->z = a_all2 == 0;
        r->n = a_all2 & 0x8000;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x98C8, 0x7EABE7); GUARD_JSR(c, sp_call, 0x98C8); } /* receive_with_supplied_delay */
        r->sp += 4;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x98CB, 0x7E9808); GUARD_JSR(c, sp_call, 0x98CB); } /* initialize_nine_native_title_particle_sprites_and_random_velocity */
        r->sp += 4;
        uint16_t dp_ret5 = r->dp;
        uint8_t db_ret4 = r->db;
        bool m_ret5 = r->mf;
        bool x_ret9 = r->xf;
        uint16_t a_all6 = r->a;
        uint16_t y_ret5 = r->y;
        bool carry_ret6 = r->c;
        bool zero_ret6 = r->z;
        bool negative_ret6 = r->n;
        bool overflow_ret6 = r->v;
        if (m_ret5) {
            BUS8_SET(c, (uint16_t)(dp_ret5 + 0x1E), 0);
            if (x_ret9) {
                a_hi_98ce = a_all6 >> 8;
                y_98ce = (uint8_t)y_ret5;
                carry_98ce = carry_ret6;
                zero_98ce = zero_ret6;
                negative_98ce = negative_ret6;
                overflow_98ce = overflow_ret6;
                direct_page_98ce = dp_ret5;
                data_bank_98ce = db_ret4;
                goto shared_98CE;
            } else {
                a_hi_98ce2 = a_all6 >> 8;
                y_98ce2 = y_ret5;
                carry_98ce2 = carry_ret6;
                zero_98ce2 = zero_ret6;
                negative_98ce2 = negative_ret6;
                overflow_98ce2 = overflow_ret6;
                direct_page_98ce2 = dp_ret5;
                data_bank_98ce2 = db_ret4;
                goto shared_98CE_1;
            }
        } else {
            BUS16_SET(c, (uint16_t)(dp_ret5 + 0x1E), 0);
            if (x_ret9) {
                a_hi_98ce3 = a_all6 >> 8;
                y_98ce3 = (uint8_t)y_ret5;
                carry_98ce3 = carry_ret6;
                zero_98ce3 = zero_ret6;
                negative_98ce3 = negative_ret6;
                overflow_98ce3 = overflow_ret6;
                direct_page_98ce3 = dp_ret5;
                data_bank_98ce3 = db_ret4;
                goto shared_98CE_2;
            } else {
                a_hi_98ce4 = a_all6 >> 8;
                y_98ce4 = y_ret5;
                carry_98ce4 = carry_ret6;
                zero_98ce4 = zero_ret6;
                negative_98ce4 = negative_ret6;
                overflow_98ce4 = overflow_ret6;
                direct_page_98ce4 = dp_ret5;
                data_bank_98ce4 = db_ret4;
                goto shared_98CE_3;
            }
        }
    }
    shared_98CE:;
    r->y = y_98ce;
    r->c = carry_98ce;
    r->z = zero_98ce;
    r->n = negative_98ce;
    r->v = overflow_98ce;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_98ce;
    r->dp = direct_page_98ce;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98D0, 0x7E9875); GUARD_JSR(c, sp_call, 0x98D0); } /* integrate_native_title_particle_signed_fractional_positions */
    r->sp += 4;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 2;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98D6, 0x7EABE7); GUARD_JSR(c, sp_call, 0x98D6); } /* receive_with_supplied_delay */
    r->sp += 4;
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret6 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret12 = r->xf;
    uint16_t x_ret13 = r->x;
    uint16_t y_ret7 = r->y;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp_ret7 + 0x1E));
    BUS16_SET(c, (uint16_t)(dp_ret7 + 0x1E), (uint16_t)(value + 1));
    if (((uint16_t)(value + 1) & 3) != 0) {
        if (x_ret12) {
            a_hi_98f0 = 0;
            x_98f0 = (uint8_t)x_ret13;
            y_98f0 = (uint8_t)y_ret7;
            direct_page_98f0 = dp_ret7;
            data_bank_98f0 = db_ret6;
            goto shared_98F0;
        } else {
            a_hi_98f02 = 0;
            x_98f02 = x_ret13;
            y_98f02 = y_ret7;
            direct_page_98f02 = dp_ret7;
            data_bank_98f02 = db_ret6;
            goto shared_98F0_1;
        }
    }
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 1));
    if ((uint8_t)(value2 + 1) < 0x0A) {
        if (x_ret12) {
            a_98ec = (uint8_t)(value2 + 1);
            a_hi_98ec = 0;
            x_98ec = (uint8_t)x_ret13;
            y_98ec = (uint8_t)y_ret7;
            direct_page_98ec = dp_ret7;
            data_bank_98ec = db_ret6;
            goto shared_98EC;
        } else {
            a_98ec2 = (uint8_t)(value2 + 1);
            a_hi_98ec2 = 0;
            x_98ec2 = x_ret13;
            y_98ec2 = y_ret7;
            direct_page_98ec2 = dp_ret7;
            data_bank_98ec2 = db_ret6;
            goto shared_98EC_1;
        }
    }
    if (x_ret12) {
        a_98ec = 0;
        a_hi_98ec = 0;
        x_98ec = (uint8_t)x_ret13;
        y_98ec = (uint8_t)y_ret7;
        direct_page_98ec = dp_ret7;
        data_bank_98ec = db_ret6;
        goto shared_98EC;
    } else {
        a_98ec2 = 0;
        a_hi_98ec2 = 0;
        x_98ec2 = x_ret13;
        y_98ec2 = y_ret7;
        direct_page_98ec2 = dp_ret7;
        data_bank_98ec2 = db_ret6;
        goto shared_98EC_1;
    }
    shared_98CE_1:;
    r->y = y_98ce2;
    r->c = carry_98ce2;
    r->z = zero_98ce2;
    r->n = negative_98ce2;
    r->v = overflow_98ce2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_98ce2;
    r->dp = direct_page_98ce2;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98D0, 0x7E9875); GUARD_JSR(c, sp_call, 0x98D0); } /* integrate_native_title_particle_signed_fractional_positions */
    r->sp += 4;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 2;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98D6, 0x7EABE7); GUARD_JSR(c, sp_call, 0x98D6); } /* receive_with_supplied_delay */
    r->sp += 4;
    uint16_t dp_ret9 = r->dp;
    uint8_t db_ret8 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret15 = r->xf;
    uint16_t x_ret16 = r->x;
    uint16_t y_ret9 = r->y;
    uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret9 + 0x1E));
    BUS16_SET(c, (uint16_t)(dp_ret9 + 0x1E), (uint16_t)(value3 + 1));
    if (((uint16_t)(value3 + 1) & 3) != 0) {
        if (x_ret15) {
            a_hi_98f0 = 0;
            x_98f0 = (uint8_t)x_ret16;
            y_98f0 = (uint8_t)y_ret9;
            direct_page_98f0 = dp_ret9;
            data_bank_98f0 = db_ret8;
            goto shared_98F0;
        } else {
            a_hi_98f02 = 0;
            x_98f02 = x_ret16;
            y_98f02 = y_ret9;
            direct_page_98f02 = dp_ret9;
            data_bank_98f02 = db_ret8;
            goto shared_98F0_1;
        }
    }
    uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 1));
    if ((uint8_t)(value4 + 1) < 0x0A) {
        if (x_ret15) {
            a_98ec = (uint8_t)(value4 + 1);
            a_hi_98ec = 0;
            x_98ec = (uint8_t)x_ret16;
            y_98ec = (uint8_t)y_ret9;
            direct_page_98ec = dp_ret9;
            data_bank_98ec = db_ret8;
            goto shared_98EC;
        } else {
            a_98ec2 = (uint8_t)(value4 + 1);
            a_hi_98ec2 = 0;
            x_98ec2 = x_ret16;
            y_98ec2 = y_ret9;
            direct_page_98ec2 = dp_ret9;
            data_bank_98ec2 = db_ret8;
            goto shared_98EC_1;
        }
    }
    if (x_ret15) {
        a_98ec = 0;
        a_hi_98ec = 0;
        x_98ec = (uint8_t)x_ret16;
        y_98ec = (uint8_t)y_ret9;
        direct_page_98ec = dp_ret9;
        data_bank_98ec = db_ret8;
        goto shared_98EC;
    } else {
        a_98ec2 = 0;
        a_hi_98ec2 = 0;
        x_98ec2 = x_ret16;
        y_98ec2 = y_ret9;
        direct_page_98ec2 = dp_ret9;
        data_bank_98ec2 = db_ret8;
        goto shared_98EC_1;
    }
    shared_98CE_2:;
    r->y = y_98ce3;
    r->c = carry_98ce3;
    r->z = zero_98ce3;
    r->n = negative_98ce3;
    r->v = overflow_98ce3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_98ce3;
    r->dp = direct_page_98ce3;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98D0, 0x7E9875); GUARD_JSR(c, sp_call, 0x98D0); } /* integrate_native_title_particle_signed_fractional_positions */
    r->sp += 4;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 2;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98D6, 0x7EABE7); GUARD_JSR(c, sp_call, 0x98D6); } /* receive_with_supplied_delay */
    r->sp += 4;
    uint16_t dp_ret11 = r->dp;
    uint8_t db_ret10 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret18 = r->xf;
    uint16_t x_ret19 = r->x;
    uint16_t y_ret11 = r->y;
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret11 + 0x1E));
    BUS16_SET(c, (uint16_t)(dp_ret11 + 0x1E), (uint16_t)(value5 + 1));
    if (((uint16_t)(value5 + 1) & 3) != 0) {
        if (x_ret18) {
            a_hi_98f0 = 0;
            x_98f0 = (uint8_t)x_ret19;
            y_98f0 = (uint8_t)y_ret11;
            direct_page_98f0 = dp_ret11;
            data_bank_98f0 = db_ret10;
            goto shared_98F0;
        } else {
            a_hi_98f02 = 0;
            x_98f02 = x_ret19;
            y_98f02 = y_ret11;
            direct_page_98f02 = dp_ret11;
            data_bank_98f02 = db_ret10;
            goto shared_98F0_1;
        }
    }
    uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret11 + 1));
    if ((uint8_t)(value6 + 1) < 0x0A) {
        if (x_ret18) {
            a_98ec = (uint8_t)(value6 + 1);
            a_hi_98ec = 0;
            x_98ec = (uint8_t)x_ret19;
            y_98ec = (uint8_t)y_ret11;
            direct_page_98ec = dp_ret11;
            data_bank_98ec = db_ret10;
            goto shared_98EC;
        } else {
            a_98ec2 = (uint8_t)(value6 + 1);
            a_hi_98ec2 = 0;
            x_98ec2 = x_ret19;
            y_98ec2 = y_ret11;
            direct_page_98ec2 = dp_ret11;
            data_bank_98ec2 = db_ret10;
            goto shared_98EC_1;
        }
    }
    if (x_ret18) {
        a_98ec = 0;
        a_hi_98ec = 0;
        x_98ec = (uint8_t)x_ret19;
        y_98ec = (uint8_t)y_ret11;
        direct_page_98ec = dp_ret11;
        data_bank_98ec = db_ret10;
        goto shared_98EC;
    } else {
        a_98ec2 = 0;
        a_hi_98ec2 = 0;
        x_98ec2 = x_ret19;
        y_98ec2 = y_ret11;
        direct_page_98ec2 = dp_ret11;
        data_bank_98ec2 = db_ret10;
        goto shared_98EC_1;
    }
    shared_98CE_3:;
    r->y = y_98ce4;
    r->c = carry_98ce4;
    r->z = zero_98ce4;
    r->n = negative_98ce4;
    r->v = overflow_98ce4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_98ce4;
    r->dp = direct_page_98ce4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98D0, 0x7E9875); GUARD_JSR(c, sp_call, 0x98D0); } /* integrate_native_title_particle_signed_fractional_positions */
    r->sp += 4;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 2;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98D6, 0x7EABE7); GUARD_JSR(c, sp_call, 0x98D6); } /* receive_with_supplied_delay */
    r->sp += 4;
    uint16_t dp_ret13 = r->dp;
    uint8_t db_ret12 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret21 = r->xf;
    uint16_t x_ret22 = r->x;
    uint16_t y_ret13 = r->y;
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret13 + 0x1E));
    BUS16_SET(c, (uint16_t)(dp_ret13 + 0x1E), (uint16_t)(value7 + 1));
    if (((uint16_t)(value7 + 1) & 3) != 0) {
        if (x_ret21) {
            a_hi_98f0 = 0;
            x_98f0 = (uint8_t)x_ret22;
            y_98f0 = (uint8_t)y_ret13;
            direct_page_98f0 = dp_ret13;
            data_bank_98f0 = db_ret12;
            goto shared_98F0;
        } else {
            a_hi_98f02 = 0;
            x_98f02 = x_ret22;
            y_98f02 = y_ret13;
            direct_page_98f02 = dp_ret13;
            data_bank_98f02 = db_ret12;
            goto shared_98F0_1;
        }
    }
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret13 + 1));
    if ((uint8_t)(value8 + 1) < 0x0A) {
        if (x_ret21) {
            a_98ec = (uint8_t)(value8 + 1);
            a_hi_98ec = 0;
            x_98ec = (uint8_t)x_ret22;
            y_98ec = (uint8_t)y_ret13;
            direct_page_98ec = dp_ret13;
            data_bank_98ec = db_ret12;
            goto shared_98EC;
        } else {
            a_98ec2 = (uint8_t)(value8 + 1);
            a_hi_98ec2 = 0;
            x_98ec2 = x_ret22;
            y_98ec2 = y_ret13;
            direct_page_98ec2 = dp_ret13;
            data_bank_98ec2 = db_ret12;
            goto shared_98EC_1;
        }
    }
    if (x_ret21) {
        a_98ec = 0;
        a_hi_98ec = 0;
        x_98ec = (uint8_t)x_ret22;
        y_98ec = (uint8_t)y_ret13;
        direct_page_98ec = dp_ret13;
        data_bank_98ec = db_ret12;
        goto shared_98EC;
    } else {
        a_98ec2 = 0;
        a_hi_98ec2 = 0;
        x_98ec2 = x_ret22;
        y_98ec2 = y_ret13;
        direct_page_98ec2 = dp_ret13;
        data_bank_98ec2 = db_ret12;
        goto shared_98EC_1;
    }
    shared_98F0:;
    uint16_t value9 = BUS16_RDP(c, (uint16_t)(direct_page_98f0 + 0x0A));
    if (((uint16_t)(value9 + 0x28) & 0x8000) == 0) {
        a_hi_98ce3 = ((uint16_t)(value9 + 0x28) & 0x8000) >> 8;
        y_98ce3 = y_98f0;
        carry_98ce3 = value9 + 0x28 > 0xFFFF;
        zero_98ce3 = ((uint16_t)(value9 + 0x28) & 0x8000) == 0;
        negative_98ce3 = (uint16_t)(value9 + 0x28) & 0x8000 & 0x8000;
        overflow_98ce3 = ((value9 ^ (uint16_t)(value9 + 0x28)) & ((uint16_t)(value9 + 0x28) ^ 0x28) & 0x8000) != 0;
        direct_page_98ce3 = direct_page_98f0;
        data_bank_98ce3 = data_bank_98f0;
        goto shared_98CE_2;
    }
    r->a = (uint16_t)(value9 + 0x28) & 0x8000;
    r->x = x_98f0;
    r->y = y_98f0;
    r->c = value9 + 0x28 > 0xFFFF;
    r->z = ((uint16_t)(value9 + 0x28) & 0x8000) == 0;
    r->n = (uint16_t)(value9 + 0x28) & 0x8000 & 0x8000;
    r->v = ((value9 ^ (uint16_t)(value9 + 0x28)) & ((uint16_t)(value9 + 0x28) ^ 0x28) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_98f0;
    r->dp = direct_page_98f0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98FD, 0x7E97EF); GUARD_JSR(c, sp_call, 0x98FD); } /* release_nine_native_title_particle_sprite_records */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9900, 0x7EACD0); GUARD_JSR(c, sp_call, 0x9900); } /* current_task_parent_id */
    r->sp += 4;
    bool m_ret11 = r->mf;
    uint16_t a_all16 = r->a;
    if (m_ret11) {
        RAM8(0x0000 + sp0 - 4) = (uint8_t)a_all16;
        r->mf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9904, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x9904); } /* allocate_eight_byte_record */
        r->sp += 5;
        bool m_ret12 = r->mf;
        uint16_t a_all17 = r->a;
        if (m_ret12) {
            uint8_t value10 = RAM8(0x0000 + sp0 - 4);
            r->a = (a_all17 >> 8 << 8) | value10;
            r->z = value10 == 0;
            r->n = value10 & 0x80;
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9908, 0x7EB258); GUARD_JSR(c, sp_call, 0x9908); } /* append_pending_record */
            r->sp += 4;
            uint8_t value11 = RAM8(0x0000 + sp0 - 3);
            uint8_t value12 = RAM8(0x0000 + sp0 - 2);
            uint8_t value13 = RAM8(0x0000 + sp0 - 1);
            uint8_t value14 = RAM8(0x0000 + sp0);
            r->c = value12 & 0x01;
            r->z = ((value14 << 8) | value13) == 0;
            r->n = ((value14 << 8) | value13) & 0x8000;
            r->v = value12 & 0x40;
            r->mf = value12 & 0x20;
            r->xf = value12 & 0x10;
            r->db = value11;
            r->dp = (value14 << 8) | value13;
            r->i = value12 & 0x04;
            r->d = value12 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        } else {
            c->fail = 3;
            return;
        }
    } else {
        RAM8(0x0000 + sp0 - 4) = a_all16 >> 8;
        RAM8(0x0000 + sp0 - 5) = (uint8_t)a_all16;
        r->mf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9904, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x9904); } /* allocate_eight_byte_record */
        r->sp += 6;
        bool m_ret15 = r->mf;
        if (m_ret15) {
            c->fail = 3;
            return;
        } else {
            uint8_t value24 = RAM8(0x0000 + sp0 - 5);
            uint8_t value25 = RAM8(0x0000 + sp0 - 4);
            r->a = (value25 << 8) | value24;
            r->z = ((value25 << 8) | value24) == 0;
            r->n = ((value25 << 8) | value24) & 0x8000;
            r->mf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9908, 0x7EB258); GUARD_JSR(c, sp_call, 0x9908); } /* append_pending_record */
            r->sp += 4;
            uint8_t value26 = RAM8(0x0000 + sp0 - 3);
            uint8_t value27 = RAM8(0x0000 + sp0 - 2);
            uint8_t value28 = RAM8(0x0000 + sp0 - 1);
            uint8_t value29 = RAM8(0x0000 + sp0);
            r->c = value27 & 0x01;
            r->z = ((value29 << 8) | value28) == 0;
            r->n = ((value29 << 8) | value28) & 0x8000;
            r->v = value27 & 0x40;
            r->mf = value27 & 0x20;
            r->xf = value27 & 0x10;
            r->db = value26;
            r->dp = (value29 << 8) | value28;
            r->i = value27 & 0x04;
            r->d = value27 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
    }
    shared_98F0_1:;
    uint16_t value30 = BUS16_RDP(c, (uint16_t)(direct_page_98f02 + 0x0A));
    if (((uint16_t)(value30 + 0x28) & 0x8000) == 0) {
        a_hi_98ce4 = ((uint16_t)(value30 + 0x28) & 0x8000) >> 8;
        y_98ce4 = y_98f02;
        carry_98ce4 = value30 + 0x28 > 0xFFFF;
        zero_98ce4 = ((uint16_t)(value30 + 0x28) & 0x8000) == 0;
        negative_98ce4 = (uint16_t)(value30 + 0x28) & 0x8000 & 0x8000;
        overflow_98ce4 = ((value30 ^ (uint16_t)(value30 + 0x28)) & ((uint16_t)(value30 + 0x28) ^ 0x28) & 0x8000) != 0;
        direct_page_98ce4 = direct_page_98f02;
        data_bank_98ce4 = data_bank_98f02;
        goto shared_98CE_3;
    }
    r->a = (uint16_t)(value30 + 0x28) & 0x8000;
    r->x = x_98f02;
    r->y = y_98f02;
    r->c = value30 + 0x28 > 0xFFFF;
    r->z = ((uint16_t)(value30 + 0x28) & 0x8000) == 0;
    r->n = (uint16_t)(value30 + 0x28) & 0x8000 & 0x8000;
    r->v = ((value30 ^ (uint16_t)(value30 + 0x28)) & ((uint16_t)(value30 + 0x28) ^ 0x28) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_98f02;
    r->dp = direct_page_98f02;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x98FD, 0x7E97EF); GUARD_JSR(c, sp_call, 0x98FD); } /* release_nine_native_title_particle_sprite_records */
    r->sp += 4;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9900, 0x7EACD0); GUARD_JSR(c, sp_call, 0x9900); } /* current_task_parent_id */
    r->sp += 4;
    bool m_ret19 = r->mf;
    uint16_t a_all24 = r->a;
    if (m_ret19) {
        RAM8(0x0000 + sp0 - 4) = (uint8_t)a_all24;
        r->mf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9904, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x9904); } /* allocate_eight_byte_record */
        r->sp += 5;
        bool m_ret20 = r->mf;
        uint16_t a_all25 = r->a;
        if (m_ret20) {
            uint8_t value31 = RAM8(0x0000 + sp0 - 4);
            r->a = (a_all25 >> 8 << 8) | value31;
            r->z = value31 == 0;
            r->n = value31 & 0x80;
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9908, 0x7EB258); GUARD_JSR(c, sp_call, 0x9908); } /* append_pending_record */
            r->sp += 4;
            uint8_t value32 = RAM8(0x0000 + sp0 - 3);
            uint8_t value33 = RAM8(0x0000 + sp0 - 2);
            uint8_t value34 = RAM8(0x0000 + sp0 - 1);
            uint8_t value35 = RAM8(0x0000 + sp0);
            r->c = value33 & 0x01;
            r->z = ((value35 << 8) | value34) == 0;
            r->n = ((value35 << 8) | value34) & 0x8000;
            r->v = value33 & 0x40;
            r->mf = value33 & 0x20;
            r->xf = value33 & 0x10;
            r->db = value32;
            r->dp = (value35 << 8) | value34;
            r->i = value33 & 0x04;
            r->d = value33 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        } else {
            c->fail = 3;
            return;
        }
    } else {
        RAM8(0x0000 + sp0 - 4) = a_all24 >> 8;
        RAM8(0x0000 + sp0 - 5) = (uint8_t)a_all24;
        r->mf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9904, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x9904); } /* allocate_eight_byte_record */
        r->sp += 6;
        bool m_ret23 = r->mf;
        if (m_ret23) {
            c->fail = 3;
            return;
        } else {
            uint8_t value45 = RAM8(0x0000 + sp0 - 5);
            uint8_t value46 = RAM8(0x0000 + sp0 - 4);
            r->a = (value46 << 8) | value45;
            r->z = ((value46 << 8) | value45) == 0;
            r->n = ((value46 << 8) | value45) & 0x8000;
            r->mf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9908, 0x7EB258); GUARD_JSR(c, sp_call, 0x9908); } /* append_pending_record */
            r->sp += 4;
            uint8_t value47 = RAM8(0x0000 + sp0 - 3);
            uint8_t value48 = RAM8(0x0000 + sp0 - 2);
            uint8_t value49 = RAM8(0x0000 + sp0 - 1);
            uint8_t value50 = RAM8(0x0000 + sp0);
            r->c = value48 & 0x01;
            r->z = ((value50 << 8) | value49) == 0;
            r->n = ((value50 << 8) | value49) & 0x8000;
            r->v = value48 & 0x40;
            r->mf = value48 & 0x20;
            r->xf = value48 & 0x10;
            r->db = value47;
            r->dp = (value50 << 8) | value49;
            r->i = value48 & 0x04;
            r->d = value48 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTL(c);
        }
    }
    shared_98EC:;
    BUS8_SET(c, (uint16_t)(direct_page_98ec + 1), a_98ec);
    a_hi_98f0 = a_hi_98ec;
    x_98f0 = x_98ec;
    y_98f0 = y_98ec;
    direct_page_98f0 = direct_page_98ec;
    data_bank_98f0 = data_bank_98ec;
    goto shared_98F0;
    shared_98EC_1:;
    BUS8_SET(c, (uint16_t)(direct_page_98ec2 + 1), a_98ec2);
    a_hi_98f02 = a_hi_98ec2;
    x_98f02 = x_98ec2;
    y_98f02 = y_98ec2;
    direct_page_98f02 = direct_page_98ec2;
    data_bank_98f02 = data_bank_98ec2;
    goto shared_98F0_1;
}
SOM_REGISTER(0x7E98AF, SOM_RTL, "gen", run_native_title_nine_sprite_particle_until_offscreen, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 1, 0, 94, 47)
