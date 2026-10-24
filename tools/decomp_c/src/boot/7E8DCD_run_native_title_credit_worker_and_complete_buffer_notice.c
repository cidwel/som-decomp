#include "som_c.h"

/* 7E8DCD run_native_title_credit_worker_and_complete_buffer_notice   [class B, 199 bytes, 91 instructions]
 * Source: src/boot/run_native_title_credit_worker_and_complete_buffer_notice.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$0000.  Callers read: ABXYCZNV.
 */
static void run_native_title_credit_worker_and_complete_buffer_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a_8e0f = 0;
    uint8_t a_hi_8e0f = 0;
    uint16_t x_8e0f = 0;
    bool carry_8e0f = 0;
    bool overflow_8e0f = 0;
    uint16_t direct_page_8e0f = 0;
    uint8_t data_bank_8e0f = 0;
    uint8_t a_8e66 = 0;
    uint8_t a_hi_8e66 = 0;
    bool carry_8e66 = 0;
    bool overflow_8e66 = 0;
    uint16_t direct_page_8e66 = 0;
    uint8_t data_bank_8e66 = 0;
    uint8_t a_8e662 = 0;
    uint8_t a_hi_8e662 = 0;
    bool carry_8e662 = 0;
    bool overflow_8e662 = 0;
    uint16_t direct_page_8e662 = 0;
    uint8_t data_bank_8e662 = 0;
    uint8_t a_8e24 = 0;
    uint8_t a_hi_8e24 = 0;
    uint16_t y_8e24 = 0;
    bool carry_8e24 = 0;
    bool overflow_8e24 = 0;
    uint16_t direct_page_8e24 = 0;
    uint8_t data_bank_8e24 = 0;
    uint8_t a_8e242 = 0;
    uint8_t a_hi_8e242 = 0;
    uint8_t y_8e242 = 0;
    bool carry_8e242 = 0;
    bool overflow_8e242 = 0;
    uint16_t direct_page_8e242 = 0;
    uint8_t data_bank_8e242 = 0;
    uint8_t a_8e49 = 0;
    uint8_t a_hi_8e49 = 0;
    uint16_t y_8e49 = 0;
    bool carry_8e49 = 0;
    bool overflow_8e49 = 0;
    uint16_t direct_page_8e49 = 0;
    uint8_t data_bank_8e49 = 0;
    uint8_t a_8e492 = 0;
    uint8_t a_hi_8e492 = 0;
    uint8_t y_8e492 = 0;
    bool carry_8e492 = 0;
    bool overflow_8e492 = 0;
    uint16_t direct_page_8e492 = 0;
    uint8_t data_bank_8e492 = 0;
    uint8_t a_8e0f2 = 0;
    uint8_t a_hi_8e0f2 = 0;
    uint8_t x_8e0f2 = 0;
    bool carry_8e0f2 = 0;
    bool overflow_8e0f2 = 0;
    uint16_t direct_page_8e0f2 = 0;
    uint8_t data_bank_8e0f2 = 0;
    uint8_t a_8e663 = 0;
    uint8_t a_hi_8e663 = 0;
    bool carry_8e663 = 0;
    bool overflow_8e663 = 0;
    uint16_t direct_page_8e663 = 0;
    uint8_t data_bank_8e663 = 0;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = (uint16_t)(sp0 - 0x0C);
    r->c = (uint16_t)(sp0 - 3) >= 9;
    r->z = (uint16_t)(sp0 - 0x0C) == 0;
    r->n = (uint16_t)(sp0 - 0x0C) & 0x8000;
    r->v = (((uint16_t)(sp0 - 3) ^ 9) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0C)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0C);
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8DDC, 0x7EACD0); GUARD_JSR(c, sp_call, 0x8DDC); } /* current_task_parent_id */
    r->sp += 12;
    uint16_t dp_ret = r->dp;
    bool m_ret = r->mf;
    uint16_t a_all = r->a;
    if (m_ret) {
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)a_all);
        r->mf = 1;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8DE1, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x8DE1); } /* allocate_eight_byte_record */
        r->sp += 12;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        BUS8_SET(c, (db_ret2 << 0x10) + 3 + x_ret4, 1);
        uint8_t value = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
        r->a = (a_all2 >> 8 << 8) | value;
        r->z = value == 0;
        r->n = value & 0x80;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8DEB, 0x7EB258); GUARD_JSR(c, sp_call, 0x8DEB); } /* append_pending_record */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8DEE, 0x7EB2FB); GUARD_JSR(c, sp_call, 0x8DEE); } /* receive_raw_task_record */
        r->sp += 12;
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        uint16_t x_ret8 = r->x;
        uint16_t value2 = BUS16_RDP(c, (db_ret4 << 0x10) + 4 + x_ret8);
        BUS16_SET(c, (uint16_t)(dp_ret4 + 2), value2);
        BUS16_SET(c, (uint16_t)(dp_ret4 + 4), (uint16_t)(value2 + 0x0440));
        r->a = (uint16_t)(value2 + 0x0440);
        r->c = value2 + 0x0440 > 0xFFFF;
        r->z = (uint16_t)(value2 + 0x0440) == 0;
        r->n = (uint16_t)(value2 + 0x0440) & 0x8000;
        r->v = ((value2 ^ (uint16_t)(value2 + 0x0440)) & ((uint16_t)(value2 + 0x0440) ^ 0x0440) & 0x8000) != 0;
        r->mf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8DFE, 0x7EB1DD); GUARD_JSR(c, sp_call, 0x8DFE); } /* release_eight_byte_record */
        r->sp += 12;
        if (r->xf != 0) { c->fail = 3; return; }
        r->x = 0x3C;
        r->z = 0;
        r->n = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E04, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8E04); } /* wait_for_native_title_timer_with_pause_clear */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E07, 0x7E8AB5); GUARD_JSR(c, sp_call, 0x8E07); } /* construct_four_title_colour_hdma_channels */
        r->sp += 12;
        uint16_t dp_ret7 = r->dp;
        uint8_t db_ret6 = r->db;
        bool x_ret11 = r->xf;
        uint16_t a_all7 = r->a;
        bool carry_ret7 = r->c;
        bool overflow_ret7 = r->v;
        if (x_ret11) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            BUS16_SET(c, (uint16_t)(dp_ret7 + 8), 0x01BE);
            a_8e0f = (uint8_t)a_all7;
            a_hi_8e0f = a_all7 >> 8;
            x_8e0f = 0x01BE;
            carry_8e0f = carry_ret7;
            overflow_8e0f = overflow_ret7;
            direct_page_8e0f = dp_ret7;
            data_bank_8e0f = db_ret6;
            goto shared_8E0F;
        }
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret + 1), a_all);
        r->mf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8DE1, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x8DE1); } /* allocate_eight_byte_record */
        r->sp += 12;
        uint16_t dp_ret8 = r->dp;
        uint8_t db_ret7 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all8 = r->a;
        uint16_t x_ret14 = r->x;
        BUS8_SET(c, (db_ret7 << 0x10) + 3 + x_ret14, 1);
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 1));
        r->a = (a_all8 >> 8 << 8) | value3;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8DEB, 0x7EB258); GUARD_JSR(c, sp_call, 0x8DEB); } /* append_pending_record */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8DEE, 0x7EB2FB); GUARD_JSR(c, sp_call, 0x8DEE); } /* receive_raw_task_record */
        r->sp += 12;
        uint16_t dp_ret10 = r->dp;
        uint8_t db_ret9 = r->db;
        uint16_t x_ret18 = r->x;
        uint16_t value4 = BUS16_RDP(c, (db_ret9 << 0x10) + 4 + x_ret18);
        BUS16_SET(c, (uint16_t)(dp_ret10 + 2), value4);
        BUS16_SET(c, (uint16_t)(dp_ret10 + 4), (uint16_t)(value4 + 0x0440));
        r->a = (uint16_t)(value4 + 0x0440);
        r->c = value4 + 0x0440 > 0xFFFF;
        r->z = (uint16_t)(value4 + 0x0440) == 0;
        r->n = (uint16_t)(value4 + 0x0440) & 0x8000;
        r->v = ((value4 ^ (uint16_t)(value4 + 0x0440)) & ((uint16_t)(value4 + 0x0440) ^ 0x0440) & 0x8000) != 0;
        r->mf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8DFE, 0x7EB1DD); GUARD_JSR(c, sp_call, 0x8DFE); } /* release_eight_byte_record */
        r->sp += 12;
        if (r->xf != 0) { c->fail = 3; return; }
        r->x = 0x3C;
        r->z = 0;
        r->n = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E04, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8E04); } /* wait_for_native_title_timer_with_pause_clear */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E07, 0x7E8AB5); GUARD_JSR(c, sp_call, 0x8E07); } /* construct_four_title_colour_hdma_channels */
        r->sp += 12;
        uint16_t dp_ret13 = r->dp;
        uint8_t db_ret11 = r->db;
        bool x_ret21 = r->xf;
        uint16_t a_all13 = r->a;
        bool carry_ret13 = r->c;
        bool overflow_ret13 = r->v;
        if (x_ret21) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            BUS16_SET(c, (uint16_t)(dp_ret13 + 8), 0x01BE);
            a_8e0f = (uint8_t)a_all13;
            a_hi_8e0f = a_all13 >> 8;
            x_8e0f = 0x01BE;
            carry_8e0f = carry_ret13;
            overflow_8e0f = overflow_ret13;
            direct_page_8e0f = dp_ret13;
            data_bank_8e0f = db_ret11;
            goto shared_8E0F;
        }
    }
    shared_8E0F:;
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(direct_page_8e0f + 4));
    r->a = (a_hi_8e0f << 8) | a_8e0f;
    r->x = x_8e0f;
    r->y = value5;
    r->c = carry_8e0f;
    r->z = value5 == 0;
    r->n = value5 & 0x8000;
    r->v = overflow_8e0f;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_8e0f;
    r->dp = direct_page_8e0f;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8E13, 0x7E8820); GUARD_JSR(c, sp_call, 0x8E13); } /* expand_title_text_row */
    r->sp += 12;
    uint16_t dp_ret14 = r->dp;
    bool m_ret12 = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all14 = r->a;
    uint16_t x_ret23 = r->x;
    bool overflow_ret14 = r->v;
    if (x_ret23 == 0) {
        if (m_ret12) {
            a_8e66 = (uint8_t)a_all14;
            a_hi_8e66 = a_all14 >> 8;
            carry_8e66 = x_ret23 >= 0;
            overflow_8e66 = overflow_ret14;
            direct_page_8e66 = dp_ret14;
            data_bank_8e66 = data_bank_8e0f;
            goto shared_8E66;
        } else {
            a_8e662 = (uint8_t)a_all14;
            a_hi_8e662 = a_all14 >> 8;
            carry_8e662 = x_ret23 >= 0;
            overflow_8e662 = overflow_ret14;
            direct_page_8e662 = dp_ret14;
            data_bank_8e662 = data_bank_8e0f;
            goto shared_8E66_1;
        }
    }
    BUS16_SET(c, (uint16_t)(dp_ret14 + 8), x_ret23);
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret14 + 2));
    r->x = value6;
    r->c = x_ret23 >= 0;
    r->z = value6 == 0;
    r->n = value6 & 0x8000;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8E1F, 0x7EC870); GUARD_JSR(c, sp_call, 0x8E1F); } /* queue_registered_vram_buffer */
    r->sp += 12;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all15 = r->a;
    uint16_t y_ret10 = r->y;
    bool carry_ret15 = r->c;
    bool overflow_ret15 = r->v;
    BUS8_SET(c, (uint16_t)(dp_ret14 + 6), 0x1F);
    a_8e24 = 0x1F;
    a_hi_8e24 = a_all15 >> 8;
    y_8e24 = y_ret10;
    carry_8e24 = carry_ret15;
    overflow_8e24 = overflow_ret15;
    direct_page_8e24 = dp_ret14;
    data_bank_8e24 = data_bank_8e0f;
    goto shared_8E24;
    shared_8E66:;
    uint16_t value7 = BUS16_RDP(c, (uint16_t)(direct_page_8e66 + 4));
    r->a = (a_hi_8e66 << 8) | a_8e66;
    r->x = 0x019E;
    r->y = value7;
    r->c = carry_8e66;
    r->z = value7 == 0;
    r->n = value7 & 0x8000;
    r->v = overflow_8e66;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_8e66;
    r->dp = direct_page_8e66;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8E6D, 0x7E8820); GUARD_JSR(c, sp_call, 0x8E6D); } /* expand_title_text_row */
    r->sp += 12;
    uint16_t dp_ret15 = r->dp;
    bool x_ret25 = r->xf;
    uint16_t y_ret11 = r->y;
    if (x_ret25) {
        uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret15 + 2));
        r->x = value8;
        r->y = (uint8_t)y_ret11;
        r->z = value8 == 0;
        r->n = value8 & 0x80;
        r->xf = 1;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E72, 0x7EC870); GUARD_JSR(c, sp_call, 0x8E72); } /* queue_registered_vram_buffer */
        r->sp += 12;
        if (r->xf != 0) { c->fail = 3; return; }
        r->x = 1;
        r->z = 0;
        r->n = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E78, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8E78); } /* wait_for_native_title_timer_with_pause_clear */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E7B, 0x7E8DAC); GUARD_JSR(c, sp_call, 0x8E7B); } /* release_native_auxiliary_credit_buffers_and_hdma */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E7E, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x8E7E); } /* allocate_eight_byte_record */
        r->sp += 12;
        uint16_t dp_ret18 = r->dp;
        uint8_t db_ret13 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all20 = r->a;
        uint16_t x_ret33 = r->x;
        BUS8_SET(c, (db_ret13 << 0x10) + 3 + x_ret33, 2);
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret18 + 1));
        r->a = (a_all20 >> 8 << 8) | value9;
        r->z = value9 == 0;
        r->n = value9 & 0x80;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E88, 0x7EB258); GUARD_JSR(c, sp_call, 0x8E88); } /* append_pending_record */
        r->sp += 12;
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        uint8_t value11 = RAM8(0x0000 + sp0 - 1);
        uint8_t value12 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
        r->c = value10 & 0x01;
        r->z = ((value12 << 8) | value11) == 0;
        r->n = ((value12 << 8) | value11) & 0x8000;
        r->v = value10 & 0x40;
        r->mf = value10 & 0x20;
        r->xf = value10 & 0x10;
        r->dp = (value12 << 8) | value11;
        r->i = value10 & 0x04;
        r->d = value10 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    } else {
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret15 + 2));
        r->x = value13;
        r->z = value13 == 0;
        r->n = value13 & 0x8000;
        r->xf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E72, 0x7EC870); GUARD_JSR(c, sp_call, 0x8E72); } /* queue_registered_vram_buffer */
        r->sp += 12;
        if (r->xf != 0) { c->fail = 3; return; }
        r->x = 1;
        r->z = 0;
        r->n = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E78, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8E78); } /* wait_for_native_title_timer_with_pause_clear */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E7B, 0x7E8DAC); GUARD_JSR(c, sp_call, 0x8E7B); } /* release_native_auxiliary_credit_buffers_and_hdma */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E7E, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x8E7E); } /* allocate_eight_byte_record */
        r->sp += 12;
        uint16_t dp_ret22 = r->dp;
        uint8_t db_ret16 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all25 = r->a;
        uint16_t x_ret42 = r->x;
        BUS8_SET(c, (db_ret16 << 0x10) + 3 + x_ret42, 2);
        uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret22 + 1));
        r->a = (a_all25 >> 8 << 8) | value14;
        r->z = value14 == 0;
        r->n = value14 & 0x80;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E88, 0x7EB258); GUARD_JSR(c, sp_call, 0x8E88); } /* append_pending_record */
        r->sp += 12;
        uint8_t value15 = RAM8(0x0000 + sp0 - 2);
        uint8_t value16 = RAM8(0x0000 + sp0 - 1);
        uint8_t value17 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
        r->c = value15 & 0x01;
        r->z = ((value17 << 8) | value16) == 0;
        r->n = ((value17 << 8) | value16) & 0x8000;
        r->v = value15 & 0x40;
        r->mf = value15 & 0x20;
        r->xf = value15 & 0x10;
        r->dp = (value17 << 8) | value16;
        r->i = value15 & 0x04;
        r->d = value15 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    shared_8E66_1:;
    uint16_t value18 = BUS16_RDP(c, (uint16_t)(direct_page_8e662 + 4));
    r->a = (a_hi_8e662 << 8) | a_8e662;
    r->x = 0x019E;
    r->y = value18;
    r->c = carry_8e662;
    r->z = value18 == 0;
    r->n = value18 & 0x8000;
    r->v = overflow_8e662;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_8e662;
    r->dp = direct_page_8e662;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8E6D, 0x7E8820); GUARD_JSR(c, sp_call, 0x8E6D); } /* expand_title_text_row */
    r->sp += 12;
    uint16_t dp_ret24 = r->dp;
    bool x_ret45 = r->xf;
    uint16_t y_ret20 = r->y;
    if (x_ret45) {
        uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret24 + 2));
        r->x = value19;
        r->y = (uint8_t)y_ret20;
        r->z = value19 == 0;
        r->n = value19 & 0x80;
        r->xf = 1;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E72, 0x7EC870); GUARD_JSR(c, sp_call, 0x8E72); } /* queue_registered_vram_buffer */
        r->sp += 12;
        if (r->xf != 0) { c->fail = 3; return; }
        r->x = 1;
        r->z = 0;
        r->n = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E78, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8E78); } /* wait_for_native_title_timer_with_pause_clear */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E7B, 0x7E8DAC); GUARD_JSR(c, sp_call, 0x8E7B); } /* release_native_auxiliary_credit_buffers_and_hdma */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E7E, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x8E7E); } /* allocate_eight_byte_record */
        r->sp += 12;
        uint16_t dp_ret27 = r->dp;
        uint8_t db_ret19 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all31 = r->a;
        uint16_t x_ret53 = r->x;
        BUS8_SET(c, (db_ret19 << 0x10) + 3 + x_ret53, 2);
        uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp_ret27 + 1));
        r->a = (a_all31 >> 8 << 8) | value20;
        r->z = value20 == 0;
        r->n = value20 & 0x80;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E88, 0x7EB258); GUARD_JSR(c, sp_call, 0x8E88); } /* append_pending_record */
        r->sp += 12;
        uint8_t value21 = RAM8(0x0000 + sp0 - 2);
        uint8_t value22 = RAM8(0x0000 + sp0 - 1);
        uint8_t value23 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
        r->c = value21 & 0x01;
        r->z = ((value23 << 8) | value22) == 0;
        r->n = ((value23 << 8) | value22) & 0x8000;
        r->v = value21 & 0x40;
        r->mf = value21 & 0x20;
        r->xf = value21 & 0x10;
        r->dp = (value23 << 8) | value22;
        r->i = value21 & 0x04;
        r->d = value21 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    } else {
        uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp_ret24 + 2));
        r->x = value24;
        r->z = value24 == 0;
        r->n = value24 & 0x8000;
        r->xf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E72, 0x7EC870); GUARD_JSR(c, sp_call, 0x8E72); } /* queue_registered_vram_buffer */
        r->sp += 12;
        if (r->xf != 0) { c->fail = 3; return; }
        r->x = 1;
        r->z = 0;
        r->n = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E78, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8E78); } /* wait_for_native_title_timer_with_pause_clear */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E7B, 0x7E8DAC); GUARD_JSR(c, sp_call, 0x8E7B); } /* release_native_auxiliary_credit_buffers_and_hdma */
        r->sp += 12;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E7E, 0x7EB1A9); GUARD_JSR(c, sp_call, 0x8E7E); } /* allocate_eight_byte_record */
        r->sp += 12;
        uint16_t dp_ret31 = r->dp;
        uint8_t db_ret22 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        uint16_t a_all36 = r->a;
        uint16_t x_ret62 = r->x;
        BUS8_SET(c, (db_ret22 << 0x10) + 3 + x_ret62, 2);
        uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp_ret31 + 1));
        r->a = (a_all36 >> 8 << 8) | value25;
        r->z = value25 == 0;
        r->n = value25 & 0x80;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E88, 0x7EB258); GUARD_JSR(c, sp_call, 0x8E88); } /* append_pending_record */
        r->sp += 12;
        uint8_t value26 = RAM8(0x0000 + sp0 - 2);
        uint8_t value27 = RAM8(0x0000 + sp0 - 1);
        uint8_t value28 = RAM8(0x0000 + sp0);
        r->a = (uint16_t)((uint16_t)(sp0 - 0x0C) + 9);
        r->c = value26 & 0x01;
        r->z = ((value28 << 8) | value27) == 0;
        r->n = ((value28 << 8) | value27) & 0x8000;
        r->v = value26 & 0x40;
        r->mf = value26 & 0x20;
        r->xf = value26 & 0x10;
        r->dp = (value28 << 8) | value27;
        r->i = value26 & 0x04;
        r->d = value26 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTL(c);
    }
    shared_8E24:;
    r->a = (a_hi_8e24 << 8) | a_8e24;
    r->x = 1;
    r->y = y_8e24;
    r->c = carry_8e24;
    r->z = 0;
    r->n = 0;
    r->v = overflow_8e24;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_8e24;
    r->dp = direct_page_8e24;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8E29, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8E29); } /* wait_for_native_title_timer_with_pause_clear */
    r->sp += 12;
    uint16_t dp_ret33 = r->dp;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret65 = r->xf;
    uint16_t a_all38 = r->a;
    uint16_t y_ret29 = r->y;
    uint8_t value29 = BUS8_RDP(c, (uint16_t)(dp_ret33 + 6));
    if (x_ret65) {
        r->a = ((a_all38 >> 8 << 8) | (uint8_t)((uint8_t)(0x20 - value29) << 1)) & 0xFF;
        r->x = ((a_all38 >> 8 << 8) | (uint8_t)((uint8_t)(0x20 - value29) << 1)) & 0xFF;
        r->y = (uint8_t)y_ret29;
        r->c = (uint8_t)(0x20 - value29) & 0x80;
        r->z = (((a_all38 >> 8 << 8) | (uint8_t)((uint8_t)(0x20 - value29) << 1)) & 0xFF) == 0;
        r->n = ((a_all38 >> 8 << 8) | (uint8_t)((uint8_t)(0x20 - value29) << 1)) & 0xFF & 0x80;
        r->v = ((value29 ^ 0x20) & ((uint8_t)(0x20 - value29) ^ 0x20) & 0x80) != 0;
        r->mf = 0;
        r->xf = 1;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E38, 0x7E8B5D); GUARD_JSR(c, sp_call, 0x8E38); } /* update_title_colour_at_offset7 */
        r->sp += 12;
        uint16_t dp_ret34 = r->dp;
        bool x_ret67 = r->xf;
        uint16_t a_all39 = r->a;
        bool carry_ret39 = r->c;
        bool overflow_ret39 = r->v;
        uint8_t value30 = BUS8_RDP(c, (uint16_t)(dp_ret34 + 6));
        BUS8_SET(c, (uint16_t)(dp_ret34 + 6), (uint8_t)(value30 - 1));
        if ((uint8_t)(value30 - 1) != 0) {
            if (x_ret67) {
                a_8e242 = (uint8_t)a_all39;
                a_hi_8e242 = a_all39 >> 8;
                y_8e242 = (uint8_t)y_ret29;
                carry_8e242 = carry_ret39;
                overflow_8e242 = overflow_ret39;
                direct_page_8e242 = dp_ret34;
                data_bank_8e242 = data_bank_8e24;
                goto shared_8E24_1;
            } else {
                a_8e24 = (uint8_t)a_all39;
                a_hi_8e24 = a_all39 >> 8;
                y_8e24 = (uint8_t)y_ret29;
                carry_8e24 = carry_ret39;
                overflow_8e24 = overflow_ret39;
                direct_page_8e24 = dp_ret34;
                goto shared_8E24;
            }
        }
        if (x_ret67) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->x = 0xF0;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8E44, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8E44); } /* wait_for_native_title_timer_with_pause_clear */
            r->sp += 12;
            uint16_t dp_ret35 = r->dp;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all40 = r->a;
            uint16_t y_ret30 = r->y;
            bool carry_ret40 = r->c;
            bool overflow_ret40 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret35 + 6), 0x1F);
            a_8e49 = 0x1F;
            a_hi_8e49 = a_all40 >> 8;
            y_8e49 = y_ret30;
            carry_8e49 = carry_ret40;
            overflow_8e49 = overflow_ret40;
            direct_page_8e49 = dp_ret35;
            data_bank_8e49 = data_bank_8e24;
            goto shared_8E49;
        }
    } else {
        r->a = ((a_all38 >> 8 << 8) | (uint8_t)((uint8_t)(0x20 - value29) << 1)) & 0xFF;
        r->x = ((a_all38 >> 8 << 8) | (uint8_t)((uint8_t)(0x20 - value29) << 1)) & 0xFF;
        r->c = (uint8_t)(0x20 - value29) & 0x80;
        r->z = (((a_all38 >> 8 << 8) | (uint8_t)((uint8_t)(0x20 - value29) << 1)) & 0xFF) == 0;
        r->n = ((a_all38 >> 8 << 8) | (uint8_t)((uint8_t)(0x20 - value29) << 1)) & 0xFF & 0x8000;
        r->v = ((value29 ^ 0x20) & ((uint8_t)(0x20 - value29) ^ 0x20) & 0x80) != 0;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8E38, 0x7E8B5D); GUARD_JSR(c, sp_call, 0x8E38); } /* update_title_colour_at_offset7 */
        r->sp += 12;
        uint16_t dp_ret36 = r->dp;
        bool x_ret70 = r->xf;
        uint16_t a_all41 = r->a;
        bool carry_ret41 = r->c;
        bool overflow_ret41 = r->v;
        uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp_ret36 + 6));
        BUS8_SET(c, (uint16_t)(dp_ret36 + 6), (uint8_t)(value31 - 1));
        if ((uint8_t)(value31 - 1) != 0) {
            if (x_ret70) {
                a_8e242 = (uint8_t)a_all41;
                a_hi_8e242 = a_all41 >> 8;
                y_8e242 = (uint8_t)y_ret29;
                carry_8e242 = carry_ret41;
                overflow_8e242 = overflow_ret41;
                direct_page_8e242 = dp_ret36;
                data_bank_8e242 = data_bank_8e24;
                goto shared_8E24_1;
            } else {
                a_8e24 = (uint8_t)a_all41;
                a_hi_8e24 = a_all41 >> 8;
                y_8e24 = y_ret29;
                carry_8e24 = carry_ret41;
                overflow_8e24 = overflow_ret41;
                direct_page_8e24 = dp_ret36;
                goto shared_8E24;
            }
        }
        if (x_ret70) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            r->x = 0xF0;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8E44, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8E44); } /* wait_for_native_title_timer_with_pause_clear */
            r->sp += 12;
            uint16_t dp_ret37 = r->dp;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all42 = r->a;
            uint16_t y_ret31 = r->y;
            bool carry_ret42 = r->c;
            bool overflow_ret42 = r->v;
            BUS8_SET(c, (uint16_t)(dp_ret37 + 6), 0x1F);
            a_8e49 = 0x1F;
            a_hi_8e49 = a_all42 >> 8;
            y_8e49 = y_ret31;
            carry_8e49 = carry_ret42;
            overflow_8e49 = overflow_ret42;
            direct_page_8e49 = dp_ret37;
            data_bank_8e49 = data_bank_8e24;
            goto shared_8E49;
        }
    }
    shared_8E24_1:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_8E49:;
    r->a = (a_hi_8e49 << 8) | a_8e49;
    r->x = 1;
    r->y = y_8e49;
    r->c = carry_8e49;
    r->z = 0;
    r->n = 0;
    r->v = overflow_8e49;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_8e49;
    r->dp = direct_page_8e49;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8E4E, 0x7E8B00); GUARD_JSR(c, sp_call, 0x8E4E); } /* wait_for_native_title_timer_with_pause_clear */
    r->sp += 12;
    uint16_t dp_ret38 = r->dp;
    bool m_ret33 = r->mf;
    bool x_ret73 = r->xf;
    uint16_t a_all43 = r->a;
    uint16_t y_ret32 = r->y;
    if (m_ret33) {
        uint8_t value32 = BUS8_RDP(c, (uint16_t)(dp_ret38 + 6));
        if (x_ret73) {
            r->a = ((a_all43 >> 8 << 8) | (uint8_t)((uint8_t)(value32 - 1) << 1)) & 0xFF;
            r->x = ((a_all43 >> 8 << 8) | (uint8_t)((uint8_t)(value32 - 1) << 1)) & 0xFF;
            r->y = (uint8_t)y_ret32;
            r->c = (uint8_t)(value32 - 1) & 0x80;
            r->z = (((a_all43 >> 8 << 8) | (uint8_t)((uint8_t)(value32 - 1) << 1)) & 0xFF) == 0;
            r->n = ((a_all43 >> 8 << 8) | (uint8_t)((uint8_t)(value32 - 1) << 1)) & 0xFF & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8E5B, 0x7E8B5D); GUARD_JSR(c, sp_call, 0x8E5B); } /* update_title_colour_at_offset7 */
            r->sp += 12;
            uint16_t dp_ret39 = r->dp;
            bool x_ret75 = r->xf;
            uint16_t a_all44 = r->a;
            bool carry_ret44 = r->c;
            bool overflow_ret44 = r->v;
            uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp_ret39 + 6));
            BUS8_SET(c, (uint16_t)(dp_ret39 + 6), (uint8_t)(value33 - 1));
            if ((uint8_t)(value33 - 1) != 0) {
                if (x_ret75) {
                    a_8e492 = (uint8_t)a_all44;
                    a_hi_8e492 = a_all44 >> 8;
                    y_8e492 = (uint8_t)y_ret32;
                    carry_8e492 = carry_ret44;
                    overflow_8e492 = overflow_ret44;
                    direct_page_8e492 = dp_ret39;
                    data_bank_8e492 = data_bank_8e49;
                    goto shared_8E49_1;
                } else {
                    a_8e49 = (uint8_t)a_all44;
                    a_hi_8e49 = a_all44 >> 8;
                    y_8e49 = (uint8_t)y_ret32;
                    carry_8e49 = carry_ret44;
                    overflow_8e49 = overflow_ret44;
                    direct_page_8e49 = dp_ret39;
                    goto shared_8E49;
                }
            }
            if (x_ret75) {
                uint8_t value34 = BUS8_RDP(c, (uint16_t)(dp_ret39 + 8));
                if (value34 != 0) {
                    a_8e0f2 = (uint8_t)a_all44;
                    a_hi_8e0f2 = a_all44 >> 8;
                    x_8e0f2 = value34;
                    carry_8e0f2 = carry_ret44;
                    overflow_8e0f2 = overflow_ret44;
                    direct_page_8e0f2 = dp_ret39;
                    data_bank_8e0f2 = data_bank_8e49;
                    goto shared_8E0F_1;
                }
                a_8e663 = (uint8_t)a_all44;
                a_hi_8e663 = a_all44 >> 8;
                carry_8e663 = carry_ret44;
                overflow_8e663 = overflow_ret44;
                direct_page_8e663 = dp_ret39;
                data_bank_8e663 = data_bank_8e49;
                goto shared_8E66_2;
            } else {
                uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp_ret39 + 8));
                if (value35 != 0) {
                    a_8e0f = (uint8_t)a_all44;
                    a_hi_8e0f = a_all44 >> 8;
                    x_8e0f = value35;
                    carry_8e0f = carry_ret44;
                    overflow_8e0f = overflow_ret44;
                    direct_page_8e0f = dp_ret39;
                    data_bank_8e0f = data_bank_8e49;
                    goto shared_8E0F;
                }
                a_8e66 = (uint8_t)a_all44;
                a_hi_8e66 = a_all44 >> 8;
                carry_8e66 = carry_ret44;
                overflow_8e66 = overflow_ret44;
                direct_page_8e66 = dp_ret39;
                data_bank_8e66 = data_bank_8e49;
                goto shared_8E66;
            }
        } else {
            r->a = ((a_all43 >> 8 << 8) | (uint8_t)((uint8_t)(value32 - 1) << 1)) & 0xFF;
            r->x = ((a_all43 >> 8 << 8) | (uint8_t)((uint8_t)(value32 - 1) << 1)) & 0xFF;
            r->c = (uint8_t)(value32 - 1) & 0x80;
            r->z = (((a_all43 >> 8 << 8) | (uint8_t)((uint8_t)(value32 - 1) << 1)) & 0xFF) == 0;
            r->n = ((a_all43 >> 8 << 8) | (uint8_t)((uint8_t)(value32 - 1) << 1)) & 0xFF & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8E5B, 0x7E8B5D); GUARD_JSR(c, sp_call, 0x8E5B); } /* update_title_colour_at_offset7 */
            r->sp += 12;
            uint16_t dp_ret40 = r->dp;
            bool x_ret77 = r->xf;
            uint16_t a_all45 = r->a;
            bool carry_ret45 = r->c;
            bool overflow_ret45 = r->v;
            uint8_t value36 = BUS8_RDP(c, (uint16_t)(dp_ret40 + 6));
            BUS8_SET(c, (uint16_t)(dp_ret40 + 6), (uint8_t)(value36 - 1));
            if ((uint8_t)(value36 - 1) != 0) {
                if (x_ret77) {
                    a_8e492 = (uint8_t)a_all45;
                    a_hi_8e492 = a_all45 >> 8;
                    y_8e492 = (uint8_t)y_ret32;
                    carry_8e492 = carry_ret45;
                    overflow_8e492 = overflow_ret45;
                    direct_page_8e492 = dp_ret40;
                    data_bank_8e492 = data_bank_8e49;
                    goto shared_8E49_1;
                } else {
                    a_8e49 = (uint8_t)a_all45;
                    a_hi_8e49 = a_all45 >> 8;
                    y_8e49 = y_ret32;
                    carry_8e49 = carry_ret45;
                    overflow_8e49 = overflow_ret45;
                    direct_page_8e49 = dp_ret40;
                    goto shared_8E49;
                }
            }
            if (x_ret77) {
                uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp_ret40 + 8));
                if (value37 != 0) {
                    a_8e0f2 = (uint8_t)a_all45;
                    a_hi_8e0f2 = a_all45 >> 8;
                    x_8e0f2 = value37;
                    carry_8e0f2 = carry_ret45;
                    overflow_8e0f2 = overflow_ret45;
                    direct_page_8e0f2 = dp_ret40;
                    data_bank_8e0f2 = data_bank_8e49;
                    goto shared_8E0F_1;
                }
                a_8e663 = (uint8_t)a_all45;
                a_hi_8e663 = a_all45 >> 8;
                carry_8e663 = carry_ret45;
                overflow_8e663 = overflow_ret45;
                direct_page_8e663 = dp_ret40;
                data_bank_8e663 = data_bank_8e49;
                goto shared_8E66_2;
            } else {
                uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret40 + 8));
                if (value38 != 0) {
                    a_8e0f = (uint8_t)a_all45;
                    a_hi_8e0f = a_all45 >> 8;
                    x_8e0f = value38;
                    carry_8e0f = carry_ret45;
                    overflow_8e0f = overflow_ret45;
                    direct_page_8e0f = dp_ret40;
                    data_bank_8e0f = data_bank_8e49;
                    goto shared_8E0F;
                }
                a_8e66 = (uint8_t)a_all45;
                a_hi_8e66 = a_all45 >> 8;
                carry_8e66 = carry_ret45;
                overflow_8e66 = overflow_ret45;
                direct_page_8e66 = dp_ret40;
                data_bank_8e66 = data_bank_8e49;
                goto shared_8E66;
            }
        }
    } else {
        uint16_t value39 = BUS16_RDP(c, (uint16_t)(dp_ret38 + 6));
        if (x_ret73) {
            r->a = (uint16_t)((uint16_t)(value39 - 1) << 1) & 0xFF;
            r->x = (uint16_t)((uint16_t)(value39 - 1) << 1) & 0xFF;
            r->y = (uint8_t)y_ret32;
            r->c = (uint16_t)(value39 - 1) & 0x8000;
            r->z = ((uint16_t)((uint16_t)(value39 - 1) << 1) & 0xFF) == 0;
            r->n = (uint16_t)((uint16_t)(value39 - 1) << 1) & 0xFF & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8E5B, 0x7E8B5D); GUARD_JSR(c, sp_call, 0x8E5B); } /* update_title_colour_at_offset7 */
            r->sp += 12;
            uint16_t dp_ret41 = r->dp;
            bool x_ret79 = r->xf;
            uint16_t a_all46 = r->a;
            bool carry_ret46 = r->c;
            bool overflow_ret46 = r->v;
            uint8_t value40 = BUS8_RDP(c, (uint16_t)(dp_ret41 + 6));
            BUS8_SET(c, (uint16_t)(dp_ret41 + 6), (uint8_t)(value40 - 1));
            if ((uint8_t)(value40 - 1) != 0) {
                if (x_ret79) {
                    a_8e492 = (uint8_t)a_all46;
                    a_hi_8e492 = a_all46 >> 8;
                    y_8e492 = (uint8_t)y_ret32;
                    carry_8e492 = carry_ret46;
                    overflow_8e492 = overflow_ret46;
                    direct_page_8e492 = dp_ret41;
                    data_bank_8e492 = data_bank_8e49;
                    goto shared_8E49_1;
                } else {
                    a_8e49 = (uint8_t)a_all46;
                    a_hi_8e49 = a_all46 >> 8;
                    y_8e49 = (uint8_t)y_ret32;
                    carry_8e49 = carry_ret46;
                    overflow_8e49 = overflow_ret46;
                    direct_page_8e49 = dp_ret41;
                    goto shared_8E49;
                }
            }
            if (x_ret79) {
                uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp_ret41 + 8));
                if (value41 != 0) {
                    a_8e0f2 = (uint8_t)a_all46;
                    a_hi_8e0f2 = a_all46 >> 8;
                    x_8e0f2 = value41;
                    carry_8e0f2 = carry_ret46;
                    overflow_8e0f2 = overflow_ret46;
                    direct_page_8e0f2 = dp_ret41;
                    data_bank_8e0f2 = data_bank_8e49;
                    goto shared_8E0F_1;
                }
                a_8e663 = (uint8_t)a_all46;
                a_hi_8e663 = a_all46 >> 8;
                carry_8e663 = carry_ret46;
                overflow_8e663 = overflow_ret46;
                direct_page_8e663 = dp_ret41;
                data_bank_8e663 = data_bank_8e49;
                goto shared_8E66_2;
            } else {
                uint16_t value42 = BUS16_RDP(c, (uint16_t)(dp_ret41 + 8));
                if (value42 != 0) {
                    a_8e0f = (uint8_t)a_all46;
                    a_hi_8e0f = a_all46 >> 8;
                    x_8e0f = value42;
                    carry_8e0f = carry_ret46;
                    overflow_8e0f = overflow_ret46;
                    direct_page_8e0f = dp_ret41;
                    data_bank_8e0f = data_bank_8e49;
                    goto shared_8E0F;
                }
                a_8e66 = (uint8_t)a_all46;
                a_hi_8e66 = a_all46 >> 8;
                carry_8e66 = carry_ret46;
                overflow_8e66 = overflow_ret46;
                direct_page_8e66 = dp_ret41;
                data_bank_8e66 = data_bank_8e49;
                goto shared_8E66;
            }
        } else {
            r->a = (uint16_t)((uint16_t)(value39 - 1) << 1) & 0xFF;
            r->x = (uint16_t)((uint16_t)(value39 - 1) << 1) & 0xFF;
            r->c = (uint16_t)(value39 - 1) & 0x8000;
            r->z = ((uint16_t)((uint16_t)(value39 - 1) << 1) & 0xFF) == 0;
            r->n = (uint16_t)((uint16_t)(value39 - 1) << 1) & 0xFF & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 12;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8E5B, 0x7E8B5D); GUARD_JSR(c, sp_call, 0x8E5B); } /* update_title_colour_at_offset7 */
            r->sp += 12;
            uint16_t dp_ret42 = r->dp;
            bool x_ret81 = r->xf;
            uint16_t a_all47 = r->a;
            bool carry_ret47 = r->c;
            bool overflow_ret47 = r->v;
            uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp_ret42 + 6));
            BUS8_SET(c, (uint16_t)(dp_ret42 + 6), (uint8_t)(value43 - 1));
            if ((uint8_t)(value43 - 1) != 0) {
                if (x_ret81) {
                    a_8e492 = (uint8_t)a_all47;
                    a_hi_8e492 = a_all47 >> 8;
                    y_8e492 = (uint8_t)y_ret32;
                    carry_8e492 = carry_ret47;
                    overflow_8e492 = overflow_ret47;
                    direct_page_8e492 = dp_ret42;
                    data_bank_8e492 = data_bank_8e49;
                    goto shared_8E49_1;
                } else {
                    a_8e49 = (uint8_t)a_all47;
                    a_hi_8e49 = a_all47 >> 8;
                    y_8e49 = y_ret32;
                    carry_8e49 = carry_ret47;
                    overflow_8e49 = overflow_ret47;
                    direct_page_8e49 = dp_ret42;
                    goto shared_8E49;
                }
            }
            if (x_ret81) {
                uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp_ret42 + 8));
                if (value44 != 0) {
                    a_8e0f2 = (uint8_t)a_all47;
                    a_hi_8e0f2 = a_all47 >> 8;
                    x_8e0f2 = value44;
                    carry_8e0f2 = carry_ret47;
                    overflow_8e0f2 = overflow_ret47;
                    direct_page_8e0f2 = dp_ret42;
                    data_bank_8e0f2 = data_bank_8e49;
                    goto shared_8E0F_1;
                }
                a_8e663 = (uint8_t)a_all47;
                a_hi_8e663 = a_all47 >> 8;
                carry_8e663 = carry_ret47;
                overflow_8e663 = overflow_ret47;
                direct_page_8e663 = dp_ret42;
                data_bank_8e663 = data_bank_8e49;
                goto shared_8E66_2;
            } else {
                uint16_t value45 = BUS16_RDP(c, (uint16_t)(dp_ret42 + 8));
                if (value45 != 0) {
                    a_8e0f = (uint8_t)a_all47;
                    a_hi_8e0f = a_all47 >> 8;
                    x_8e0f = value45;
                    carry_8e0f = carry_ret47;
                    overflow_8e0f = overflow_ret47;
                    direct_page_8e0f = dp_ret42;
                    data_bank_8e0f = data_bank_8e49;
                    goto shared_8E0F;
                }
                a_8e66 = (uint8_t)a_all47;
                a_hi_8e66 = a_all47 >> 8;
                carry_8e66 = carry_ret47;
                overflow_8e66 = overflow_ret47;
                direct_page_8e66 = dp_ret42;
                data_bank_8e66 = data_bank_8e49;
                goto shared_8E66;
            }
        }
    }
    shared_8E49_1:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_8E0F_1:;
    uint8_t value46 = BUS8_RDP(c, (uint16_t)(direct_page_8e0f2 + 4));
    r->a = (a_hi_8e0f2 << 8) | a_8e0f2;
    r->x = x_8e0f2;
    r->y = value46;
    r->c = carry_8e0f2;
    r->z = value46 == 0;
    r->n = value46 & 0x80;
    r->v = overflow_8e0f2;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_8e0f2;
    r->dp = direct_page_8e0f2;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8E13, 0x7E8820); GUARD_JSR(c, sp_call, 0x8E13); } /* expand_title_text_row */
    r->sp += 12;
    uint16_t dp_ret43 = r->dp;
    bool m_ret38 = r->mf;
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all48 = r->a;
    uint16_t x_ret83 = r->x;
    bool overflow_ret48 = r->v;
    if (x_ret83 == 0) {
        if (m_ret38) {
            a_8e66 = (uint8_t)a_all48;
            a_hi_8e66 = a_all48 >> 8;
            carry_8e66 = x_ret83 >= 0;
            overflow_8e66 = overflow_ret48;
            direct_page_8e66 = dp_ret43;
            data_bank_8e66 = data_bank_8e0f2;
            goto shared_8E66;
        } else {
            a_8e662 = (uint8_t)a_all48;
            a_hi_8e662 = a_all48 >> 8;
            carry_8e662 = x_ret83 >= 0;
            overflow_8e662 = overflow_ret48;
            direct_page_8e662 = dp_ret43;
            data_bank_8e662 = data_bank_8e0f2;
            goto shared_8E66_1;
        }
    }
    BUS16_SET(c, (uint16_t)(dp_ret43 + 8), x_ret83);
    uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret43 + 2));
    r->x = value47;
    r->c = x_ret83 >= 0;
    r->z = value47 == 0;
    r->n = value47 & 0x8000;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8E1F, 0x7EC870); GUARD_JSR(c, sp_call, 0x8E1F); } /* queue_registered_vram_buffer */
    r->sp += 12;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all49 = r->a;
    uint16_t y_ret34 = r->y;
    bool carry_ret49 = r->c;
    bool overflow_ret49 = r->v;
    BUS8_SET(c, (uint16_t)(dp_ret43 + 6), 0x1F);
    a_8e24 = 0x1F;
    a_hi_8e24 = a_all49 >> 8;
    y_8e24 = y_ret34;
    carry_8e24 = carry_ret49;
    overflow_8e24 = overflow_ret49;
    direct_page_8e24 = dp_ret43;
    data_bank_8e24 = data_bank_8e0f2;
    goto shared_8E24;
    shared_8E66_2:;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0x7E8DCD, SOM_RTL, "gen", run_native_title_credit_worker_and_complete_buffer_notice, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 12, 1, 0, 199, 91)
