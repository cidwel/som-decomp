#include "som_c.h"

/* 7ED473 prepare_native_title_coordinator_and_enter_palette_spawn_prefix   [class C, 188 bytes, 81 instructions]
 * Source: src/boot/prepare_native_title_coordinator_and_enter_palette_spawn_prefix.s
 * Documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-prefix.md
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: CZNV.
 */
static void prepare_native_title_coordinator_and_enter_palette_spawn_prefix(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_d48d = 0;
    uint8_t a_hi_d48d = 0;
    uint8_t x_d48d = 0;
    uint8_t y_d48d = 0;
    bool carry_d48d = 0;
    bool zero_d48d = 0;
    bool negative_d48d = 0;
    bool overflow_d48d = 0;
    uint16_t direct_page_d48d = 0;
    uint8_t data_bank_d48d = 0;
    uint8_t a_d48d2 = 0;
    uint8_t a_hi_d48d2 = 0;
    uint16_t x_d48d2 = 0;
    uint16_t y_d48d2 = 0;
    bool carry_d48d2 = 0;
    bool zero_d48d2 = 0;
    bool negative_d48d2 = 0;
    bool overflow_d48d2 = 0;
    uint16_t direct_page_d48d2 = 0;
    uint8_t data_bank_d48d2 = 0;
    uint8_t a_d48d3 = 0;
    uint8_t a_hi_d48d3 = 0;
    uint8_t x_d48d3 = 0;
    uint8_t y_d48d3 = 0;
    bool carry_d48d3 = 0;
    bool zero_d48d3 = 0;
    bool negative_d48d3 = 0;
    bool overflow_d48d3 = 0;
    uint16_t direct_page_d48d3 = 0;
    uint8_t data_bank_d48d3 = 0;
    uint8_t a_d48d4 = 0;
    uint8_t a_hi_d48d4 = 0;
    uint16_t x_d48d4 = 0;
    uint16_t y_d48d4 = 0;
    bool carry_d48d4 = 0;
    bool zero_d48d4 = 0;
    bool negative_d48d4 = 0;
    bool overflow_d48d4 = 0;
    uint16_t direct_page_d48d4 = 0;
    uint8_t data_bank_d48d4 = 0;
    uint8_t a_hi_d4f5 = 0;
    uint16_t x_d4f5 = 0;
    uint16_t y_d4f5 = 0;
    bool carry_d4f5 = 0;
    bool overflow_d4f5 = 0;
    uint16_t direct_page_d4f5 = 0;
    uint8_t data_bank_d4f5 = 0;
    uint8_t a_hi_d4f52 = 0;
    uint8_t x_d4f52 = 0;
    uint8_t y_d4f52 = 0;
    bool carry_d4f52 = 0;
    bool overflow_d4f52 = 0;
    uint16_t direct_page_d4f52 = 0;
    uint8_t data_bank_d4f52 = 0;
    uint8_t a_hi_d4cb = 0;
    uint8_t y_d4cb = 0;
    bool carry_d4cb = 0;
    bool overflow_d4cb = 0;
    uint16_t direct_page_d4cb = 0;
    uint8_t data_bank_d4cb = 0;
    uint8_t a_hi_d4cb2 = 0;
    uint16_t y_d4cb2 = 0;
    bool carry_d4cb2 = 0;
    bool overflow_d4cb2 = 0;
    uint16_t direct_page_d4cb2 = 0;
    uint8_t data_bank_d4cb2 = 0;
    uint8_t a_d503 = 0;
    uint8_t a_hi_d503 = 0;
    uint16_t x_d503 = 0;
    uint16_t y_d503 = 0;
    bool carry_d503 = 0;
    bool zero_d503 = 0;
    bool negative_d503 = 0;
    bool overflow_d503 = 0;
    uint16_t direct_page_d503 = 0;
    uint8_t data_bank_d503 = 0;
    uint8_t a_d5032 = 0;
    uint8_t a_hi_d5032 = 0;
    uint8_t x_d5032 = 0;
    uint8_t y_d5032 = 0;
    bool carry_d5032 = 0;
    bool zero_d5032 = 0;
    bool negative_d5032 = 0;
    bool overflow_d5032 = 0;
    uint16_t direct_page_d5032 = 0;
    uint8_t data_bank_d5032 = 0;
    uint8_t a_d5033 = 0;
    uint8_t a_hi_d5033 = 0;
    uint8_t x_d5033 = 0;
    uint8_t y_d5033 = 0;
    bool carry_d5033 = 0;
    bool zero_d5033 = 0;
    bool negative_d5033 = 0;
    bool overflow_d5033 = 0;
    uint16_t direct_page_d5033 = 0;
    uint8_t data_bank_d5033 = 0;
    uint8_t a_d5034 = 0;
    uint8_t a_hi_d5034 = 0;
    uint16_t x_d5034 = 0;
    uint16_t y_d5034 = 0;
    bool carry_d5034 = 0;
    bool zero_d5034 = 0;
    bool negative_d5034 = 0;
    bool overflow_d5034 = 0;
    uint16_t direct_page_d5034 = 0;
    uint8_t data_bank_d5034 = 0;
    uint8_t a_d4cf = 0;
    uint8_t a_hi_d4cf = 0;
    uint8_t y_d4cf = 0;
    bool carry_d4cf = 0;
    bool zero_d4cf = 0;
    bool negative_d4cf = 0;
    bool overflow_d4cf = 0;
    uint16_t direct_page_d4cf = 0;
    uint8_t data_bank_d4cf = 0;
    uint8_t a_d4cf2 = 0;
    uint8_t a_hi_d4cf2 = 0;
    uint16_t y_d4cf2 = 0;
    bool carry_d4cf2 = 0;
    bool zero_d4cf2 = 0;
    bool negative_d4cf2 = 0;
    bool overflow_d4cf2 = 0;
    uint16_t direct_page_d4cf2 = 0;
    uint8_t data_bank_d4cf2 = 0;
    uint8_t a_hi_d506 = 0;
    uint16_t x_d506 = 0;
    uint16_t y_d506 = 0;
    bool carry_d506 = 0;
    bool overflow_d506 = 0;
    uint16_t direct_page_d506 = 0;
    uint8_t data_bank_d506 = 0;
    uint8_t a_hi_d5062 = 0;
    uint16_t x_d5062 = 0;
    uint16_t y_d5062 = 0;
    bool carry_d5062 = 0;
    bool overflow_d5062 = 0;
    uint16_t direct_page_d5062 = 0;
    uint8_t data_bank_d5062 = 0;
    uint8_t a_hi_d5063 = 0;
    uint8_t x_d5063 = 0;
    uint8_t y_d5063 = 0;
    bool carry_d5063 = 0;
    bool overflow_d5063 = 0;
    uint16_t direct_page_d5063 = 0;
    uint8_t data_bank_d5063 = 0;
    uint8_t a_hi_d5064 = 0;
    uint8_t x_d5064 = 0;
    uint8_t y_d5064 = 0;
    bool carry_d5064 = 0;
    bool overflow_d5064 = 0;
    uint16_t direct_page_d5064 = 0;
    uint8_t data_bank_d5064 = 0;
    uint8_t y_d527 = 0;
    bool carry_d527 = 0;
    bool zero_d527 = 0;
    bool negative_d527 = 0;
    bool overflow_d527 = 0;
    uint16_t direct_page_d527 = 0;
    uint8_t data_bank_d527 = 0;
    uint16_t y_d5272 = 0;
    bool carry_d5272 = 0;
    bool zero_d5272 = 0;
    bool negative_d5272 = 0;
    bool overflow_d5272 = 0;
    uint16_t direct_page_d5272 = 0;
    uint8_t data_bank_d5272 = 0;
    uint8_t y_d5273 = 0;
    bool carry_d5273 = 0;
    bool zero_d5273 = 0;
    bool negative_d5273 = 0;
    bool overflow_d5273 = 0;
    uint16_t direct_page_d5273 = 0;
    uint8_t data_bank_d5273 = 0;
    uint16_t y_d5274 = 0;
    bool carry_d5274 = 0;
    bool zero_d5274 = 0;
    bool negative_d5274 = 0;
    bool overflow_d5274 = 0;
    uint16_t direct_page_d5274 = 0;
    uint8_t data_bank_d5274 = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | 0x7E;
    r->x = 0x649C;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD483, 0x7EAB88); GUARD_JSR(c, sp_call, 0xD483); } /* create_and_enqueue_task */
    r->sp += 5;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    uint16_t a_all = r->a;
    if (m_ret) {
        BUS8_SET(c, (db_ret << 0x10) + 0x0315, (uint8_t)a_all);
        BUS8_SET(c, (db_ret << 0x10) + 0x0316, 0);
        r->mf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD48C, 0x7ED445); GUARD_JSR(c, sp_call, 0xD48C); } /* check_title_video_region_or_queue_error_and_spin */
        r->sp += 5;
        uint16_t dp_ret2 = r->dp;
        bool m_ret2 = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool zero_ret2 = r->z;
        bool negative_ret2 = r->n;
        bool overflow_ret2 = r->v;
        if (m_ret2) {
            if (x_ret3) {
                a_d48d = (uint8_t)a_all2;
                a_hi_d48d = a_all2 >> 8;
                x_d48d = (uint8_t)x_ret4;
                y_d48d = (uint8_t)y_ret2;
                carry_d48d = carry_ret2;
                zero_d48d = zero_ret2;
                negative_d48d = negative_ret2;
                overflow_d48d = overflow_ret2;
                direct_page_d48d = dp_ret2;
                data_bank_d48d = db_ret;
                goto shared_D48D;
            } else {
                a_d48d2 = (uint8_t)a_all2;
                a_hi_d48d2 = a_all2 >> 8;
                x_d48d2 = x_ret4;
                y_d48d2 = y_ret2;
                carry_d48d2 = carry_ret2;
                zero_d48d2 = zero_ret2;
                negative_d48d2 = negative_ret2;
                overflow_d48d2 = overflow_ret2;
                direct_page_d48d2 = dp_ret2;
                data_bank_d48d2 = db_ret;
                goto shared_D48D_1;
            }
        } else {
            if (x_ret3) {
                a_d48d3 = (uint8_t)a_all2;
                a_hi_d48d3 = a_all2 >> 8;
                x_d48d3 = (uint8_t)x_ret4;
                y_d48d3 = (uint8_t)y_ret2;
                carry_d48d3 = carry_ret2;
                zero_d48d3 = zero_ret2;
                negative_d48d3 = negative_ret2;
                overflow_d48d3 = overflow_ret2;
                direct_page_d48d3 = dp_ret2;
                data_bank_d48d3 = db_ret;
                goto shared_D48D_2;
            } else {
                a_d48d4 = (uint8_t)a_all2;
                a_hi_d48d4 = a_all2 >> 8;
                x_d48d4 = x_ret4;
                y_d48d4 = y_ret2;
                carry_d48d4 = carry_ret2;
                zero_d48d4 = zero_ret2;
                negative_d48d4 = negative_ret2;
                overflow_d48d4 = overflow_ret2;
                direct_page_d48d4 = dp_ret2;
                data_bank_d48d4 = db_ret;
                goto shared_D48D_3;
            }
        }
    } else {
        BUS16_SET(c, (db_ret << 0x10) + 0x0315, a_all);
        BUS16_SET(c, (db_ret << 0x10) + 0x0316, 0);
        r->mf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD48C, 0x7ED445); GUARD_JSR(c, sp_call, 0xD48C); } /* check_title_video_region_or_queue_error_and_spin */
        r->sp += 5;
        uint16_t dp_ret3 = r->dp;
        bool m_ret3 = r->mf;
        bool x_ret5 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret6 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool zero_ret3 = r->z;
        bool negative_ret3 = r->n;
        bool overflow_ret3 = r->v;
        if (m_ret3) {
            if (x_ret5) {
                a_d48d = (uint8_t)a_all3;
                a_hi_d48d = a_all3 >> 8;
                x_d48d = (uint8_t)x_ret6;
                y_d48d = (uint8_t)y_ret3;
                carry_d48d = carry_ret3;
                zero_d48d = zero_ret3;
                negative_d48d = negative_ret3;
                overflow_d48d = overflow_ret3;
                direct_page_d48d = dp_ret3;
                data_bank_d48d = db_ret;
                goto shared_D48D;
            } else {
                a_d48d2 = (uint8_t)a_all3;
                a_hi_d48d2 = a_all3 >> 8;
                x_d48d2 = x_ret6;
                y_d48d2 = y_ret3;
                carry_d48d2 = carry_ret3;
                zero_d48d2 = zero_ret3;
                negative_d48d2 = negative_ret3;
                overflow_d48d2 = overflow_ret3;
                direct_page_d48d2 = dp_ret3;
                data_bank_d48d2 = db_ret;
                goto shared_D48D_1;
            }
        } else {
            if (x_ret5) {
                a_d48d3 = (uint8_t)a_all3;
                a_hi_d48d3 = a_all3 >> 8;
                x_d48d3 = (uint8_t)x_ret6;
                y_d48d3 = (uint8_t)y_ret3;
                carry_d48d3 = carry_ret3;
                zero_d48d3 = zero_ret3;
                negative_d48d3 = negative_ret3;
                overflow_d48d3 = overflow_ret3;
                direct_page_d48d3 = dp_ret3;
                data_bank_d48d3 = db_ret;
                goto shared_D48D_2;
            } else {
                a_d48d4 = (uint8_t)a_all3;
                a_hi_d48d4 = a_all3 >> 8;
                x_d48d4 = x_ret6;
                y_d48d4 = y_ret3;
                carry_d48d4 = carry_ret3;
                zero_d48d4 = zero_ret3;
                negative_d48d4 = negative_ret3;
                overflow_d48d4 = overflow_ret3;
                direct_page_d48d4 = dp_ret3;
                data_bank_d48d4 = db_ret;
                goto shared_D48D_3;
            }
        }
    }
    shared_D48D:;
    r->a = (a_hi_d48d << 8) | a_d48d;
    r->x = x_d48d;
    r->y = y_d48d;
    r->c = carry_d48d;
    r->z = zero_d48d;
    r->n = negative_d48d;
    r->v = overflow_d48d;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_d48d;
    r->dp = direct_page_d48d;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD48F, 0x7ED23E); GUARD_JSR(c, sp_call, 0xD48F); } /* run_title_parent_sequence */
    r->sp += 5;
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret2 = r->db;
    uint16_t a_all4 = r->a;
    uint16_t x_ret7 = r->x;
    uint16_t y_ret4 = r->y;
    bool overflow_ret4 = r->v;
    if ((uint8_t)a_all4 == 0) {
        a_hi_d4f5 = a_all4 >> 8;
        x_d4f5 = x_ret7;
        y_d4f5 = y_ret4;
        carry_d4f5 = (uint8_t)a_all4 >= 0;
        overflow_d4f5 = overflow_ret4;
        direct_page_d4f5 = dp_ret4;
        data_bank_d4f5 = db_ret2;
        goto shared_D4F5;
    }
    r->x = 0x0564;
    r->c = (uint8_t)a_all4 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD499, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD499); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret3 = r->db;
    bool x_ret8 = r->xf;
    uint16_t a_all5 = r->a;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret5 = r->y;
    bool overflow_ret5 = r->v;
    if ((uint8_t)a_all5 == 0) {
        if (x_ret8) {
            a_hi_d4f52 = a_all5 >> 8;
            x_d4f52 = (uint8_t)x_ret9;
            y_d4f52 = (uint8_t)y_ret5;
            carry_d4f52 = (uint8_t)a_all5 >= 0;
            overflow_d4f52 = overflow_ret5;
            direct_page_d4f52 = dp_ret5;
            data_bank_d4f52 = db_ret3;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all5 >> 8;
            x_d4f5 = x_ret9;
            y_d4f5 = y_ret5;
            carry_d4f5 = (uint8_t)a_all5 >= 0;
            overflow_d4f5 = overflow_ret5;
            direct_page_d4f5 = dp_ret5;
            data_bank_d4f5 = db_ret3;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all5 >= 0;
    r->z = (uint8_t)a_all5 == 0;
    r->n = (uint8_t)a_all5 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4A0, 0x7ED2FC); GUARD_JSR(c, sp_call, 0xD4A0); } /* open_title_scanline_window */
    r->sp += 5;
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret4 = r->db;
    uint16_t a_all6 = r->a;
    uint16_t x_ret10 = r->x;
    uint16_t y_ret6 = r->y;
    bool overflow_ret6 = r->v;
    if ((uint8_t)a_all6 == 0) {
        a_hi_d4f5 = a_all6 >> 8;
        x_d4f5 = x_ret10;
        y_d4f5 = y_ret6;
        carry_d4f5 = (uint8_t)a_all6 >= 0;
        overflow_d4f5 = overflow_ret6;
        direct_page_d4f5 = dp_ret6;
        data_bank_d4f5 = db_ret4;
        goto shared_D4F5;
    }
    r->x = 0xF0;
    r->c = (uint8_t)a_all6 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4AA, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4AA); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret5 = r->db;
    bool x_ret11 = r->xf;
    uint16_t a_all7 = r->a;
    uint16_t x_ret12 = r->x;
    uint16_t y_ret7 = r->y;
    bool overflow_ret7 = r->v;
    if ((uint8_t)a_all7 == 0) {
        if (x_ret11) {
            a_hi_d4f52 = a_all7 >> 8;
            x_d4f52 = (uint8_t)x_ret12;
            y_d4f52 = (uint8_t)y_ret7;
            carry_d4f52 = (uint8_t)a_all7 >= 0;
            overflow_d4f52 = overflow_ret7;
            direct_page_d4f52 = dp_ret7;
            data_bank_d4f52 = db_ret5;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all7 >> 8;
            x_d4f5 = x_ret12;
            y_d4f5 = y_ret7;
            carry_d4f5 = (uint8_t)a_all7 >= 0;
            overflow_d4f5 = overflow_ret7;
            direct_page_d4f5 = dp_ret7;
            data_bank_d4f5 = db_ret5;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all7 >= 0;
    r->z = (uint8_t)a_all7 == 0;
    r->n = (uint8_t)a_all7 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4B1, 0x7ED348); GUARD_JSR(c, sp_call, 0xD4B1); } /* scroll_title_register_word_to_endpoint */
    r->sp += 5;
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret6 = r->db;
    uint16_t a_all8 = r->a;
    uint16_t x_ret13 = r->x;
    uint16_t y_ret8 = r->y;
    bool overflow_ret8 = r->v;
    if ((uint8_t)a_all8 == 0) {
        a_hi_d4f5 = a_all8 >> 8;
        x_d4f5 = x_ret13;
        y_d4f5 = y_ret8;
        carry_d4f5 = (uint8_t)a_all8 >= 0;
        overflow_d4f5 = overflow_ret8;
        direct_page_d4f5 = dp_ret8;
        data_bank_d4f5 = db_ret6;
        goto shared_D4F5;
    }
    r->x = 0xC6;
    r->c = (uint8_t)a_all8 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4BB, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4BB); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret9 = r->dp;
    uint8_t db_ret7 = r->db;
    bool x_ret14 = r->xf;
    uint16_t a_all9 = r->a;
    uint16_t x_ret15 = r->x;
    uint16_t y_ret9 = r->y;
    bool overflow_ret9 = r->v;
    if ((uint8_t)a_all9 == 0) {
        if (x_ret14) {
            a_hi_d4f52 = a_all9 >> 8;
            x_d4f52 = (uint8_t)x_ret15;
            y_d4f52 = (uint8_t)y_ret9;
            carry_d4f52 = (uint8_t)a_all9 >= 0;
            overflow_d4f52 = overflow_ret9;
            direct_page_d4f52 = dp_ret9;
            data_bank_d4f52 = db_ret7;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all9 >> 8;
            x_d4f5 = x_ret15;
            y_d4f5 = y_ret9;
            carry_d4f5 = (uint8_t)a_all9 >= 0;
            overflow_d4f5 = overflow_ret9;
            direct_page_d4f5 = dp_ret9;
            data_bank_d4f5 = db_ret7;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all9 >= 0;
    r->z = (uint8_t)a_all9 == 0;
    r->n = (uint8_t)a_all9 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4C2, 0x7ED377); GUARD_JSR(c, sp_call, 0xD4C2); } /* expand_title_scanline_window */
    r->sp += 5;
    uint16_t dp_ret10 = r->dp;
    uint8_t db_ret8 = r->db;
    bool x_ret16 = r->xf;
    uint16_t a_all10 = r->a;
    uint16_t x_ret17 = r->x;
    uint16_t y_ret10 = r->y;
    bool overflow_ret10 = r->v;
    if ((uint8_t)a_all10 == 0) {
        if (x_ret16) {
            a_hi_d4f52 = a_all10 >> 8;
            x_d4f52 = (uint8_t)x_ret17;
            y_d4f52 = (uint8_t)y_ret10;
            carry_d4f52 = (uint8_t)a_all10 >= 0;
            overflow_d4f52 = overflow_ret10;
            direct_page_d4f52 = dp_ret10;
            data_bank_d4f52 = db_ret8;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all10 >> 8;
            x_d4f5 = x_ret17;
            y_d4f5 = y_ret10;
            carry_d4f5 = (uint8_t)a_all10 >= 0;
            overflow_d4f5 = overflow_ret10;
            direct_page_d4f5 = dp_ret10;
            data_bank_d4f5 = db_ret8;
            goto shared_D4F5;
        }
    }
    RAM8(0x0001 + dp_ret10) = 2;
    if (x_ret16) {
        a_hi_d4cb = a_all10 >> 8;
        y_d4cb = (uint8_t)y_ret10;
        carry_d4cb = (uint8_t)a_all10 >= 0;
        overflow_d4cb = overflow_ret10;
        direct_page_d4cb = dp_ret10;
        data_bank_d4cb = db_ret8;
        goto shared_D4CB;
    } else {
        a_hi_d4cb2 = a_all10 >> 8;
        y_d4cb2 = y_ret10;
        carry_d4cb2 = (uint8_t)a_all10 >= 0;
        overflow_d4cb2 = overflow_ret10;
        direct_page_d4cb2 = dp_ret10;
        data_bank_d4cb2 = db_ret8;
        goto shared_D4CB_1;
    }
    shared_D48D_1:;
    r->a = (a_hi_d48d2 << 8) | a_d48d2;
    r->x = x_d48d2;
    r->y = y_d48d2;
    r->c = carry_d48d2;
    r->z = zero_d48d2;
    r->n = negative_d48d2;
    r->v = overflow_d48d2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_d48d2;
    r->dp = direct_page_d48d2;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD48F, 0x7ED23E); GUARD_JSR(c, sp_call, 0xD48F); } /* run_title_parent_sequence */
    r->sp += 5;
    uint16_t dp_ret11 = r->dp;
    uint8_t db_ret9 = r->db;
    uint16_t a_all11 = r->a;
    uint16_t x_ret18 = r->x;
    uint16_t y_ret11 = r->y;
    bool overflow_ret11 = r->v;
    if ((uint8_t)a_all11 == 0) {
        a_hi_d4f5 = a_all11 >> 8;
        x_d4f5 = x_ret18;
        y_d4f5 = y_ret11;
        carry_d4f5 = (uint8_t)a_all11 >= 0;
        overflow_d4f5 = overflow_ret11;
        direct_page_d4f5 = dp_ret11;
        data_bank_d4f5 = db_ret9;
        goto shared_D4F5;
    }
    r->x = 0x0564;
    r->c = (uint8_t)a_all11 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD499, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD499); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret12 = r->dp;
    uint8_t db_ret10 = r->db;
    bool x_ret19 = r->xf;
    uint16_t a_all12 = r->a;
    uint16_t x_ret20 = r->x;
    uint16_t y_ret12 = r->y;
    bool overflow_ret12 = r->v;
    if ((uint8_t)a_all12 == 0) {
        if (x_ret19) {
            a_hi_d4f52 = a_all12 >> 8;
            x_d4f52 = (uint8_t)x_ret20;
            y_d4f52 = (uint8_t)y_ret12;
            carry_d4f52 = (uint8_t)a_all12 >= 0;
            overflow_d4f52 = overflow_ret12;
            direct_page_d4f52 = dp_ret12;
            data_bank_d4f52 = db_ret10;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all12 >> 8;
            x_d4f5 = x_ret20;
            y_d4f5 = y_ret12;
            carry_d4f5 = (uint8_t)a_all12 >= 0;
            overflow_d4f5 = overflow_ret12;
            direct_page_d4f5 = dp_ret12;
            data_bank_d4f5 = db_ret10;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all12 >= 0;
    r->z = (uint8_t)a_all12 == 0;
    r->n = (uint8_t)a_all12 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4A0, 0x7ED2FC); GUARD_JSR(c, sp_call, 0xD4A0); } /* open_title_scanline_window */
    r->sp += 5;
    uint16_t dp_ret13 = r->dp;
    uint8_t db_ret11 = r->db;
    uint16_t a_all13 = r->a;
    uint16_t x_ret21 = r->x;
    uint16_t y_ret13 = r->y;
    bool overflow_ret13 = r->v;
    if ((uint8_t)a_all13 == 0) {
        a_hi_d4f5 = a_all13 >> 8;
        x_d4f5 = x_ret21;
        y_d4f5 = y_ret13;
        carry_d4f5 = (uint8_t)a_all13 >= 0;
        overflow_d4f5 = overflow_ret13;
        direct_page_d4f5 = dp_ret13;
        data_bank_d4f5 = db_ret11;
        goto shared_D4F5;
    }
    r->x = 0xF0;
    r->c = (uint8_t)a_all13 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4AA, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4AA); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret14 = r->dp;
    uint8_t db_ret12 = r->db;
    bool x_ret22 = r->xf;
    uint16_t a_all14 = r->a;
    uint16_t x_ret23 = r->x;
    uint16_t y_ret14 = r->y;
    bool overflow_ret14 = r->v;
    if ((uint8_t)a_all14 == 0) {
        if (x_ret22) {
            a_hi_d4f52 = a_all14 >> 8;
            x_d4f52 = (uint8_t)x_ret23;
            y_d4f52 = (uint8_t)y_ret14;
            carry_d4f52 = (uint8_t)a_all14 >= 0;
            overflow_d4f52 = overflow_ret14;
            direct_page_d4f52 = dp_ret14;
            data_bank_d4f52 = db_ret12;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all14 >> 8;
            x_d4f5 = x_ret23;
            y_d4f5 = y_ret14;
            carry_d4f5 = (uint8_t)a_all14 >= 0;
            overflow_d4f5 = overflow_ret14;
            direct_page_d4f5 = dp_ret14;
            data_bank_d4f5 = db_ret12;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all14 >= 0;
    r->z = (uint8_t)a_all14 == 0;
    r->n = (uint8_t)a_all14 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4B1, 0x7ED348); GUARD_JSR(c, sp_call, 0xD4B1); } /* scroll_title_register_word_to_endpoint */
    r->sp += 5;
    uint16_t dp_ret15 = r->dp;
    uint8_t db_ret13 = r->db;
    uint16_t a_all15 = r->a;
    uint16_t x_ret24 = r->x;
    uint16_t y_ret15 = r->y;
    bool overflow_ret15 = r->v;
    if ((uint8_t)a_all15 == 0) {
        a_hi_d4f5 = a_all15 >> 8;
        x_d4f5 = x_ret24;
        y_d4f5 = y_ret15;
        carry_d4f5 = (uint8_t)a_all15 >= 0;
        overflow_d4f5 = overflow_ret15;
        direct_page_d4f5 = dp_ret15;
        data_bank_d4f5 = db_ret13;
        goto shared_D4F5;
    }
    r->x = 0xC6;
    r->c = (uint8_t)a_all15 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4BB, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4BB); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret16 = r->dp;
    uint8_t db_ret14 = r->db;
    bool x_ret25 = r->xf;
    uint16_t a_all16 = r->a;
    uint16_t x_ret26 = r->x;
    uint16_t y_ret16 = r->y;
    bool overflow_ret16 = r->v;
    if ((uint8_t)a_all16 == 0) {
        if (x_ret25) {
            a_hi_d4f52 = a_all16 >> 8;
            x_d4f52 = (uint8_t)x_ret26;
            y_d4f52 = (uint8_t)y_ret16;
            carry_d4f52 = (uint8_t)a_all16 >= 0;
            overflow_d4f52 = overflow_ret16;
            direct_page_d4f52 = dp_ret16;
            data_bank_d4f52 = db_ret14;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all16 >> 8;
            x_d4f5 = x_ret26;
            y_d4f5 = y_ret16;
            carry_d4f5 = (uint8_t)a_all16 >= 0;
            overflow_d4f5 = overflow_ret16;
            direct_page_d4f5 = dp_ret16;
            data_bank_d4f5 = db_ret14;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all16 >= 0;
    r->z = (uint8_t)a_all16 == 0;
    r->n = (uint8_t)a_all16 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4C2, 0x7ED377); GUARD_JSR(c, sp_call, 0xD4C2); } /* expand_title_scanline_window */
    r->sp += 5;
    uint16_t dp_ret17 = r->dp;
    uint8_t db_ret15 = r->db;
    bool x_ret27 = r->xf;
    uint16_t a_all17 = r->a;
    uint16_t x_ret28 = r->x;
    uint16_t y_ret17 = r->y;
    bool overflow_ret17 = r->v;
    if ((uint8_t)a_all17 == 0) {
        if (x_ret27) {
            a_hi_d4f52 = a_all17 >> 8;
            x_d4f52 = (uint8_t)x_ret28;
            y_d4f52 = (uint8_t)y_ret17;
            carry_d4f52 = (uint8_t)a_all17 >= 0;
            overflow_d4f52 = overflow_ret17;
            direct_page_d4f52 = dp_ret17;
            data_bank_d4f52 = db_ret15;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all17 >> 8;
            x_d4f5 = x_ret28;
            y_d4f5 = y_ret17;
            carry_d4f5 = (uint8_t)a_all17 >= 0;
            overflow_d4f5 = overflow_ret17;
            direct_page_d4f5 = dp_ret17;
            data_bank_d4f5 = db_ret15;
            goto shared_D4F5;
        }
    }
    RAM8(0x0001 + dp_ret17) = 2;
    if (x_ret27) {
        a_hi_d4cb = a_all17 >> 8;
        y_d4cb = (uint8_t)y_ret17;
        carry_d4cb = (uint8_t)a_all17 >= 0;
        overflow_d4cb = overflow_ret17;
        direct_page_d4cb = dp_ret17;
        data_bank_d4cb = db_ret15;
        goto shared_D4CB;
    } else {
        a_hi_d4cb2 = a_all17 >> 8;
        y_d4cb2 = y_ret17;
        carry_d4cb2 = (uint8_t)a_all17 >= 0;
        overflow_d4cb2 = overflow_ret17;
        direct_page_d4cb2 = dp_ret17;
        data_bank_d4cb2 = db_ret15;
        goto shared_D4CB_1;
    }
    shared_D48D_2:;
    r->a = (a_hi_d48d3 << 8) | a_d48d3;
    r->x = x_d48d3;
    r->y = y_d48d3;
    r->c = carry_d48d3;
    r->z = zero_d48d3;
    r->n = negative_d48d3;
    r->v = overflow_d48d3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_d48d3;
    r->dp = direct_page_d48d3;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD48F, 0x7ED23E); GUARD_JSR(c, sp_call, 0xD48F); } /* run_title_parent_sequence */
    r->sp += 5;
    uint16_t dp_ret18 = r->dp;
    uint8_t db_ret16 = r->db;
    uint16_t a_all18 = r->a;
    uint16_t x_ret29 = r->x;
    uint16_t y_ret18 = r->y;
    bool overflow_ret18 = r->v;
    if ((uint8_t)a_all18 == 0) {
        a_hi_d4f5 = a_all18 >> 8;
        x_d4f5 = x_ret29;
        y_d4f5 = y_ret18;
        carry_d4f5 = (uint8_t)a_all18 >= 0;
        overflow_d4f5 = overflow_ret18;
        direct_page_d4f5 = dp_ret18;
        data_bank_d4f5 = db_ret16;
        goto shared_D4F5;
    }
    r->x = 0x0564;
    r->c = (uint8_t)a_all18 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD499, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD499); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret19 = r->dp;
    uint8_t db_ret17 = r->db;
    bool x_ret30 = r->xf;
    uint16_t a_all19 = r->a;
    uint16_t x_ret31 = r->x;
    uint16_t y_ret19 = r->y;
    bool overflow_ret19 = r->v;
    if ((uint8_t)a_all19 == 0) {
        if (x_ret30) {
            a_hi_d4f52 = a_all19 >> 8;
            x_d4f52 = (uint8_t)x_ret31;
            y_d4f52 = (uint8_t)y_ret19;
            carry_d4f52 = (uint8_t)a_all19 >= 0;
            overflow_d4f52 = overflow_ret19;
            direct_page_d4f52 = dp_ret19;
            data_bank_d4f52 = db_ret17;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all19 >> 8;
            x_d4f5 = x_ret31;
            y_d4f5 = y_ret19;
            carry_d4f5 = (uint8_t)a_all19 >= 0;
            overflow_d4f5 = overflow_ret19;
            direct_page_d4f5 = dp_ret19;
            data_bank_d4f5 = db_ret17;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all19 >= 0;
    r->z = (uint8_t)a_all19 == 0;
    r->n = (uint8_t)a_all19 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4A0, 0x7ED2FC); GUARD_JSR(c, sp_call, 0xD4A0); } /* open_title_scanline_window */
    r->sp += 5;
    uint16_t dp_ret20 = r->dp;
    uint8_t db_ret18 = r->db;
    uint16_t a_all20 = r->a;
    uint16_t x_ret32 = r->x;
    uint16_t y_ret20 = r->y;
    bool overflow_ret20 = r->v;
    if ((uint8_t)a_all20 == 0) {
        a_hi_d4f5 = a_all20 >> 8;
        x_d4f5 = x_ret32;
        y_d4f5 = y_ret20;
        carry_d4f5 = (uint8_t)a_all20 >= 0;
        overflow_d4f5 = overflow_ret20;
        direct_page_d4f5 = dp_ret20;
        data_bank_d4f5 = db_ret18;
        goto shared_D4F5;
    }
    r->x = 0xF0;
    r->c = (uint8_t)a_all20 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4AA, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4AA); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret21 = r->dp;
    uint8_t db_ret19 = r->db;
    bool x_ret33 = r->xf;
    uint16_t a_all21 = r->a;
    uint16_t x_ret34 = r->x;
    uint16_t y_ret21 = r->y;
    bool overflow_ret21 = r->v;
    if ((uint8_t)a_all21 == 0) {
        if (x_ret33) {
            a_hi_d4f52 = a_all21 >> 8;
            x_d4f52 = (uint8_t)x_ret34;
            y_d4f52 = (uint8_t)y_ret21;
            carry_d4f52 = (uint8_t)a_all21 >= 0;
            overflow_d4f52 = overflow_ret21;
            direct_page_d4f52 = dp_ret21;
            data_bank_d4f52 = db_ret19;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all21 >> 8;
            x_d4f5 = x_ret34;
            y_d4f5 = y_ret21;
            carry_d4f5 = (uint8_t)a_all21 >= 0;
            overflow_d4f5 = overflow_ret21;
            direct_page_d4f5 = dp_ret21;
            data_bank_d4f5 = db_ret19;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all21 >= 0;
    r->z = (uint8_t)a_all21 == 0;
    r->n = (uint8_t)a_all21 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4B1, 0x7ED348); GUARD_JSR(c, sp_call, 0xD4B1); } /* scroll_title_register_word_to_endpoint */
    r->sp += 5;
    uint16_t dp_ret22 = r->dp;
    uint8_t db_ret20 = r->db;
    uint16_t a_all22 = r->a;
    uint16_t x_ret35 = r->x;
    uint16_t y_ret22 = r->y;
    bool overflow_ret22 = r->v;
    if ((uint8_t)a_all22 == 0) {
        a_hi_d4f5 = a_all22 >> 8;
        x_d4f5 = x_ret35;
        y_d4f5 = y_ret22;
        carry_d4f5 = (uint8_t)a_all22 >= 0;
        overflow_d4f5 = overflow_ret22;
        direct_page_d4f5 = dp_ret22;
        data_bank_d4f5 = db_ret20;
        goto shared_D4F5;
    }
    r->x = 0xC6;
    r->c = (uint8_t)a_all22 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4BB, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4BB); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret23 = r->dp;
    uint8_t db_ret21 = r->db;
    bool x_ret36 = r->xf;
    uint16_t a_all23 = r->a;
    uint16_t x_ret37 = r->x;
    uint16_t y_ret23 = r->y;
    bool overflow_ret23 = r->v;
    if ((uint8_t)a_all23 == 0) {
        if (x_ret36) {
            a_hi_d4f52 = a_all23 >> 8;
            x_d4f52 = (uint8_t)x_ret37;
            y_d4f52 = (uint8_t)y_ret23;
            carry_d4f52 = (uint8_t)a_all23 >= 0;
            overflow_d4f52 = overflow_ret23;
            direct_page_d4f52 = dp_ret23;
            data_bank_d4f52 = db_ret21;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all23 >> 8;
            x_d4f5 = x_ret37;
            y_d4f5 = y_ret23;
            carry_d4f5 = (uint8_t)a_all23 >= 0;
            overflow_d4f5 = overflow_ret23;
            direct_page_d4f5 = dp_ret23;
            data_bank_d4f5 = db_ret21;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all23 >= 0;
    r->z = (uint8_t)a_all23 == 0;
    r->n = (uint8_t)a_all23 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4C2, 0x7ED377); GUARD_JSR(c, sp_call, 0xD4C2); } /* expand_title_scanline_window */
    r->sp += 5;
    uint16_t dp_ret24 = r->dp;
    uint8_t db_ret22 = r->db;
    bool x_ret38 = r->xf;
    uint16_t a_all24 = r->a;
    uint16_t x_ret39 = r->x;
    uint16_t y_ret24 = r->y;
    bool overflow_ret24 = r->v;
    if ((uint8_t)a_all24 == 0) {
        if (x_ret38) {
            a_hi_d4f52 = a_all24 >> 8;
            x_d4f52 = (uint8_t)x_ret39;
            y_d4f52 = (uint8_t)y_ret24;
            carry_d4f52 = (uint8_t)a_all24 >= 0;
            overflow_d4f52 = overflow_ret24;
            direct_page_d4f52 = dp_ret24;
            data_bank_d4f52 = db_ret22;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all24 >> 8;
            x_d4f5 = x_ret39;
            y_d4f5 = y_ret24;
            carry_d4f5 = (uint8_t)a_all24 >= 0;
            overflow_d4f5 = overflow_ret24;
            direct_page_d4f5 = dp_ret24;
            data_bank_d4f5 = db_ret22;
            goto shared_D4F5;
        }
    }
    RAM8(0x0001 + dp_ret24) = 2;
    if (x_ret38) {
        a_hi_d4cb = a_all24 >> 8;
        y_d4cb = (uint8_t)y_ret24;
        carry_d4cb = (uint8_t)a_all24 >= 0;
        overflow_d4cb = overflow_ret24;
        direct_page_d4cb = dp_ret24;
        data_bank_d4cb = db_ret22;
        goto shared_D4CB;
    } else {
        a_hi_d4cb2 = a_all24 >> 8;
        y_d4cb2 = y_ret24;
        carry_d4cb2 = (uint8_t)a_all24 >= 0;
        overflow_d4cb2 = overflow_ret24;
        direct_page_d4cb2 = dp_ret24;
        data_bank_d4cb2 = db_ret22;
        goto shared_D4CB_1;
    }
    shared_D48D_3:;
    r->a = (a_hi_d48d4 << 8) | a_d48d4;
    r->x = x_d48d4;
    r->y = y_d48d4;
    r->c = carry_d48d4;
    r->z = zero_d48d4;
    r->n = negative_d48d4;
    r->v = overflow_d48d4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_d48d4;
    r->dp = direct_page_d48d4;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD48F, 0x7ED23E); GUARD_JSR(c, sp_call, 0xD48F); } /* run_title_parent_sequence */
    r->sp += 5;
    uint16_t dp_ret25 = r->dp;
    uint8_t db_ret23 = r->db;
    uint16_t a_all25 = r->a;
    uint16_t x_ret40 = r->x;
    uint16_t y_ret25 = r->y;
    bool overflow_ret25 = r->v;
    if ((uint8_t)a_all25 == 0) {
        a_hi_d4f5 = a_all25 >> 8;
        x_d4f5 = x_ret40;
        y_d4f5 = y_ret25;
        carry_d4f5 = (uint8_t)a_all25 >= 0;
        overflow_d4f5 = overflow_ret25;
        direct_page_d4f5 = dp_ret25;
        data_bank_d4f5 = db_ret23;
        goto shared_D4F5;
    }
    r->x = 0x0564;
    r->c = (uint8_t)a_all25 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD499, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD499); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret26 = r->dp;
    uint8_t db_ret24 = r->db;
    bool x_ret41 = r->xf;
    uint16_t a_all26 = r->a;
    uint16_t x_ret42 = r->x;
    uint16_t y_ret26 = r->y;
    bool overflow_ret26 = r->v;
    if ((uint8_t)a_all26 == 0) {
        if (x_ret41) {
            a_hi_d4f52 = a_all26 >> 8;
            x_d4f52 = (uint8_t)x_ret42;
            y_d4f52 = (uint8_t)y_ret26;
            carry_d4f52 = (uint8_t)a_all26 >= 0;
            overflow_d4f52 = overflow_ret26;
            direct_page_d4f52 = dp_ret26;
            data_bank_d4f52 = db_ret24;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all26 >> 8;
            x_d4f5 = x_ret42;
            y_d4f5 = y_ret26;
            carry_d4f5 = (uint8_t)a_all26 >= 0;
            overflow_d4f5 = overflow_ret26;
            direct_page_d4f5 = dp_ret26;
            data_bank_d4f5 = db_ret24;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all26 >= 0;
    r->z = (uint8_t)a_all26 == 0;
    r->n = (uint8_t)a_all26 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4A0, 0x7ED2FC); GUARD_JSR(c, sp_call, 0xD4A0); } /* open_title_scanline_window */
    r->sp += 5;
    uint16_t dp_ret27 = r->dp;
    uint8_t db_ret25 = r->db;
    uint16_t a_all27 = r->a;
    uint16_t x_ret43 = r->x;
    uint16_t y_ret27 = r->y;
    bool overflow_ret27 = r->v;
    if ((uint8_t)a_all27 == 0) {
        a_hi_d4f5 = a_all27 >> 8;
        x_d4f5 = x_ret43;
        y_d4f5 = y_ret27;
        carry_d4f5 = (uint8_t)a_all27 >= 0;
        overflow_d4f5 = overflow_ret27;
        direct_page_d4f5 = dp_ret27;
        data_bank_d4f5 = db_ret25;
        goto shared_D4F5;
    }
    r->x = 0xF0;
    r->c = (uint8_t)a_all27 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4AA, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4AA); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret28 = r->dp;
    uint8_t db_ret26 = r->db;
    bool x_ret44 = r->xf;
    uint16_t a_all28 = r->a;
    uint16_t x_ret45 = r->x;
    uint16_t y_ret28 = r->y;
    bool overflow_ret28 = r->v;
    if ((uint8_t)a_all28 == 0) {
        if (x_ret44) {
            a_hi_d4f52 = a_all28 >> 8;
            x_d4f52 = (uint8_t)x_ret45;
            y_d4f52 = (uint8_t)y_ret28;
            carry_d4f52 = (uint8_t)a_all28 >= 0;
            overflow_d4f52 = overflow_ret28;
            direct_page_d4f52 = dp_ret28;
            data_bank_d4f52 = db_ret26;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all28 >> 8;
            x_d4f5 = x_ret45;
            y_d4f5 = y_ret28;
            carry_d4f5 = (uint8_t)a_all28 >= 0;
            overflow_d4f5 = overflow_ret28;
            direct_page_d4f5 = dp_ret28;
            data_bank_d4f5 = db_ret26;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all28 >= 0;
    r->z = (uint8_t)a_all28 == 0;
    r->n = (uint8_t)a_all28 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4B1, 0x7ED348); GUARD_JSR(c, sp_call, 0xD4B1); } /* scroll_title_register_word_to_endpoint */
    r->sp += 5;
    uint16_t dp_ret29 = r->dp;
    uint8_t db_ret27 = r->db;
    uint16_t a_all29 = r->a;
    uint16_t x_ret46 = r->x;
    uint16_t y_ret29 = r->y;
    bool overflow_ret29 = r->v;
    if ((uint8_t)a_all29 == 0) {
        a_hi_d4f5 = a_all29 >> 8;
        x_d4f5 = x_ret46;
        y_d4f5 = y_ret29;
        carry_d4f5 = (uint8_t)a_all29 >= 0;
        overflow_d4f5 = overflow_ret29;
        direct_page_d4f5 = dp_ret29;
        data_bank_d4f5 = db_ret27;
        goto shared_D4F5;
    }
    r->x = 0xC6;
    r->c = (uint8_t)a_all29 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4BB, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4BB); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret30 = r->dp;
    uint8_t db_ret28 = r->db;
    bool x_ret47 = r->xf;
    uint16_t a_all30 = r->a;
    uint16_t x_ret48 = r->x;
    uint16_t y_ret30 = r->y;
    bool overflow_ret30 = r->v;
    if ((uint8_t)a_all30 == 0) {
        if (x_ret47) {
            a_hi_d4f52 = a_all30 >> 8;
            x_d4f52 = (uint8_t)x_ret48;
            y_d4f52 = (uint8_t)y_ret30;
            carry_d4f52 = (uint8_t)a_all30 >= 0;
            overflow_d4f52 = overflow_ret30;
            direct_page_d4f52 = dp_ret30;
            data_bank_d4f52 = db_ret28;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all30 >> 8;
            x_d4f5 = x_ret48;
            y_d4f5 = y_ret30;
            carry_d4f5 = (uint8_t)a_all30 >= 0;
            overflow_d4f5 = overflow_ret30;
            direct_page_d4f5 = dp_ret30;
            data_bank_d4f5 = db_ret28;
            goto shared_D4F5;
        }
    }
    r->c = (uint8_t)a_all30 >= 0;
    r->z = (uint8_t)a_all30 == 0;
    r->n = (uint8_t)a_all30 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4C2, 0x7ED377); GUARD_JSR(c, sp_call, 0xD4C2); } /* expand_title_scanline_window */
    r->sp += 5;
    uint16_t dp_ret31 = r->dp;
    uint8_t db_ret29 = r->db;
    bool x_ret49 = r->xf;
    uint16_t a_all31 = r->a;
    uint16_t x_ret50 = r->x;
    uint16_t y_ret31 = r->y;
    bool overflow_ret31 = r->v;
    if ((uint8_t)a_all31 == 0) {
        if (x_ret49) {
            a_hi_d4f52 = a_all31 >> 8;
            x_d4f52 = (uint8_t)x_ret50;
            y_d4f52 = (uint8_t)y_ret31;
            carry_d4f52 = (uint8_t)a_all31 >= 0;
            overflow_d4f52 = overflow_ret31;
            direct_page_d4f52 = dp_ret31;
            data_bank_d4f52 = db_ret29;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all31 >> 8;
            x_d4f5 = x_ret50;
            y_d4f5 = y_ret31;
            carry_d4f5 = (uint8_t)a_all31 >= 0;
            overflow_d4f5 = overflow_ret31;
            direct_page_d4f5 = dp_ret31;
            data_bank_d4f5 = db_ret29;
            goto shared_D4F5;
        }
    }
    RAM8(0x0001 + dp_ret31) = 2;
    if (x_ret49) {
        a_hi_d4cb = a_all31 >> 8;
        y_d4cb = (uint8_t)y_ret31;
        carry_d4cb = (uint8_t)a_all31 >= 0;
        overflow_d4cb = overflow_ret31;
        direct_page_d4cb = dp_ret31;
        data_bank_d4cb = db_ret29;
        goto shared_D4CB;
    } else {
        a_hi_d4cb2 = a_all31 >> 8;
        y_d4cb2 = y_ret31;
        carry_d4cb2 = (uint8_t)a_all31 >= 0;
        overflow_d4cb2 = overflow_ret31;
        direct_page_d4cb2 = dp_ret31;
        data_bank_d4cb2 = db_ret29;
        goto shared_D4CB_1;
    }
    shared_D4F5:;
    uint8_t value = BUS8_RDP(c, (data_bank_d4f5 << 0x10) + 0x0316);
    if (value == 0) {
        a_d503 = value;
        a_hi_d503 = a_hi_d4f5;
        x_d503 = x_d4f5;
        y_d503 = y_d4f5;
        carry_d503 = carry_d4f5;
        zero_d503 = value == 0;
        negative_d503 = value & 0x80;
        overflow_d503 = overflow_d4f5;
        direct_page_d503 = direct_page_d4f5;
        data_bank_d503 = data_bank_d4f5;
        goto shared_D503;
    }
    uint8_t value2 = BUS8_RDP(c, (data_bank_d4f5 << 0x10) + 0x0315);
    r->a = (a_hi_d4f5 << 8) | value2;
    r->x = x_d4f5;
    r->y = y_d4f5;
    r->c = carry_d4f5;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    r->v = overflow_d4f5;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_d4f5;
    r->dp = direct_page_d4f5;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4FF, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD4FF); } /* request_task_stop_by_id */
    r->sp += 5;
    uint16_t dp_ret32 = r->dp;
    uint8_t db_ret30 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret51 = r->xf;
    uint16_t a_all32 = r->a;
    uint16_t x_ret52 = r->x;
    uint16_t y_ret32 = r->y;
    bool carry_ret32 = r->c;
    bool zero_ret32 = r->z;
    bool negative_ret32 = r->n;
    bool overflow_ret32 = r->v;
    if (m_ret4) {
        BUS8_SET(c, (db_ret30 << 0x10) + 0x0315, 0);
        if (x_ret51) {
            a_d5032 = (uint8_t)a_all32;
            a_hi_d5032 = a_all32 >> 8;
            x_d5032 = (uint8_t)x_ret52;
            y_d5032 = (uint8_t)y_ret32;
            carry_d5032 = carry_ret32;
            zero_d5032 = zero_ret32;
            negative_d5032 = negative_ret32;
            overflow_d5032 = overflow_ret32;
            direct_page_d5032 = dp_ret32;
            data_bank_d5032 = db_ret30;
            goto shared_D503_1;
        } else {
            a_d503 = (uint8_t)a_all32;
            a_hi_d503 = a_all32 >> 8;
            x_d503 = x_ret52;
            y_d503 = y_ret32;
            carry_d503 = carry_ret32;
            zero_d503 = zero_ret32;
            negative_d503 = negative_ret32;
            overflow_d503 = overflow_ret32;
            direct_page_d503 = dp_ret32;
            data_bank_d503 = db_ret30;
            goto shared_D503;
        }
    } else {
        BUS16_SET(c, (db_ret30 << 0x10) + 0x0315, 0);
        if (x_ret51) {
            a_d5033 = (uint8_t)a_all32;
            a_hi_d5033 = a_all32 >> 8;
            x_d5033 = (uint8_t)x_ret52;
            y_d5033 = (uint8_t)y_ret32;
            carry_d5033 = carry_ret32;
            zero_d5033 = zero_ret32;
            negative_d5033 = negative_ret32;
            overflow_d5033 = overflow_ret32;
            direct_page_d5033 = dp_ret32;
            data_bank_d5033 = db_ret30;
            goto shared_D503_2;
        } else {
            a_d5034 = (uint8_t)a_all32;
            a_hi_d5034 = a_all32 >> 8;
            x_d5034 = x_ret52;
            y_d5034 = y_ret32;
            carry_d5034 = carry_ret32;
            zero_d5034 = zero_ret32;
            negative_d5034 = negative_ret32;
            overflow_d5034 = overflow_ret32;
            direct_page_d5034 = dp_ret32;
            data_bank_d5034 = db_ret30;
            goto shared_D503_3;
        }
    }
    shared_D4F5_1:;
    uint8_t value3 = BUS8_RDP(c, (data_bank_d4f52 << 0x10) + 0x0316);
    if (value3 == 0) {
        a_d5032 = value3;
        a_hi_d5032 = a_hi_d4f52;
        x_d5032 = x_d4f52;
        y_d5032 = y_d4f52;
        carry_d5032 = carry_d4f52;
        zero_d5032 = value3 == 0;
        negative_d5032 = value3 & 0x80;
        overflow_d5032 = overflow_d4f52;
        direct_page_d5032 = direct_page_d4f52;
        data_bank_d5032 = data_bank_d4f52;
        goto shared_D503_1;
    }
    uint8_t value4 = BUS8_RDP(c, (data_bank_d4f52 << 0x10) + 0x0315);
    r->a = (a_hi_d4f52 << 8) | value4;
    r->x = x_d4f52;
    r->y = y_d4f52;
    r->c = carry_d4f52;
    r->z = value4 == 0;
    r->n = value4 & 0x80;
    r->v = overflow_d4f52;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_d4f52;
    r->dp = direct_page_d4f52;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4FF, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD4FF); } /* request_task_stop_by_id */
    r->sp += 5;
    uint16_t dp_ret33 = r->dp;
    uint8_t db_ret31 = r->db;
    bool m_ret5 = r->mf;
    bool x_ret53 = r->xf;
    uint16_t a_all33 = r->a;
    uint16_t x_ret54 = r->x;
    uint16_t y_ret33 = r->y;
    bool carry_ret33 = r->c;
    bool zero_ret33 = r->z;
    bool negative_ret33 = r->n;
    bool overflow_ret33 = r->v;
    if (m_ret5) {
        BUS8_SET(c, (db_ret31 << 0x10) + 0x0315, 0);
        if (x_ret53) {
            a_d5032 = (uint8_t)a_all33;
            a_hi_d5032 = a_all33 >> 8;
            x_d5032 = (uint8_t)x_ret54;
            y_d5032 = (uint8_t)y_ret33;
            carry_d5032 = carry_ret33;
            zero_d5032 = zero_ret33;
            negative_d5032 = negative_ret33;
            overflow_d5032 = overflow_ret33;
            direct_page_d5032 = dp_ret33;
            data_bank_d5032 = db_ret31;
            goto shared_D503_1;
        } else {
            a_d503 = (uint8_t)a_all33;
            a_hi_d503 = a_all33 >> 8;
            x_d503 = x_ret54;
            y_d503 = y_ret33;
            carry_d503 = carry_ret33;
            zero_d503 = zero_ret33;
            negative_d503 = negative_ret33;
            overflow_d503 = overflow_ret33;
            direct_page_d503 = dp_ret33;
            data_bank_d503 = db_ret31;
            goto shared_D503;
        }
    } else {
        BUS16_SET(c, (db_ret31 << 0x10) + 0x0315, 0);
        if (x_ret53) {
            a_d5033 = (uint8_t)a_all33;
            a_hi_d5033 = a_all33 >> 8;
            x_d5033 = (uint8_t)x_ret54;
            y_d5033 = (uint8_t)y_ret33;
            carry_d5033 = carry_ret33;
            zero_d5033 = zero_ret33;
            negative_d5033 = negative_ret33;
            overflow_d5033 = overflow_ret33;
            direct_page_d5033 = dp_ret33;
            data_bank_d5033 = db_ret31;
            goto shared_D503_2;
        } else {
            a_d5034 = (uint8_t)a_all33;
            a_hi_d5034 = a_all33 >> 8;
            x_d5034 = x_ret54;
            y_d5034 = y_ret33;
            carry_d5034 = carry_ret33;
            zero_d5034 = zero_ret33;
            negative_d5034 = negative_ret33;
            overflow_d5034 = overflow_ret33;
            direct_page_d5034 = dp_ret33;
            data_bank_d5034 = db_ret31;
            goto shared_D503_3;
        }
    }
    shared_D4CB:;
    RAM8(0x0002 + direct_page_d4cb) = 3;
    a_d4cf = 3;
    a_hi_d4cf = a_hi_d4cb;
    y_d4cf = y_d4cb;
    carry_d4cf = carry_d4cb;
    zero_d4cf = 0;
    negative_d4cf = 0;
    overflow_d4cf = overflow_d4cb;
    direct_page_d4cf = direct_page_d4cb;
    data_bank_d4cf = data_bank_d4cb;
    goto shared_D4CF;
    shared_D4CB_1:;
    RAM8(0x0002 + direct_page_d4cb2) = 3;
    a_d4cf2 = 3;
    a_hi_d4cf2 = a_hi_d4cb2;
    y_d4cf2 = y_d4cb2;
    carry_d4cf2 = carry_d4cb2;
    zero_d4cf2 = 0;
    negative_d4cf2 = 0;
    overflow_d4cf2 = overflow_d4cb2;
    direct_page_d4cf2 = direct_page_d4cb2;
    data_bank_d4cf2 = data_bank_d4cb2;
    goto shared_D4CF_1;
    shared_D503:;
    r->a = (a_hi_d503 << 8) | a_d503;
    r->x = x_d503;
    r->y = y_d503;
    r->c = carry_d503;
    r->z = zero_d503;
    r->n = negative_d503;
    r->v = overflow_d503;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_d503;
    r->dp = direct_page_d503;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD505, 0x7ED1DA); GUARD_JSR(c, sp_call, 0xD505); } /* fade_parent_display_until_control_exit */
    r->sp += 5;
    uint16_t dp_ret34 = r->dp;
    uint8_t db_ret32 = r->db;
    bool m_ret6 = r->mf;
    uint16_t a_all34 = r->a;
    uint16_t x_ret55 = r->x;
    uint16_t y_ret34 = r->y;
    bool carry_ret34 = r->c;
    bool overflow_ret34 = r->v;
    if (m_ret6) {
        a_hi_d506 = a_all34 >> 8;
        x_d506 = x_ret55;
        y_d506 = y_ret34;
        carry_d506 = carry_ret34;
        overflow_d506 = overflow_ret34;
        direct_page_d506 = dp_ret34;
        data_bank_d506 = db_ret32;
        goto shared_D506;
    } else {
        a_hi_d5062 = a_all34 >> 8;
        x_d5062 = x_ret55;
        y_d5062 = y_ret34;
        carry_d5062 = carry_ret34;
        overflow_d5062 = overflow_ret34;
        direct_page_d5062 = dp_ret34;
        data_bank_d5062 = db_ret32;
        goto shared_D506_1;
    }
    shared_D503_1:;
    r->a = (a_hi_d5032 << 8) | a_d5032;
    r->x = x_d5032;
    r->y = y_d5032;
    r->c = carry_d5032;
    r->z = zero_d5032;
    r->n = negative_d5032;
    r->v = overflow_d5032;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_d5032;
    r->dp = direct_page_d5032;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD505, 0x7ED1DA); GUARD_JSR(c, sp_call, 0xD505); } /* fade_parent_display_until_control_exit */
    r->sp += 5;
    uint16_t dp_ret35 = r->dp;
    uint8_t db_ret33 = r->db;
    bool m_ret7 = r->mf;
    uint16_t a_all35 = r->a;
    uint16_t x_ret56 = r->x;
    uint16_t y_ret35 = r->y;
    bool carry_ret35 = r->c;
    bool overflow_ret35 = r->v;
    if (m_ret7) {
        a_hi_d506 = a_all35 >> 8;
        x_d506 = x_ret56;
        y_d506 = y_ret35;
        carry_d506 = carry_ret35;
        overflow_d506 = overflow_ret35;
        direct_page_d506 = dp_ret35;
        data_bank_d506 = db_ret33;
        goto shared_D506;
    } else {
        a_hi_d5062 = a_all35 >> 8;
        x_d5062 = x_ret56;
        y_d5062 = y_ret35;
        carry_d5062 = carry_ret35;
        overflow_d5062 = overflow_ret35;
        direct_page_d5062 = dp_ret35;
        data_bank_d5062 = db_ret33;
        goto shared_D506_1;
    }
    shared_D503_2:;
    r->a = (a_hi_d5033 << 8) | a_d5033;
    r->x = x_d5033;
    r->y = y_d5033;
    r->c = carry_d5033;
    r->z = zero_d5033;
    r->n = negative_d5033;
    r->v = overflow_d5033;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_d5033;
    r->dp = direct_page_d5033;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD505, 0x7ED1DA); GUARD_JSR(c, sp_call, 0xD505); } /* fade_parent_display_until_control_exit */
    r->sp += 5;
    uint16_t dp_ret36 = r->dp;
    uint8_t db_ret34 = r->db;
    bool m_ret8 = r->mf;
    uint16_t a_all36 = r->a;
    uint16_t x_ret57 = r->x;
    uint16_t y_ret36 = r->y;
    bool carry_ret36 = r->c;
    bool overflow_ret36 = r->v;
    if (m_ret8) {
        a_hi_d506 = a_all36 >> 8;
        x_d506 = x_ret57;
        y_d506 = y_ret36;
        carry_d506 = carry_ret36;
        overflow_d506 = overflow_ret36;
        direct_page_d506 = dp_ret36;
        data_bank_d506 = db_ret34;
        goto shared_D506;
    } else {
        a_hi_d5062 = a_all36 >> 8;
        x_d5062 = x_ret57;
        y_d5062 = y_ret36;
        carry_d5062 = carry_ret36;
        overflow_d5062 = overflow_ret36;
        direct_page_d5062 = dp_ret36;
        data_bank_d5062 = db_ret34;
        goto shared_D506_1;
    }
    shared_D503_3:;
    r->a = (a_hi_d5034 << 8) | a_d5034;
    r->x = x_d5034;
    r->y = y_d5034;
    r->c = carry_d5034;
    r->z = zero_d5034;
    r->n = negative_d5034;
    r->v = overflow_d5034;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_d5034;
    r->dp = direct_page_d5034;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD505, 0x7ED1DA); GUARD_JSR(c, sp_call, 0xD505); } /* fade_parent_display_until_control_exit */
    r->sp += 5;
    uint16_t dp_ret37 = r->dp;
    uint8_t db_ret35 = r->db;
    bool m_ret9 = r->mf;
    uint16_t a_all37 = r->a;
    uint16_t x_ret58 = r->x;
    uint16_t y_ret37 = r->y;
    bool carry_ret37 = r->c;
    bool overflow_ret37 = r->v;
    if (m_ret9) {
        a_hi_d506 = a_all37 >> 8;
        x_d506 = x_ret58;
        y_d506 = y_ret37;
        carry_d506 = carry_ret37;
        overflow_d506 = overflow_ret37;
        direct_page_d506 = dp_ret37;
        data_bank_d506 = db_ret35;
        goto shared_D506;
    } else {
        a_hi_d5062 = a_all37 >> 8;
        x_d5062 = x_ret58;
        y_d5062 = y_ret37;
        carry_d5062 = carry_ret37;
        overflow_d5062 = overflow_ret37;
        direct_page_d5062 = dp_ret37;
        data_bank_d5062 = db_ret35;
        goto shared_D506_1;
    }
    shared_D4CF:;
    r->a = (a_hi_d4cf << 8) | a_d4cf;
    r->y = y_d4cf;
    r->c = carry_d4cf;
    r->z = zero_d4cf;
    r->n = negative_d4cf;
    r->v = overflow_d4cf;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_d4cf;
    r->dp = direct_page_d4cf;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4D1, 0x7ED051); GUARD_JSR(c, sp_call, 0xD4D1); } /* spawn_ten_native_title_children_and_track_returned_ids */
    r->sp += 5;
    r->x = 0x012C;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4D7, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4D7); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret39 = r->dp;
    uint8_t db_ret37 = r->db;
    uint16_t a_all39 = r->a;
    uint16_t x_ret60 = r->x;
    uint16_t y_ret39 = r->y;
    bool overflow_ret39 = r->v;
    if ((uint8_t)a_all39 == 0) {
        a_hi_d4f5 = a_all39 >> 8;
        x_d4f5 = x_ret60;
        y_d4f5 = y_ret39;
        carry_d4f5 = (uint8_t)a_all39 >= 0;
        overflow_d4f5 = overflow_ret39;
        direct_page_d4f5 = dp_ret39;
        data_bank_d4f5 = db_ret37;
        goto shared_D4F5;
    }
    RAM8(0x0002 + dp_ret39)--;
    if (RAM8(0x0002 + dp_ret39) != 0) {
        a_d4cf2 = (uint8_t)a_all39;
        a_hi_d4cf2 = a_all39 >> 8;
        y_d4cf2 = y_ret39;
        carry_d4cf2 = (uint8_t)a_all39 >= 0;
        zero_d4cf2 = RAM8(0x0002 + dp_ret39) == 0;
        negative_d4cf2 = RAM8(0x0002 + dp_ret39) & 0x80;
        overflow_d4cf2 = overflow_ret39;
        direct_page_d4cf2 = dp_ret39;
        data_bank_d4cf2 = db_ret37;
        goto shared_D4CF_1;
    }
    r->x = 0x012C;
    r->c = (uint8_t)a_all39 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4E5, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4E5); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret40 = r->dp;
    uint8_t db_ret38 = r->db;
    bool x_ret61 = r->xf;
    uint16_t a_all40 = r->a;
    uint16_t x_ret62 = r->x;
    uint16_t y_ret40 = r->y;
    bool overflow_ret40 = r->v;
    if ((uint8_t)a_all40 == 0) {
        if (x_ret61) {
            a_hi_d4f52 = a_all40 >> 8;
            x_d4f52 = (uint8_t)x_ret62;
            y_d4f52 = (uint8_t)y_ret40;
            carry_d4f52 = (uint8_t)a_all40 >= 0;
            overflow_d4f52 = overflow_ret40;
            direct_page_d4f52 = dp_ret40;
            data_bank_d4f52 = db_ret38;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all40 >> 8;
            x_d4f5 = x_ret62;
            y_d4f5 = y_ret40;
            carry_d4f5 = (uint8_t)a_all40 >= 0;
            overflow_d4f5 = overflow_ret40;
            direct_page_d4f5 = dp_ret40;
            data_bank_d4f5 = db_ret38;
            goto shared_D4F5;
        }
    }
    RAM8(0x0001 + dp_ret40)--;
    if (RAM8(0x0001 + dp_ret40) != 0) {
        if (x_ret61) {
            a_hi_d4cb = a_all40 >> 8;
            y_d4cb = (uint8_t)y_ret40;
            carry_d4cb = (uint8_t)a_all40 >= 0;
            overflow_d4cb = overflow_ret40;
            direct_page_d4cb = dp_ret40;
            data_bank_d4cb = db_ret38;
            goto shared_D4CB;
        } else {
            a_hi_d4cb2 = a_all40 >> 8;
            y_d4cb2 = y_ret40;
            carry_d4cb2 = (uint8_t)a_all40 >= 0;
            overflow_d4cb2 = overflow_ret40;
            direct_page_d4cb2 = dp_ret40;
            data_bank_d4cb2 = db_ret38;
            goto shared_D4CB_1;
        }
    }
    uint8_t value5 = RAM8(0x0001 + dp_ret40);
    r->c = (uint8_t)a_all40 >= 0;
    r->z = value5 == 0;
    r->n = value5 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4F0, 0x7ED40D); GUARD_JSR(c, sp_call, 0xD4F0); } /* fade_notify_image_and_teardown_before_title_repeat */
    r->sp += 5;
    uint16_t dp_ret41 = r->dp;
    uint8_t db_ret39 = r->db;
    bool x_ret63 = r->xf;
    uint16_t a_all41 = r->a;
    uint16_t x_ret64 = r->x;
    uint16_t y_ret41 = r->y;
    bool overflow_ret41 = r->v;
    if ((uint8_t)a_all41 != 0) {
        if (x_ret63) {
            a_d48d = (uint8_t)a_all41;
            a_hi_d48d = a_all41 >> 8;
            x_d48d = (uint8_t)x_ret64;
            y_d48d = (uint8_t)y_ret41;
            carry_d48d = (uint8_t)a_all41 >= 0;
            zero_d48d = (uint8_t)a_all41 == 0;
            negative_d48d = (uint8_t)a_all41 & 0x80;
            overflow_d48d = overflow_ret41;
            direct_page_d48d = dp_ret41;
            data_bank_d48d = db_ret39;
            goto shared_D48D;
        } else {
            a_d48d2 = (uint8_t)a_all41;
            a_hi_d48d2 = a_all41 >> 8;
            x_d48d2 = x_ret64;
            y_d48d2 = y_ret41;
            carry_d48d2 = (uint8_t)a_all41 >= 0;
            zero_d48d2 = (uint8_t)a_all41 == 0;
            negative_d48d2 = (uint8_t)a_all41 & 0x80;
            overflow_d48d2 = overflow_ret41;
            direct_page_d48d2 = dp_ret41;
            data_bank_d48d2 = db_ret39;
            goto shared_D48D_1;
        }
    }
    if (x_ret63) {
        a_hi_d4f52 = a_all41 >> 8;
        x_d4f52 = (uint8_t)x_ret64;
        y_d4f52 = (uint8_t)y_ret41;
        carry_d4f52 = (uint8_t)a_all41 >= 0;
        overflow_d4f52 = overflow_ret41;
        direct_page_d4f52 = dp_ret41;
        data_bank_d4f52 = db_ret39;
        goto shared_D4F5_1;
    } else {
        a_hi_d4f5 = a_all41 >> 8;
        x_d4f5 = x_ret64;
        y_d4f5 = y_ret41;
        carry_d4f5 = (uint8_t)a_all41 >= 0;
        overflow_d4f5 = overflow_ret41;
        direct_page_d4f5 = dp_ret41;
        data_bank_d4f5 = db_ret39;
        goto shared_D4F5;
    }
    shared_D4CF_1:;
    r->a = (a_hi_d4cf2 << 8) | a_d4cf2;
    r->y = y_d4cf2;
    r->c = carry_d4cf2;
    r->z = zero_d4cf2;
    r->n = negative_d4cf2;
    r->v = overflow_d4cf2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_d4cf2;
    r->dp = direct_page_d4cf2;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4D1, 0x7ED051); GUARD_JSR(c, sp_call, 0xD4D1); } /* spawn_ten_native_title_children_and_track_returned_ids */
    r->sp += 5;
    r->x = 0x012C;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4D7, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4D7); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret43 = r->dp;
    uint8_t db_ret41 = r->db;
    uint16_t a_all43 = r->a;
    uint16_t x_ret66 = r->x;
    uint16_t y_ret43 = r->y;
    bool overflow_ret43 = r->v;
    if ((uint8_t)a_all43 == 0) {
        a_hi_d4f5 = a_all43 >> 8;
        x_d4f5 = x_ret66;
        y_d4f5 = y_ret43;
        carry_d4f5 = (uint8_t)a_all43 >= 0;
        overflow_d4f5 = overflow_ret43;
        direct_page_d4f5 = dp_ret43;
        data_bank_d4f5 = db_ret41;
        goto shared_D4F5;
    }
    RAM8(0x0002 + dp_ret43)--;
    if (RAM8(0x0002 + dp_ret43) != 0) {
        a_d4cf2 = (uint8_t)a_all43;
        a_hi_d4cf2 = a_all43 >> 8;
        y_d4cf2 = y_ret43;
        carry_d4cf2 = (uint8_t)a_all43 >= 0;
        zero_d4cf2 = RAM8(0x0002 + dp_ret43) == 0;
        negative_d4cf2 = RAM8(0x0002 + dp_ret43) & 0x80;
        overflow_d4cf2 = overflow_ret43;
        direct_page_d4cf2 = dp_ret43;
        data_bank_d4cf2 = db_ret41;
        goto shared_D4CF_1;
    }
    r->x = 0x012C;
    r->c = (uint8_t)a_all43 >= 0;
    r->z = 0;
    r->n = 0;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4E5, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD4E5); } /* dispatch_parent_messages */
    r->sp += 5;
    uint16_t dp_ret44 = r->dp;
    uint8_t db_ret42 = r->db;
    bool x_ret67 = r->xf;
    uint16_t a_all44 = r->a;
    uint16_t x_ret68 = r->x;
    uint16_t y_ret44 = r->y;
    bool overflow_ret44 = r->v;
    if ((uint8_t)a_all44 == 0) {
        if (x_ret67) {
            a_hi_d4f52 = a_all44 >> 8;
            x_d4f52 = (uint8_t)x_ret68;
            y_d4f52 = (uint8_t)y_ret44;
            carry_d4f52 = (uint8_t)a_all44 >= 0;
            overflow_d4f52 = overflow_ret44;
            direct_page_d4f52 = dp_ret44;
            data_bank_d4f52 = db_ret42;
            goto shared_D4F5_1;
        } else {
            a_hi_d4f5 = a_all44 >> 8;
            x_d4f5 = x_ret68;
            y_d4f5 = y_ret44;
            carry_d4f5 = (uint8_t)a_all44 >= 0;
            overflow_d4f5 = overflow_ret44;
            direct_page_d4f5 = dp_ret44;
            data_bank_d4f5 = db_ret42;
            goto shared_D4F5;
        }
    }
    RAM8(0x0001 + dp_ret44)--;
    if (RAM8(0x0001 + dp_ret44) != 0) {
        if (x_ret67) {
            a_hi_d4cb = a_all44 >> 8;
            y_d4cb = (uint8_t)y_ret44;
            carry_d4cb = (uint8_t)a_all44 >= 0;
            overflow_d4cb = overflow_ret44;
            direct_page_d4cb = dp_ret44;
            data_bank_d4cb = db_ret42;
            goto shared_D4CB;
        } else {
            a_hi_d4cb2 = a_all44 >> 8;
            y_d4cb2 = y_ret44;
            carry_d4cb2 = (uint8_t)a_all44 >= 0;
            overflow_d4cb2 = overflow_ret44;
            direct_page_d4cb2 = dp_ret44;
            data_bank_d4cb2 = db_ret42;
            goto shared_D4CB_1;
        }
    }
    uint8_t value6 = RAM8(0x0001 + dp_ret44);
    r->c = (uint8_t)a_all44 >= 0;
    r->z = value6 == 0;
    r->n = value6 & 0x80;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD4F0, 0x7ED40D); GUARD_JSR(c, sp_call, 0xD4F0); } /* fade_notify_image_and_teardown_before_title_repeat */
    r->sp += 5;
    uint16_t dp_ret45 = r->dp;
    uint8_t db_ret43 = r->db;
    bool x_ret69 = r->xf;
    uint16_t a_all45 = r->a;
    uint16_t x_ret70 = r->x;
    uint16_t y_ret45 = r->y;
    bool overflow_ret45 = r->v;
    if ((uint8_t)a_all45 != 0) {
        if (x_ret69) {
            a_d48d = (uint8_t)a_all45;
            a_hi_d48d = a_all45 >> 8;
            x_d48d = (uint8_t)x_ret70;
            y_d48d = (uint8_t)y_ret45;
            carry_d48d = (uint8_t)a_all45 >= 0;
            zero_d48d = (uint8_t)a_all45 == 0;
            negative_d48d = (uint8_t)a_all45 & 0x80;
            overflow_d48d = overflow_ret45;
            direct_page_d48d = dp_ret45;
            data_bank_d48d = db_ret43;
            goto shared_D48D;
        } else {
            a_d48d2 = (uint8_t)a_all45;
            a_hi_d48d2 = a_all45 >> 8;
            x_d48d2 = x_ret70;
            y_d48d2 = y_ret45;
            carry_d48d2 = (uint8_t)a_all45 >= 0;
            zero_d48d2 = (uint8_t)a_all45 == 0;
            negative_d48d2 = (uint8_t)a_all45 & 0x80;
            overflow_d48d2 = overflow_ret45;
            direct_page_d48d2 = dp_ret45;
            data_bank_d48d2 = db_ret43;
            goto shared_D48D_1;
        }
    }
    if (x_ret69) {
        a_hi_d4f52 = a_all45 >> 8;
        x_d4f52 = (uint8_t)x_ret70;
        y_d4f52 = (uint8_t)y_ret45;
        carry_d4f52 = (uint8_t)a_all45 >= 0;
        overflow_d4f52 = overflow_ret45;
        direct_page_d4f52 = dp_ret45;
        data_bank_d4f52 = db_ret43;
        goto shared_D4F5_1;
    } else {
        a_hi_d4f5 = a_all45 >> 8;
        x_d4f5 = x_ret70;
        y_d4f5 = y_ret45;
        carry_d4f5 = (uint8_t)a_all45 >= 0;
        overflow_d4f5 = overflow_ret45;
        direct_page_d4f5 = dp_ret45;
        data_bank_d4f5 = db_ret43;
        goto shared_D4F5;
    }
    shared_D506:;
    uint8_t value7 = BUS8_RDP(c, (data_bank_d506 << 0x10) + 0x0316);
    if (value7 == 0) {
        r->a = (a_hi_d506 << 8) | value7;
        r->x = 1;
        r->y = y_d506;
        r->c = carry_d506;
        r->z = 0;
        r->n = 0;
        r->v = overflow_d506;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_d506;
        r->dp = direct_page_d506;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD510, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD510); } /* dispatch_parent_messages */
        r->sp += 5;
        uint16_t dp_ret46 = r->dp;
        uint8_t db_ret44 = r->db;
        bool m_ret12 = r->mf;
        bool x_ret71 = r->xf;
        uint16_t a_all46 = r->a;
        uint16_t x_ret72 = r->x;
        uint16_t y_ret46 = r->y;
        bool carry_ret46 = r->c;
        bool overflow_ret46 = r->v;
        if (m_ret12) {
            if (x_ret71) {
                a_hi_d5063 = a_all46 >> 8;
                x_d5063 = (uint8_t)x_ret72;
                y_d5063 = (uint8_t)y_ret46;
                carry_d5063 = carry_ret46;
                overflow_d5063 = overflow_ret46;
                direct_page_d5063 = dp_ret46;
                data_bank_d5063 = db_ret44;
                goto shared_D506_2;
            } else {
                a_hi_d506 = a_all46 >> 8;
                x_d506 = x_ret72;
                y_d506 = y_ret46;
                carry_d506 = carry_ret46;
                overflow_d506 = overflow_ret46;
                direct_page_d506 = dp_ret46;
                data_bank_d506 = db_ret44;
                goto shared_D506;
            }
        } else {
            if (x_ret71) {
                a_hi_d5064 = a_all46 >> 8;
                x_d5064 = (uint8_t)x_ret72;
                y_d5064 = (uint8_t)y_ret46;
                carry_d5064 = carry_ret46;
                overflow_d5064 = overflow_ret46;
                direct_page_d5064 = dp_ret46;
                data_bank_d5064 = db_ret44;
                goto shared_D506_3;
            } else {
                a_hi_d5062 = a_all46 >> 8;
                x_d5062 = x_ret72;
                y_d5062 = y_ret46;
                carry_d5062 = carry_ret46;
                overflow_d5062 = overflow_ret46;
                direct_page_d5062 = dp_ret46;
                data_bank_d5062 = db_ret44;
                goto shared_D506_1;
            }
        }
    }
    uint8_t value8 = BUS8_RDP(c, (data_bank_d506 << 0x10) + 0x0315);
    r->a = (a_hi_d506 << 8) | value8;
    r->x = x_d506;
    r->y = y_d506;
    r->c = carry_d506;
    r->z = value8 == 0;
    r->n = value8 & 0x80;
    r->v = overflow_d506;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_d506;
    r->dp = direct_page_d506;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD518, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD518); } /* request_task_stop_by_id */
    r->sp += 5;
    uint16_t dp_ret47 = r->dp;
    uint8_t db_ret45 = r->db;
    bool m_ret13 = r->mf;
    bool x_ret73 = r->xf;
    uint16_t a_all47 = r->a;
    uint16_t y_ret47 = r->y;
    bool carry_ret47 = r->c;
    bool overflow_ret47 = r->v;
    if (m_ret13) {
        uint8_t value9 = BUS8_RDP(c, (db_ret45 << 0x10) + 0x0311);
        if (value9 == 0) {
            if (x_ret73) {
                y_d527 = (uint8_t)y_ret47;
                carry_d527 = carry_ret47;
                zero_d527 = value9 == 0;
                negative_d527 = value9 & 0x80;
                overflow_d527 = overflow_ret47;
                direct_page_d527 = dp_ret47;
                data_bank_d527 = db_ret45;
                goto shared_D527;
            } else {
                y_d5272 = y_ret47;
                carry_d5272 = carry_ret47;
                zero_d5272 = value9 == 0;
                negative_d5272 = value9 & 0x80;
                overflow_d5272 = overflow_ret47;
                direct_page_d5272 = dp_ret47;
                data_bank_d5272 = db_ret45;
                goto shared_D527_1;
            }
        }
        r->a = (a_all47 >> 8 << 8) | value9;
        r->z = value9 == 0;
        r->n = value9 & 0x80;
        r->mf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD520, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD520); } /* request_task_stop_by_id */
        r->sp += 5;
        uint8_t db_ret46 = r->db;
        bool m_ret14 = r->mf;
        uint16_t a_all48 = r->a;
        if (m_ret14) {
            uint8_t value10 = BUS8_RDP(c, (db_ret46 << 0x10) + 0x0312);
            r->a = (a_all48 >> 8 << 8) | value10;
            r->z = value10 == 0;
            r->n = value10 & 0x80;
            r->mf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret49 = r->dp;
            uint8_t db_ret47 = r->db;
            bool m_ret15 = r->mf;
            bool x_ret77 = r->xf;
            uint16_t y_ret49 = r->y;
            bool carry_ret49 = r->c;
            bool zero_ret49 = r->z;
            bool negative_ret49 = r->n;
            bool overflow_ret49 = r->v;
            if (m_ret15) {
                if (x_ret77) {
                    y_d527 = (uint8_t)y_ret49;
                    carry_d527 = carry_ret49;
                    zero_d527 = zero_ret49;
                    negative_d527 = negative_ret49;
                    overflow_d527 = overflow_ret49;
                    direct_page_d527 = dp_ret49;
                    data_bank_d527 = db_ret47;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret49;
                    carry_d5272 = carry_ret49;
                    zero_d5272 = zero_ret49;
                    negative_d5272 = negative_ret49;
                    overflow_d5272 = overflow_ret49;
                    direct_page_d5272 = dp_ret49;
                    data_bank_d5272 = db_ret47;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret77) {
                    y_d5273 = (uint8_t)y_ret49;
                    carry_d5273 = carry_ret49;
                    zero_d5273 = zero_ret49;
                    negative_d5273 = negative_ret49;
                    overflow_d5273 = overflow_ret49;
                    direct_page_d5273 = dp_ret49;
                    data_bank_d5273 = db_ret47;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret49;
                    carry_d5274 = carry_ret49;
                    zero_d5274 = zero_ret49;
                    negative_d5274 = negative_ret49;
                    overflow_d5274 = overflow_ret49;
                    direct_page_d5274 = dp_ret49;
                    data_bank_d5274 = db_ret47;
                    goto shared_D527_3;
                }
            }
        } else {
            uint16_t value11 = BUS16_RDP(c, (db_ret46 << 0x10) + 0x0312);
            r->a = value11;
            r->z = value11 == 0;
            r->n = value11 & 0x8000;
            r->mf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret50 = r->dp;
            uint8_t db_ret48 = r->db;
            bool m_ret16 = r->mf;
            bool x_ret79 = r->xf;
            uint16_t y_ret50 = r->y;
            bool carry_ret50 = r->c;
            bool zero_ret50 = r->z;
            bool negative_ret50 = r->n;
            bool overflow_ret50 = r->v;
            if (m_ret16) {
                if (x_ret79) {
                    y_d527 = (uint8_t)y_ret50;
                    carry_d527 = carry_ret50;
                    zero_d527 = zero_ret50;
                    negative_d527 = negative_ret50;
                    overflow_d527 = overflow_ret50;
                    direct_page_d527 = dp_ret50;
                    data_bank_d527 = db_ret48;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret50;
                    carry_d5272 = carry_ret50;
                    zero_d5272 = zero_ret50;
                    negative_d5272 = negative_ret50;
                    overflow_d5272 = overflow_ret50;
                    direct_page_d5272 = dp_ret50;
                    data_bank_d5272 = db_ret48;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret79) {
                    y_d5273 = (uint8_t)y_ret50;
                    carry_d5273 = carry_ret50;
                    zero_d5273 = zero_ret50;
                    negative_d5273 = negative_ret50;
                    overflow_d5273 = overflow_ret50;
                    direct_page_d5273 = dp_ret50;
                    data_bank_d5273 = db_ret48;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret50;
                    carry_d5274 = carry_ret50;
                    zero_d5274 = zero_ret50;
                    negative_d5274 = negative_ret50;
                    overflow_d5274 = overflow_ret50;
                    direct_page_d5274 = dp_ret50;
                    data_bank_d5274 = db_ret48;
                    goto shared_D527_3;
                }
            }
        }
    } else {
        uint16_t value12 = BUS16_RDP(c, (db_ret45 << 0x10) + 0x0311);
        if (value12 == 0) {
            if (x_ret73) {
                y_d5273 = (uint8_t)y_ret47;
                carry_d5273 = carry_ret47;
                zero_d5273 = value12 == 0;
                negative_d5273 = value12 & 0x8000;
                overflow_d5273 = overflow_ret47;
                direct_page_d5273 = dp_ret47;
                data_bank_d5273 = db_ret45;
                goto shared_D527_2;
            } else {
                y_d5274 = y_ret47;
                carry_d5274 = carry_ret47;
                zero_d5274 = value12 == 0;
                negative_d5274 = value12 & 0x8000;
                overflow_d5274 = overflow_ret47;
                direct_page_d5274 = dp_ret47;
                data_bank_d5274 = db_ret45;
                goto shared_D527_3;
            }
        }
        r->a = value12;
        r->z = value12 == 0;
        r->n = value12 & 0x8000;
        r->mf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD520, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD520); } /* request_task_stop_by_id */
        r->sp += 5;
        uint8_t db_ret49 = r->db;
        bool m_ret17 = r->mf;
        uint16_t a_all51 = r->a;
        if (m_ret17) {
            uint8_t value13 = BUS8_RDP(c, (db_ret49 << 0x10) + 0x0312);
            r->a = (a_all51 >> 8 << 8) | value13;
            r->z = value13 == 0;
            r->n = value13 & 0x80;
            r->mf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret52 = r->dp;
            uint8_t db_ret50 = r->db;
            bool m_ret18 = r->mf;
            bool x_ret83 = r->xf;
            uint16_t y_ret52 = r->y;
            bool carry_ret52 = r->c;
            bool zero_ret52 = r->z;
            bool negative_ret52 = r->n;
            bool overflow_ret52 = r->v;
            if (m_ret18) {
                if (x_ret83) {
                    y_d527 = (uint8_t)y_ret52;
                    carry_d527 = carry_ret52;
                    zero_d527 = zero_ret52;
                    negative_d527 = negative_ret52;
                    overflow_d527 = overflow_ret52;
                    direct_page_d527 = dp_ret52;
                    data_bank_d527 = db_ret50;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret52;
                    carry_d5272 = carry_ret52;
                    zero_d5272 = zero_ret52;
                    negative_d5272 = negative_ret52;
                    overflow_d5272 = overflow_ret52;
                    direct_page_d5272 = dp_ret52;
                    data_bank_d5272 = db_ret50;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret83) {
                    y_d5273 = (uint8_t)y_ret52;
                    carry_d5273 = carry_ret52;
                    zero_d5273 = zero_ret52;
                    negative_d5273 = negative_ret52;
                    overflow_d5273 = overflow_ret52;
                    direct_page_d5273 = dp_ret52;
                    data_bank_d5273 = db_ret50;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret52;
                    carry_d5274 = carry_ret52;
                    zero_d5274 = zero_ret52;
                    negative_d5274 = negative_ret52;
                    overflow_d5274 = overflow_ret52;
                    direct_page_d5274 = dp_ret52;
                    data_bank_d5274 = db_ret50;
                    goto shared_D527_3;
                }
            }
        } else {
            uint16_t value14 = BUS16_RDP(c, (db_ret49 << 0x10) + 0x0312);
            r->a = value14;
            r->z = value14 == 0;
            r->n = value14 & 0x8000;
            r->mf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret53 = r->dp;
            uint8_t db_ret51 = r->db;
            bool m_ret19 = r->mf;
            bool x_ret85 = r->xf;
            uint16_t y_ret53 = r->y;
            bool carry_ret53 = r->c;
            bool zero_ret53 = r->z;
            bool negative_ret53 = r->n;
            bool overflow_ret53 = r->v;
            if (m_ret19) {
                if (x_ret85) {
                    y_d527 = (uint8_t)y_ret53;
                    carry_d527 = carry_ret53;
                    zero_d527 = zero_ret53;
                    negative_d527 = negative_ret53;
                    overflow_d527 = overflow_ret53;
                    direct_page_d527 = dp_ret53;
                    data_bank_d527 = db_ret51;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret53;
                    carry_d5272 = carry_ret53;
                    zero_d5272 = zero_ret53;
                    negative_d5272 = negative_ret53;
                    overflow_d5272 = overflow_ret53;
                    direct_page_d5272 = dp_ret53;
                    data_bank_d5272 = db_ret51;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret85) {
                    y_d5273 = (uint8_t)y_ret53;
                    carry_d5273 = carry_ret53;
                    zero_d5273 = zero_ret53;
                    negative_d5273 = negative_ret53;
                    overflow_d5273 = overflow_ret53;
                    direct_page_d5273 = dp_ret53;
                    data_bank_d5273 = db_ret51;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret53;
                    carry_d5274 = carry_ret53;
                    zero_d5274 = zero_ret53;
                    negative_d5274 = negative_ret53;
                    overflow_d5274 = overflow_ret53;
                    direct_page_d5274 = dp_ret53;
                    data_bank_d5274 = db_ret51;
                    goto shared_D527_3;
                }
            }
        }
    }
    shared_D506_1:;
    uint16_t value15 = BUS16_RDP(c, (data_bank_d5062 << 0x10) + 0x0316);
    if (value15 == 0) {
        r->a = value15;
        r->x = 1;
        r->y = y_d5062;
        r->c = carry_d5062;
        r->z = 0;
        r->n = 0;
        r->v = overflow_d5062;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank_d5062;
        r->dp = direct_page_d5062;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD510, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD510); } /* dispatch_parent_messages */
        r->sp += 5;
        uint16_t dp_ret54 = r->dp;
        uint8_t db_ret52 = r->db;
        bool m_ret20 = r->mf;
        bool x_ret87 = r->xf;
        uint16_t a_all54 = r->a;
        uint16_t x_ret88 = r->x;
        uint16_t y_ret54 = r->y;
        bool carry_ret54 = r->c;
        bool overflow_ret54 = r->v;
        if (m_ret20) {
            if (x_ret87) {
                a_hi_d5063 = a_all54 >> 8;
                x_d5063 = (uint8_t)x_ret88;
                y_d5063 = (uint8_t)y_ret54;
                carry_d5063 = carry_ret54;
                overflow_d5063 = overflow_ret54;
                direct_page_d5063 = dp_ret54;
                data_bank_d5063 = db_ret52;
                goto shared_D506_2;
            } else {
                a_hi_d506 = a_all54 >> 8;
                x_d506 = x_ret88;
                y_d506 = y_ret54;
                carry_d506 = carry_ret54;
                overflow_d506 = overflow_ret54;
                direct_page_d506 = dp_ret54;
                data_bank_d506 = db_ret52;
                goto shared_D506;
            }
        } else {
            if (x_ret87) {
                a_hi_d5064 = a_all54 >> 8;
                x_d5064 = (uint8_t)x_ret88;
                y_d5064 = (uint8_t)y_ret54;
                carry_d5064 = carry_ret54;
                overflow_d5064 = overflow_ret54;
                direct_page_d5064 = dp_ret54;
                data_bank_d5064 = db_ret52;
                goto shared_D506_3;
            } else {
                a_hi_d5062 = a_all54 >> 8;
                x_d5062 = x_ret88;
                y_d5062 = y_ret54;
                carry_d5062 = carry_ret54;
                overflow_d5062 = overflow_ret54;
                direct_page_d5062 = dp_ret54;
                data_bank_d5062 = db_ret52;
                goto shared_D506_1;
            }
        }
    }
    uint16_t value16 = BUS16_RDP(c, (data_bank_d5062 << 0x10) + 0x0315);
    r->a = value16;
    r->x = x_d5062;
    r->y = y_d5062;
    r->c = carry_d5062;
    r->z = value16 == 0;
    r->n = value16 & 0x8000;
    r->v = overflow_d5062;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_d5062;
    r->dp = direct_page_d5062;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD518, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD518); } /* request_task_stop_by_id */
    r->sp += 5;
    uint16_t dp_ret55 = r->dp;
    uint8_t db_ret53 = r->db;
    bool m_ret21 = r->mf;
    bool x_ret89 = r->xf;
    uint16_t a_all55 = r->a;
    uint16_t y_ret55 = r->y;
    bool carry_ret55 = r->c;
    bool overflow_ret55 = r->v;
    if (m_ret21) {
        uint8_t value17 = BUS8_RDP(c, (db_ret53 << 0x10) + 0x0311);
        if (value17 == 0) {
            if (x_ret89) {
                y_d527 = (uint8_t)y_ret55;
                carry_d527 = carry_ret55;
                zero_d527 = value17 == 0;
                negative_d527 = value17 & 0x80;
                overflow_d527 = overflow_ret55;
                direct_page_d527 = dp_ret55;
                data_bank_d527 = db_ret53;
                goto shared_D527;
            } else {
                y_d5272 = y_ret55;
                carry_d5272 = carry_ret55;
                zero_d5272 = value17 == 0;
                negative_d5272 = value17 & 0x80;
                overflow_d5272 = overflow_ret55;
                direct_page_d5272 = dp_ret55;
                data_bank_d5272 = db_ret53;
                goto shared_D527_1;
            }
        }
        r->a = (a_all55 >> 8 << 8) | value17;
        r->z = value17 == 0;
        r->n = value17 & 0x80;
        r->mf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD520, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD520); } /* request_task_stop_by_id */
        r->sp += 5;
        uint8_t db_ret54 = r->db;
        bool m_ret22 = r->mf;
        uint16_t a_all56 = r->a;
        if (m_ret22) {
            uint8_t value18 = BUS8_RDP(c, (db_ret54 << 0x10) + 0x0312);
            r->a = (a_all56 >> 8 << 8) | value18;
            r->z = value18 == 0;
            r->n = value18 & 0x80;
            r->mf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret57 = r->dp;
            uint8_t db_ret55 = r->db;
            bool m_ret23 = r->mf;
            bool x_ret93 = r->xf;
            uint16_t y_ret57 = r->y;
            bool carry_ret57 = r->c;
            bool zero_ret57 = r->z;
            bool negative_ret57 = r->n;
            bool overflow_ret57 = r->v;
            if (m_ret23) {
                if (x_ret93) {
                    y_d527 = (uint8_t)y_ret57;
                    carry_d527 = carry_ret57;
                    zero_d527 = zero_ret57;
                    negative_d527 = negative_ret57;
                    overflow_d527 = overflow_ret57;
                    direct_page_d527 = dp_ret57;
                    data_bank_d527 = db_ret55;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret57;
                    carry_d5272 = carry_ret57;
                    zero_d5272 = zero_ret57;
                    negative_d5272 = negative_ret57;
                    overflow_d5272 = overflow_ret57;
                    direct_page_d5272 = dp_ret57;
                    data_bank_d5272 = db_ret55;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret93) {
                    y_d5273 = (uint8_t)y_ret57;
                    carry_d5273 = carry_ret57;
                    zero_d5273 = zero_ret57;
                    negative_d5273 = negative_ret57;
                    overflow_d5273 = overflow_ret57;
                    direct_page_d5273 = dp_ret57;
                    data_bank_d5273 = db_ret55;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret57;
                    carry_d5274 = carry_ret57;
                    zero_d5274 = zero_ret57;
                    negative_d5274 = negative_ret57;
                    overflow_d5274 = overflow_ret57;
                    direct_page_d5274 = dp_ret57;
                    data_bank_d5274 = db_ret55;
                    goto shared_D527_3;
                }
            }
        } else {
            uint16_t value19 = BUS16_RDP(c, (db_ret54 << 0x10) + 0x0312);
            r->a = value19;
            r->z = value19 == 0;
            r->n = value19 & 0x8000;
            r->mf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret58 = r->dp;
            uint8_t db_ret56 = r->db;
            bool m_ret24 = r->mf;
            bool x_ret95 = r->xf;
            uint16_t y_ret58 = r->y;
            bool carry_ret58 = r->c;
            bool zero_ret58 = r->z;
            bool negative_ret58 = r->n;
            bool overflow_ret58 = r->v;
            if (m_ret24) {
                if (x_ret95) {
                    y_d527 = (uint8_t)y_ret58;
                    carry_d527 = carry_ret58;
                    zero_d527 = zero_ret58;
                    negative_d527 = negative_ret58;
                    overflow_d527 = overflow_ret58;
                    direct_page_d527 = dp_ret58;
                    data_bank_d527 = db_ret56;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret58;
                    carry_d5272 = carry_ret58;
                    zero_d5272 = zero_ret58;
                    negative_d5272 = negative_ret58;
                    overflow_d5272 = overflow_ret58;
                    direct_page_d5272 = dp_ret58;
                    data_bank_d5272 = db_ret56;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret95) {
                    y_d5273 = (uint8_t)y_ret58;
                    carry_d5273 = carry_ret58;
                    zero_d5273 = zero_ret58;
                    negative_d5273 = negative_ret58;
                    overflow_d5273 = overflow_ret58;
                    direct_page_d5273 = dp_ret58;
                    data_bank_d5273 = db_ret56;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret58;
                    carry_d5274 = carry_ret58;
                    zero_d5274 = zero_ret58;
                    negative_d5274 = negative_ret58;
                    overflow_d5274 = overflow_ret58;
                    direct_page_d5274 = dp_ret58;
                    data_bank_d5274 = db_ret56;
                    goto shared_D527_3;
                }
            }
        }
    } else {
        uint16_t value20 = BUS16_RDP(c, (db_ret53 << 0x10) + 0x0311);
        if (value20 == 0) {
            if (x_ret89) {
                y_d5273 = (uint8_t)y_ret55;
                carry_d5273 = carry_ret55;
                zero_d5273 = value20 == 0;
                negative_d5273 = value20 & 0x8000;
                overflow_d5273 = overflow_ret55;
                direct_page_d5273 = dp_ret55;
                data_bank_d5273 = db_ret53;
                goto shared_D527_2;
            } else {
                y_d5274 = y_ret55;
                carry_d5274 = carry_ret55;
                zero_d5274 = value20 == 0;
                negative_d5274 = value20 & 0x8000;
                overflow_d5274 = overflow_ret55;
                direct_page_d5274 = dp_ret55;
                data_bank_d5274 = db_ret53;
                goto shared_D527_3;
            }
        }
        r->a = value20;
        r->z = value20 == 0;
        r->n = value20 & 0x8000;
        r->mf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD520, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD520); } /* request_task_stop_by_id */
        r->sp += 5;
        uint8_t db_ret57 = r->db;
        bool m_ret25 = r->mf;
        uint16_t a_all59 = r->a;
        if (m_ret25) {
            uint8_t value21 = BUS8_RDP(c, (db_ret57 << 0x10) + 0x0312);
            r->a = (a_all59 >> 8 << 8) | value21;
            r->z = value21 == 0;
            r->n = value21 & 0x80;
            r->mf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret60 = r->dp;
            uint8_t db_ret58 = r->db;
            bool m_ret26 = r->mf;
            bool x_ret99 = r->xf;
            uint16_t y_ret60 = r->y;
            bool carry_ret60 = r->c;
            bool zero_ret60 = r->z;
            bool negative_ret60 = r->n;
            bool overflow_ret60 = r->v;
            if (m_ret26) {
                if (x_ret99) {
                    y_d527 = (uint8_t)y_ret60;
                    carry_d527 = carry_ret60;
                    zero_d527 = zero_ret60;
                    negative_d527 = negative_ret60;
                    overflow_d527 = overflow_ret60;
                    direct_page_d527 = dp_ret60;
                    data_bank_d527 = db_ret58;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret60;
                    carry_d5272 = carry_ret60;
                    zero_d5272 = zero_ret60;
                    negative_d5272 = negative_ret60;
                    overflow_d5272 = overflow_ret60;
                    direct_page_d5272 = dp_ret60;
                    data_bank_d5272 = db_ret58;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret99) {
                    y_d5273 = (uint8_t)y_ret60;
                    carry_d5273 = carry_ret60;
                    zero_d5273 = zero_ret60;
                    negative_d5273 = negative_ret60;
                    overflow_d5273 = overflow_ret60;
                    direct_page_d5273 = dp_ret60;
                    data_bank_d5273 = db_ret58;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret60;
                    carry_d5274 = carry_ret60;
                    zero_d5274 = zero_ret60;
                    negative_d5274 = negative_ret60;
                    overflow_d5274 = overflow_ret60;
                    direct_page_d5274 = dp_ret60;
                    data_bank_d5274 = db_ret58;
                    goto shared_D527_3;
                }
            }
        } else {
            uint16_t value22 = BUS16_RDP(c, (db_ret57 << 0x10) + 0x0312);
            r->a = value22;
            r->z = value22 == 0;
            r->n = value22 & 0x8000;
            r->mf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret61 = r->dp;
            uint8_t db_ret59 = r->db;
            bool m_ret27 = r->mf;
            bool x_ret101 = r->xf;
            uint16_t y_ret61 = r->y;
            bool carry_ret61 = r->c;
            bool zero_ret61 = r->z;
            bool negative_ret61 = r->n;
            bool overflow_ret61 = r->v;
            if (m_ret27) {
                if (x_ret101) {
                    y_d527 = (uint8_t)y_ret61;
                    carry_d527 = carry_ret61;
                    zero_d527 = zero_ret61;
                    negative_d527 = negative_ret61;
                    overflow_d527 = overflow_ret61;
                    direct_page_d527 = dp_ret61;
                    data_bank_d527 = db_ret59;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret61;
                    carry_d5272 = carry_ret61;
                    zero_d5272 = zero_ret61;
                    negative_d5272 = negative_ret61;
                    overflow_d5272 = overflow_ret61;
                    direct_page_d5272 = dp_ret61;
                    data_bank_d5272 = db_ret59;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret101) {
                    y_d5273 = (uint8_t)y_ret61;
                    carry_d5273 = carry_ret61;
                    zero_d5273 = zero_ret61;
                    negative_d5273 = negative_ret61;
                    overflow_d5273 = overflow_ret61;
                    direct_page_d5273 = dp_ret61;
                    data_bank_d5273 = db_ret59;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret61;
                    carry_d5274 = carry_ret61;
                    zero_d5274 = zero_ret61;
                    negative_d5274 = negative_ret61;
                    overflow_d5274 = overflow_ret61;
                    direct_page_d5274 = dp_ret61;
                    data_bank_d5274 = db_ret59;
                    goto shared_D527_3;
                }
            }
        }
    }
    shared_D506_2:;
    uint8_t value23 = BUS8_RDP(c, (data_bank_d5063 << 0x10) + 0x0316);
    if (value23 == 0) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    uint8_t value24 = BUS8_RDP(c, (data_bank_d5063 << 0x10) + 0x0315);
    r->a = (a_hi_d5063 << 8) | value24;
    r->x = x_d5063;
    r->y = y_d5063;
    r->c = carry_d5063;
    r->z = value24 == 0;
    r->n = value24 & 0x80;
    r->v = overflow_d5063;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_d5063;
    r->dp = direct_page_d5063;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD518, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD518); } /* request_task_stop_by_id */
    r->sp += 5;
    uint16_t dp_ret62 = r->dp;
    uint8_t db_ret60 = r->db;
    bool m_ret28 = r->mf;
    bool x_ret103 = r->xf;
    uint16_t a_all62 = r->a;
    uint16_t y_ret62 = r->y;
    bool carry_ret62 = r->c;
    bool overflow_ret62 = r->v;
    if (m_ret28) {
        uint8_t value25 = BUS8_RDP(c, (db_ret60 << 0x10) + 0x0311);
        if (value25 == 0) {
            if (x_ret103) {
                y_d527 = (uint8_t)y_ret62;
                carry_d527 = carry_ret62;
                zero_d527 = value25 == 0;
                negative_d527 = value25 & 0x80;
                overflow_d527 = overflow_ret62;
                direct_page_d527 = dp_ret62;
                data_bank_d527 = db_ret60;
                goto shared_D527;
            } else {
                y_d5272 = y_ret62;
                carry_d5272 = carry_ret62;
                zero_d5272 = value25 == 0;
                negative_d5272 = value25 & 0x80;
                overflow_d5272 = overflow_ret62;
                direct_page_d5272 = dp_ret62;
                data_bank_d5272 = db_ret60;
                goto shared_D527_1;
            }
        }
        r->a = (a_all62 >> 8 << 8) | value25;
        r->z = value25 == 0;
        r->n = value25 & 0x80;
        r->mf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD520, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD520); } /* request_task_stop_by_id */
        r->sp += 5;
        uint8_t db_ret61 = r->db;
        bool m_ret29 = r->mf;
        uint16_t a_all63 = r->a;
        if (m_ret29) {
            uint8_t value26 = BUS8_RDP(c, (db_ret61 << 0x10) + 0x0312);
            r->a = (a_all63 >> 8 << 8) | value26;
            r->z = value26 == 0;
            r->n = value26 & 0x80;
            r->mf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret64 = r->dp;
            uint8_t db_ret62 = r->db;
            bool m_ret30 = r->mf;
            bool x_ret107 = r->xf;
            uint16_t y_ret64 = r->y;
            bool carry_ret64 = r->c;
            bool zero_ret64 = r->z;
            bool negative_ret64 = r->n;
            bool overflow_ret64 = r->v;
            if (m_ret30) {
                if (x_ret107) {
                    y_d527 = (uint8_t)y_ret64;
                    carry_d527 = carry_ret64;
                    zero_d527 = zero_ret64;
                    negative_d527 = negative_ret64;
                    overflow_d527 = overflow_ret64;
                    direct_page_d527 = dp_ret64;
                    data_bank_d527 = db_ret62;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret64;
                    carry_d5272 = carry_ret64;
                    zero_d5272 = zero_ret64;
                    negative_d5272 = negative_ret64;
                    overflow_d5272 = overflow_ret64;
                    direct_page_d5272 = dp_ret64;
                    data_bank_d5272 = db_ret62;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret107) {
                    y_d5273 = (uint8_t)y_ret64;
                    carry_d5273 = carry_ret64;
                    zero_d5273 = zero_ret64;
                    negative_d5273 = negative_ret64;
                    overflow_d5273 = overflow_ret64;
                    direct_page_d5273 = dp_ret64;
                    data_bank_d5273 = db_ret62;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret64;
                    carry_d5274 = carry_ret64;
                    zero_d5274 = zero_ret64;
                    negative_d5274 = negative_ret64;
                    overflow_d5274 = overflow_ret64;
                    direct_page_d5274 = dp_ret64;
                    data_bank_d5274 = db_ret62;
                    goto shared_D527_3;
                }
            }
        } else {
            uint16_t value27 = BUS16_RDP(c, (db_ret61 << 0x10) + 0x0312);
            r->a = value27;
            r->z = value27 == 0;
            r->n = value27 & 0x8000;
            r->mf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret65 = r->dp;
            uint8_t db_ret63 = r->db;
            bool m_ret31 = r->mf;
            bool x_ret109 = r->xf;
            uint16_t y_ret65 = r->y;
            bool carry_ret65 = r->c;
            bool zero_ret65 = r->z;
            bool negative_ret65 = r->n;
            bool overflow_ret65 = r->v;
            if (m_ret31) {
                if (x_ret109) {
                    y_d527 = (uint8_t)y_ret65;
                    carry_d527 = carry_ret65;
                    zero_d527 = zero_ret65;
                    negative_d527 = negative_ret65;
                    overflow_d527 = overflow_ret65;
                    direct_page_d527 = dp_ret65;
                    data_bank_d527 = db_ret63;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret65;
                    carry_d5272 = carry_ret65;
                    zero_d5272 = zero_ret65;
                    negative_d5272 = negative_ret65;
                    overflow_d5272 = overflow_ret65;
                    direct_page_d5272 = dp_ret65;
                    data_bank_d5272 = db_ret63;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret109) {
                    y_d5273 = (uint8_t)y_ret65;
                    carry_d5273 = carry_ret65;
                    zero_d5273 = zero_ret65;
                    negative_d5273 = negative_ret65;
                    overflow_d5273 = overflow_ret65;
                    direct_page_d5273 = dp_ret65;
                    data_bank_d5273 = db_ret63;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret65;
                    carry_d5274 = carry_ret65;
                    zero_d5274 = zero_ret65;
                    negative_d5274 = negative_ret65;
                    overflow_d5274 = overflow_ret65;
                    direct_page_d5274 = dp_ret65;
                    data_bank_d5274 = db_ret63;
                    goto shared_D527_3;
                }
            }
        }
    } else {
        uint16_t value28 = BUS16_RDP(c, (db_ret60 << 0x10) + 0x0311);
        if (value28 == 0) {
            if (x_ret103) {
                y_d5273 = (uint8_t)y_ret62;
                carry_d5273 = carry_ret62;
                zero_d5273 = value28 == 0;
                negative_d5273 = value28 & 0x8000;
                overflow_d5273 = overflow_ret62;
                direct_page_d5273 = dp_ret62;
                data_bank_d5273 = db_ret60;
                goto shared_D527_2;
            } else {
                y_d5274 = y_ret62;
                carry_d5274 = carry_ret62;
                zero_d5274 = value28 == 0;
                negative_d5274 = value28 & 0x8000;
                overflow_d5274 = overflow_ret62;
                direct_page_d5274 = dp_ret62;
                data_bank_d5274 = db_ret60;
                goto shared_D527_3;
            }
        }
        r->a = value28;
        r->z = value28 == 0;
        r->n = value28 & 0x8000;
        r->mf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD520, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD520); } /* request_task_stop_by_id */
        r->sp += 5;
        uint8_t db_ret64 = r->db;
        bool m_ret32 = r->mf;
        uint16_t a_all66 = r->a;
        if (m_ret32) {
            uint8_t value29 = BUS8_RDP(c, (db_ret64 << 0x10) + 0x0312);
            r->a = (a_all66 >> 8 << 8) | value29;
            r->z = value29 == 0;
            r->n = value29 & 0x80;
            r->mf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret67 = r->dp;
            uint8_t db_ret65 = r->db;
            bool m_ret33 = r->mf;
            bool x_ret113 = r->xf;
            uint16_t y_ret67 = r->y;
            bool carry_ret67 = r->c;
            bool zero_ret67 = r->z;
            bool negative_ret67 = r->n;
            bool overflow_ret67 = r->v;
            if (m_ret33) {
                if (x_ret113) {
                    y_d527 = (uint8_t)y_ret67;
                    carry_d527 = carry_ret67;
                    zero_d527 = zero_ret67;
                    negative_d527 = negative_ret67;
                    overflow_d527 = overflow_ret67;
                    direct_page_d527 = dp_ret67;
                    data_bank_d527 = db_ret65;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret67;
                    carry_d5272 = carry_ret67;
                    zero_d5272 = zero_ret67;
                    negative_d5272 = negative_ret67;
                    overflow_d5272 = overflow_ret67;
                    direct_page_d5272 = dp_ret67;
                    data_bank_d5272 = db_ret65;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret113) {
                    y_d5273 = (uint8_t)y_ret67;
                    carry_d5273 = carry_ret67;
                    zero_d5273 = zero_ret67;
                    negative_d5273 = negative_ret67;
                    overflow_d5273 = overflow_ret67;
                    direct_page_d5273 = dp_ret67;
                    data_bank_d5273 = db_ret65;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret67;
                    carry_d5274 = carry_ret67;
                    zero_d5274 = zero_ret67;
                    negative_d5274 = negative_ret67;
                    overflow_d5274 = overflow_ret67;
                    direct_page_d5274 = dp_ret67;
                    data_bank_d5274 = db_ret65;
                    goto shared_D527_3;
                }
            }
        } else {
            uint16_t value30 = BUS16_RDP(c, (db_ret64 << 0x10) + 0x0312);
            r->a = value30;
            r->z = value30 == 0;
            r->n = value30 & 0x8000;
            r->mf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret68 = r->dp;
            uint8_t db_ret66 = r->db;
            bool m_ret34 = r->mf;
            bool x_ret115 = r->xf;
            uint16_t y_ret68 = r->y;
            bool carry_ret68 = r->c;
            bool zero_ret68 = r->z;
            bool negative_ret68 = r->n;
            bool overflow_ret68 = r->v;
            if (m_ret34) {
                if (x_ret115) {
                    y_d527 = (uint8_t)y_ret68;
                    carry_d527 = carry_ret68;
                    zero_d527 = zero_ret68;
                    negative_d527 = negative_ret68;
                    overflow_d527 = overflow_ret68;
                    direct_page_d527 = dp_ret68;
                    data_bank_d527 = db_ret66;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret68;
                    carry_d5272 = carry_ret68;
                    zero_d5272 = zero_ret68;
                    negative_d5272 = negative_ret68;
                    overflow_d5272 = overflow_ret68;
                    direct_page_d5272 = dp_ret68;
                    data_bank_d5272 = db_ret66;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret115) {
                    y_d5273 = (uint8_t)y_ret68;
                    carry_d5273 = carry_ret68;
                    zero_d5273 = zero_ret68;
                    negative_d5273 = negative_ret68;
                    overflow_d5273 = overflow_ret68;
                    direct_page_d5273 = dp_ret68;
                    data_bank_d5273 = db_ret66;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret68;
                    carry_d5274 = carry_ret68;
                    zero_d5274 = zero_ret68;
                    negative_d5274 = negative_ret68;
                    overflow_d5274 = overflow_ret68;
                    direct_page_d5274 = dp_ret68;
                    data_bank_d5274 = db_ret66;
                    goto shared_D527_3;
                }
            }
        }
    }
    shared_D506_3:;
    uint16_t value31 = BUS16_RDP(c, (data_bank_d5064 << 0x10) + 0x0316);
    if (value31 == 0) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    uint16_t value32 = BUS16_RDP(c, (data_bank_d5064 << 0x10) + 0x0315);
    r->a = value32;
    r->x = x_d5064;
    r->y = y_d5064;
    r->c = carry_d5064;
    r->z = value32 == 0;
    r->n = value32 & 0x8000;
    r->v = overflow_d5064;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_d5064;
    r->dp = direct_page_d5064;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD518, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD518); } /* request_task_stop_by_id */
    r->sp += 5;
    uint16_t dp_ret69 = r->dp;
    uint8_t db_ret67 = r->db;
    bool m_ret35 = r->mf;
    bool x_ret117 = r->xf;
    uint16_t a_all69 = r->a;
    uint16_t y_ret69 = r->y;
    bool carry_ret69 = r->c;
    bool overflow_ret69 = r->v;
    if (m_ret35) {
        uint8_t value33 = BUS8_RDP(c, (db_ret67 << 0x10) + 0x0311);
        if (value33 == 0) {
            if (x_ret117) {
                y_d527 = (uint8_t)y_ret69;
                carry_d527 = carry_ret69;
                zero_d527 = value33 == 0;
                negative_d527 = value33 & 0x80;
                overflow_d527 = overflow_ret69;
                direct_page_d527 = dp_ret69;
                data_bank_d527 = db_ret67;
                goto shared_D527;
            } else {
                y_d5272 = y_ret69;
                carry_d5272 = carry_ret69;
                zero_d5272 = value33 == 0;
                negative_d5272 = value33 & 0x80;
                overflow_d5272 = overflow_ret69;
                direct_page_d5272 = dp_ret69;
                data_bank_d5272 = db_ret67;
                goto shared_D527_1;
            }
        }
        r->a = (a_all69 >> 8 << 8) | value33;
        r->z = value33 == 0;
        r->n = value33 & 0x80;
        r->mf = 1;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD520, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD520); } /* request_task_stop_by_id */
        r->sp += 5;
        uint8_t db_ret68 = r->db;
        bool m_ret36 = r->mf;
        uint16_t a_all70 = r->a;
        if (m_ret36) {
            uint8_t value34 = BUS8_RDP(c, (db_ret68 << 0x10) + 0x0312);
            r->a = (a_all70 >> 8 << 8) | value34;
            r->z = value34 == 0;
            r->n = value34 & 0x80;
            r->mf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret71 = r->dp;
            uint8_t db_ret69 = r->db;
            bool m_ret37 = r->mf;
            bool x_ret121 = r->xf;
            uint16_t y_ret71 = r->y;
            bool carry_ret71 = r->c;
            bool zero_ret71 = r->z;
            bool negative_ret71 = r->n;
            bool overflow_ret71 = r->v;
            if (m_ret37) {
                if (x_ret121) {
                    y_d527 = (uint8_t)y_ret71;
                    carry_d527 = carry_ret71;
                    zero_d527 = zero_ret71;
                    negative_d527 = negative_ret71;
                    overflow_d527 = overflow_ret71;
                    direct_page_d527 = dp_ret71;
                    data_bank_d527 = db_ret69;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret71;
                    carry_d5272 = carry_ret71;
                    zero_d5272 = zero_ret71;
                    negative_d5272 = negative_ret71;
                    overflow_d5272 = overflow_ret71;
                    direct_page_d5272 = dp_ret71;
                    data_bank_d5272 = db_ret69;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret121) {
                    y_d5273 = (uint8_t)y_ret71;
                    carry_d5273 = carry_ret71;
                    zero_d5273 = zero_ret71;
                    negative_d5273 = negative_ret71;
                    overflow_d5273 = overflow_ret71;
                    direct_page_d5273 = dp_ret71;
                    data_bank_d5273 = db_ret69;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret71;
                    carry_d5274 = carry_ret71;
                    zero_d5274 = zero_ret71;
                    negative_d5274 = negative_ret71;
                    overflow_d5274 = overflow_ret71;
                    direct_page_d5274 = dp_ret71;
                    data_bank_d5274 = db_ret69;
                    goto shared_D527_3;
                }
            }
        } else {
            uint16_t value35 = BUS16_RDP(c, (db_ret68 << 0x10) + 0x0312);
            r->a = value35;
            r->z = value35 == 0;
            r->n = value35 & 0x8000;
            r->mf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret72 = r->dp;
            uint8_t db_ret70 = r->db;
            bool m_ret38 = r->mf;
            bool x_ret123 = r->xf;
            uint16_t y_ret72 = r->y;
            bool carry_ret72 = r->c;
            bool zero_ret72 = r->z;
            bool negative_ret72 = r->n;
            bool overflow_ret72 = r->v;
            if (m_ret38) {
                if (x_ret123) {
                    y_d527 = (uint8_t)y_ret72;
                    carry_d527 = carry_ret72;
                    zero_d527 = zero_ret72;
                    negative_d527 = negative_ret72;
                    overflow_d527 = overflow_ret72;
                    direct_page_d527 = dp_ret72;
                    data_bank_d527 = db_ret70;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret72;
                    carry_d5272 = carry_ret72;
                    zero_d5272 = zero_ret72;
                    negative_d5272 = negative_ret72;
                    overflow_d5272 = overflow_ret72;
                    direct_page_d5272 = dp_ret72;
                    data_bank_d5272 = db_ret70;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret123) {
                    y_d5273 = (uint8_t)y_ret72;
                    carry_d5273 = carry_ret72;
                    zero_d5273 = zero_ret72;
                    negative_d5273 = negative_ret72;
                    overflow_d5273 = overflow_ret72;
                    direct_page_d5273 = dp_ret72;
                    data_bank_d5273 = db_ret70;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret72;
                    carry_d5274 = carry_ret72;
                    zero_d5274 = zero_ret72;
                    negative_d5274 = negative_ret72;
                    overflow_d5274 = overflow_ret72;
                    direct_page_d5274 = dp_ret72;
                    data_bank_d5274 = db_ret70;
                    goto shared_D527_3;
                }
            }
        }
    } else {
        uint16_t value36 = BUS16_RDP(c, (db_ret67 << 0x10) + 0x0311);
        if (value36 == 0) {
            if (x_ret117) {
                y_d5273 = (uint8_t)y_ret69;
                carry_d5273 = carry_ret69;
                zero_d5273 = value36 == 0;
                negative_d5273 = value36 & 0x8000;
                overflow_d5273 = overflow_ret69;
                direct_page_d5273 = dp_ret69;
                data_bank_d5273 = db_ret67;
                goto shared_D527_2;
            } else {
                y_d5274 = y_ret69;
                carry_d5274 = carry_ret69;
                zero_d5274 = value36 == 0;
                negative_d5274 = value36 & 0x8000;
                overflow_d5274 = overflow_ret69;
                direct_page_d5274 = dp_ret69;
                data_bank_d5274 = db_ret67;
                goto shared_D527_3;
            }
        }
        r->a = value36;
        r->z = value36 == 0;
        r->n = value36 & 0x8000;
        r->mf = 0;
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD520, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD520); } /* request_task_stop_by_id */
        r->sp += 5;
        uint8_t db_ret71 = r->db;
        bool m_ret39 = r->mf;
        uint16_t a_all73 = r->a;
        if (m_ret39) {
            uint8_t value37 = BUS8_RDP(c, (db_ret71 << 0x10) + 0x0312);
            r->a = (a_all73 >> 8 << 8) | value37;
            r->z = value37 == 0;
            r->n = value37 & 0x80;
            r->mf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret74 = r->dp;
            uint8_t db_ret72 = r->db;
            bool m_ret40 = r->mf;
            bool x_ret127 = r->xf;
            uint16_t y_ret74 = r->y;
            bool carry_ret74 = r->c;
            bool zero_ret74 = r->z;
            bool negative_ret74 = r->n;
            bool overflow_ret74 = r->v;
            if (m_ret40) {
                if (x_ret127) {
                    y_d527 = (uint8_t)y_ret74;
                    carry_d527 = carry_ret74;
                    zero_d527 = zero_ret74;
                    negative_d527 = negative_ret74;
                    overflow_d527 = overflow_ret74;
                    direct_page_d527 = dp_ret74;
                    data_bank_d527 = db_ret72;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret74;
                    carry_d5272 = carry_ret74;
                    zero_d5272 = zero_ret74;
                    negative_d5272 = negative_ret74;
                    overflow_d5272 = overflow_ret74;
                    direct_page_d5272 = dp_ret74;
                    data_bank_d5272 = db_ret72;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret127) {
                    y_d5273 = (uint8_t)y_ret74;
                    carry_d5273 = carry_ret74;
                    zero_d5273 = zero_ret74;
                    negative_d5273 = negative_ret74;
                    overflow_d5273 = overflow_ret74;
                    direct_page_d5273 = dp_ret74;
                    data_bank_d5273 = db_ret72;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret74;
                    carry_d5274 = carry_ret74;
                    zero_d5274 = zero_ret74;
                    negative_d5274 = negative_ret74;
                    overflow_d5274 = overflow_ret74;
                    direct_page_d5274 = dp_ret74;
                    data_bank_d5274 = db_ret72;
                    goto shared_D527_3;
                }
            }
        } else {
            uint16_t value38 = BUS16_RDP(c, (db_ret71 << 0x10) + 0x0312);
            r->a = value38;
            r->z = value38 == 0;
            r->n = value38 & 0x8000;
            r->mf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD526, 0x7EACAC); GUARD_JSR(c, sp_call, 0xD526); } /* request_task_stop_by_id */
            r->sp += 5;
            uint16_t dp_ret75 = r->dp;
            uint8_t db_ret73 = r->db;
            bool m_ret41 = r->mf;
            bool x_ret129 = r->xf;
            uint16_t y_ret75 = r->y;
            bool carry_ret75 = r->c;
            bool zero_ret75 = r->z;
            bool negative_ret75 = r->n;
            bool overflow_ret75 = r->v;
            if (m_ret41) {
                if (x_ret129) {
                    y_d527 = (uint8_t)y_ret75;
                    carry_d527 = carry_ret75;
                    zero_d527 = zero_ret75;
                    negative_d527 = negative_ret75;
                    overflow_d527 = overflow_ret75;
                    direct_page_d527 = dp_ret75;
                    data_bank_d527 = db_ret73;
                    goto shared_D527;
                } else {
                    y_d5272 = y_ret75;
                    carry_d5272 = carry_ret75;
                    zero_d5272 = zero_ret75;
                    negative_d5272 = negative_ret75;
                    overflow_d5272 = overflow_ret75;
                    direct_page_d5272 = dp_ret75;
                    data_bank_d5272 = db_ret73;
                    goto shared_D527_1;
                }
            } else {
                if (x_ret129) {
                    y_d5273 = (uint8_t)y_ret75;
                    carry_d5273 = carry_ret75;
                    zero_d5273 = zero_ret75;
                    negative_d5273 = negative_ret75;
                    overflow_d5273 = overflow_ret75;
                    direct_page_d5273 = dp_ret75;
                    data_bank_d5273 = db_ret73;
                    goto shared_D527_2;
                } else {
                    y_d5274 = y_ret75;
                    carry_d5274 = carry_ret75;
                    zero_d5274 = zero_ret75;
                    negative_d5274 = negative_ret75;
                    overflow_d5274 = overflow_ret75;
                    direct_page_d5274 = dp_ret75;
                    data_bank_d5274 = db_ret73;
                    goto shared_D527_3;
                }
            }
        }
    }
    shared_D527:;
    r->y = y_d527;
    r->c = carry_d527;
    r->z = zero_d527;
    r->n = negative_d527;
    r->v = overflow_d527;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_d527;
    r->dp = direct_page_d527;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD529, 0x7ED3AA); GUARD_JSR(c, sp_call, 0xD529); } /* teardown_title_window_and_tracked_tasks */
    r->sp += 5;
    bool m_ret42 = r->mf;
    if (m_ret42) {
        uint8_t value41 = RAM8(0x0000 + sp0 - 2);
        uint8_t value42 = RAM8(0x0000 + sp0 - 1);
        uint8_t value43 = RAM8(0x0000 + sp0);
        r->c = value41 & 0x01;
        r->z = ((value43 << 8) | value42) == 0;
        r->n = ((value43 << 8) | value42) & 0x8000;
        r->v = value41 & 0x40;
        r->mf = value41 & 0x20;
        r->xf = value41 & 0x10;
        r->dp = (value43 << 8) | value42;
        r->i = value41 & 0x04;
        r->d = value41 & 0x08;
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_D527_1:;
    r->y = y_d5272;
    r->c = carry_d5272;
    r->z = zero_d5272;
    r->n = negative_d5272;
    r->v = overflow_d5272;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_d5272;
    r->dp = direct_page_d5272;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD529, 0x7ED3AA); GUARD_JSR(c, sp_call, 0xD529); } /* teardown_title_window_and_tracked_tasks */
    r->sp += 5;
    bool m_ret43 = r->mf;
    if (m_ret43) {
        uint8_t value51 = RAM8(0x0000 + sp0 - 2);
        uint8_t value52 = RAM8(0x0000 + sp0 - 1);
        uint8_t value53 = RAM8(0x0000 + sp0);
        r->c = value51 & 0x01;
        r->z = ((value53 << 8) | value52) == 0;
        r->n = ((value53 << 8) | value52) & 0x8000;
        r->v = value51 & 0x40;
        r->mf = value51 & 0x20;
        r->xf = value51 & 0x10;
        r->dp = (value53 << 8) | value52;
        r->i = value51 & 0x04;
        r->d = value51 & 0x08;
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_D527_2:;
    r->y = y_d5273;
    r->c = carry_d5273;
    r->z = zero_d5273;
    r->n = negative_d5273;
    r->v = overflow_d5273;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_d5273;
    r->dp = direct_page_d5273;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD529, 0x7ED3AA); GUARD_JSR(c, sp_call, 0xD529); } /* teardown_title_window_and_tracked_tasks */
    r->sp += 5;
    bool m_ret44 = r->mf;
    if (m_ret44) {
        uint8_t value61 = RAM8(0x0000 + sp0 - 2);
        uint8_t value62 = RAM8(0x0000 + sp0 - 1);
        uint8_t value63 = RAM8(0x0000 + sp0);
        r->c = value61 & 0x01;
        r->z = ((value63 << 8) | value62) == 0;
        r->n = ((value63 << 8) | value62) & 0x8000;
        r->v = value61 & 0x40;
        r->mf = value61 & 0x20;
        r->xf = value61 & 0x10;
        r->dp = (value63 << 8) | value62;
        r->i = value61 & 0x04;
        r->d = value61 & 0x08;
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
    shared_D527_3:;
    r->y = y_d5274;
    r->c = carry_d5274;
    r->z = zero_d5274;
    r->n = negative_d5274;
    r->v = overflow_d5274;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_d5274;
    r->dp = direct_page_d5274;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD529, 0x7ED3AA); GUARD_JSR(c, sp_call, 0xD529); } /* teardown_title_window_and_tracked_tasks */
    r->sp += 5;
    bool m_ret45 = r->mf;
    if (m_ret45) {
        uint8_t value71 = RAM8(0x0000 + sp0 - 2);
        uint8_t value72 = RAM8(0x0000 + sp0 - 1);
        uint8_t value73 = RAM8(0x0000 + sp0);
        r->c = value71 & 0x01;
        r->z = ((value73 << 8) | value72) == 0;
        r->n = ((value73 << 8) | value72) & 0x8000;
        r->v = value71 & 0x40;
        r->mf = value71 & 0x20;
        r->xf = value71 & 0x10;
        r->dp = (value73 << 8) | value72;
        r->i = value71 & 0x04;
        r->d = value71 & 0x08;
        RETURN_RTS(c);
    } else {
        c->fail = 3;
        return;
    }
}
SOM_REGISTER(0x7ED473, SOM_RTS, "gen", prepare_native_title_coordinator_and_enter_palette_spawn_prefix, 0, L_C | L_Z | L_N | L_V, 5, 0, 0, 188, 81)
