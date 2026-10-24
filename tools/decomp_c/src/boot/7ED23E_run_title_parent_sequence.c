#include "som_c.h"

/* 7ED23E run_title_parent_sequence   [class B, 190 bytes, 73 instructions]
 * Source: src/boot/run_title_parent_sequence.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABXYV.
 */
static void run_title_parent_sequence(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_hi_d273 = 0;
    uint8_t x_d273 = 0;
    uint8_t y_d273 = 0;
    bool carry_d273 = 0;
    bool overflow_d273 = 0;
    uint16_t direct_page_d273 = 0;
    uint8_t data_bank_d273 = 0;
    uint8_t a_hi_d2732 = 0;
    uint16_t x_d2732 = 0;
    uint16_t y_d2732 = 0;
    bool carry_d2732 = 0;
    bool overflow_d2732 = 0;
    uint16_t direct_page_d2732 = 0;
    uint8_t data_bank_d2732 = 0;
    uint8_t a_d264 = 0;
    uint8_t a_hi_d264 = 0;
    uint8_t y_d264 = 0;
    bool carry_d264 = 0;
    bool overflow_d264 = 0;
    uint16_t direct_page_d264 = 0;
    uint8_t data_bank_d264 = 0;
    uint8_t a_d2642 = 0;
    uint8_t a_hi_d2642 = 0;
    uint16_t y_d2642 = 0;
    bool carry_d2642 = 0;
    bool overflow_d2642 = 0;
    uint16_t direct_page_d2642 = 0;
    uint8_t data_bank_d2642 = 0;
    uint8_t a_d25c = 0;
    uint8_t a_hi_d25c = 0;
    uint8_t x_d25c = 0;
    uint8_t y_d25c = 0;
    uint16_t direct_page_d25c = 0;
    uint8_t data_bank_d25c = 0;
    uint8_t a_d25c2 = 0;
    uint8_t a_hi_d25c2 = 0;
    uint16_t x_d25c2 = 0;
    uint16_t y_d25c2 = 0;
    uint16_t direct_page_d25c2 = 0;
    uint8_t data_bank_d25c2 = 0;
    uint8_t a_d2f9 = 0;
    uint8_t a_hi_d2f9 = 0;
    uint8_t x_d2f9 = 0;
    uint8_t y_d2f9 = 0;
    uint16_t direct_page_d2f9 = 0;
    uint8_t data_bank_d2f9 = 0;
    uint8_t a_d2f92 = 0;
    uint8_t a_hi_d2f92 = 0;
    uint16_t x_d2f92 = 0;
    uint16_t y_d2f92 = 0;
    uint16_t direct_page_d2f92 = 0;
    uint8_t data_bank_d2f92 = 0;
    uint8_t a_d2f93 = 0;
    uint8_t a_hi_d2f93 = 0;
    uint8_t x_d2f93 = 0;
    uint8_t y_d2f93 = 0;
    uint16_t direct_page_d2f93 = 0;
    uint8_t data_bank_d2f93 = 0;
    uint8_t a_d2f94 = 0;
    uint8_t a_hi_d2f94 = 0;
    uint16_t x_d2f94 = 0;
    uint16_t y_d2f94 = 0;
    uint16_t direct_page_d2f94 = 0;
    uint8_t data_bank_d2f94 = 0;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = (a_hi << 8) | 0x7E;
    r->x = 0x5F12;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD24B, 0x7EAB88); GUARD_JSR(c, sp_call, 0xD24B); } /* create_and_enqueue_task */
    r->sp += 3;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    uint16_t a_all = r->a;
    if (m_ret) {
        BUS8_SET(c, (db_ret << 0x10) + 0x0311, (uint8_t)a_all);
        r->x = 0x03A0;
        r->z = 0;
        r->n = 0;
        r->mf = 1;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD254, 0x7ECD82); GUARD_JSR(c, sp_call, 0xD254); } /* copy_and_submit_title_tilemap */
        r->sp += 3;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD257, 0x7ED20D); GUARD_JSR(c, sp_call, 0xD257); } /* fade_parent_display_in */
        r->sp += 3;
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret2 = r->db;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret3 = r->y;
        bool overflow_ret3 = r->v;
        if ((uint8_t)a_all3 != 0) {
            uint8_t value = BUS8_RDP(c, (db_ret2 << 0x10) + 0x0316);
            if (value != 0) {
                if (x_ret4) {
                    a_hi_d273 = a_all3 >> 8;
                    x_d273 = (uint8_t)x_ret5;
                    y_d273 = (uint8_t)y_ret3;
                    carry_d273 = (uint8_t)a_all3 >= 0;
                    overflow_d273 = overflow_ret3;
                    direct_page_d273 = dp_ret3;
                    data_bank_d273 = db_ret2;
                    goto shared_D273;
                } else {
                    a_hi_d2732 = a_all3 >> 8;
                    x_d2732 = x_ret5;
                    y_d2732 = y_ret3;
                    carry_d2732 = (uint8_t)a_all3 >= 0;
                    overflow_d2732 = overflow_ret3;
                    direct_page_d2732 = dp_ret3;
                    data_bank_d2732 = db_ret2;
                    goto shared_D273_1;
                }
            }
            if (x_ret4) {
                a_d264 = value;
                a_hi_d264 = a_all3 >> 8;
                y_d264 = (uint8_t)y_ret3;
                carry_d264 = (uint8_t)a_all3 >= 0;
                overflow_d264 = overflow_ret3;
                direct_page_d264 = dp_ret3;
                data_bank_d264 = db_ret2;
                goto shared_D264;
            } else {
                a_d2642 = value;
                a_hi_d2642 = a_all3 >> 8;
                y_d2642 = y_ret3;
                carry_d2642 = (uint8_t)a_all3 >= 0;
                overflow_d2642 = overflow_ret3;
                direct_page_d2642 = dp_ret3;
                data_bank_d2642 = db_ret2;
                goto shared_D264_1;
            }
        }
        if (x_ret4) {
            a_d25c = (uint8_t)a_all3;
            a_hi_d25c = a_all3 >> 8;
            x_d25c = (uint8_t)x_ret5;
            y_d25c = (uint8_t)y_ret3;
            direct_page_d25c = dp_ret3;
            data_bank_d25c = db_ret2;
            goto shared_D25C;
        } else {
            a_d25c2 = (uint8_t)a_all3;
            a_hi_d25c2 = a_all3 >> 8;
            x_d25c2 = x_ret5;
            y_d25c2 = y_ret3;
            direct_page_d25c2 = dp_ret3;
            data_bank_d25c2 = db_ret2;
            goto shared_D25C_1;
        }
    } else {
        BUS16_SET(c, (db_ret << 0x10) + 0x0311, a_all);
        r->x = 0x03A0;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD254, 0x7ECD82); GUARD_JSR(c, sp_call, 0xD254); } /* copy_and_submit_title_tilemap */
        r->sp += 3;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD257, 0x7ED20D); GUARD_JSR(c, sp_call, 0xD257); } /* fade_parent_display_in */
        r->sp += 3;
        uint16_t dp_ret5 = r->dp;
        uint8_t db_ret3 = r->db;
        bool x_ret8 = r->xf;
        uint16_t a_all5 = r->a;
        uint16_t x_ret9 = r->x;
        uint16_t y_ret5 = r->y;
        bool overflow_ret5 = r->v;
        if ((uint8_t)a_all5 != 0) {
            uint8_t value2 = BUS8_RDP(c, (db_ret3 << 0x10) + 0x0316);
            if (value2 != 0) {
                if (x_ret8) {
                    a_hi_d273 = a_all5 >> 8;
                    x_d273 = (uint8_t)x_ret9;
                    y_d273 = (uint8_t)y_ret5;
                    carry_d273 = (uint8_t)a_all5 >= 0;
                    overflow_d273 = overflow_ret5;
                    direct_page_d273 = dp_ret5;
                    data_bank_d273 = db_ret3;
                    goto shared_D273;
                } else {
                    a_hi_d2732 = a_all5 >> 8;
                    x_d2732 = x_ret9;
                    y_d2732 = y_ret5;
                    carry_d2732 = (uint8_t)a_all5 >= 0;
                    overflow_d2732 = overflow_ret5;
                    direct_page_d2732 = dp_ret5;
                    data_bank_d2732 = db_ret3;
                    goto shared_D273_1;
                }
            }
            if (x_ret8) {
                a_d264 = value2;
                a_hi_d264 = a_all5 >> 8;
                y_d264 = (uint8_t)y_ret5;
                carry_d264 = (uint8_t)a_all5 >= 0;
                overflow_d264 = overflow_ret5;
                direct_page_d264 = dp_ret5;
                data_bank_d264 = db_ret3;
                goto shared_D264;
            } else {
                a_d2642 = value2;
                a_hi_d2642 = a_all5 >> 8;
                y_d2642 = y_ret5;
                carry_d2642 = (uint8_t)a_all5 >= 0;
                overflow_d2642 = overflow_ret5;
                direct_page_d2642 = dp_ret5;
                data_bank_d2642 = db_ret3;
                goto shared_D264_1;
            }
        }
        if (x_ret8) {
            a_d25c = (uint8_t)a_all5;
            a_hi_d25c = a_all5 >> 8;
            x_d25c = (uint8_t)x_ret9;
            y_d25c = (uint8_t)y_ret5;
            direct_page_d25c = dp_ret5;
            data_bank_d25c = db_ret3;
            goto shared_D25C;
        } else {
            a_d25c2 = (uint8_t)a_all5;
            a_hi_d25c2 = a_all5 >> 8;
            x_d25c2 = x_ret9;
            y_d25c2 = y_ret5;
            direct_page_d25c2 = dp_ret5;
            data_bank_d25c2 = db_ret3;
            goto shared_D25C_1;
        }
    }
    shared_D273:;
    RAM8(0x1E00) = 1;
    RAM8(0x1E01) = 0x2D;
    RAM8(0x1E02) = 0x0B;
    RAM8(0x1E03) = 0x0F;
    r->a = (a_hi_d273 << 8) | 0x0F;
    r->x = x_d273;
    r->y = y_d273;
    r->c = carry_d273;
    r->z = 0;
    r->n = 0;
    r->v = overflow_d273;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_d273;
    r->dp = direct_page_d273;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSL(c, 0xD28E, 0xC30004); GUARD_JSL(c, sp_call, 0xD28E); } /* audio_command_sender_public_jump */
    r->sp += 3;
    r->x = 0x7FFF;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD294, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD294); } /* dispatch_parent_messages */
    r->sp += 3;
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret4 = r->db;
    bool x_ret11 = r->xf;
    uint16_t a_all7 = r->a;
    uint16_t x_ret12 = r->x;
    uint16_t y_ret7 = r->y;
    if ((uint8_t)a_all7 == 0) {
        if (x_ret11) {
            a_d2f9 = (uint8_t)a_all7;
            a_hi_d2f9 = a_all7 >> 8;
            x_d2f9 = (uint8_t)x_ret12;
            y_d2f9 = (uint8_t)y_ret7;
            direct_page_d2f9 = dp_ret6;
            data_bank_d2f9 = db_ret4;
            goto shared_D2F9;
        } else {
            a_d2f92 = (uint8_t)a_all7;
            a_hi_d2f92 = a_all7 >> 8;
            x_d2f92 = x_ret12;
            y_d2f92 = y_ret7;
            direct_page_d2f92 = dp_ret6;
            data_bank_d2f92 = db_ret4;
            goto shared_D2F9_1;
        }
    }
    r->c = (uint8_t)a_all7 >= 0;
    r->z = (uint8_t)a_all7 == 0;
    r->n = (uint8_t)a_all7 & 0x80;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD29B, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xD29B); } /* release_eight_byte_record */
    r->sp += 3;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD29E, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xD29E); } /* allocate_eight_byte_record */
    r->sp += 3;
    uint8_t db_ret6 = r->db;
    bool m_ret6 = r->mf;
    uint16_t a_all9 = r->a;
    if (m_ret6) {
        uint8_t value3 = BUS8_RDP(c, (db_ret6 << 0x10) + 0x0311);
        r->a = (a_all9 >> 8 << 8) | value3;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->mf = 1;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2A4, 0x7EB258); GUARD_JSR(c, sp_call, 0xD2A4); } /* append_pending_record */
        r->sp += 3;
        r->x = 0x010E;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2AA, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD2AA); } /* dispatch_parent_messages */
        r->sp += 3;
        uint16_t dp_ret10 = r->dp;
        uint8_t db_ret8 = r->db;
        bool x_ret17 = r->xf;
        uint16_t a_all11 = r->a;
        uint16_t x_ret18 = r->x;
        uint16_t y_ret9 = r->y;
        if ((uint8_t)a_all11 == 0) {
            if (x_ret17) {
                a_d2f9 = (uint8_t)a_all11;
                a_hi_d2f9 = a_all11 >> 8;
                x_d2f9 = (uint8_t)x_ret18;
                y_d2f9 = (uint8_t)y_ret9;
                direct_page_d2f9 = dp_ret10;
                data_bank_d2f9 = db_ret8;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all11;
                a_hi_d2f92 = a_all11 >> 8;
                x_d2f92 = x_ret18;
                y_d2f92 = y_ret9;
                direct_page_d2f92 = dp_ret10;
                data_bank_d2f92 = db_ret8;
                goto shared_D2F9_1;
            }
        }
        r->c = (uint8_t)a_all11 >= 0;
        r->z = (uint8_t)a_all11 == 0;
        r->n = (uint8_t)a_all11 & 0x80;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2B1, 0x7ED1DA); GUARD_JSR(c, sp_call, 0xD2B1); } /* fade_parent_display_until_control_exit */
        r->sp += 3;
        uint16_t dp_ret11 = r->dp;
        uint8_t db_ret9 = r->db;
        uint16_t a_all12 = r->a;
        uint16_t x_ret19 = r->x;
        uint16_t y_ret10 = r->y;
        if ((uint8_t)a_all12 == 0) {
            a_d2f92 = (uint8_t)a_all12;
            a_hi_d2f92 = a_all12 >> 8;
            x_d2f92 = x_ret19;
            y_d2f92 = y_ret10;
            direct_page_d2f92 = dp_ret11;
            data_bank_d2f92 = db_ret9;
            goto shared_D2F9_1;
        }
        r->x = 0;
        r->c = (uint8_t)a_all12 >= 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2BB, 0x7ECD82); GUARD_JSR(c, sp_call, 0xD2BB); } /* copy_and_submit_title_tilemap */
        r->sp += 3;
        r->x = 0x1E;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2C1, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD2C1); } /* dispatch_parent_messages */
        r->sp += 3;
        uint16_t dp_ret13 = r->dp;
        uint8_t db_ret10 = r->db;
        bool x_ret21 = r->xf;
        uint16_t a_all14 = r->a;
        uint16_t x_ret22 = r->x;
        uint16_t y_ret12 = r->y;
        if ((uint8_t)a_all14 == 0) {
            if (x_ret21) {
                a_d2f9 = (uint8_t)a_all14;
                a_hi_d2f9 = a_all14 >> 8;
                x_d2f9 = (uint8_t)x_ret22;
                y_d2f9 = (uint8_t)y_ret12;
                direct_page_d2f9 = dp_ret13;
                data_bank_d2f9 = db_ret10;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all14;
                a_hi_d2f92 = a_all14 >> 8;
                x_d2f92 = x_ret22;
                y_d2f92 = y_ret12;
                direct_page_d2f92 = dp_ret13;
                data_bank_d2f92 = db_ret10;
                goto shared_D2F9_1;
            }
        }
        RAM8(0x1E00) = 1;
        RAM8(0x1E01) = 0x2C;
        RAM8(0x1E02) = 0x0F;
        RAM8(0x1E03) = 0x0F;
        r->a = (a_all14 >> 8 << 8) | 0x0F;
        r->c = (uint8_t)a_all14 >= 0;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD2E1, 0xC30004); GUARD_JSL(c, sp_call, 0xD2E1); } /* audio_command_sender_public_jump */
        r->sp += 3;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2E4, 0x7ED20D); GUARD_JSR(c, sp_call, 0xD2E4); } /* fade_parent_display_in */
        r->sp += 3;
        uint16_t dp_ret14 = r->dp;
        uint8_t db_ret11 = r->db;
        uint16_t a_all16 = r->a;
        uint16_t x_ret25 = r->x;
        uint16_t y_ret14 = r->y;
        if ((uint8_t)a_all16 == 0) {
            a_d2f92 = (uint8_t)a_all16;
            a_hi_d2f92 = a_all16 >> 8;
            x_d2f92 = x_ret25;
            y_d2f92 = y_ret14;
            direct_page_d2f92 = dp_ret14;
            data_bank_d2f92 = db_ret11;
            goto shared_D2F9_1;
        }
        BUS8_SET(c, (db_ret11 << 0x10) + 0x0317, 1);
        r->a = (a_all16 >> 8 << 8) | 0x7E;
        r->x = 0x5EAA;
        r->c = (uint8_t)a_all16 >= 0;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2F5, 0x7EAB88); GUARD_JSR(c, sp_call, 0xD2F5); } /* create_and_enqueue_task */
        r->sp += 3;
        uint16_t dp_ret15 = r->dp;
        uint8_t db_ret12 = r->db;
        bool m_ret10 = r->mf;
        bool x_ret26 = r->xf;
        uint16_t a_all17 = r->a;
        uint16_t x_ret27 = r->x;
        uint16_t y_ret15 = r->y;
        if (m_ret10) {
            BUS8_SET(c, (db_ret12 << 0x10) + 0x0312, (uint8_t)a_all17);
            if (x_ret26) {
                a_d2f9 = (uint8_t)a_all17;
                a_hi_d2f9 = a_all17 >> 8;
                x_d2f9 = (uint8_t)x_ret27;
                y_d2f9 = (uint8_t)y_ret15;
                direct_page_d2f9 = dp_ret15;
                data_bank_d2f9 = db_ret12;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all17;
                a_hi_d2f92 = a_all17 >> 8;
                x_d2f92 = x_ret27;
                y_d2f92 = y_ret15;
                direct_page_d2f92 = dp_ret15;
                data_bank_d2f92 = db_ret12;
                goto shared_D2F9_1;
            }
        } else {
            BUS16_SET(c, (db_ret12 << 0x10) + 0x0312, a_all17);
            if (x_ret26) {
                a_d2f93 = (uint8_t)a_all17;
                a_hi_d2f93 = a_all17 >> 8;
                x_d2f93 = (uint8_t)x_ret27;
                y_d2f93 = (uint8_t)y_ret15;
                direct_page_d2f93 = dp_ret15;
                data_bank_d2f93 = db_ret12;
                goto shared_D2F9_2;
            } else {
                a_d2f94 = (uint8_t)a_all17;
                a_hi_d2f94 = a_all17 >> 8;
                x_d2f94 = x_ret27;
                y_d2f94 = y_ret15;
                direct_page_d2f94 = dp_ret15;
                data_bank_d2f94 = db_ret12;
                goto shared_D2F9_3;
            }
        }
    } else {
        uint16_t value4 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x0311);
        r->a = value4;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->mf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2A4, 0x7EB258); GUARD_JSR(c, sp_call, 0xD2A4); } /* append_pending_record */
        r->sp += 3;
        r->x = 0x010E;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2AA, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD2AA); } /* dispatch_parent_messages */
        r->sp += 3;
        uint16_t dp_ret17 = r->dp;
        uint8_t db_ret14 = r->db;
        bool x_ret29 = r->xf;
        uint16_t a_all19 = r->a;
        uint16_t x_ret30 = r->x;
        uint16_t y_ret17 = r->y;
        if ((uint8_t)a_all19 == 0) {
            if (x_ret29) {
                a_d2f9 = (uint8_t)a_all19;
                a_hi_d2f9 = a_all19 >> 8;
                x_d2f9 = (uint8_t)x_ret30;
                y_d2f9 = (uint8_t)y_ret17;
                direct_page_d2f9 = dp_ret17;
                data_bank_d2f9 = db_ret14;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all19;
                a_hi_d2f92 = a_all19 >> 8;
                x_d2f92 = x_ret30;
                y_d2f92 = y_ret17;
                direct_page_d2f92 = dp_ret17;
                data_bank_d2f92 = db_ret14;
                goto shared_D2F9_1;
            }
        }
        r->c = (uint8_t)a_all19 >= 0;
        r->z = (uint8_t)a_all19 == 0;
        r->n = (uint8_t)a_all19 & 0x80;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2B1, 0x7ED1DA); GUARD_JSR(c, sp_call, 0xD2B1); } /* fade_parent_display_until_control_exit */
        r->sp += 3;
        uint16_t dp_ret18 = r->dp;
        uint8_t db_ret15 = r->db;
        uint16_t a_all20 = r->a;
        uint16_t x_ret31 = r->x;
        uint16_t y_ret18 = r->y;
        if ((uint8_t)a_all20 == 0) {
            a_d2f92 = (uint8_t)a_all20;
            a_hi_d2f92 = a_all20 >> 8;
            x_d2f92 = x_ret31;
            y_d2f92 = y_ret18;
            direct_page_d2f92 = dp_ret18;
            data_bank_d2f92 = db_ret15;
            goto shared_D2F9_1;
        }
        r->x = 0;
        r->c = (uint8_t)a_all20 >= 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2BB, 0x7ECD82); GUARD_JSR(c, sp_call, 0xD2BB); } /* copy_and_submit_title_tilemap */
        r->sp += 3;
        r->x = 0x1E;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2C1, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD2C1); } /* dispatch_parent_messages */
        r->sp += 3;
        uint16_t dp_ret20 = r->dp;
        uint8_t db_ret16 = r->db;
        bool x_ret33 = r->xf;
        uint16_t a_all22 = r->a;
        uint16_t x_ret34 = r->x;
        uint16_t y_ret20 = r->y;
        if ((uint8_t)a_all22 == 0) {
            if (x_ret33) {
                a_d2f9 = (uint8_t)a_all22;
                a_hi_d2f9 = a_all22 >> 8;
                x_d2f9 = (uint8_t)x_ret34;
                y_d2f9 = (uint8_t)y_ret20;
                direct_page_d2f9 = dp_ret20;
                data_bank_d2f9 = db_ret16;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all22;
                a_hi_d2f92 = a_all22 >> 8;
                x_d2f92 = x_ret34;
                y_d2f92 = y_ret20;
                direct_page_d2f92 = dp_ret20;
                data_bank_d2f92 = db_ret16;
                goto shared_D2F9_1;
            }
        }
        RAM8(0x1E00) = 1;
        RAM8(0x1E01) = 0x2C;
        RAM8(0x1E02) = 0x0F;
        RAM8(0x1E03) = 0x0F;
        r->a = (a_all22 >> 8 << 8) | 0x0F;
        r->c = (uint8_t)a_all22 >= 0;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD2E1, 0xC30004); GUARD_JSL(c, sp_call, 0xD2E1); } /* audio_command_sender_public_jump */
        r->sp += 3;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2E4, 0x7ED20D); GUARD_JSR(c, sp_call, 0xD2E4); } /* fade_parent_display_in */
        r->sp += 3;
        uint16_t dp_ret21 = r->dp;
        uint8_t db_ret17 = r->db;
        uint16_t a_all24 = r->a;
        uint16_t x_ret37 = r->x;
        uint16_t y_ret22 = r->y;
        if ((uint8_t)a_all24 == 0) {
            a_d2f92 = (uint8_t)a_all24;
            a_hi_d2f92 = a_all24 >> 8;
            x_d2f92 = x_ret37;
            y_d2f92 = y_ret22;
            direct_page_d2f92 = dp_ret21;
            data_bank_d2f92 = db_ret17;
            goto shared_D2F9_1;
        }
        BUS8_SET(c, (db_ret17 << 0x10) + 0x0317, 1);
        r->a = (a_all24 >> 8 << 8) | 0x7E;
        r->x = 0x5EAA;
        r->c = (uint8_t)a_all24 >= 0;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2F5, 0x7EAB88); GUARD_JSR(c, sp_call, 0xD2F5); } /* create_and_enqueue_task */
        r->sp += 3;
        uint16_t dp_ret22 = r->dp;
        uint8_t db_ret18 = r->db;
        bool m_ret14 = r->mf;
        bool x_ret38 = r->xf;
        uint16_t a_all25 = r->a;
        uint16_t x_ret39 = r->x;
        uint16_t y_ret23 = r->y;
        if (m_ret14) {
            BUS8_SET(c, (db_ret18 << 0x10) + 0x0312, (uint8_t)a_all25);
            if (x_ret38) {
                a_d2f9 = (uint8_t)a_all25;
                a_hi_d2f9 = a_all25 >> 8;
                x_d2f9 = (uint8_t)x_ret39;
                y_d2f9 = (uint8_t)y_ret23;
                direct_page_d2f9 = dp_ret22;
                data_bank_d2f9 = db_ret18;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all25;
                a_hi_d2f92 = a_all25 >> 8;
                x_d2f92 = x_ret39;
                y_d2f92 = y_ret23;
                direct_page_d2f92 = dp_ret22;
                data_bank_d2f92 = db_ret18;
                goto shared_D2F9_1;
            }
        } else {
            BUS16_SET(c, (db_ret18 << 0x10) + 0x0312, a_all25);
            if (x_ret38) {
                a_d2f93 = (uint8_t)a_all25;
                a_hi_d2f93 = a_all25 >> 8;
                x_d2f93 = (uint8_t)x_ret39;
                y_d2f93 = (uint8_t)y_ret23;
                direct_page_d2f93 = dp_ret22;
                data_bank_d2f93 = db_ret18;
                goto shared_D2F9_2;
            } else {
                a_d2f94 = (uint8_t)a_all25;
                a_hi_d2f94 = a_all25 >> 8;
                x_d2f94 = x_ret39;
                y_d2f94 = y_ret23;
                direct_page_d2f94 = dp_ret22;
                data_bank_d2f94 = db_ret18;
                goto shared_D2F9_3;
            }
        }
    }
    shared_D273_1:;
    RAM8(0x1E00) = 1;
    RAM8(0x1E01) = 0x2D;
    RAM8(0x1E02) = 0x0B;
    RAM8(0x1E03) = 0x0F;
    r->a = (a_hi_d2732 << 8) | 0x0F;
    r->x = x_d2732;
    r->y = y_d2732;
    r->c = carry_d2732;
    r->z = 0;
    r->n = 0;
    r->v = overflow_d2732;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_d2732;
    r->dp = direct_page_d2732;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSL(c, 0xD28E, 0xC30004); GUARD_JSL(c, sp_call, 0xD28E); } /* audio_command_sender_public_jump */
    r->sp += 3;
    r->x = 0x7FFF;
    r->z = 0;
    r->n = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD294, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD294); } /* dispatch_parent_messages */
    r->sp += 3;
    uint16_t dp_ret23 = r->dp;
    uint8_t db_ret19 = r->db;
    bool x_ret41 = r->xf;
    uint16_t a_all27 = r->a;
    uint16_t x_ret42 = r->x;
    uint16_t y_ret25 = r->y;
    if ((uint8_t)a_all27 == 0) {
        if (x_ret41) {
            a_d2f9 = (uint8_t)a_all27;
            a_hi_d2f9 = a_all27 >> 8;
            x_d2f9 = (uint8_t)x_ret42;
            y_d2f9 = (uint8_t)y_ret25;
            direct_page_d2f9 = dp_ret23;
            data_bank_d2f9 = db_ret19;
            goto shared_D2F9;
        } else {
            a_d2f92 = (uint8_t)a_all27;
            a_hi_d2f92 = a_all27 >> 8;
            x_d2f92 = x_ret42;
            y_d2f92 = y_ret25;
            direct_page_d2f92 = dp_ret23;
            data_bank_d2f92 = db_ret19;
            goto shared_D2F9_1;
        }
    }
    r->c = (uint8_t)a_all27 >= 0;
    r->z = (uint8_t)a_all27 == 0;
    r->n = (uint8_t)a_all27 & 0x80;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD29B, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xD29B); } /* release_eight_byte_record */
    r->sp += 3;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD29E, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xD29E); } /* allocate_eight_byte_record */
    r->sp += 3;
    uint8_t db_ret21 = r->db;
    bool m_ret17 = r->mf;
    uint16_t a_all29 = r->a;
    if (m_ret17) {
        uint8_t value5 = BUS8_RDP(c, (db_ret21 << 0x10) + 0x0311);
        r->a = (a_all29 >> 8 << 8) | value5;
        r->z = value5 == 0;
        r->n = value5 & 0x80;
        r->mf = 1;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2A4, 0x7EB258); GUARD_JSR(c, sp_call, 0xD2A4); } /* append_pending_record */
        r->sp += 3;
        r->x = 0x010E;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2AA, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD2AA); } /* dispatch_parent_messages */
        r->sp += 3;
        uint16_t dp_ret27 = r->dp;
        uint8_t db_ret23 = r->db;
        bool x_ret47 = r->xf;
        uint16_t a_all31 = r->a;
        uint16_t x_ret48 = r->x;
        uint16_t y_ret27 = r->y;
        if ((uint8_t)a_all31 == 0) {
            if (x_ret47) {
                a_d2f9 = (uint8_t)a_all31;
                a_hi_d2f9 = a_all31 >> 8;
                x_d2f9 = (uint8_t)x_ret48;
                y_d2f9 = (uint8_t)y_ret27;
                direct_page_d2f9 = dp_ret27;
                data_bank_d2f9 = db_ret23;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all31;
                a_hi_d2f92 = a_all31 >> 8;
                x_d2f92 = x_ret48;
                y_d2f92 = y_ret27;
                direct_page_d2f92 = dp_ret27;
                data_bank_d2f92 = db_ret23;
                goto shared_D2F9_1;
            }
        }
        r->c = (uint8_t)a_all31 >= 0;
        r->z = (uint8_t)a_all31 == 0;
        r->n = (uint8_t)a_all31 & 0x80;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2B1, 0x7ED1DA); GUARD_JSR(c, sp_call, 0xD2B1); } /* fade_parent_display_until_control_exit */
        r->sp += 3;
        uint16_t dp_ret28 = r->dp;
        uint8_t db_ret24 = r->db;
        uint16_t a_all32 = r->a;
        uint16_t x_ret49 = r->x;
        uint16_t y_ret28 = r->y;
        if ((uint8_t)a_all32 == 0) {
            a_d2f92 = (uint8_t)a_all32;
            a_hi_d2f92 = a_all32 >> 8;
            x_d2f92 = x_ret49;
            y_d2f92 = y_ret28;
            direct_page_d2f92 = dp_ret28;
            data_bank_d2f92 = db_ret24;
            goto shared_D2F9_1;
        }
        r->x = 0;
        r->c = (uint8_t)a_all32 >= 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2BB, 0x7ECD82); GUARD_JSR(c, sp_call, 0xD2BB); } /* copy_and_submit_title_tilemap */
        r->sp += 3;
        r->x = 0x1E;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2C1, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD2C1); } /* dispatch_parent_messages */
        r->sp += 3;
        uint16_t dp_ret30 = r->dp;
        uint8_t db_ret25 = r->db;
        bool x_ret51 = r->xf;
        uint16_t a_all34 = r->a;
        uint16_t x_ret52 = r->x;
        uint16_t y_ret30 = r->y;
        if ((uint8_t)a_all34 == 0) {
            if (x_ret51) {
                a_d2f9 = (uint8_t)a_all34;
                a_hi_d2f9 = a_all34 >> 8;
                x_d2f9 = (uint8_t)x_ret52;
                y_d2f9 = (uint8_t)y_ret30;
                direct_page_d2f9 = dp_ret30;
                data_bank_d2f9 = db_ret25;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all34;
                a_hi_d2f92 = a_all34 >> 8;
                x_d2f92 = x_ret52;
                y_d2f92 = y_ret30;
                direct_page_d2f92 = dp_ret30;
                data_bank_d2f92 = db_ret25;
                goto shared_D2F9_1;
            }
        }
        RAM8(0x1E00) = 1;
        RAM8(0x1E01) = 0x2C;
        RAM8(0x1E02) = 0x0F;
        RAM8(0x1E03) = 0x0F;
        r->a = (a_all34 >> 8 << 8) | 0x0F;
        r->c = (uint8_t)a_all34 >= 0;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD2E1, 0xC30004); GUARD_JSL(c, sp_call, 0xD2E1); } /* audio_command_sender_public_jump */
        r->sp += 3;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2E4, 0x7ED20D); GUARD_JSR(c, sp_call, 0xD2E4); } /* fade_parent_display_in */
        r->sp += 3;
        uint16_t dp_ret31 = r->dp;
        uint8_t db_ret26 = r->db;
        uint16_t a_all36 = r->a;
        uint16_t x_ret55 = r->x;
        uint16_t y_ret32 = r->y;
        if ((uint8_t)a_all36 == 0) {
            a_d2f92 = (uint8_t)a_all36;
            a_hi_d2f92 = a_all36 >> 8;
            x_d2f92 = x_ret55;
            y_d2f92 = y_ret32;
            direct_page_d2f92 = dp_ret31;
            data_bank_d2f92 = db_ret26;
            goto shared_D2F9_1;
        }
        BUS8_SET(c, (db_ret26 << 0x10) + 0x0317, 1);
        r->a = (a_all36 >> 8 << 8) | 0x7E;
        r->x = 0x5EAA;
        r->c = (uint8_t)a_all36 >= 0;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2F5, 0x7EAB88); GUARD_JSR(c, sp_call, 0xD2F5); } /* create_and_enqueue_task */
        r->sp += 3;
        uint16_t dp_ret32 = r->dp;
        uint8_t db_ret27 = r->db;
        bool m_ret21 = r->mf;
        bool x_ret56 = r->xf;
        uint16_t a_all37 = r->a;
        uint16_t x_ret57 = r->x;
        uint16_t y_ret33 = r->y;
        if (m_ret21) {
            BUS8_SET(c, (db_ret27 << 0x10) + 0x0312, (uint8_t)a_all37);
            if (x_ret56) {
                a_d2f9 = (uint8_t)a_all37;
                a_hi_d2f9 = a_all37 >> 8;
                x_d2f9 = (uint8_t)x_ret57;
                y_d2f9 = (uint8_t)y_ret33;
                direct_page_d2f9 = dp_ret32;
                data_bank_d2f9 = db_ret27;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all37;
                a_hi_d2f92 = a_all37 >> 8;
                x_d2f92 = x_ret57;
                y_d2f92 = y_ret33;
                direct_page_d2f92 = dp_ret32;
                data_bank_d2f92 = db_ret27;
                goto shared_D2F9_1;
            }
        } else {
            BUS16_SET(c, (db_ret27 << 0x10) + 0x0312, a_all37);
            if (x_ret56) {
                a_d2f93 = (uint8_t)a_all37;
                a_hi_d2f93 = a_all37 >> 8;
                x_d2f93 = (uint8_t)x_ret57;
                y_d2f93 = (uint8_t)y_ret33;
                direct_page_d2f93 = dp_ret32;
                data_bank_d2f93 = db_ret27;
                goto shared_D2F9_2;
            } else {
                a_d2f94 = (uint8_t)a_all37;
                a_hi_d2f94 = a_all37 >> 8;
                x_d2f94 = x_ret57;
                y_d2f94 = y_ret33;
                direct_page_d2f94 = dp_ret32;
                data_bank_d2f94 = db_ret27;
                goto shared_D2F9_3;
            }
        }
    } else {
        uint16_t value6 = BUS16_RDP(c, (db_ret21 << 0x10) + 0x0311);
        r->a = value6;
        r->z = value6 == 0;
        r->n = value6 & 0x8000;
        r->mf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2A4, 0x7EB258); GUARD_JSR(c, sp_call, 0xD2A4); } /* append_pending_record */
        r->sp += 3;
        r->x = 0x010E;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2AA, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD2AA); } /* dispatch_parent_messages */
        r->sp += 3;
        uint16_t dp_ret34 = r->dp;
        uint8_t db_ret29 = r->db;
        bool x_ret59 = r->xf;
        uint16_t a_all39 = r->a;
        uint16_t x_ret60 = r->x;
        uint16_t y_ret35 = r->y;
        if ((uint8_t)a_all39 == 0) {
            if (x_ret59) {
                a_d2f9 = (uint8_t)a_all39;
                a_hi_d2f9 = a_all39 >> 8;
                x_d2f9 = (uint8_t)x_ret60;
                y_d2f9 = (uint8_t)y_ret35;
                direct_page_d2f9 = dp_ret34;
                data_bank_d2f9 = db_ret29;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all39;
                a_hi_d2f92 = a_all39 >> 8;
                x_d2f92 = x_ret60;
                y_d2f92 = y_ret35;
                direct_page_d2f92 = dp_ret34;
                data_bank_d2f92 = db_ret29;
                goto shared_D2F9_1;
            }
        }
        r->c = (uint8_t)a_all39 >= 0;
        r->z = (uint8_t)a_all39 == 0;
        r->n = (uint8_t)a_all39 & 0x80;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2B1, 0x7ED1DA); GUARD_JSR(c, sp_call, 0xD2B1); } /* fade_parent_display_until_control_exit */
        r->sp += 3;
        uint16_t dp_ret35 = r->dp;
        uint8_t db_ret30 = r->db;
        uint16_t a_all40 = r->a;
        uint16_t x_ret61 = r->x;
        uint16_t y_ret36 = r->y;
        if ((uint8_t)a_all40 == 0) {
            a_d2f92 = (uint8_t)a_all40;
            a_hi_d2f92 = a_all40 >> 8;
            x_d2f92 = x_ret61;
            y_d2f92 = y_ret36;
            direct_page_d2f92 = dp_ret35;
            data_bank_d2f92 = db_ret30;
            goto shared_D2F9_1;
        }
        r->x = 0;
        r->c = (uint8_t)a_all40 >= 0;
        r->z = 1;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2BB, 0x7ECD82); GUARD_JSR(c, sp_call, 0xD2BB); } /* copy_and_submit_title_tilemap */
        r->sp += 3;
        r->x = 0x1E;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2C1, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD2C1); } /* dispatch_parent_messages */
        r->sp += 3;
        uint16_t dp_ret37 = r->dp;
        uint8_t db_ret31 = r->db;
        bool x_ret63 = r->xf;
        uint16_t a_all42 = r->a;
        uint16_t x_ret64 = r->x;
        uint16_t y_ret38 = r->y;
        if ((uint8_t)a_all42 == 0) {
            if (x_ret63) {
                a_d2f9 = (uint8_t)a_all42;
                a_hi_d2f9 = a_all42 >> 8;
                x_d2f9 = (uint8_t)x_ret64;
                y_d2f9 = (uint8_t)y_ret38;
                direct_page_d2f9 = dp_ret37;
                data_bank_d2f9 = db_ret31;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all42;
                a_hi_d2f92 = a_all42 >> 8;
                x_d2f92 = x_ret64;
                y_d2f92 = y_ret38;
                direct_page_d2f92 = dp_ret37;
                data_bank_d2f92 = db_ret31;
                goto shared_D2F9_1;
            }
        }
        RAM8(0x1E00) = 1;
        RAM8(0x1E01) = 0x2C;
        RAM8(0x1E02) = 0x0F;
        RAM8(0x1E03) = 0x0F;
        r->a = (a_all42 >> 8 << 8) | 0x0F;
        r->c = (uint8_t)a_all42 >= 0;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD2E1, 0xC30004); GUARD_JSL(c, sp_call, 0xD2E1); } /* audio_command_sender_public_jump */
        r->sp += 3;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2E4, 0x7ED20D); GUARD_JSR(c, sp_call, 0xD2E4); } /* fade_parent_display_in */
        r->sp += 3;
        uint16_t dp_ret38 = r->dp;
        uint8_t db_ret32 = r->db;
        uint16_t a_all44 = r->a;
        uint16_t x_ret67 = r->x;
        uint16_t y_ret40 = r->y;
        if ((uint8_t)a_all44 == 0) {
            a_d2f92 = (uint8_t)a_all44;
            a_hi_d2f92 = a_all44 >> 8;
            x_d2f92 = x_ret67;
            y_d2f92 = y_ret40;
            direct_page_d2f92 = dp_ret38;
            data_bank_d2f92 = db_ret32;
            goto shared_D2F9_1;
        }
        BUS8_SET(c, (db_ret32 << 0x10) + 0x0317, 1);
        r->a = (a_all44 >> 8 << 8) | 0x7E;
        r->x = 0x5EAA;
        r->c = (uint8_t)a_all44 >= 0;
        r->z = 0;
        r->n = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD2F5, 0x7EAB88); GUARD_JSR(c, sp_call, 0xD2F5); } /* create_and_enqueue_task */
        r->sp += 3;
        uint16_t dp_ret39 = r->dp;
        uint8_t db_ret33 = r->db;
        bool m_ret25 = r->mf;
        bool x_ret68 = r->xf;
        uint16_t a_all45 = r->a;
        uint16_t x_ret69 = r->x;
        uint16_t y_ret41 = r->y;
        if (m_ret25) {
            BUS8_SET(c, (db_ret33 << 0x10) + 0x0312, (uint8_t)a_all45);
            if (x_ret68) {
                a_d2f9 = (uint8_t)a_all45;
                a_hi_d2f9 = a_all45 >> 8;
                x_d2f9 = (uint8_t)x_ret69;
                y_d2f9 = (uint8_t)y_ret41;
                direct_page_d2f9 = dp_ret39;
                data_bank_d2f9 = db_ret33;
                goto shared_D2F9;
            } else {
                a_d2f92 = (uint8_t)a_all45;
                a_hi_d2f92 = a_all45 >> 8;
                x_d2f92 = x_ret69;
                y_d2f92 = y_ret41;
                direct_page_d2f92 = dp_ret39;
                data_bank_d2f92 = db_ret33;
                goto shared_D2F9_1;
            }
        } else {
            BUS16_SET(c, (db_ret33 << 0x10) + 0x0312, a_all45);
            if (x_ret68) {
                a_d2f93 = (uint8_t)a_all45;
                a_hi_d2f93 = a_all45 >> 8;
                x_d2f93 = (uint8_t)x_ret69;
                y_d2f93 = (uint8_t)y_ret41;
                direct_page_d2f93 = dp_ret39;
                data_bank_d2f93 = db_ret33;
                goto shared_D2F9_2;
            } else {
                a_d2f94 = (uint8_t)a_all45;
                a_hi_d2f94 = a_all45 >> 8;
                x_d2f94 = x_ret69;
                y_d2f94 = y_ret41;
                direct_page_d2f94 = dp_ret39;
                data_bank_d2f94 = db_ret33;
                goto shared_D2F9_3;
            }
        }
    }
    shared_D264:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_D264_1:;
    r->a = (a_hi_d2642 << 8) | a_d2642;
    r->x = 1;
    r->y = y_d2642;
    r->c = carry_d2642;
    r->z = 0;
    r->n = 0;
    r->v = overflow_d2642;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_d2642;
    r->dp = direct_page_d2642;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD269, 0x7ED17F); GUARD_JSR(c, sp_call, 0xD269); } /* dispatch_parent_messages */
    r->sp += 3;
    uint16_t dp_ret40 = r->dp;
    uint8_t db_ret34 = r->db;
    bool x_ret70 = r->xf;
    uint16_t a_all46 = r->a;
    uint16_t x_ret71 = r->x;
    uint16_t y_ret42 = r->y;
    bool overflow_ret46 = r->v;
    if ((uint8_t)a_all46 == 0) {
        if (x_ret70) {
            a_d25c = (uint8_t)a_all46;
            a_hi_d25c = a_all46 >> 8;
            x_d25c = (uint8_t)x_ret71;
            y_d25c = (uint8_t)y_ret42;
            direct_page_d25c = dp_ret40;
            data_bank_d25c = db_ret34;
            goto shared_D25C;
        } else {
            a_d25c2 = (uint8_t)a_all46;
            a_hi_d25c2 = a_all46 >> 8;
            x_d25c2 = x_ret71;
            y_d25c2 = y_ret42;
            direct_page_d25c2 = dp_ret40;
            data_bank_d25c2 = db_ret34;
            goto shared_D25C_1;
        }
    }
    uint8_t value7 = BUS8_RDP(c, (db_ret34 << 0x10) + 0x0316);
    if (value7 == 0) {
        if (x_ret70) {
            a_d264 = value7;
            a_hi_d264 = a_all46 >> 8;
            y_d264 = (uint8_t)y_ret42;
            carry_d264 = (uint8_t)a_all46 >= 0;
            overflow_d264 = overflow_ret46;
            direct_page_d264 = dp_ret40;
            data_bank_d264 = db_ret34;
            goto shared_D264;
        } else {
            a_d2642 = value7;
            a_hi_d2642 = a_all46 >> 8;
            y_d2642 = y_ret42;
            carry_d2642 = (uint8_t)a_all46 >= 0;
            overflow_d2642 = overflow_ret46;
            direct_page_d2642 = dp_ret40;
            data_bank_d2642 = db_ret34;
            goto shared_D264_1;
        }
    }
    if (x_ret70) {
        a_hi_d273 = a_all46 >> 8;
        x_d273 = (uint8_t)x_ret71;
        y_d273 = (uint8_t)y_ret42;
        carry_d273 = (uint8_t)a_all46 >= 0;
        overflow_d273 = overflow_ret46;
        direct_page_d273 = dp_ret40;
        data_bank_d273 = db_ret34;
        goto shared_D273;
    } else {
        a_hi_d2732 = a_all46 >> 8;
        x_d2732 = x_ret71;
        y_d2732 = y_ret42;
        carry_d2732 = (uint8_t)a_all46 >= 0;
        overflow_d2732 = overflow_ret46;
        direct_page_d2732 = dp_ret40;
        data_bank_d2732 = db_ret34;
        goto shared_D273_1;
    }
    shared_D25C:;
    a_d2f9 = a_d25c;
    a_hi_d2f9 = a_hi_d25c;
    x_d2f9 = x_d25c;
    y_d2f9 = y_d25c;
    direct_page_d2f9 = direct_page_d25c;
    data_bank_d2f9 = data_bank_d25c;
    goto shared_D2F9;
    shared_D25C_1:;
    a_d2f92 = a_d25c2;
    a_hi_d2f92 = a_hi_d25c2;
    x_d2f92 = x_d25c2;
    y_d2f92 = y_d25c2;
    direct_page_d2f92 = direct_page_d25c2;
    data_bank_d2f92 = data_bank_d25c2;
    goto shared_D2F9_1;
    shared_D2F9:;
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->a = (a_hi_d2f9 << 8) | a_d2f9;
    r->x = x_d2f9;
    r->y = y_d2f9;
    r->v = value8 & 0x40;
    r->mf = value8 & 0x20;
    r->xf = value8 & 0x10;
    r->db = data_bank_d2f9;
    r->dp = (value10 << 8) | value9;
    r->i = value8 & 0x04;
    r->d = value8 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_D2F9_1:;
    uint8_t value11 = RAM8(0x0000 + sp0 - 2);
    uint8_t value12 = RAM8(0x0000 + sp0 - 1);
    uint8_t value13 = RAM8(0x0000 + sp0);
    r->a = (a_hi_d2f92 << 8) | a_d2f92;
    r->x = x_d2f92;
    r->y = y_d2f92;
    r->v = value11 & 0x40;
    r->mf = value11 & 0x20;
    r->xf = value11 & 0x10;
    r->db = data_bank_d2f92;
    r->dp = (value13 << 8) | value12;
    r->i = value11 & 0x04;
    r->d = value11 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_D2F9_2:;
    uint8_t value14 = RAM8(0x0000 + sp0 - 2);
    uint8_t value15 = RAM8(0x0000 + sp0 - 1);
    uint8_t value16 = RAM8(0x0000 + sp0);
    r->a = (a_hi_d2f93 << 8) | a_d2f93;
    r->x = x_d2f93;
    r->y = y_d2f93;
    r->v = value14 & 0x40;
    r->mf = value14 & 0x20;
    r->xf = value14 & 0x10;
    r->db = data_bank_d2f93;
    r->dp = (value16 << 8) | value15;
    r->i = value14 & 0x04;
    r->d = value14 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_D2F9_3:;
    uint8_t value17 = RAM8(0x0000 + sp0 - 2);
    uint8_t value18 = RAM8(0x0000 + sp0 - 1);
    uint8_t value19 = RAM8(0x0000 + sp0);
    r->a = (a_hi_d2f94 << 8) | a_d2f94;
    r->x = x_d2f94;
    r->y = y_d2f94;
    r->v = value17 & 0x40;
    r->mf = value17 & 0x20;
    r->xf = value17 & 0x10;
    r->db = data_bank_d2f94;
    r->dp = (value19 << 8) | value18;
    r->i = value17 & 0x04;
    r->d = value17 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED23E, SOM_RTS, "gen", run_title_parent_sequence, 0, L_A | L_B | L_X | L_Y | L_V, 3, 1, 0, 190, 73)
