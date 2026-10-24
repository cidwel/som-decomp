#include "som_c.h"

/* 7E95E8 enter_warm_runtime_and_call_brightness_fade   [class C, 94 bytes, 44 instructions]
 * Source: src/boot/enter_warm_runtime_and_call_brightness_fade.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void enter_warm_runtime_and_call_brightness_fade(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_hi_95f8 = 0;
    uint16_t y_95f8 = 0;
    bool carry_95f8 = 0;
    bool overflow_95f8 = 0;
    uint16_t direct_page_95f8 = 0;
    uint8_t data_bank_95f8 = 0;
    uint8_t a_hi_95f82 = 0;
    uint16_t y_95f82 = 0;
    bool carry_95f82 = 0;
    bool overflow_95f82 = 0;
    uint16_t direct_page_95f82 = 0;
    uint8_t data_bank_95f82 = 0;
    uint8_t a_hi_960c = 0;
    uint8_t x_960c = 0;
    uint8_t y_960c = 0;
    bool carry_960c = 0;
    bool overflow_960c = 0;
    uint16_t direct_page_960c = 0;
    uint8_t data_bank_960c = 0;
    uint8_t a_hi_960c2 = 0;
    uint8_t x_960c2 = 0;
    uint8_t y_960c2 = 0;
    bool carry_960c2 = 0;
    bool overflow_960c2 = 0;
    uint16_t direct_page_960c2 = 0;
    uint8_t data_bank_960c2 = 0;
    uint8_t a_hi_960c3 = 0;
    uint16_t x_960c3 = 0;
    uint16_t y_960c3 = 0;
    bool carry_960c3 = 0;
    bool overflow_960c3 = 0;
    uint16_t direct_page_960c3 = 0;
    uint8_t data_bank_960c3 = 0;
    uint8_t a_hi_960c4 = 0;
    uint16_t x_960c4 = 0;
    uint16_t y_960c4 = 0;
    bool carry_960c4 = 0;
    bool overflow_960c4 = 0;
    uint16_t direct_page_960c4 = 0;
    uint8_t data_bank_960c4 = 0;
    uint8_t a_hi_95f83 = 0;
    uint8_t y_95f83 = 0;
    bool carry_95f83 = 0;
    bool overflow_95f83 = 0;
    uint16_t direct_page_95f83 = 0;
    uint8_t data_bank_95f83 = 0;
    uint8_t a_hi_95f84 = 0;
    uint8_t y_95f84 = 0;
    bool carry_95f84 = 0;
    bool overflow_95f84 = 0;
    uint16_t direct_page_95f84 = 0;
    uint8_t data_bank_95f84 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    r->a = (uint16_t)(sp0 - 5);
    r->z = (uint16_t)(sp0 - 5) == 0;
    r->n = (uint16_t)(sp0 - 5) & 0x8000;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x95F3, 0x7E95C0); GUARD_JSR(c, sp_call, 0x95F3); } /* enter_warm_brightness_fade_and_suspend_first_timer */
    r->sp += 5;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    if (m_ret) {
        BUS8_SET(c, (uint16_t)(dp_ret + 1), 0);
        BUS8_SET(c, (uint16_t)(dp_ret + 2), 0);
        a_hi_95f8 = a_all >> 8;
        y_95f8 = y_ret;
        carry_95f8 = carry_ret;
        overflow_95f8 = overflow_ret;
        direct_page_95f8 = dp_ret;
        data_bank_95f8 = db_ret;
        goto shared_95F8;
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret + 1), 0);
        BUS16_SET(c, (uint16_t)(dp_ret + 2), 0);
        a_hi_95f82 = a_all >> 8;
        y_95f82 = y_ret;
        carry_95f82 = carry_ret;
        overflow_95f82 = overflow_ret;
        direct_page_95f82 = dp_ret;
        data_bank_95f82 = db_ret;
        goto shared_95F8_1;
    }
    shared_95F8:;
    r->x = 1;
    r->y = y_95f8;
    r->c = carry_95f8;
    r->z = 0;
    r->n = 0;
    r->v = overflow_95f8;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_95f8;
    r->dp = direct_page_95f8;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x95FD, 0x7EABE7); GUARD_JSR(c, sp_call, 0x95FD); } /* receive_with_supplied_delay */
    r->sp += 5;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret2 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t y_ret2 = r->y;
    bool carry_ret2 = r->c;
    bool overflow_ret2 = r->v;
    if (x_ret2) {
        uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
        if (value == 0) {
            if (m_ret2) {
                a_hi_960c = a_all2 >> 8;
                x_960c = value;
                y_960c = (uint8_t)y_ret2;
                carry_960c = carry_ret2;
                overflow_960c = overflow_ret2;
                direct_page_960c = dp_ret2;
                data_bank_960c = db_ret2;
                goto shared_960C;
            } else {
                a_hi_960c2 = a_all2 >> 8;
                x_960c2 = value;
                y_960c2 = (uint8_t)y_ret2;
                carry_960c2 = carry_ret2;
                overflow_960c2 = overflow_ret2;
                direct_page_960c2 = dp_ret2;
                data_bank_960c2 = db_ret2;
                goto shared_960C_1;
            }
        }
        if (m_ret2) {
            BUS8_SET(c, (db_ret2 << 0x10) + 3 + value, 0);
            r->x = value;
            r->y = (uint8_t)y_ret2;
            r->z = value == 0;
            r->n = value & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9607, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9607); } /* publish_native_sprite_record_with_data_bank_7f */
            r->sp += 5;
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret4 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t x_ret5 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret3 + 1), 0);
            BUS8_SET(c, (uint16_t)(dp_ret3 + 2), 0);
            if (x_ret4) {
                a_hi_960c = a_all3 >> 8;
                x_960c = (uint8_t)x_ret5;
                y_960c = (uint8_t)y_ret3;
                carry_960c = carry_ret3;
                overflow_960c = overflow_ret3;
                direct_page_960c = dp_ret3;
                data_bank_960c = db_ret3;
                goto shared_960C;
            } else {
                a_hi_960c3 = a_all3 >> 8;
                x_960c3 = x_ret5;
                y_960c3 = y_ret3;
                carry_960c3 = carry_ret3;
                overflow_960c3 = overflow_ret3;
                direct_page_960c3 = dp_ret3;
                data_bank_960c3 = db_ret3;
                goto shared_960C_2;
            }
        } else {
            BUS16_SET(c, (db_ret2 << 0x10) + 3 + value, 0);
            r->x = value;
            r->y = (uint8_t)y_ret2;
            r->z = value == 0;
            r->n = value & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9607, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9607); } /* publish_native_sprite_record_with_data_bank_7f */
            r->sp += 5;
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret6 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t x_ret7 = r->x;
            uint16_t y_ret4 = r->y;
            bool carry_ret4 = r->c;
            bool overflow_ret4 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret4 + 1), 0);
            BUS8_SET(c, (uint16_t)(dp_ret4 + 2), 0);
            if (x_ret6) {
                a_hi_960c = a_all4 >> 8;
                x_960c = (uint8_t)x_ret7;
                y_960c = (uint8_t)y_ret4;
                carry_960c = carry_ret4;
                overflow_960c = overflow_ret4;
                direct_page_960c = dp_ret4;
                data_bank_960c = db_ret4;
                goto shared_960C;
            } else {
                a_hi_960c3 = a_all4 >> 8;
                x_960c3 = x_ret7;
                y_960c3 = y_ret4;
                carry_960c3 = carry_ret4;
                overflow_960c3 = overflow_ret4;
                direct_page_960c3 = dp_ret4;
                data_bank_960c3 = db_ret4;
                goto shared_960C_2;
            }
        }
    } else {
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        if (value2 == 0) {
            if (m_ret2) {
                a_hi_960c3 = a_all2 >> 8;
                x_960c3 = value2;
                y_960c3 = y_ret2;
                carry_960c3 = carry_ret2;
                overflow_960c3 = overflow_ret2;
                direct_page_960c3 = dp_ret2;
                data_bank_960c3 = db_ret2;
                goto shared_960C_2;
            } else {
                a_hi_960c4 = a_all2 >> 8;
                x_960c4 = value2;
                y_960c4 = y_ret2;
                carry_960c4 = carry_ret2;
                overflow_960c4 = overflow_ret2;
                direct_page_960c4 = dp_ret2;
                data_bank_960c4 = db_ret2;
                goto shared_960C_3;
            }
        }
        if (m_ret2) {
            BUS8_SET(c, (db_ret2 << 0x10) + 3 + value2, 0);
            r->x = value2;
            r->z = value2 == 0;
            r->n = value2 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9607, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9607); } /* publish_native_sprite_record_with_data_bank_7f */
            r->sp += 5;
            uint16_t dp_ret5 = r->dp;
            uint8_t db_ret5 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret8 = r->xf;
            uint16_t a_all5 = r->a;
            uint16_t x_ret9 = r->x;
            uint16_t y_ret5 = r->y;
            bool carry_ret5 = r->c;
            bool overflow_ret5 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret5 + 1), 0);
            BUS8_SET(c, (uint16_t)(dp_ret5 + 2), 0);
            if (x_ret8) {
                a_hi_960c = a_all5 >> 8;
                x_960c = (uint8_t)x_ret9;
                y_960c = (uint8_t)y_ret5;
                carry_960c = carry_ret5;
                overflow_960c = overflow_ret5;
                direct_page_960c = dp_ret5;
                data_bank_960c = db_ret5;
                goto shared_960C;
            } else {
                a_hi_960c3 = a_all5 >> 8;
                x_960c3 = x_ret9;
                y_960c3 = y_ret5;
                carry_960c3 = carry_ret5;
                overflow_960c3 = overflow_ret5;
                direct_page_960c3 = dp_ret5;
                data_bank_960c3 = db_ret5;
                goto shared_960C_2;
            }
        } else {
            BUS16_SET(c, (db_ret2 << 0x10) + 3 + value2, 0);
            r->x = value2;
            r->z = value2 == 0;
            r->n = value2 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9607, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9607); } /* publish_native_sprite_record_with_data_bank_7f */
            r->sp += 5;
            uint16_t dp_ret6 = r->dp;
            uint8_t db_ret6 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret10 = r->xf;
            uint16_t a_all6 = r->a;
            uint16_t x_ret11 = r->x;
            uint16_t y_ret6 = r->y;
            bool carry_ret6 = r->c;
            bool overflow_ret6 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret6 + 1), 0);
            BUS8_SET(c, (uint16_t)(dp_ret6 + 2), 0);
            if (x_ret10) {
                a_hi_960c = a_all6 >> 8;
                x_960c = (uint8_t)x_ret11;
                y_960c = (uint8_t)y_ret6;
                carry_960c = carry_ret6;
                overflow_960c = overflow_ret6;
                direct_page_960c = dp_ret6;
                data_bank_960c = db_ret6;
                goto shared_960C;
            } else {
                a_hi_960c3 = a_all6 >> 8;
                x_960c3 = x_ret11;
                y_960c3 = y_ret6;
                carry_960c3 = carry_ret6;
                overflow_960c3 = overflow_ret6;
                direct_page_960c3 = dp_ret6;
                data_bank_960c3 = db_ret6;
                goto shared_960C_2;
            }
        }
    }
    shared_95F8_1:;
    r->x = 1;
    r->y = y_95f82;
    r->c = carry_95f82;
    r->z = 0;
    r->n = 0;
    r->v = overflow_95f82;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_95f82;
    r->dp = direct_page_95f82;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x95FD, 0x7EABE7); GUARD_JSR(c, sp_call, 0x95FD); } /* receive_with_supplied_delay */
    r->sp += 5;
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret7 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret12 = r->xf;
    uint16_t a_all7 = r->a;
    uint16_t y_ret7 = r->y;
    bool carry_ret7 = r->c;
    bool overflow_ret7 = r->v;
    if (x_ret12) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 1));
        if (value3 == 0) {
            if (m_ret3) {
                a_hi_960c = a_all7 >> 8;
                x_960c = value3;
                y_960c = (uint8_t)y_ret7;
                carry_960c = carry_ret7;
                overflow_960c = overflow_ret7;
                direct_page_960c = dp_ret7;
                data_bank_960c = db_ret7;
                goto shared_960C;
            } else {
                a_hi_960c2 = a_all7 >> 8;
                x_960c2 = value3;
                y_960c2 = (uint8_t)y_ret7;
                carry_960c2 = carry_ret7;
                overflow_960c2 = overflow_ret7;
                direct_page_960c2 = dp_ret7;
                data_bank_960c2 = db_ret7;
                goto shared_960C_1;
            }
        }
        if (m_ret3) {
            BUS8_SET(c, (db_ret7 << 0x10) + 3 + value3, 0);
            r->x = value3;
            r->y = (uint8_t)y_ret7;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9607, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9607); } /* publish_native_sprite_record_with_data_bank_7f */
            r->sp += 5;
            uint16_t dp_ret8 = r->dp;
            uint8_t db_ret8 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret14 = r->xf;
            uint16_t a_all8 = r->a;
            uint16_t x_ret15 = r->x;
            uint16_t y_ret8 = r->y;
            bool carry_ret8 = r->c;
            bool overflow_ret8 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret8 + 1), 0);
            BUS8_SET(c, (uint16_t)(dp_ret8 + 2), 0);
            if (x_ret14) {
                a_hi_960c = a_all8 >> 8;
                x_960c = (uint8_t)x_ret15;
                y_960c = (uint8_t)y_ret8;
                carry_960c = carry_ret8;
                overflow_960c = overflow_ret8;
                direct_page_960c = dp_ret8;
                data_bank_960c = db_ret8;
                goto shared_960C;
            } else {
                a_hi_960c3 = a_all8 >> 8;
                x_960c3 = x_ret15;
                y_960c3 = y_ret8;
                carry_960c3 = carry_ret8;
                overflow_960c3 = overflow_ret8;
                direct_page_960c3 = dp_ret8;
                data_bank_960c3 = db_ret8;
                goto shared_960C_2;
            }
        } else {
            BUS16_SET(c, (db_ret7 << 0x10) + 3 + value3, 0);
            r->x = value3;
            r->y = (uint8_t)y_ret7;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9607, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9607); } /* publish_native_sprite_record_with_data_bank_7f */
            r->sp += 5;
            uint16_t dp_ret9 = r->dp;
            uint8_t db_ret9 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret16 = r->xf;
            uint16_t a_all9 = r->a;
            uint16_t x_ret17 = r->x;
            uint16_t y_ret9 = r->y;
            bool carry_ret9 = r->c;
            bool overflow_ret9 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret9 + 1), 0);
            BUS8_SET(c, (uint16_t)(dp_ret9 + 2), 0);
            if (x_ret16) {
                a_hi_960c = a_all9 >> 8;
                x_960c = (uint8_t)x_ret17;
                y_960c = (uint8_t)y_ret9;
                carry_960c = carry_ret9;
                overflow_960c = overflow_ret9;
                direct_page_960c = dp_ret9;
                data_bank_960c = db_ret9;
                goto shared_960C;
            } else {
                a_hi_960c3 = a_all9 >> 8;
                x_960c3 = x_ret17;
                y_960c3 = y_ret9;
                carry_960c3 = carry_ret9;
                overflow_960c3 = overflow_ret9;
                direct_page_960c3 = dp_ret9;
                data_bank_960c3 = db_ret9;
                goto shared_960C_2;
            }
        }
    } else {
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 1));
        if (value4 == 0) {
            if (m_ret3) {
                a_hi_960c3 = a_all7 >> 8;
                x_960c3 = value4;
                y_960c3 = y_ret7;
                carry_960c3 = carry_ret7;
                overflow_960c3 = overflow_ret7;
                direct_page_960c3 = dp_ret7;
                data_bank_960c3 = db_ret7;
                goto shared_960C_2;
            } else {
                a_hi_960c4 = a_all7 >> 8;
                x_960c4 = value4;
                y_960c4 = y_ret7;
                carry_960c4 = carry_ret7;
                overflow_960c4 = overflow_ret7;
                direct_page_960c4 = dp_ret7;
                data_bank_960c4 = db_ret7;
                goto shared_960C_3;
            }
        }
        if (m_ret3) {
            BUS8_SET(c, (db_ret7 << 0x10) + 3 + value4, 0);
            r->x = value4;
            r->z = value4 == 0;
            r->n = value4 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9607, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9607); } /* publish_native_sprite_record_with_data_bank_7f */
            r->sp += 5;
            uint16_t dp_ret10 = r->dp;
            uint8_t db_ret10 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret18 = r->xf;
            uint16_t a_all10 = r->a;
            uint16_t x_ret19 = r->x;
            uint16_t y_ret10 = r->y;
            bool carry_ret10 = r->c;
            bool overflow_ret10 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret10 + 1), 0);
            BUS8_SET(c, (uint16_t)(dp_ret10 + 2), 0);
            if (x_ret18) {
                a_hi_960c = a_all10 >> 8;
                x_960c = (uint8_t)x_ret19;
                y_960c = (uint8_t)y_ret10;
                carry_960c = carry_ret10;
                overflow_960c = overflow_ret10;
                direct_page_960c = dp_ret10;
                data_bank_960c = db_ret10;
                goto shared_960C;
            } else {
                a_hi_960c3 = a_all10 >> 8;
                x_960c3 = x_ret19;
                y_960c3 = y_ret10;
                carry_960c3 = carry_ret10;
                overflow_960c3 = overflow_ret10;
                direct_page_960c3 = dp_ret10;
                data_bank_960c3 = db_ret10;
                goto shared_960C_2;
            }
        } else {
            BUS16_SET(c, (db_ret7 << 0x10) + 3 + value4, 0);
            r->x = value4;
            r->z = value4 == 0;
            r->n = value4 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9607, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9607); } /* publish_native_sprite_record_with_data_bank_7f */
            r->sp += 5;
            uint16_t dp_ret11 = r->dp;
            uint8_t db_ret11 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret20 = r->xf;
            uint16_t a_all11 = r->a;
            uint16_t x_ret21 = r->x;
            uint16_t y_ret11 = r->y;
            bool carry_ret11 = r->c;
            bool overflow_ret11 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret11 + 1), 0);
            BUS8_SET(c, (uint16_t)(dp_ret11 + 2), 0);
            if (x_ret20) {
                a_hi_960c = a_all11 >> 8;
                x_960c = (uint8_t)x_ret21;
                y_960c = (uint8_t)y_ret11;
                carry_960c = carry_ret11;
                overflow_960c = overflow_ret11;
                direct_page_960c = dp_ret11;
                data_bank_960c = db_ret11;
                goto shared_960C;
            } else {
                a_hi_960c3 = a_all11 >> 8;
                x_960c3 = x_ret21;
                y_960c3 = y_ret11;
                carry_960c3 = carry_ret11;
                overflow_960c3 = overflow_ret11;
                direct_page_960c3 = dp_ret11;
                data_bank_960c3 = db_ret11;
                goto shared_960C_2;
            }
        }
    }
    shared_960C:;
    r->a = (a_hi_960c << 8) | 0;
    r->x = x_960c;
    r->y = y_960c;
    r->c = carry_960c;
    r->z = 1;
    r->n = 0;
    r->v = overflow_960c;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_960c;
    r->dp = direct_page_960c;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9610, 0x7EC288); GUARD_JSR(c, sp_call, 0x9610); } /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 5;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret22 = r->xf;
    uint16_t a_all12 = r->a;
    uint16_t y_ret12 = r->y;
    bool overflow_ret12 = r->v;
    if ((uint8_t)a_all12 == 0x10) {
        r->a = (a_all12 >> 8 << 8) | 8;
        r->c = (uint8_t)a_all12 >= 0x10;
        r->z = 0;
        r->n = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9637, 0x7EC288); GUARD_JSR(c, sp_call, 0x9637); } /* draw_native_random_byte_below_low_byte_limit */
        r->sp += 5;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all13 = r->a;
        uint16_t y_ret13 = r->y;
        bool overflow_ret13 = r->v;
        if ((uint8_t)a_all13 != 0) {
            a_hi_95f8 = a_all13 >> 8;
            y_95f8 = y_ret13;
            carry_95f8 = (uint8_t)a_all13 >= 0;
            overflow_95f8 = overflow_ret13;
            direct_page_95f8 = direct_page_960c;
            data_bank_95f8 = data_bank_960c;
            goto shared_95F8;
        }
        r->a = (a_all13 >> 8 << 8) | 0x7E;
        r->x = 0x6014;
        r->c = (uint8_t)a_all13 >= 0;
        r->z = 0;
        r->n = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9643, 0x7EAB88); GUARD_JSR(c, sp_call, 0x9643); } /* create_and_enqueue_task */
        r->sp += 5;
        uint16_t dp_ret12 = r->dp;
        uint8_t db_ret12 = r->db;
        bool m_ret4 = r->mf;
        bool x_ret25 = r->xf;
        uint16_t a_all14 = r->a;
        uint16_t y_ret14 = r->y;
        bool carry_ret14 = r->c;
        bool overflow_ret14 = r->v;
        if (m_ret4) {
            if (x_ret25) {
                a_hi_95f83 = a_all14 >> 8;
                y_95f83 = (uint8_t)y_ret14;
                carry_95f83 = carry_ret14;
                overflow_95f83 = overflow_ret14;
                direct_page_95f83 = dp_ret12;
                data_bank_95f83 = db_ret12;
                goto shared_95F8_2;
            } else {
                a_hi_95f8 = a_all14 >> 8;
                y_95f8 = y_ret14;
                carry_95f8 = carry_ret14;
                overflow_95f8 = overflow_ret14;
                direct_page_95f8 = dp_ret12;
                data_bank_95f8 = db_ret12;
                goto shared_95F8;
            }
        } else {
            if (x_ret25) {
                a_hi_95f84 = a_all14 >> 8;
                y_95f84 = (uint8_t)y_ret14;
                carry_95f84 = carry_ret14;
                overflow_95f84 = overflow_ret14;
                direct_page_95f84 = dp_ret12;
                data_bank_95f84 = db_ret12;
                goto shared_95F8_3;
            } else {
                a_hi_95f82 = a_all14 >> 8;
                y_95f82 = y_ret14;
                carry_95f82 = carry_ret14;
                overflow_95f82 = overflow_ret14;
                direct_page_95f82 = dp_ret12;
                data_bank_95f82 = db_ret12;
                goto shared_95F8_1;
            }
        }
    }
    if ((uint8_t)a_all12 >= 0x10) {
        if (x_ret22) {
            a_hi_95f83 = a_all12 >> 8;
            y_95f83 = (uint8_t)y_ret12;
            carry_95f83 = (uint8_t)a_all12 >= 0x10;
            overflow_95f83 = overflow_ret12;
            direct_page_95f83 = direct_page_960c;
            data_bank_95f83 = data_bank_960c;
            goto shared_95F8_2;
        } else {
            a_hi_95f8 = a_all12 >> 8;
            y_95f8 = y_ret12;
            carry_95f8 = (uint8_t)a_all12 >= 0x10;
            overflow_95f8 = overflow_ret12;
            direct_page_95f8 = direct_page_960c;
            data_bank_95f8 = data_bank_960c;
            goto shared_95F8;
        }
    }
    uint16_t value5 = BUS16_RDP(c, (data_bank_960c << 0x10) + 0x7C);
    if (x_ret22) {
        uint8_t value6 = BUS8_RDP(c, (data_bank_960c << 0x10) + (uint8_t)((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5));
        BUS8_SET(c, (uint16_t)(direct_page_960c + 1), value6);
        BUS8_SET(c, (data_bank_960c << 0x10) + 3 + value6, 1);
        r->a = ((uint16_t)((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5) >> 8 << 8) | 1;
        r->x = value6;
        r->y = (uint8_t)((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5);
        r->c = (((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) ^ (uint16_t)((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5)) & (value5 ^ (uint16_t)((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5)) & 0x8000) != 0;
        r->xf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9630, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9630); } /* publish_native_sprite_record_with_data_bank_7f */
        r->sp += 5;
        uint16_t dp_ret13 = r->dp;
        uint8_t db_ret13 = r->db;
        bool m_ret5 = r->mf;
        bool x_ret27 = r->xf;
        uint16_t a_all15 = r->a;
        uint16_t y_ret15 = r->y;
        bool carry_ret15 = r->c;
        bool overflow_ret15 = r->v;
        if (m_ret5) {
            if (x_ret27) {
                a_hi_95f83 = a_all15 >> 8;
                y_95f83 = (uint8_t)y_ret15;
                carry_95f83 = carry_ret15;
                overflow_95f83 = overflow_ret15;
                direct_page_95f83 = dp_ret13;
                data_bank_95f83 = db_ret13;
                goto shared_95F8_2;
            } else {
                a_hi_95f8 = a_all15 >> 8;
                y_95f8 = y_ret15;
                carry_95f8 = carry_ret15;
                overflow_95f8 = overflow_ret15;
                direct_page_95f8 = dp_ret13;
                data_bank_95f8 = db_ret13;
                goto shared_95F8;
            }
        } else {
            if (x_ret27) {
                a_hi_95f84 = a_all15 >> 8;
                y_95f84 = (uint8_t)y_ret15;
                carry_95f84 = carry_ret15;
                overflow_95f84 = overflow_ret15;
                direct_page_95f84 = dp_ret13;
                data_bank_95f84 = db_ret13;
                goto shared_95F8_3;
            } else {
                a_hi_95f82 = a_all15 >> 8;
                y_95f82 = y_ret15;
                carry_95f82 = carry_ret15;
                overflow_95f82 = overflow_ret15;
                direct_page_95f82 = dp_ret13;
                data_bank_95f82 = db_ret13;
                goto shared_95F8_1;
            }
        }
    } else {
        uint16_t value7 = BUS16_RDP(c, (data_bank_960c << 0x10) + (uint16_t)((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5));
        BUS16_SET(c, (uint16_t)(direct_page_960c + 1), value7);
        BUS8_SET(c, (data_bank_960c << 0x10) + 3 + value7, 1);
        r->a = ((uint16_t)((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5) >> 8 << 8) | 1;
        r->x = value7;
        r->y = (uint16_t)((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5);
        r->c = (((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) ^ (uint16_t)((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5)) & (value5 ^ (uint16_t)((((a_all12 >> 8 << 8) | (uint8_t)((uint8_t)a_all12 << 1)) & 0xFF) + value5)) & 0x8000) != 0;
        r->xf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9630, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9630); } /* publish_native_sprite_record_with_data_bank_7f */
        r->sp += 5;
        uint16_t dp_ret14 = r->dp;
        uint8_t db_ret14 = r->db;
        bool m_ret6 = r->mf;
        bool x_ret29 = r->xf;
        uint16_t a_all16 = r->a;
        uint16_t y_ret16 = r->y;
        bool carry_ret16 = r->c;
        bool overflow_ret16 = r->v;
        if (m_ret6) {
            if (x_ret29) {
                a_hi_95f83 = a_all16 >> 8;
                y_95f83 = (uint8_t)y_ret16;
                carry_95f83 = carry_ret16;
                overflow_95f83 = overflow_ret16;
                direct_page_95f83 = dp_ret14;
                data_bank_95f83 = db_ret14;
                goto shared_95F8_2;
            } else {
                a_hi_95f8 = a_all16 >> 8;
                y_95f8 = y_ret16;
                carry_95f8 = carry_ret16;
                overflow_95f8 = overflow_ret16;
                direct_page_95f8 = dp_ret14;
                data_bank_95f8 = db_ret14;
                goto shared_95F8;
            }
        } else {
            if (x_ret29) {
                a_hi_95f84 = a_all16 >> 8;
                y_95f84 = (uint8_t)y_ret16;
                carry_95f84 = carry_ret16;
                overflow_95f84 = overflow_ret16;
                direct_page_95f84 = dp_ret14;
                data_bank_95f84 = db_ret14;
                goto shared_95F8_3;
            } else {
                a_hi_95f82 = a_all16 >> 8;
                y_95f82 = y_ret16;
                carry_95f82 = carry_ret16;
                overflow_95f82 = overflow_ret16;
                direct_page_95f82 = dp_ret14;
                data_bank_95f82 = db_ret14;
                goto shared_95F8_1;
            }
        }
    }
    shared_960C_1:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_960C_2:;
    r->a = (a_hi_960c3 << 8) | 0;
    r->x = x_960c3;
    r->y = y_960c3;
    r->c = carry_960c3;
    r->z = 1;
    r->n = 0;
    r->v = overflow_960c3;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_960c3;
    r->dp = direct_page_960c3;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9610, 0x7EC288); GUARD_JSR(c, sp_call, 0x9610); } /* draw_native_random_byte_below_low_byte_limit */
    r->sp += 5;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret31 = r->xf;
    uint16_t a_all17 = r->a;
    uint16_t y_ret17 = r->y;
    bool overflow_ret17 = r->v;
    if ((uint8_t)a_all17 == 0x10) {
        r->a = (a_all17 >> 8 << 8) | 8;
        r->c = (uint8_t)a_all17 >= 0x10;
        r->z = 0;
        r->n = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9637, 0x7EC288); GUARD_JSR(c, sp_call, 0x9637); } /* draw_native_random_byte_below_low_byte_limit */
        r->sp += 5;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all18 = r->a;
        uint16_t y_ret18 = r->y;
        bool overflow_ret18 = r->v;
        if ((uint8_t)a_all18 != 0) {
            a_hi_95f8 = a_all18 >> 8;
            y_95f8 = y_ret18;
            carry_95f8 = (uint8_t)a_all18 >= 0;
            overflow_95f8 = overflow_ret18;
            direct_page_95f8 = direct_page_960c3;
            data_bank_95f8 = data_bank_960c3;
            goto shared_95F8;
        }
        r->a = (a_all18 >> 8 << 8) | 0x7E;
        r->x = 0x6014;
        r->c = (uint8_t)a_all18 >= 0;
        r->z = 0;
        r->n = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9643, 0x7EAB88); GUARD_JSR(c, sp_call, 0x9643); } /* create_and_enqueue_task */
        r->sp += 5;
        uint16_t dp_ret15 = r->dp;
        uint8_t db_ret15 = r->db;
        bool m_ret7 = r->mf;
        bool x_ret34 = r->xf;
        uint16_t a_all19 = r->a;
        uint16_t y_ret19 = r->y;
        bool carry_ret19 = r->c;
        bool overflow_ret19 = r->v;
        if (m_ret7) {
            if (x_ret34) {
                a_hi_95f83 = a_all19 >> 8;
                y_95f83 = (uint8_t)y_ret19;
                carry_95f83 = carry_ret19;
                overflow_95f83 = overflow_ret19;
                direct_page_95f83 = dp_ret15;
                data_bank_95f83 = db_ret15;
                goto shared_95F8_2;
            } else {
                a_hi_95f8 = a_all19 >> 8;
                y_95f8 = y_ret19;
                carry_95f8 = carry_ret19;
                overflow_95f8 = overflow_ret19;
                direct_page_95f8 = dp_ret15;
                data_bank_95f8 = db_ret15;
                goto shared_95F8;
            }
        } else {
            if (x_ret34) {
                a_hi_95f84 = a_all19 >> 8;
                y_95f84 = (uint8_t)y_ret19;
                carry_95f84 = carry_ret19;
                overflow_95f84 = overflow_ret19;
                direct_page_95f84 = dp_ret15;
                data_bank_95f84 = db_ret15;
                goto shared_95F8_3;
            } else {
                a_hi_95f82 = a_all19 >> 8;
                y_95f82 = y_ret19;
                carry_95f82 = carry_ret19;
                overflow_95f82 = overflow_ret19;
                direct_page_95f82 = dp_ret15;
                data_bank_95f82 = db_ret15;
                goto shared_95F8_1;
            }
        }
    }
    if ((uint8_t)a_all17 >= 0x10) {
        if (x_ret31) {
            a_hi_95f83 = a_all17 >> 8;
            y_95f83 = (uint8_t)y_ret17;
            carry_95f83 = (uint8_t)a_all17 >= 0x10;
            overflow_95f83 = overflow_ret17;
            direct_page_95f83 = direct_page_960c3;
            data_bank_95f83 = data_bank_960c3;
            goto shared_95F8_2;
        } else {
            a_hi_95f8 = a_all17 >> 8;
            y_95f8 = y_ret17;
            carry_95f8 = (uint8_t)a_all17 >= 0x10;
            overflow_95f8 = overflow_ret17;
            direct_page_95f8 = direct_page_960c3;
            data_bank_95f8 = data_bank_960c3;
            goto shared_95F8;
        }
    }
    uint16_t value8 = BUS16_RDP(c, (data_bank_960c3 << 0x10) + 0x7C);
    if (x_ret31) {
        uint8_t value9 = BUS8_RDP(c, (data_bank_960c3 << 0x10) + (uint8_t)((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8));
        BUS8_SET(c, (uint16_t)(direct_page_960c3 + 1), value9);
        BUS8_SET(c, (data_bank_960c3 << 0x10) + 3 + value9, 1);
        r->a = ((uint16_t)((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8) >> 8 << 8) | 1;
        r->x = value9;
        r->y = (uint8_t)((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8);
        r->c = (((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) ^ (uint16_t)((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8)) & (value8 ^ (uint16_t)((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8)) & 0x8000) != 0;
        r->xf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9630, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9630); } /* publish_native_sprite_record_with_data_bank_7f */
        r->sp += 5;
        uint16_t dp_ret16 = r->dp;
        uint8_t db_ret16 = r->db;
        bool m_ret8 = r->mf;
        bool x_ret36 = r->xf;
        uint16_t a_all20 = r->a;
        uint16_t y_ret20 = r->y;
        bool carry_ret20 = r->c;
        bool overflow_ret20 = r->v;
        if (m_ret8) {
            if (x_ret36) {
                a_hi_95f83 = a_all20 >> 8;
                y_95f83 = (uint8_t)y_ret20;
                carry_95f83 = carry_ret20;
                overflow_95f83 = overflow_ret20;
                direct_page_95f83 = dp_ret16;
                data_bank_95f83 = db_ret16;
                goto shared_95F8_2;
            } else {
                a_hi_95f8 = a_all20 >> 8;
                y_95f8 = y_ret20;
                carry_95f8 = carry_ret20;
                overflow_95f8 = overflow_ret20;
                direct_page_95f8 = dp_ret16;
                data_bank_95f8 = db_ret16;
                goto shared_95F8;
            }
        } else {
            if (x_ret36) {
                a_hi_95f84 = a_all20 >> 8;
                y_95f84 = (uint8_t)y_ret20;
                carry_95f84 = carry_ret20;
                overflow_95f84 = overflow_ret20;
                direct_page_95f84 = dp_ret16;
                data_bank_95f84 = db_ret16;
                goto shared_95F8_3;
            } else {
                a_hi_95f82 = a_all20 >> 8;
                y_95f82 = y_ret20;
                carry_95f82 = carry_ret20;
                overflow_95f82 = overflow_ret20;
                direct_page_95f82 = dp_ret16;
                data_bank_95f82 = db_ret16;
                goto shared_95F8_1;
            }
        }
    } else {
        uint16_t value10 = BUS16_RDP(c, (data_bank_960c3 << 0x10) + (uint16_t)((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8));
        BUS16_SET(c, (uint16_t)(direct_page_960c3 + 1), value10);
        BUS8_SET(c, (data_bank_960c3 << 0x10) + 3 + value10, 1);
        r->a = ((uint16_t)((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8) >> 8 << 8) | 1;
        r->x = value10;
        r->y = (uint16_t)((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8);
        r->c = (((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) ^ (uint16_t)((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8)) & (value8 ^ (uint16_t)((((a_all17 >> 8 << 8) | (uint8_t)((uint8_t)a_all17 << 1)) & 0xFF) + value8)) & 0x8000) != 0;
        r->xf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9630, 0x7EB7B9); GUARD_JSR(c, sp_call, 0x9630); } /* publish_native_sprite_record_with_data_bank_7f */
        r->sp += 5;
        uint16_t dp_ret17 = r->dp;
        uint8_t db_ret17 = r->db;
        bool m_ret9 = r->mf;
        bool x_ret38 = r->xf;
        uint16_t a_all21 = r->a;
        uint16_t y_ret21 = r->y;
        bool carry_ret21 = r->c;
        bool overflow_ret21 = r->v;
        if (m_ret9) {
            if (x_ret38) {
                a_hi_95f83 = a_all21 >> 8;
                y_95f83 = (uint8_t)y_ret21;
                carry_95f83 = carry_ret21;
                overflow_95f83 = overflow_ret21;
                direct_page_95f83 = dp_ret17;
                data_bank_95f83 = db_ret17;
                goto shared_95F8_2;
            } else {
                a_hi_95f8 = a_all21 >> 8;
                y_95f8 = y_ret21;
                carry_95f8 = carry_ret21;
                overflow_95f8 = overflow_ret21;
                direct_page_95f8 = dp_ret17;
                data_bank_95f8 = db_ret17;
                goto shared_95F8;
            }
        } else {
            if (x_ret38) {
                a_hi_95f84 = a_all21 >> 8;
                y_95f84 = (uint8_t)y_ret21;
                carry_95f84 = carry_ret21;
                overflow_95f84 = overflow_ret21;
                direct_page_95f84 = dp_ret17;
                data_bank_95f84 = db_ret17;
                goto shared_95F8_3;
            } else {
                a_hi_95f82 = a_all21 >> 8;
                y_95f82 = y_ret21;
                carry_95f82 = carry_ret21;
                overflow_95f82 = overflow_ret21;
                direct_page_95f82 = dp_ret17;
                data_bank_95f82 = db_ret17;
                goto shared_95F8_1;
            }
        }
    }
    shared_960C_3:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_95F8_2:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_95F8_3:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0x7E95E8, SOM_RTS, "gen", enter_warm_runtime_and_call_brightness_fade, 0, 0, 5, 1, 0, 94, 44)
