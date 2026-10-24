#include "som_c.h"

/* C07E30 confirm_native_shop_transaction_with_real_dialogue_and_controller   [class B, 80 bytes, 35 instructions]
 * Source: src/rom/confirm_native_shop_transaction_with_real_dialogue_and_controller.s
 * Documented in docs/event-menu-shop-dialogue.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZV.
 */
static void confirm_native_shop_transaction_with_real_dialogue_and_controller(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    uint8_t a_hi_7e50 = 0;
    uint8_t x_7e50 = 0;
    uint8_t y_7e50 = 0;
    bool overflow_7e50 = 0;
    uint16_t direct_page_7e50 = 0;
    uint8_t data_bank_7e50 = 0;
    uint8_t a_hi_7e502 = 0;
    uint16_t x_7e502 = 0;
    uint16_t y_7e502 = 0;
    bool overflow_7e502 = 0;
    uint16_t direct_page_7e502 = 0;
    uint8_t data_bank_7e502 = 0;
    uint8_t a_7e70 = 0;
    uint8_t a_hi_7e70 = 0;
    uint8_t x_7e70 = 0;
    uint8_t y_7e70 = 0;
    bool carry_7e70 = 0;
    bool zero_7e70 = 0;
    bool negative_7e70 = 0;
    bool overflow_7e70 = 0;
    uint16_t direct_page_7e70 = 0;
    uint8_t data_bank_7e70 = 0;
    uint8_t a_7e702 = 0;
    uint8_t a_hi_7e702 = 0;
    uint16_t x_7e702 = 0;
    uint16_t y_7e702 = 0;
    bool carry_7e702 = 0;
    bool zero_7e702 = 0;
    bool negative_7e702 = 0;
    bool overflow_7e702 = 0;
    uint16_t direct_page_7e702 = 0;
    uint8_t data_bank_7e702 = 0;
    uint8_t a_hi_7e503 = 0;
    uint8_t x_7e503 = 0;
    uint8_t y_7e503 = 0;
    bool overflow_7e503 = 0;
    uint16_t direct_page_7e503 = 0;
    uint8_t data_bank_7e503 = 0;
    uint8_t a_hi_7e504 = 0;
    uint16_t x_7e504 = 0;
    uint16_t y_7e504 = 0;
    bool overflow_7e504 = 0;
    uint16_t direct_page_7e504 = 0;
    uint8_t data_bank_7e504 = 0;
    RAM8(0x1803) |= 0x40;
    r->a = (a >> 8 << 8) | 0x40;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E39, 0xC0794A); GUARD_JSR(c, sp_call, 0x7E39); } /* mark_selected_native_ring_row_and_return_owner_or_special_descriptor */
    uint16_t a_all = r->a;
    RAM8(0x1804) |= 0x80;
    r->a = (a_all >> 8 << 8) | 0x80;
    r->x = 0xFEEC;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E48, 0xC07B81); GUARD_JSR(c, sp_call, 0x7E48); } /* external */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool x_ret2 = r->xf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret2 = r->y;
    bool overflow_ret = r->v;
    uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0x1804);
    BUS8_SET(c, (db_ret << 0x10) + 0x1804, value3 & 0x7F);
    if (x_ret2) {
        a_hi_7e50 = a_all2 >> 8;
        x_7e50 = (uint8_t)x_ret3;
        y_7e50 = (uint8_t)y_ret2;
        overflow_7e50 = overflow_ret;
        direct_page_7e50 = dp_ret;
        data_bank_7e50 = db_ret;
        goto shared_7E50;
    } else {
        a_hi_7e502 = a_all2 >> 8;
        x_7e502 = x_ret3;
        y_7e502 = y_ret2;
        overflow_7e502 = overflow_ret;
        direct_page_7e502 = dp_ret;
        data_bank_7e502 = db_ret;
        goto shared_7E50_1;
    }
    shared_7E50:;
    uint8_t value4 = BUS8_RDP(c, (data_bank_7e50 << 0x10) + 0x1801);
    if (value4 == 0x80) {
        a_7e70 = value4;
        a_hi_7e70 = a_hi_7e50;
        x_7e70 = x_7e50;
        y_7e70 = y_7e50;
        carry_7e70 = value4 >= 0x80;
        zero_7e70 = value4 == 0x80;
        negative_7e70 = (uint8_t)(value4 - 0x80) & 0x80;
        overflow_7e70 = overflow_7e50;
        direct_page_7e70 = direct_page_7e50;
        data_bank_7e70 = data_bank_7e50;
        goto shared_7E70;
    }
    if (value4 == 0x40) {
        uint8_t value5 = BUS8_RDP(c, (data_bank_7e50 << 0x10) + 0x1803);
        BUS8_SET(c, (data_bank_7e50 << 0x10) + 0x1803, value5 | 2);
        r->a = (a_hi_7e50 << 8) | 2;
        r->x = x_7e50;
        r->y = y_7e50;
        r->c = value4 >= 0x40;
        r->v = overflow_7e50;
        r->mf = 1;
        r->xf = 1;
        r->db = data_bank_7e50;
        r->dp = direct_page_7e50;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7E6B, 0xC07ED5); GUARD_JSR(c, sp_call, 0x7E6B); } /* external */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret2 = r->v;
        if (x_ret4) {
            a_7e70 = 1;
            a_hi_7e70 = a_all3 >> 8;
            x_7e70 = (uint8_t)x_ret5;
            y_7e70 = (uint8_t)y_ret3;
            carry_7e70 = carry_ret3;
            zero_7e70 = 0;
            negative_7e70 = 0;
            overflow_7e70 = overflow_ret2;
            direct_page_7e70 = dp_ret2;
            data_bank_7e70 = db_ret2;
            goto shared_7E70;
        } else {
            a_7e702 = 1;
            a_hi_7e702 = a_all3 >> 8;
            x_7e702 = x_ret5;
            y_7e702 = y_ret3;
            carry_7e702 = carry_ret3;
            zero_7e702 = 0;
            negative_7e702 = 0;
            overflow_7e702 = overflow_ret2;
            direct_page_7e702 = dp_ret2;
            data_bank_7e702 = db_ret2;
            goto shared_7E70_1;
        }
    }
    r->a = (a_hi_7e50 << 8) | value4;
    r->x = x_7e50;
    r->y = y_7e50;
    r->c = value4 >= 0x40;
    r->z = value4 == 0x40;
    r->n = (uint8_t)(value4 - 0x40) & 0x80;
    r->v = overflow_7e50;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_7e50;
    r->dp = direct_page_7e50;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E5F, 0xC07E80); GUARD_JSR(c, sp_call, 0x7E5F); } /* advance_native_shop_vblank_input_and_active_ring_phase */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool x_ret6 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t x_ret7 = r->x;
    uint16_t y_ret4 = r->y;
    bool overflow_ret3 = r->v;
    if (x_ret6) {
        a_hi_7e503 = a_all4 >> 8;
        x_7e503 = (uint8_t)x_ret7;
        y_7e503 = (uint8_t)y_ret4;
        overflow_7e503 = overflow_ret3;
        direct_page_7e503 = dp_ret3;
        data_bank_7e503 = db_ret3;
        goto shared_7E50_2;
    } else {
        a_hi_7e504 = a_all4 >> 8;
        x_7e504 = x_ret7;
        y_7e504 = y_ret4;
        overflow_7e504 = overflow_ret3;
        direct_page_7e504 = dp_ret3;
        data_bank_7e504 = db_ret3;
        goto shared_7E50_3;
    }
    shared_7E50_1:;
    uint8_t value6 = BUS8_RDP(c, (data_bank_7e502 << 0x10) + 0x1801);
    if (value6 == 0x80) {
        a_7e702 = value6;
        a_hi_7e702 = a_hi_7e502;
        x_7e702 = x_7e502;
        y_7e702 = y_7e502;
        carry_7e702 = value6 >= 0x80;
        zero_7e702 = value6 == 0x80;
        negative_7e702 = (uint8_t)(value6 - 0x80) & 0x80;
        overflow_7e702 = overflow_7e502;
        direct_page_7e702 = direct_page_7e502;
        data_bank_7e702 = data_bank_7e502;
        goto shared_7E70_1;
    }
    if (value6 == 0x40) {
        uint8_t value7 = BUS8_RDP(c, (data_bank_7e502 << 0x10) + 0x1803);
        BUS8_SET(c, (data_bank_7e502 << 0x10) + 0x1803, value7 | 2);
        r->a = (a_hi_7e502 << 8) | 2;
        r->x = x_7e502;
        r->y = y_7e502;
        r->c = value6 >= 0x40;
        r->v = overflow_7e502;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_7e502;
        r->dp = direct_page_7e502;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7E6B, 0xC07ED5); GUARD_JSR(c, sp_call, 0x7E6B); } /* external */
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        bool x_ret8 = r->xf;
        uint16_t a_all5 = r->a;
        uint16_t x_ret9 = r->x;
        uint16_t y_ret5 = r->y;
        bool carry_ret5 = r->c;
        bool overflow_ret4 = r->v;
        if (x_ret8) {
            a_7e70 = 1;
            a_hi_7e70 = a_all5 >> 8;
            x_7e70 = (uint8_t)x_ret9;
            y_7e70 = (uint8_t)y_ret5;
            carry_7e70 = carry_ret5;
            zero_7e70 = 0;
            negative_7e70 = 0;
            overflow_7e70 = overflow_ret4;
            direct_page_7e70 = dp_ret4;
            data_bank_7e70 = db_ret4;
            goto shared_7E70;
        } else {
            a_7e702 = 1;
            a_hi_7e702 = a_all5 >> 8;
            x_7e702 = x_ret9;
            y_7e702 = y_ret5;
            carry_7e702 = carry_ret5;
            zero_7e702 = 0;
            negative_7e702 = 0;
            overflow_7e702 = overflow_ret4;
            direct_page_7e702 = dp_ret4;
            data_bank_7e702 = db_ret4;
            goto shared_7E70_1;
        }
    }
    r->a = (a_hi_7e502 << 8) | value6;
    r->x = x_7e502;
    r->y = y_7e502;
    r->c = value6 >= 0x40;
    r->z = value6 == 0x40;
    r->n = (uint8_t)(value6 - 0x40) & 0x80;
    r->v = overflow_7e502;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_7e502;
    r->dp = direct_page_7e502;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E5F, 0xC07E80); GUARD_JSR(c, sp_call, 0x7E5F); } /* advance_native_shop_vblank_input_and_active_ring_phase */
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret5 = r->db;
    bool x_ret10 = r->xf;
    uint16_t a_all6 = r->a;
    uint16_t x_ret11 = r->x;
    uint16_t y_ret6 = r->y;
    bool overflow_ret5 = r->v;
    if (x_ret10) {
        a_hi_7e503 = a_all6 >> 8;
        x_7e503 = (uint8_t)x_ret11;
        y_7e503 = (uint8_t)y_ret6;
        overflow_7e503 = overflow_ret5;
        direct_page_7e503 = dp_ret5;
        data_bank_7e503 = db_ret5;
        goto shared_7E50_2;
    } else {
        a_hi_7e504 = a_all6 >> 8;
        x_7e504 = x_ret11;
        y_7e504 = y_ret6;
        overflow_7e504 = overflow_ret5;
        direct_page_7e504 = dp_ret5;
        data_bank_7e504 = db_ret5;
        goto shared_7E50_3;
    }
    shared_7E70:;
    RAM8(0x0000 + sp0) = ((((negative_7e70 << 7) | (overflow_7e70 << 6) | 0x20 | 0x10) | (d_entry << 3)) | (i_entry << 2)) | (zero_7e70 << 1) | carry_7e70;
    r->y = y_7e70;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_7e70;
    r->dp = direct_page_7e70;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E73, 0xC07908); GUARD_JSR(c, sp_call, 0x7E73); } /* clear_native_menu_ring_blink_bit_in_twelve_rows */
    r->sp += 1;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E76, 0xC07E80); GUARD_JSR(c, sp_call, 0x7E76); } /* advance_native_shop_vblank_input_and_active_ring_phase */
    r->sp += 1;
    uint8_t db_ret6 = r->db;
    uint16_t a_all8 = r->a;
    uint8_t value8 = BUS8_RDP(c, (db_ret6 << 0x10) + 0x1803);
    BUS8_SET(c, (db_ret6 << 0x10) + 0x1803, value8 & 0xBF);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_all8 >> 8 << 8) | 0x40;
    r->c = value9 & 0x01;
    r->z = value9 & 0x02;
    r->v = value9 & 0x40;
    r->mf = value9 & 0x20;
    r->xf = value9 & 0x10;
    r->i = value9 & 0x04;
    r->d = value9 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_7E70_1:;
    RAM8(0x0000 + sp0) = ((((negative_7e702 << 7) | (overflow_7e702 << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero_7e702 << 1) | carry_7e702;
    r->y = y_7e702;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_7e702;
    r->dp = direct_page_7e702;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E73, 0xC07908); GUARD_JSR(c, sp_call, 0x7E73); } /* clear_native_menu_ring_blink_bit_in_twelve_rows */
    r->sp += 1;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E76, 0xC07E80); GUARD_JSR(c, sp_call, 0x7E76); } /* advance_native_shop_vblank_input_and_active_ring_phase */
    r->sp += 1;
    uint8_t db_ret7 = r->db;
    uint16_t a_all10 = r->a;
    uint8_t value10 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x1803);
    BUS8_SET(c, (db_ret7 << 0x10) + 0x1803, value10 & 0xBF);
    uint8_t value11 = RAM8(0x0000 + sp0);
    r->a = (a_all10 >> 8 << 8) | 0x40;
    r->c = value11 & 0x01;
    r->z = value11 & 0x02;
    r->v = value11 & 0x40;
    r->mf = value11 & 0x20;
    r->xf = value11 & 0x10;
    r->i = value11 & 0x04;
    r->d = value11 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_7E50_2:;
    uint8_t value12 = BUS8_RDP(c, (data_bank_7e503 << 0x10) + 0x1801);
    if (value12 == 0x80) {
        a_7e70 = value12;
        a_hi_7e70 = a_hi_7e503;
        x_7e70 = x_7e503;
        y_7e70 = y_7e503;
        carry_7e70 = value12 >= 0x80;
        zero_7e70 = value12 == 0x80;
        negative_7e70 = (uint8_t)(value12 - 0x80) & 0x80;
        overflow_7e70 = overflow_7e503;
        direct_page_7e70 = direct_page_7e503;
        data_bank_7e70 = data_bank_7e503;
        goto shared_7E70;
    }
    if (value12 == 0x40) {
        uint8_t value13 = BUS8_RDP(c, (data_bank_7e503 << 0x10) + 0x1803);
        BUS8_SET(c, (data_bank_7e503 << 0x10) + 0x1803, value13 | 2);
        r->a = (a_hi_7e503 << 8) | 2;
        r->x = x_7e503;
        r->y = y_7e503;
        r->c = value12 >= 0x40;
        r->v = overflow_7e503;
        r->mf = 1;
        r->xf = 1;
        r->db = data_bank_7e503;
        r->dp = direct_page_7e503;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7E6B, 0xC07ED5); GUARD_JSR(c, sp_call, 0x7E6B); } /* external */
        uint16_t dp_ret8 = r->dp;
        uint8_t db_ret8 = r->db;
        bool x_ret18 = r->xf;
        uint16_t a_all11 = r->a;
        uint16_t x_ret19 = r->x;
        uint16_t y_ret9 = r->y;
        bool carry_ret11 = r->c;
        bool overflow_ret10 = r->v;
        if (x_ret18) {
            a_7e70 = 1;
            a_hi_7e70 = a_all11 >> 8;
            x_7e70 = (uint8_t)x_ret19;
            y_7e70 = (uint8_t)y_ret9;
            carry_7e70 = carry_ret11;
            zero_7e70 = 0;
            negative_7e70 = 0;
            overflow_7e70 = overflow_ret10;
            direct_page_7e70 = dp_ret8;
            data_bank_7e70 = db_ret8;
            goto shared_7E70;
        } else {
            a_7e702 = 1;
            a_hi_7e702 = a_all11 >> 8;
            x_7e702 = x_ret19;
            y_7e702 = y_ret9;
            carry_7e702 = carry_ret11;
            zero_7e702 = 0;
            negative_7e702 = 0;
            overflow_7e702 = overflow_ret10;
            direct_page_7e702 = dp_ret8;
            data_bank_7e702 = db_ret8;
            goto shared_7E70_1;
        }
    }
    r->a = (a_hi_7e503 << 8) | value12;
    r->x = x_7e503;
    r->y = y_7e503;
    r->c = value12 >= 0x40;
    r->z = value12 == 0x40;
    r->n = (uint8_t)(value12 - 0x40) & 0x80;
    r->v = overflow_7e503;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_7e503;
    r->dp = direct_page_7e503;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E5F, 0xC07E80); GUARD_JSR(c, sp_call, 0x7E5F); } /* advance_native_shop_vblank_input_and_active_ring_phase */
    uint16_t dp_ret9 = r->dp;
    uint8_t db_ret9 = r->db;
    bool x_ret20 = r->xf;
    uint16_t a_all12 = r->a;
    uint16_t x_ret21 = r->x;
    uint16_t y_ret10 = r->y;
    bool overflow_ret11 = r->v;
    if (x_ret20) {
        a_hi_7e503 = a_all12 >> 8;
        x_7e503 = (uint8_t)x_ret21;
        y_7e503 = (uint8_t)y_ret10;
        overflow_7e503 = overflow_ret11;
        direct_page_7e503 = dp_ret9;
        data_bank_7e503 = db_ret9;
        goto shared_7E50_2;
    } else {
        a_hi_7e504 = a_all12 >> 8;
        x_7e504 = x_ret21;
        y_7e504 = y_ret10;
        overflow_7e504 = overflow_ret11;
        direct_page_7e504 = dp_ret9;
        data_bank_7e504 = db_ret9;
        goto shared_7E50_3;
    }
    shared_7E50_3:;
    uint8_t value14 = BUS8_RDP(c, (data_bank_7e504 << 0x10) + 0x1801);
    if (value14 == 0x80) {
        a_7e702 = value14;
        a_hi_7e702 = a_hi_7e504;
        x_7e702 = x_7e504;
        y_7e702 = y_7e504;
        carry_7e702 = value14 >= 0x80;
        zero_7e702 = value14 == 0x80;
        negative_7e702 = (uint8_t)(value14 - 0x80) & 0x80;
        overflow_7e702 = overflow_7e504;
        direct_page_7e702 = direct_page_7e504;
        data_bank_7e702 = data_bank_7e504;
        goto shared_7E70_1;
    }
    if (value14 == 0x40) {
        uint8_t value15 = BUS8_RDP(c, (data_bank_7e504 << 0x10) + 0x1803);
        BUS8_SET(c, (data_bank_7e504 << 0x10) + 0x1803, value15 | 2);
        r->a = (a_hi_7e504 << 8) | 2;
        r->x = x_7e504;
        r->y = y_7e504;
        r->c = value14 >= 0x40;
        r->v = overflow_7e504;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank_7e504;
        r->dp = direct_page_7e504;
        { const uint16_t sp_call = r->sp; JSR(c, 0x7E6B, 0xC07ED5); GUARD_JSR(c, sp_call, 0x7E6B); } /* external */
        uint16_t dp_ret10 = r->dp;
        uint8_t db_ret10 = r->db;
        bool x_ret22 = r->xf;
        uint16_t a_all13 = r->a;
        uint16_t x_ret23 = r->x;
        uint16_t y_ret11 = r->y;
        bool carry_ret13 = r->c;
        bool overflow_ret12 = r->v;
        if (x_ret22) {
            a_7e70 = 1;
            a_hi_7e70 = a_all13 >> 8;
            x_7e70 = (uint8_t)x_ret23;
            y_7e70 = (uint8_t)y_ret11;
            carry_7e70 = carry_ret13;
            zero_7e70 = 0;
            negative_7e70 = 0;
            overflow_7e70 = overflow_ret12;
            direct_page_7e70 = dp_ret10;
            data_bank_7e70 = db_ret10;
            goto shared_7E70;
        } else {
            a_7e702 = 1;
            a_hi_7e702 = a_all13 >> 8;
            x_7e702 = x_ret23;
            y_7e702 = y_ret11;
            carry_7e702 = carry_ret13;
            zero_7e702 = 0;
            negative_7e702 = 0;
            overflow_7e702 = overflow_ret12;
            direct_page_7e702 = dp_ret10;
            data_bank_7e702 = db_ret10;
            goto shared_7E70_1;
        }
    }
    r->a = (a_hi_7e504 << 8) | value14;
    r->x = x_7e504;
    r->y = y_7e504;
    r->c = value14 >= 0x40;
    r->z = value14 == 0x40;
    r->n = (uint8_t)(value14 - 0x40) & 0x80;
    r->v = overflow_7e504;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_7e504;
    r->dp = direct_page_7e504;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7E5F, 0xC07E80); GUARD_JSR(c, sp_call, 0x7E5F); } /* advance_native_shop_vblank_input_and_active_ring_phase */
    uint16_t dp_ret11 = r->dp;
    uint8_t db_ret11 = r->db;
    bool x_ret24 = r->xf;
    uint16_t a_all14 = r->a;
    uint16_t x_ret25 = r->x;
    uint16_t y_ret12 = r->y;
    bool overflow_ret13 = r->v;
    if (x_ret24) {
        a_hi_7e503 = a_all14 >> 8;
        x_7e503 = (uint8_t)x_ret25;
        y_7e503 = (uint8_t)y_ret12;
        overflow_7e503 = overflow_ret13;
        direct_page_7e503 = dp_ret11;
        data_bank_7e503 = db_ret11;
        goto shared_7E50_2;
    } else {
        a_hi_7e504 = a_all14 >> 8;
        x_7e504 = x_ret25;
        y_7e504 = y_ret12;
        overflow_7e504 = overflow_ret13;
        direct_page_7e504 = dp_ret11;
        data_bank_7e504 = db_ret11;
        goto shared_7E50_3;
    }
}
SOM_REGISTER(0xC07E30, SOM_RTS, "gen", confirm_native_shop_transaction_with_real_dialogue_and_controller, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 0, 0, 80, 35)
