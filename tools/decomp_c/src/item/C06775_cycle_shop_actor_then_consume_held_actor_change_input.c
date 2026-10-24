#include "som_c.h"

/* C06775 cycle_shop_actor_then_consume_held_actor_change_input   [class C, 356 bytes, 142 instructions]
 * Source: src/rom/cycle_shop_actor_then_consume_held_actor_change_input.s
 * Entry: M=any X=any DB=any D=any.  Callers read: BXYCV.
 */
static void cycle_shop_actor_then_consume_held_actor_change_input(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_hi_67a8 = 0;
    uint8_t x_67a8 = 0;
    uint8_t y_67a8 = 0;
    bool carry_67a8 = 0;
    bool overflow_67a8 = 0;
    uint16_t direct_page_67a8 = 0;
    uint8_t data_bank_67a8 = 0;
    uint8_t a_hi_67a82 = 0;
    uint16_t x_67a82 = 0;
    uint16_t y_67a82 = 0;
    bool carry_67a82 = 0;
    bool overflow_67a82 = 0;
    uint16_t direct_page_67a82 = 0;
    uint8_t data_bank_67a82 = 0;
    uint8_t a_6799 = 0;
    uint8_t a_hi_6799 = 0;
    uint16_t x_6799 = 0;
    uint16_t y_6799 = 0;
    bool carry_6799 = 0;
    bool zero_6799 = 0;
    bool negative_6799 = 0;
    bool overflow_6799 = 0;
    uint16_t direct_page_6799 = 0;
    uint8_t data_bank_6799 = 0;
    uint8_t a_hi_67bd = 0;
    uint8_t x_67bd = 0;
    uint8_t y_67bd = 0;
    bool carry_67bd = 0;
    bool overflow_67bd = 0;
    uint16_t direct_page_67bd = 0;
    uint8_t data_bank_67bd = 0;
    uint8_t a_hi_680d = 0;
    uint8_t x_680d = 0;
    uint8_t y_680d = 0;
    bool carry_680d = 0;
    bool overflow_680d = 0;
    uint16_t direct_page_680d = 0;
    uint8_t data_bank_680d = 0;
    uint8_t a_hi_67bd2 = 0;
    uint16_t x_67bd2 = 0;
    uint16_t y_67bd2 = 0;
    bool carry_67bd2 = 0;
    bool overflow_67bd2 = 0;
    uint16_t direct_page_67bd2 = 0;
    uint8_t data_bank_67bd2 = 0;
    uint8_t a_hi_680d2 = 0;
    uint16_t x_680d2 = 0;
    uint16_t y_680d2 = 0;
    bool carry_680d2 = 0;
    bool overflow_680d2 = 0;
    uint16_t direct_page_680d2 = 0;
    uint8_t data_bank_680d2 = 0;
    uint8_t a_67992 = 0;
    uint8_t a_hi_67992 = 0;
    uint8_t x_67992 = 0;
    uint8_t y_67992 = 0;
    bool carry_67992 = 0;
    bool zero_67992 = 0;
    bool negative_67992 = 0;
    bool overflow_67992 = 0;
    uint16_t direct_page_67992 = 0;
    uint8_t data_bank_67992 = 0;
    uint8_t a_hi_67a83 = 0;
    uint16_t x_67a83 = 0;
    uint16_t y_67a83 = 0;
    bool carry_67a83 = 0;
    bool overflow_67a83 = 0;
    uint16_t direct_page_67a83 = 0;
    uint8_t data_bank_67a83 = 0;
    uint8_t a_hi_680d3 = 0;
    uint16_t x_680d3 = 0;
    uint16_t y_680d3 = 0;
    bool carry_680d3 = 0;
    bool overflow_680d3 = 0;
    uint16_t direct_page_680d3 = 0;
    uint8_t data_bank_680d3 = 0;
    uint8_t a_hi_6847 = 0;
    uint16_t x_6847 = 0;
    uint16_t y_6847 = 0;
    bool carry_6847 = 0;
    bool overflow_6847 = 0;
    uint16_t direct_page_6847 = 0;
    uint8_t data_bank_6847 = 0;
    uint8_t a_6823 = 0;
    uint8_t a_hi_6823 = 0;
    uint16_t x_6823 = 0;
    uint16_t y_6823 = 0;
    bool carry_6823 = 0;
    bool zero_6823 = 0;
    bool negative_6823 = 0;
    bool overflow_6823 = 0;
    uint16_t direct_page_6823 = 0;
    uint8_t data_bank_6823 = 0;
    uint8_t a_6804 = 0;
    uint8_t a_hi_6804 = 0;
    uint16_t x_6804 = 0;
    uint16_t y_6804 = 0;
    bool carry_6804 = 0;
    bool zero_6804 = 0;
    bool negative_6804 = 0;
    bool overflow_6804 = 0;
    uint16_t direct_page_6804 = 0;
    uint8_t data_bank_6804 = 0;
    uint8_t a_68232 = 0;
    uint8_t a_hi_68232 = 0;
    uint8_t x_68232 = 0;
    uint8_t y_68232 = 0;
    bool carry_68232 = 0;
    bool zero_68232 = 0;
    bool negative_68232 = 0;
    bool overflow_68232 = 0;
    uint16_t direct_page_68232 = 0;
    uint8_t data_bank_68232 = 0;
    uint8_t a_68233 = 0;
    uint8_t a_hi_68233 = 0;
    uint16_t x_68233 = 0;
    uint16_t y_68233 = 0;
    bool carry_68233 = 0;
    bool zero_68233 = 0;
    bool negative_68233 = 0;
    bool overflow_68233 = 0;
    uint16_t direct_page_68233 = 0;
    uint8_t data_bank_68233 = 0;
    uint8_t a_68234 = 0;
    uint8_t a_hi_68234 = 0;
    uint8_t x_68234 = 0;
    uint8_t y_68234 = 0;
    bool carry_68234 = 0;
    bool zero_68234 = 0;
    bool negative_68234 = 0;
    bool overflow_68234 = 0;
    uint16_t direct_page_68234 = 0;
    uint8_t data_bank_68234 = 0;
    uint8_t a_hi_68472 = 0;
    uint8_t x_68472 = 0;
    uint8_t y_68472 = 0;
    bool carry_68472 = 0;
    bool overflow_68472 = 0;
    uint16_t direct_page_68472 = 0;
    uint8_t data_bank_68472 = 0;
    uint8_t a_hi_68473 = 0;
    uint16_t x_68473 = 0;
    uint16_t y_68473 = 0;
    bool carry_68473 = 0;
    bool overflow_68473 = 0;
    uint16_t direct_page_68473 = 0;
    uint8_t data_bank_68473 = 0;
    uint8_t a_hi_6894 = 0;
    uint16_t x_6894 = 0;
    uint16_t y_6894 = 0;
    bool carry_6894 = 0;
    bool overflow_6894 = 0;
    uint16_t direct_page_6894 = 0;
    uint8_t data_bank_6894 = 0;
    uint8_t a_hi_68942 = 0;
    uint16_t x_68942 = 0;
    uint16_t y_68942 = 0;
    bool carry_68942 = 0;
    bool overflow_68942 = 0;
    uint16_t direct_page_68942 = 0;
    uint8_t data_bank_68942 = 0;
    uint8_t a_hi_68a7 = 0;
    uint16_t x_68a7 = 0;
    uint16_t y_68a7 = 0;
    bool carry_68a7 = 0;
    bool overflow_68a7 = 0;
    uint16_t direct_page_68a7 = 0;
    uint8_t data_bank_68a7 = 0;
    uint8_t a_hi_6887 = 0;
    uint16_t x_6887 = 0;
    uint16_t y_6887 = 0;
    bool carry_6887 = 0;
    bool overflow_6887 = 0;
    uint16_t direct_page_6887 = 0;
    uint8_t data_bank_6887 = 0;
    uint8_t a_hi_68474 = 0;
    uint8_t x_68474 = 0;
    uint8_t y_68474 = 0;
    bool carry_68474 = 0;
    bool overflow_68474 = 0;
    uint16_t direct_page_68474 = 0;
    uint8_t data_bank_68474 = 0;
    uint8_t a_hi_680d4 = 0;
    uint8_t x_680d4 = 0;
    uint8_t y_680d4 = 0;
    bool carry_680d4 = 0;
    bool overflow_680d4 = 0;
    uint16_t direct_page_680d4 = 0;
    uint8_t data_bank_680d4 = 0;
    uint8_t a_hi_68943 = 0;
    uint8_t x_68943 = 0;
    uint8_t y_68943 = 0;
    bool carry_68943 = 0;
    bool overflow_68943 = 0;
    uint16_t direct_page_68943 = 0;
    uint8_t data_bank_68943 = 0;
    uint8_t a_hi_68944 = 0;
    uint8_t x_68944 = 0;
    uint8_t y_68944 = 0;
    bool carry_68944 = 0;
    bool overflow_68944 = 0;
    uint16_t direct_page_68944 = 0;
    uint8_t data_bank_68944 = 0;
    uint8_t a_hi_68e0 = 0;
    uint16_t x_68e0 = 0;
    uint16_t y_68e0 = 0;
    bool carry_68e0 = 0;
    bool overflow_68e0 = 0;
    uint16_t direct_page_68e0 = 0;
    uint8_t data_bank_68e0 = 0;
    uint8_t a_hi_68e02 = 0;
    uint16_t x_68e02 = 0;
    uint16_t y_68e02 = 0;
    bool carry_68e02 = 0;
    bool overflow_68e02 = 0;
    uint16_t direct_page_68e02 = 0;
    uint8_t data_bank_68e02 = 0;
    uint8_t a_hi_68e03 = 0;
    uint8_t x_68e03 = 0;
    uint8_t y_68e03 = 0;
    bool carry_68e03 = 0;
    bool overflow_68e03 = 0;
    uint16_t direct_page_68e03 = 0;
    uint8_t data_bank_68e03 = 0;
    uint8_t a_hi_68d4 = 0;
    uint8_t x_68d4 = 0;
    uint8_t y_68d4 = 0;
    bool overflow_68d4 = 0;
    uint16_t direct_page_68d4 = 0;
    uint8_t data_bank_68d4 = 0;
    uint8_t a_hi_68e04 = 0;
    uint8_t x_68e04 = 0;
    uint8_t y_68e04 = 0;
    bool carry_68e04 = 0;
    bool overflow_68e04 = 0;
    uint16_t direct_page_68e04 = 0;
    uint8_t data_bank_68e04 = 0;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1812);
    if (value != 0) {
        a_hi_67a8 = a >> 8;
        x_67a8 = (uint8_t)x;
        y_67a8 = (uint8_t)y;
        carry_67a8 = carry;
        overflow_67a8 = overflow;
        direct_page_67a8 = dp;
        data_bank_67a8 = db;
        goto shared_67A8;
    }
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x1800);
    if ((value2 & 0x40) == 0) {
        a_hi_67a8 = a >> 8;
        x_67a8 = (uint8_t)x;
        y_67a8 = (uint8_t)y;
        carry_67a8 = carry;
        overflow_67a8 = overflow;
        direct_page_67a8 = dp;
        data_bank_67a8 = db;
        goto shared_67A8;
    }
    r->a = (a >> 8 << 8) | value2;
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->z = (value2 & 0x40) == 0;
    r->n = value2 & 0x80;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6786, 0xC06B4C); GUARD_JSL(c, sp_call, 0x6786); } /* persist_native_menu_category_row_and_equipment_rank */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6789, 0xC06986); GUARD_JSR(c, sp_call, 0x6789); } /* cycle_to_next_eligible_unbound_menu_actor */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret2 = r->c;
    bool zero_ret2 = r->z;
    bool overflow_ret2 = r->v;
    if (zero_ret2) {
        a_hi_67a82 = a_all2 >> 8;
        x_67a82 = x_ret2;
        y_67a82 = y_ret;
        carry_67a82 = carry_ret2;
        overflow_67a82 = overflow_ret2;
        direct_page_67a82 = dp;
        data_bank_67a82 = db;
        goto shared_67A8_1;
    }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x678E, 0xC06914); GUARD_JSR(c, sp_call, 0x678E); } /* restore_native_menu_actor_saved_category */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6791, 0xC068FF); GUARD_JSR(c, sp_call, 0x6791); } /* clear_packed_menu_flag_then_open_native_ring */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    uint16_t a_all4 = r->a;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 0x1803);
    BUS8_SET(c, (db_ret << 0x10) + 0x1803, value3 & 0xB7);
    a_6799 = 0x48;
    a_hi_6799 = a_all4 >> 8;
    x_6799 = x_ret4;
    y_6799 = y_ret3;
    carry_6799 = carry_ret3;
    zero_6799 = (value3 & 0x48) == 0;
    negative_6799 = 0;
    overflow_6799 = overflow_ret3;
    direct_page_6799 = dp_ret;
    data_bank_6799 = db_ret;
    shared_6799:;
    r->a = (a_hi_6799 << 8) | a_6799;
    r->x = x_6799;
    r->y = y_6799;
    r->c = carry_6799;
    r->z = zero_6799;
    r->n = negative_6799;
    r->v = overflow_6799;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_6799;
    r->dp = direct_page_6799;
    { const uint16_t sp_call = r->sp; JSR(c, 0x679B, 0xC0695E); GUARD_JSR(c, sp_call, 0x679B); } /* wait_vblank_before_polling_native_menu_input */
    { const uint16_t sp_call = r->sp; JSR(c, 0x679E, 0xC06BF8); GUARD_JSR(c, sp_call, 0x679E); } /* dispatch_native_menu_ring_phase_from_original_jump_table */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool x_ret7 = r->xf;
    uint16_t a_all6 = r->a;
    uint16_t x_ret8 = r->x;
    uint16_t y_ret5 = r->y;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    uint8_t value10 = BUS8_RDP(c, (db_ret3 << 0x10) + 0x1800);
    if ((value10 & 0x40) != 0) {
        if (x_ret7) {
            a_67992 = value10 & 0x40;
            a_hi_67992 = a_all6 >> 8;
            x_67992 = (uint8_t)x_ret8;
            y_67992 = (uint8_t)y_ret5;
            carry_67992 = carry_ret5;
            zero_67992 = (value10 & 0x40) == 0;
            negative_67992 = value10 & 0x40 & 0x80;
            overflow_67992 = overflow_ret5;
            direct_page_67992 = dp_ret3;
            data_bank_67992 = db_ret3;
            goto shared_6799_1;
        } else {
            a_6799 = value10 & 0x40;
            a_hi_6799 = a_all6 >> 8;
            x_6799 = x_ret8;
            y_6799 = y_ret5;
            carry_6799 = carry_ret5;
            zero_6799 = (value10 & 0x40) == 0;
            negative_6799 = value10 & 0x40 & 0x80;
            overflow_6799 = overflow_ret5;
            direct_page_6799 = dp_ret3;
            data_bank_6799 = db_ret3;
            goto shared_6799;
        }
    }
    if (x_ret7) {
        a_hi_67a8 = a_all6 >> 8;
        x_67a8 = (uint8_t)x_ret8;
        y_67a8 = (uint8_t)y_ret5;
        carry_67a8 = carry_ret5;
        overflow_67a8 = overflow_ret5;
        direct_page_67a8 = dp_ret3;
        data_bank_67a8 = db_ret3;
        goto shared_67A8;
    } else {
        a_hi_67a83 = a_all6 >> 8;
        x_67a83 = x_ret8;
        y_67a83 = y_ret5;
        carry_67a83 = carry_ret5;
        overflow_67a83 = overflow_ret5;
        direct_page_67a83 = dp_ret3;
        data_bank_67a83 = db_ret3;
        goto shared_67A8_2;
    }
    shared_67A8:;
    uint8_t value4 = BUS8_RDP(c, (data_bank_67a8 << 0x10) + 0x1804);
    if ((value4 & 8) == 0) {
        a_hi_67bd = a_hi_67a8;
        x_67bd = x_67a8;
        y_67bd = y_67a8;
        carry_67bd = carry_67a8;
        overflow_67bd = overflow_67a8;
        direct_page_67bd = direct_page_67a8;
        data_bank_67bd = data_bank_67a8;
        goto shared_67BD;
    }
    uint8_t value5 = BUS8_RDP(c, (data_bank_67a8 << 0x10) + 0x1801);
    if ((value5 & 0x40) != 0) {
        a_hi_680d = a_hi_67a8;
        x_680d = x_67a8;
        y_680d = y_67a8;
        carry_680d = carry_67a8;
        overflow_680d = overflow_67a8;
        direct_page_680d = direct_page_67a8;
        data_bank_680d = data_bank_67a8;
        goto shared_680D;
    }
    uint8_t value6 = BUS8_RDP(c, (data_bank_67a8 << 0x10) + 0x1804);
    BUS8_SET(c, (data_bank_67a8 << 0x10) + 0x1804, value6 & 0xF7);
    a_hi_67bd = a_hi_67a8;
    x_67bd = x_67a8;
    y_67bd = y_67a8;
    carry_67bd = carry_67a8;
    overflow_67bd = overflow_67a8;
    direct_page_67bd = direct_page_67a8;
    data_bank_67bd = data_bank_67a8;
    goto shared_67BD;
    shared_67A8_1:;
    uint8_t value7 = BUS8_RDP(c, (data_bank_67a82 << 0x10) + 0x1804);
    if ((value7 & 8) == 0) {
        a_hi_67bd2 = a_hi_67a82;
        x_67bd2 = x_67a82;
        y_67bd2 = y_67a82;
        carry_67bd2 = carry_67a82;
        overflow_67bd2 = overflow_67a82;
        direct_page_67bd2 = direct_page_67a82;
        data_bank_67bd2 = data_bank_67a82;
        goto shared_67BD_1;
    }
    uint8_t value8 = BUS8_RDP(c, (data_bank_67a82 << 0x10) + 0x1801);
    if ((value8 & 0x40) != 0) {
        a_hi_680d2 = a_hi_67a82;
        x_680d2 = x_67a82;
        y_680d2 = y_67a82;
        carry_680d2 = carry_67a82;
        overflow_680d2 = overflow_67a82;
        direct_page_680d2 = direct_page_67a82;
        data_bank_680d2 = data_bank_67a82;
        goto shared_680D_1;
    }
    uint8_t value9 = BUS8_RDP(c, (data_bank_67a82 << 0x10) + 0x1804);
    BUS8_SET(c, (data_bank_67a82 << 0x10) + 0x1804, value9 & 0xF7);
    a_hi_67bd2 = a_hi_67a82;
    x_67bd2 = x_67a82;
    y_67bd2 = y_67a82;
    carry_67bd2 = carry_67a82;
    overflow_67bd2 = overflow_67a82;
    direct_page_67bd2 = direct_page_67a82;
    data_bank_67bd2 = data_bank_67a82;
    goto shared_67BD_1;
    shared_67BD:;
    uint16_t value11 = BUS16_RDP(c, (data_bank_67bd << 0x10) + 0x1800);
    if ((value11 & 0x4000) == 0) {
        a_hi_680d3 = value11 >> 8;
        x_680d3 = x_67bd;
        y_680d3 = y_67bd;
        carry_680d3 = carry_67bd;
        overflow_680d3 = overflow_67bd;
        direct_page_680d3 = direct_page_67bd;
        data_bank_680d3 = data_bank_67bd;
        goto shared_680D_2;
    }
    r->a = value11;
    r->x = x_67bd;
    r->y = y_67bd;
    r->c = carry_67bd;
    r->z = (value11 & 0x4000) == 0;
    r->n = value11 & 0x8000;
    r->v = overflow_67bd;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_67bd;
    r->dp = direct_page_67bd;
    { const uint16_t sp_call = r->sp; JSL(c, 0x67CA, 0xC06B4C); GUARD_JSL(c, sp_call, 0x67CA); } /* persist_native_menu_category_row_and_equipment_rank */
    uint16_t a_all7 = r->a;
    uint8_t value12 = BUS8_RDP(c, (data_bank_67bd << 0x10) + 0x1803);
    if ((value12 & 0x40) == 0) {
        uint8_t value13 = BUS8_RDP(c, (data_bank_67bd << 0x10) + 0x1803);
        if ((value13 & 0x88) == 0) {
            uint8_t value14 = BUS8_RDP(c, (data_bank_67bd << 0x10) + 0x1805);
            uint8_t value15 = BUS8_RDP(c, (data_bank_67bd << 0x10) + 0x1808);
            if (value14 == value15) {
                r->a = (a_all7 >> 8 << 8) | value14;
                r->c = value14 >= value15;
                r->z = value14 == value15;
                r->n = (uint8_t)(value14 - value15) & 0x80;
                r->v = value12 & 0x40;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0x6834, 0xD0CF18); GUARD_JSL(c, sp_call, 0x6834); } /* request_native_menu_audio_2a */
                uint8_t db_ret4 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                BUS16_SET(c, (db_ret4 << 0x10) + 0x1812, 6);
                BUS16_SET(c, (db_ret4 << 0x10) + 0x1814, 1);
                r->a = 1;
                r->z = 0;
                r->n = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x6843, 0xC068F1); GUARD_JSR(c, sp_call, 0x6843); } /* advance_native_menu_ring_frames_until_phase_zero */
                uint16_t dp_ret5 = r->dp;
                uint8_t db_ret5 = r->db;
                uint16_t a_all9 = r->a;
                uint16_t x_ret12 = r->x;
                uint16_t y_ret7 = r->y;
                bool carry_ret8 = r->c;
                bool overflow_ret8 = r->v;
                BUS16_SET(c, (db_ret5 << 0x10) + 0x1826, 0);
                a_hi_6847 = a_all9 >> 8;
                x_6847 = x_ret12;
                y_6847 = y_ret7;
                carry_6847 = carry_ret8;
                overflow_6847 = overflow_ret8;
                direct_page_6847 = dp_ret5;
                data_bank_6847 = db_ret5;
                goto shared_6847;
            }
            BUS8_SET(c, (data_bank_67bd << 0x10) + 0x1808, value14);
            r->a = (a_all7 >> 8 << 8) | value14;
            r->c = value14 >= value15;
            r->z = value14 == value15;
            r->n = (uint8_t)(value14 - value15) & 0x80;
            r->v = value12 & 0x40;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x681C, 0xC06914); GUARD_JSR(c, sp_call, 0x681C); } /* restore_native_menu_actor_saved_category */
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x681F, 0xC06906); GUARD_JSR(c, sp_call, 0x681F); } /* request_native_menu_ring_open_and_build_selected_list */
            { const uint16_t sp_call = r->sp; JSR(c, 0x6822, 0xC068F1); GUARD_JSR(c, sp_call, 0x6822); } /* advance_native_menu_ring_frames_until_phase_zero */
            uint16_t dp_ret7 = r->dp;
            uint8_t db_ret7 = r->db;
            uint16_t a_all12 = r->a;
            uint16_t x_ret16 = r->x;
            uint16_t y_ret10 = r->y;
            bool carry_ret10 = r->c;
            bool zero_ret12 = r->z;
            bool negative_ret12 = r->n;
            bool overflow_ret10 = r->v;
            a_6823 = (uint8_t)a_all12;
            a_hi_6823 = a_all12 >> 8;
            x_6823 = x_ret16;
            y_6823 = y_ret10;
            carry_6823 = carry_ret10;
            zero_6823 = zero_ret12;
            negative_6823 = negative_ret12;
            overflow_6823 = overflow_ret10;
            direct_page_6823 = dp_ret7;
            data_bank_6823 = db_ret7;
            goto shared_6823;
        }
        r->a = (a_all7 >> 8 << 8) | value13;
        r->z = (value13 & 0x88) == 0;
        r->n = value13 & 0x80;
        r->v = value12 & 0x40;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x67F0, 0xC06B4C); GUARD_JSL(c, sp_call, 0x67F0); } /* persist_native_menu_category_row_and_equipment_rank */
        uint16_t a_all13 = r->a;
        uint16_t x_ret17 = r->x;
        bool carry_ret11 = r->c;
        bool overflow_ret11 = r->v;
        uint8_t value16 = BUS8_RDP(c, (data_bank_67bd << 0x10) + 0x1803);
        if ((value16 & 8) == 0) {
            a_6804 = value16;
            a_hi_6804 = a_all13 >> 8;
            x_6804 = x_ret17;
            y_6804 = y_67bd;
            carry_6804 = carry_ret11;
            zero_6804 = (value16 & 8) == 0;
            negative_6804 = value16 & 0x80;
            overflow_6804 = overflow_ret11;
            direct_page_6804 = direct_page_67bd;
            data_bank_6804 = data_bank_67bd;
            goto shared_6804;
        }
        uint8_t value17 = BUS8_RDP(c, (data_bank_67bd << 0x10) + 0x1803);
        BUS8_SET(c, (data_bank_67bd << 0x10) + 0x1803, value17 & 0x37);
        BUS8_SET(c, (data_bank_67bd << 0x10) + 0x1809, 2);
        a_6804 = 2;
        a_hi_6804 = a_all13 >> 8;
        x_6804 = x_ret17;
        y_6804 = y_67bd;
        carry_6804 = carry_ret11;
        zero_6804 = 0;
        negative_6804 = 0;
        overflow_6804 = overflow_ret11;
        direct_page_6804 = direct_page_67bd;
        data_bank_6804 = data_bank_67bd;
        goto shared_6804;
    }
    uint8_t value18 = BUS8_RDP(c, (data_bank_67bd << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_67bd << 0x10) + 0x1803, value18 & 0xBF);
    r->a = (a_all7 >> 8 << 8) | 0x40;
    r->z = (value18 & 0x40) == 0;
    r->n = value12 & 0x80;
    r->v = value12 & 0x40;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x67D9, 0xC07908); GUARD_JSR(c, sp_call, 0x67D9); } /* clear_native_menu_ring_blink_bit_in_twelve_rows */
    BUS16_SET(c, (data_bank_67bd << 0x10) + 0x1800, 0);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x67E1, 0xC06BF8); GUARD_JSR(c, sp_call, 0x67E1); } /* dispatch_native_menu_ring_phase_from_original_jump_table */
    uint16_t dp_ret8 = r->dp;
    uint8_t db_ret8 = r->db;
    bool m_ret4 = r->mf;
    bool x_ret19 = r->xf;
    uint16_t a_all15 = r->a;
    uint16_t x_ret20 = r->x;
    uint16_t y_ret11 = r->y;
    bool carry_ret13 = r->c;
    bool zero_ret15 = r->z;
    bool negative_ret15 = r->n;
    bool overflow_ret13 = r->v;
    if (m_ret4) {
        if (x_ret19) {
            a_68232 = (uint8_t)a_all15;
            a_hi_68232 = a_all15 >> 8;
            x_68232 = (uint8_t)x_ret20;
            y_68232 = (uint8_t)y_ret11;
            carry_68232 = carry_ret13;
            zero_68232 = zero_ret15;
            negative_68232 = negative_ret15;
            overflow_68232 = overflow_ret13;
            direct_page_68232 = dp_ret8;
            data_bank_68232 = db_ret8;
            goto shared_6823_1;
        } else {
            a_68233 = (uint8_t)a_all15;
            a_hi_68233 = a_all15 >> 8;
            x_68233 = x_ret20;
            y_68233 = y_ret11;
            carry_68233 = carry_ret13;
            zero_68233 = zero_ret15;
            negative_68233 = negative_ret15;
            overflow_68233 = overflow_ret13;
            direct_page_68233 = dp_ret8;
            data_bank_68233 = db_ret8;
            goto shared_6823_2;
        }
    } else {
        if (x_ret19) {
            a_68234 = (uint8_t)a_all15;
            a_hi_68234 = a_all15 >> 8;
            x_68234 = (uint8_t)x_ret20;
            y_68234 = (uint8_t)y_ret11;
            carry_68234 = carry_ret13;
            zero_68234 = zero_ret15;
            negative_68234 = negative_ret15;
            overflow_68234 = overflow_ret13;
            direct_page_68234 = dp_ret8;
            data_bank_68234 = db_ret8;
            goto shared_6823_3;
        } else {
            a_6823 = (uint8_t)a_all15;
            a_hi_6823 = a_all15 >> 8;
            x_6823 = x_ret20;
            y_6823 = y_ret11;
            carry_6823 = carry_ret13;
            zero_6823 = zero_ret15;
            negative_6823 = negative_ret15;
            overflow_6823 = overflow_ret13;
            direct_page_6823 = dp_ret8;
            data_bank_6823 = db_ret8;
            goto shared_6823;
        }
    }
    shared_680D:;
    a_hi_68472 = a_hi_680d;
    x_68472 = x_680d;
    y_68472 = y_680d;
    carry_68472 = carry_680d;
    overflow_68472 = overflow_680d;
    direct_page_68472 = direct_page_680d;
    data_bank_68472 = data_bank_680d;
    goto shared_6847_1;
    shared_67BD_1:;
    uint16_t value19 = BUS16_RDP(c, (data_bank_67bd2 << 0x10) + 0x1800);
    if ((value19 & 0x4000) == 0) {
        a_hi_680d3 = value19 >> 8;
        x_680d3 = x_67bd2;
        y_680d3 = y_67bd2;
        carry_680d3 = carry_67bd2;
        overflow_680d3 = overflow_67bd2;
        direct_page_680d3 = direct_page_67bd2;
        data_bank_680d3 = data_bank_67bd2;
        goto shared_680D_2;
    }
    r->a = value19;
    r->x = x_67bd2;
    r->y = y_67bd2;
    r->c = carry_67bd2;
    r->z = (value19 & 0x4000) == 0;
    r->n = value19 & 0x8000;
    r->v = overflow_67bd2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_67bd2;
    r->dp = direct_page_67bd2;
    { const uint16_t sp_call = r->sp; JSL(c, 0x67CA, 0xC06B4C); GUARD_JSL(c, sp_call, 0x67CA); } /* persist_native_menu_category_row_and_equipment_rank */
    uint16_t a_all16 = r->a;
    uint8_t value20 = BUS8_RDP(c, (data_bank_67bd2 << 0x10) + 0x1803);
    if ((value20 & 0x40) == 0) {
        uint8_t value21 = BUS8_RDP(c, (data_bank_67bd2 << 0x10) + 0x1803);
        if ((value21 & 0x88) == 0) {
            uint8_t value22 = BUS8_RDP(c, (data_bank_67bd2 << 0x10) + 0x1805);
            uint8_t value23 = BUS8_RDP(c, (data_bank_67bd2 << 0x10) + 0x1808);
            if (value22 == value23) {
                r->a = (a_all16 >> 8 << 8) | value22;
                r->c = value22 >= value23;
                r->z = value22 == value23;
                r->n = (uint8_t)(value22 - value23) & 0x80;
                r->v = value20 & 0x40;
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0x6834, 0xD0CF18); GUARD_JSL(c, sp_call, 0x6834); } /* request_native_menu_audio_2a */
                uint8_t db_ret9 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                BUS16_SET(c, (db_ret9 << 0x10) + 0x1812, 6);
                BUS16_SET(c, (db_ret9 << 0x10) + 0x1814, 1);
                r->a = 1;
                r->z = 0;
                r->n = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x6843, 0xC068F1); GUARD_JSR(c, sp_call, 0x6843); } /* advance_native_menu_ring_frames_until_phase_zero */
                uint16_t dp_ret10 = r->dp;
                uint8_t db_ret10 = r->db;
                uint16_t a_all18 = r->a;
                uint16_t x_ret24 = r->x;
                uint16_t y_ret13 = r->y;
                bool carry_ret16 = r->c;
                bool overflow_ret16 = r->v;
                BUS16_SET(c, (db_ret10 << 0x10) + 0x1826, 0);
                a_hi_6847 = a_all18 >> 8;
                x_6847 = x_ret24;
                y_6847 = y_ret13;
                carry_6847 = carry_ret16;
                overflow_6847 = overflow_ret16;
                direct_page_6847 = dp_ret10;
                data_bank_6847 = db_ret10;
                goto shared_6847;
            }
            BUS8_SET(c, (data_bank_67bd2 << 0x10) + 0x1808, value22);
            r->a = (a_all16 >> 8 << 8) | value22;
            r->c = value22 >= value23;
            r->z = value22 == value23;
            r->n = (uint8_t)(value22 - value23) & 0x80;
            r->v = value20 & 0x40;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x681C, 0xC06914); GUARD_JSR(c, sp_call, 0x681C); } /* restore_native_menu_actor_saved_category */
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x681F, 0xC06906); GUARD_JSR(c, sp_call, 0x681F); } /* request_native_menu_ring_open_and_build_selected_list */
            { const uint16_t sp_call = r->sp; JSR(c, 0x6822, 0xC068F1); GUARD_JSR(c, sp_call, 0x6822); } /* advance_native_menu_ring_frames_until_phase_zero */
            uint16_t dp_ret12 = r->dp;
            uint8_t db_ret12 = r->db;
            uint16_t a_all21 = r->a;
            uint16_t x_ret28 = r->x;
            uint16_t y_ret16 = r->y;
            bool carry_ret18 = r->c;
            bool zero_ret21 = r->z;
            bool negative_ret21 = r->n;
            bool overflow_ret18 = r->v;
            a_6823 = (uint8_t)a_all21;
            a_hi_6823 = a_all21 >> 8;
            x_6823 = x_ret28;
            y_6823 = y_ret16;
            carry_6823 = carry_ret18;
            zero_6823 = zero_ret21;
            negative_6823 = negative_ret21;
            overflow_6823 = overflow_ret18;
            direct_page_6823 = dp_ret12;
            data_bank_6823 = db_ret12;
            goto shared_6823;
        }
        r->a = (a_all16 >> 8 << 8) | value21;
        r->z = (value21 & 0x88) == 0;
        r->n = value21 & 0x80;
        r->v = value20 & 0x40;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x67F0, 0xC06B4C); GUARD_JSL(c, sp_call, 0x67F0); } /* persist_native_menu_category_row_and_equipment_rank */
        uint16_t a_all22 = r->a;
        uint16_t x_ret29 = r->x;
        bool carry_ret19 = r->c;
        bool overflow_ret19 = r->v;
        uint8_t value24 = BUS8_RDP(c, (data_bank_67bd2 << 0x10) + 0x1803);
        if ((value24 & 8) == 0) {
            a_6804 = value24;
            a_hi_6804 = a_all22 >> 8;
            x_6804 = x_ret29;
            y_6804 = y_67bd2;
            carry_6804 = carry_ret19;
            zero_6804 = (value24 & 8) == 0;
            negative_6804 = value24 & 0x80;
            overflow_6804 = overflow_ret19;
            direct_page_6804 = direct_page_67bd2;
            data_bank_6804 = data_bank_67bd2;
            goto shared_6804;
        }
        uint8_t value25 = BUS8_RDP(c, (data_bank_67bd2 << 0x10) + 0x1803);
        BUS8_SET(c, (data_bank_67bd2 << 0x10) + 0x1803, value25 & 0x37);
        BUS8_SET(c, (data_bank_67bd2 << 0x10) + 0x1809, 2);
        a_6804 = 2;
        a_hi_6804 = a_all22 >> 8;
        x_6804 = x_ret29;
        y_6804 = y_67bd2;
        carry_6804 = carry_ret19;
        zero_6804 = 0;
        negative_6804 = 0;
        overflow_6804 = overflow_ret19;
        direct_page_6804 = direct_page_67bd2;
        data_bank_6804 = data_bank_67bd2;
        goto shared_6804;
    }
    uint8_t value26 = BUS8_RDP(c, (data_bank_67bd2 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_67bd2 << 0x10) + 0x1803, value26 & 0xBF);
    r->a = (a_all16 >> 8 << 8) | 0x40;
    r->z = (value26 & 0x40) == 0;
    r->n = value20 & 0x80;
    r->v = value20 & 0x40;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x67D9, 0xC07908); GUARD_JSR(c, sp_call, 0x67D9); } /* clear_native_menu_ring_blink_bit_in_twelve_rows */
    BUS16_SET(c, (data_bank_67bd2 << 0x10) + 0x1800, 0);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x67E1, 0xC06BF8); GUARD_JSR(c, sp_call, 0x67E1); } /* dispatch_native_menu_ring_phase_from_original_jump_table */
    uint16_t dp_ret13 = r->dp;
    uint8_t db_ret13 = r->db;
    bool m_ret6 = r->mf;
    bool x_ret31 = r->xf;
    uint16_t a_all24 = r->a;
    uint16_t x_ret32 = r->x;
    uint16_t y_ret17 = r->y;
    bool carry_ret21 = r->c;
    bool zero_ret24 = r->z;
    bool negative_ret24 = r->n;
    bool overflow_ret21 = r->v;
    if (m_ret6) {
        if (x_ret31) {
            a_68232 = (uint8_t)a_all24;
            a_hi_68232 = a_all24 >> 8;
            x_68232 = (uint8_t)x_ret32;
            y_68232 = (uint8_t)y_ret17;
            carry_68232 = carry_ret21;
            zero_68232 = zero_ret24;
            negative_68232 = negative_ret24;
            overflow_68232 = overflow_ret21;
            direct_page_68232 = dp_ret13;
            data_bank_68232 = db_ret13;
            goto shared_6823_1;
        } else {
            a_68233 = (uint8_t)a_all24;
            a_hi_68233 = a_all24 >> 8;
            x_68233 = x_ret32;
            y_68233 = y_ret17;
            carry_68233 = carry_ret21;
            zero_68233 = zero_ret24;
            negative_68233 = negative_ret24;
            overflow_68233 = overflow_ret21;
            direct_page_68233 = dp_ret13;
            data_bank_68233 = db_ret13;
            goto shared_6823_2;
        }
    } else {
        if (x_ret31) {
            a_68234 = (uint8_t)a_all24;
            a_hi_68234 = a_all24 >> 8;
            x_68234 = (uint8_t)x_ret32;
            y_68234 = (uint8_t)y_ret17;
            carry_68234 = carry_ret21;
            zero_68234 = zero_ret24;
            negative_68234 = negative_ret24;
            overflow_68234 = overflow_ret21;
            direct_page_68234 = dp_ret13;
            data_bank_68234 = db_ret13;
            goto shared_6823_3;
        } else {
            a_6823 = (uint8_t)a_all24;
            a_hi_6823 = a_all24 >> 8;
            x_6823 = x_ret32;
            y_6823 = y_ret17;
            carry_6823 = carry_ret21;
            zero_6823 = zero_ret24;
            negative_6823 = negative_ret24;
            overflow_6823 = overflow_ret21;
            direct_page_6823 = dp_ret13;
            data_bank_6823 = db_ret13;
            goto shared_6823;
        }
    }
    shared_680D_1:;
    a_hi_68473 = a_hi_680d2;
    x_68473 = x_680d2;
    y_68473 = y_680d2;
    carry_68473 = carry_680d2;
    overflow_68473 = overflow_680d2;
    direct_page_68473 = direct_page_680d2;
    data_bank_68473 = data_bank_680d2;
    goto shared_6847_2;
    shared_6799_1:;
    r->a = (a_hi_67992 << 8) | a_67992;
    r->x = x_67992;
    r->y = y_67992;
    r->c = carry_67992;
    r->z = zero_67992;
    r->n = negative_67992;
    r->v = overflow_67992;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_67992;
    r->dp = direct_page_67992;
    { const uint16_t sp_call = r->sp; JSR(c, 0x679B, 0xC0695E); GUARD_JSR(c, sp_call, 0x679B); } /* wait_vblank_before_polling_native_menu_input */
    { const uint16_t sp_call = r->sp; JSR(c, 0x679E, 0xC06BF8); GUARD_JSR(c, sp_call, 0x679E); } /* dispatch_native_menu_ring_phase_from_original_jump_table */
    uint16_t dp_ret15 = r->dp;
    uint8_t db_ret15 = r->db;
    bool x_ret35 = r->xf;
    uint16_t a_all26 = r->a;
    uint16_t x_ret36 = r->x;
    uint16_t y_ret19 = r->y;
    bool carry_ret23 = r->c;
    bool overflow_ret23 = r->v;
    uint8_t value27 = BUS8_RDP(c, (db_ret15 << 0x10) + 0x1800);
    if ((value27 & 0x40) != 0) {
        if (x_ret35) {
            a_67992 = value27 & 0x40;
            a_hi_67992 = a_all26 >> 8;
            x_67992 = (uint8_t)x_ret36;
            y_67992 = (uint8_t)y_ret19;
            carry_67992 = carry_ret23;
            zero_67992 = (value27 & 0x40) == 0;
            negative_67992 = value27 & 0x40 & 0x80;
            overflow_67992 = overflow_ret23;
            direct_page_67992 = dp_ret15;
            data_bank_67992 = db_ret15;
            goto shared_6799_1;
        } else {
            a_6799 = value27 & 0x40;
            a_hi_6799 = a_all26 >> 8;
            x_6799 = x_ret36;
            y_6799 = y_ret19;
            carry_6799 = carry_ret23;
            zero_6799 = (value27 & 0x40) == 0;
            negative_6799 = value27 & 0x40 & 0x80;
            overflow_6799 = overflow_ret23;
            direct_page_6799 = dp_ret15;
            data_bank_6799 = db_ret15;
            goto shared_6799;
        }
    }
    if (x_ret35) {
        a_hi_67a8 = a_all26 >> 8;
        x_67a8 = (uint8_t)x_ret36;
        y_67a8 = (uint8_t)y_ret19;
        carry_67a8 = carry_ret23;
        overflow_67a8 = overflow_ret23;
        direct_page_67a8 = dp_ret15;
        data_bank_67a8 = db_ret15;
        goto shared_67A8;
    } else {
        a_hi_67a83 = a_all26 >> 8;
        x_67a83 = x_ret36;
        y_67a83 = y_ret19;
        carry_67a83 = carry_ret23;
        overflow_67a83 = overflow_ret23;
        direct_page_67a83 = dp_ret15;
        data_bank_67a83 = db_ret15;
        goto shared_67A8_2;
    }
    shared_67A8_2:;
    uint8_t value28 = BUS8_RDP(c, (data_bank_67a83 << 0x10) + 0x1804);
    if ((value28 & 8) == 0) {
        a_hi_67bd2 = a_hi_67a83;
        x_67bd2 = x_67a83;
        y_67bd2 = y_67a83;
        carry_67bd2 = carry_67a83;
        overflow_67bd2 = overflow_67a83;
        direct_page_67bd2 = direct_page_67a83;
        data_bank_67bd2 = data_bank_67a83;
        goto shared_67BD_1;
    }
    uint8_t value29 = BUS8_RDP(c, (data_bank_67a83 << 0x10) + 0x1801);
    if ((value29 & 0x40) != 0) {
        a_hi_680d2 = a_hi_67a83;
        x_680d2 = x_67a83;
        y_680d2 = y_67a83;
        carry_680d2 = carry_67a83;
        overflow_680d2 = overflow_67a83;
        direct_page_680d2 = direct_page_67a83;
        data_bank_680d2 = data_bank_67a83;
        goto shared_680D_1;
    }
    uint8_t value30 = BUS8_RDP(c, (data_bank_67a83 << 0x10) + 0x1804);
    BUS8_SET(c, (data_bank_67a83 << 0x10) + 0x1804, value30 & 0xF7);
    a_hi_67bd2 = a_hi_67a83;
    x_67bd2 = x_67a83;
    y_67bd2 = y_67a83;
    carry_67bd2 = carry_67a83;
    overflow_67bd2 = overflow_67a83;
    direct_page_67bd2 = direct_page_67a83;
    data_bank_67bd2 = data_bank_67a83;
    goto shared_67BD_1;
    shared_680D_2:;
    a_hi_6847 = a_hi_680d3;
    x_6847 = x_680d3;
    y_6847 = y_680d3;
    carry_6847 = carry_680d3;
    overflow_6847 = overflow_680d3;
    direct_page_6847 = direct_page_680d3;
    data_bank_6847 = data_bank_680d3;
    goto shared_6847;
    shared_6847:;
    uint8_t value31 = BUS8_RDP(c, (data_bank_6847 << 0x10) + 0x1806);
    if (value31 != 0) {
        a_hi_6894 = a_hi_6847;
        x_6894 = x_6847;
        y_6894 = y_6847;
        carry_6894 = carry_6847;
        overflow_6894 = overflow_6847;
        direct_page_6894 = direct_page_6847;
        data_bank_6894 = data_bank_6847;
        goto shared_6894;
    }
    uint8_t value32 = BUS8_RDP(c, (data_bank_6847 << 0x10) + 0x1812);
    if (value32 != 0) {
        a_hi_6894 = a_hi_6847;
        x_6894 = x_6847;
        y_6894 = y_6847;
        carry_6894 = carry_6847;
        overflow_6894 = overflow_6847;
        direct_page_6894 = direct_page_6847;
        data_bank_6894 = data_bank_6847;
        goto shared_6894;
    }
    uint16_t value33 = BUS16_RDP(c, (data_bank_6847 << 0x10) + 0x1800);
    if ((value33 & 0x8000) == 0) {
        a_hi_68942 = value33 >> 8;
        x_68942 = x_6847;
        y_68942 = y_6847;
        carry_68942 = carry_6847;
        overflow_68942 = overflow_6847;
        direct_page_68942 = direct_page_6847;
        data_bank_68942 = data_bank_6847;
        goto shared_6894_1;
    }
    r->a = value33;
    r->x = x_6847;
    r->y = y_6847;
    r->c = carry_6847;
    r->z = (value33 & 0x8000) == 0;
    r->n = value33 & 0x8000;
    r->v = overflow_6847;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_6847;
    r->dp = direct_page_6847;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6860, 0xC06B4C); GUARD_JSL(c, sp_call, 0x6860); } /* persist_native_menu_category_row_and_equipment_rank */
    uint16_t a_all27 = r->a;
    uint16_t x_ret37 = r->x;
    bool carry_ret24 = r->c;
    bool overflow_ret24 = r->v;
    uint8_t value34 = BUS8_RDP(c, (data_bank_6847 << 0x10) + 0x1809);
    if ((uint8_t)(value34 - 1) != 0) {
        a_hi_68a7 = a_all27 >> 8;
        x_68a7 = x_ret37;
        y_68a7 = y_6847;
        carry_68a7 = carry_ret24;
        overflow_68a7 = overflow_ret24;
        direct_page_68a7 = direct_page_6847;
        data_bank_68a7 = data_bank_6847;
        goto shared_68A7;
    }
    uint8_t value35 = BUS8_RDP(c, (data_bank_6847 << 0x10) + 0x1803);
    if ((value35 & 0x80) != 0) {
        a_hi_68a7 = a_all27 >> 8;
        x_68a7 = x_ret37;
        y_68a7 = y_6847;
        carry_68a7 = carry_ret24;
        overflow_68a7 = value35 & 0x40;
        direct_page_68a7 = direct_page_6847;
        data_bank_68a7 = data_bank_6847;
        goto shared_68A7;
    }
    uint8_t value36 = BUS8_RDP(c, (data_bank_6847 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_6847 << 0x10) + 0x1803, value36 | 0x80);
    a_hi_6887 = a_all27 >> 8;
    x_6887 = x_ret37;
    y_6887 = y_6847;
    carry_6887 = carry_ret24;
    overflow_6887 = value35 & 0x40;
    direct_page_6887 = direct_page_6847;
    data_bank_6887 = data_bank_6847;
    goto shared_6887;
    shared_6823:;
    r->a = (a_hi_6823 << 8) | a_6823;
    r->x = x_6823;
    r->y = y_6823;
    r->c = carry_6823;
    r->z = zero_6823;
    r->n = negative_6823;
    r->v = overflow_6823;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_6823;
    r->dp = direct_page_6823;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6827, 0xC0695E); GUARD_JSR(c, sp_call, 0x6827); } /* wait_vblank_before_polling_native_menu_input */
    uint16_t dp_ret16 = r->dp;
    uint8_t db_ret16 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret38 = r->xf;
    uint16_t a_all28 = r->a;
    uint16_t x_ret39 = r->x;
    uint16_t y_ret20 = r->y;
    bool carry_ret25 = r->c;
    bool overflow_ret25 = r->v;
    if ((a_all28 & 0x4000) != 0) {
        if (x_ret38) {
            a_68234 = (uint8_t)(a_all28 & 0x4000);
            a_hi_68234 = (a_all28 & 0x4000) >> 8;
            x_68234 = (uint8_t)x_ret39;
            y_68234 = (uint8_t)y_ret20;
            carry_68234 = carry_ret25;
            zero_68234 = (a_all28 & 0x4000) == 0;
            negative_68234 = a_all28 & 0x4000 & 0x8000;
            overflow_68234 = overflow_ret25;
            direct_page_68234 = dp_ret16;
            data_bank_68234 = db_ret16;
            goto shared_6823_3;
        } else {
            a_6823 = (uint8_t)(a_all28 & 0x4000);
            a_hi_6823 = (a_all28 & 0x4000) >> 8;
            x_6823 = x_ret39;
            y_6823 = y_ret20;
            carry_6823 = carry_ret25;
            zero_6823 = (a_all28 & 0x4000) == 0;
            negative_6823 = a_all28 & 0x4000 & 0x8000;
            overflow_6823 = overflow_ret25;
            direct_page_6823 = dp_ret16;
            data_bank_6823 = db_ret16;
            goto shared_6823;
        }
    }
    if (x_ret38) {
        a_hi_68474 = (a_all28 & 0x4000) >> 8;
        x_68474 = (uint8_t)x_ret39;
        y_68474 = (uint8_t)y_ret20;
        carry_68474 = carry_ret25;
        overflow_68474 = overflow_ret25;
        direct_page_68474 = dp_ret16;
        data_bank_68474 = db_ret16;
        goto shared_6847_3;
    } else {
        a_hi_6847 = (a_all28 & 0x4000) >> 8;
        x_6847 = x_ret39;
        y_6847 = y_ret20;
        carry_6847 = carry_ret25;
        overflow_6847 = overflow_ret25;
        direct_page_6847 = dp_ret16;
        data_bank_6847 = db_ret16;
        goto shared_6847;
    }
    shared_6804:;
    r->a = (a_hi_6804 << 8) | a_6804;
    r->x = x_6804;
    r->y = y_6804;
    r->c = carry_6804;
    r->z = zero_6804;
    r->n = negative_6804;
    r->v = overflow_6804;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_6804;
    r->dp = direct_page_6804;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6806, 0xC068FF); GUARD_JSR(c, sp_call, 0x6806); } /* clear_packed_menu_flag_then_open_native_ring */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6809, 0xC068F1); GUARD_JSR(c, sp_call, 0x6809); } /* advance_native_menu_ring_frames_until_phase_zero */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x680C, 0xC06896); GUARD_JSR(c, sp_call, 0x680C); } /* poll_and_update_native_ring_until_confirm_and_cancel_are_released */
    uint16_t dp_ret19 = r->dp;
    uint8_t db_ret19 = r->db;
    bool x_ret42 = r->xf;
    uint16_t a_all31 = r->a;
    uint16_t x_ret43 = r->x;
    uint16_t y_ret23 = r->y;
    bool carry_ret28 = r->c;
    bool overflow_ret28 = r->v;
    if (x_ret42) {
        a_hi_680d4 = a_all31 >> 8;
        x_680d4 = (uint8_t)x_ret43;
        y_680d4 = (uint8_t)y_ret23;
        carry_680d4 = carry_ret28;
        overflow_680d4 = overflow_ret28;
        direct_page_680d4 = dp_ret19;
        data_bank_680d4 = db_ret19;
        goto shared_680D_3;
    } else {
        a_hi_680d3 = a_all31 >> 8;
        x_680d3 = x_ret43;
        y_680d3 = y_ret23;
        carry_680d3 = carry_ret28;
        overflow_680d3 = overflow_ret28;
        direct_page_680d3 = dp_ret19;
        data_bank_680d3 = db_ret19;
        goto shared_680D_2;
    }
    shared_6823_1:;
    r->a = (a_hi_68232 << 8) | a_68232;
    r->x = x_68232;
    r->y = y_68232;
    r->c = carry_68232;
    r->z = zero_68232;
    r->n = negative_68232;
    r->v = overflow_68232;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_68232;
    r->dp = direct_page_68232;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6827, 0xC0695E); GUARD_JSR(c, sp_call, 0x6827); } /* wait_vblank_before_polling_native_menu_input */
    uint16_t dp_ret20 = r->dp;
    uint8_t db_ret20 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret44 = r->xf;
    uint16_t a_all32 = r->a;
    uint16_t x_ret45 = r->x;
    uint16_t y_ret24 = r->y;
    bool carry_ret29 = r->c;
    bool overflow_ret29 = r->v;
    if ((a_all32 & 0x4000) != 0) {
        if (x_ret44) {
            a_68234 = (uint8_t)(a_all32 & 0x4000);
            a_hi_68234 = (a_all32 & 0x4000) >> 8;
            x_68234 = (uint8_t)x_ret45;
            y_68234 = (uint8_t)y_ret24;
            carry_68234 = carry_ret29;
            zero_68234 = (a_all32 & 0x4000) == 0;
            negative_68234 = a_all32 & 0x4000 & 0x8000;
            overflow_68234 = overflow_ret29;
            direct_page_68234 = dp_ret20;
            data_bank_68234 = db_ret20;
            goto shared_6823_3;
        } else {
            a_6823 = (uint8_t)(a_all32 & 0x4000);
            a_hi_6823 = (a_all32 & 0x4000) >> 8;
            x_6823 = x_ret45;
            y_6823 = y_ret24;
            carry_6823 = carry_ret29;
            zero_6823 = (a_all32 & 0x4000) == 0;
            negative_6823 = a_all32 & 0x4000 & 0x8000;
            overflow_6823 = overflow_ret29;
            direct_page_6823 = dp_ret20;
            data_bank_6823 = db_ret20;
            goto shared_6823;
        }
    }
    if (x_ret44) {
        a_hi_68474 = (a_all32 & 0x4000) >> 8;
        x_68474 = (uint8_t)x_ret45;
        y_68474 = (uint8_t)y_ret24;
        carry_68474 = carry_ret29;
        overflow_68474 = overflow_ret29;
        direct_page_68474 = dp_ret20;
        data_bank_68474 = db_ret20;
        goto shared_6847_3;
    } else {
        a_hi_6847 = (a_all32 & 0x4000) >> 8;
        x_6847 = x_ret45;
        y_6847 = y_ret24;
        carry_6847 = carry_ret29;
        overflow_6847 = overflow_ret29;
        direct_page_6847 = dp_ret20;
        data_bank_6847 = db_ret20;
        goto shared_6847;
    }
    shared_6823_2:;
    r->a = (a_hi_68233 << 8) | a_68233;
    r->x = x_68233;
    r->y = y_68233;
    r->c = carry_68233;
    r->z = zero_68233;
    r->n = negative_68233;
    r->v = overflow_68233;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_68233;
    r->dp = direct_page_68233;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6827, 0xC0695E); GUARD_JSR(c, sp_call, 0x6827); } /* wait_vblank_before_polling_native_menu_input */
    uint16_t dp_ret21 = r->dp;
    uint8_t db_ret21 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret46 = r->xf;
    uint16_t a_all33 = r->a;
    uint16_t x_ret47 = r->x;
    uint16_t y_ret25 = r->y;
    bool carry_ret30 = r->c;
    bool overflow_ret30 = r->v;
    if ((a_all33 & 0x4000) != 0) {
        if (x_ret46) {
            a_68234 = (uint8_t)(a_all33 & 0x4000);
            a_hi_68234 = (a_all33 & 0x4000) >> 8;
            x_68234 = (uint8_t)x_ret47;
            y_68234 = (uint8_t)y_ret25;
            carry_68234 = carry_ret30;
            zero_68234 = (a_all33 & 0x4000) == 0;
            negative_68234 = a_all33 & 0x4000 & 0x8000;
            overflow_68234 = overflow_ret30;
            direct_page_68234 = dp_ret21;
            data_bank_68234 = db_ret21;
            goto shared_6823_3;
        } else {
            a_6823 = (uint8_t)(a_all33 & 0x4000);
            a_hi_6823 = (a_all33 & 0x4000) >> 8;
            x_6823 = x_ret47;
            y_6823 = y_ret25;
            carry_6823 = carry_ret30;
            zero_6823 = (a_all33 & 0x4000) == 0;
            negative_6823 = a_all33 & 0x4000 & 0x8000;
            overflow_6823 = overflow_ret30;
            direct_page_6823 = dp_ret21;
            data_bank_6823 = db_ret21;
            goto shared_6823;
        }
    }
    if (x_ret46) {
        a_hi_68474 = (a_all33 & 0x4000) >> 8;
        x_68474 = (uint8_t)x_ret47;
        y_68474 = (uint8_t)y_ret25;
        carry_68474 = carry_ret30;
        overflow_68474 = overflow_ret30;
        direct_page_68474 = dp_ret21;
        data_bank_68474 = db_ret21;
        goto shared_6847_3;
    } else {
        a_hi_6847 = (a_all33 & 0x4000) >> 8;
        x_6847 = x_ret47;
        y_6847 = y_ret25;
        carry_6847 = carry_ret30;
        overflow_6847 = overflow_ret30;
        direct_page_6847 = dp_ret21;
        data_bank_6847 = db_ret21;
        goto shared_6847;
    }
    shared_6823_3:;
    r->a = (a_hi_68234 << 8) | a_68234;
    r->x = x_68234;
    r->y = y_68234;
    r->c = carry_68234;
    r->z = zero_68234;
    r->n = negative_68234;
    r->v = overflow_68234;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_68234;
    r->dp = direct_page_68234;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6827, 0xC0695E); GUARD_JSR(c, sp_call, 0x6827); } /* wait_vblank_before_polling_native_menu_input */
    uint16_t dp_ret22 = r->dp;
    uint8_t db_ret22 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret48 = r->xf;
    uint16_t a_all34 = r->a;
    uint16_t x_ret49 = r->x;
    uint16_t y_ret26 = r->y;
    bool carry_ret31 = r->c;
    bool overflow_ret31 = r->v;
    if ((a_all34 & 0x4000) != 0) {
        if (x_ret48) {
            a_68234 = (uint8_t)(a_all34 & 0x4000);
            a_hi_68234 = (a_all34 & 0x4000) >> 8;
            x_68234 = (uint8_t)x_ret49;
            y_68234 = (uint8_t)y_ret26;
            carry_68234 = carry_ret31;
            zero_68234 = (a_all34 & 0x4000) == 0;
            negative_68234 = a_all34 & 0x4000 & 0x8000;
            overflow_68234 = overflow_ret31;
            direct_page_68234 = dp_ret22;
            data_bank_68234 = db_ret22;
            goto shared_6823_3;
        } else {
            a_6823 = (uint8_t)(a_all34 & 0x4000);
            a_hi_6823 = (a_all34 & 0x4000) >> 8;
            x_6823 = x_ret49;
            y_6823 = y_ret26;
            carry_6823 = carry_ret31;
            zero_6823 = (a_all34 & 0x4000) == 0;
            negative_6823 = a_all34 & 0x4000 & 0x8000;
            overflow_6823 = overflow_ret31;
            direct_page_6823 = dp_ret22;
            data_bank_6823 = db_ret22;
            goto shared_6823;
        }
    }
    if (x_ret48) {
        a_hi_68474 = (a_all34 & 0x4000) >> 8;
        x_68474 = (uint8_t)x_ret49;
        y_68474 = (uint8_t)y_ret26;
        carry_68474 = carry_ret31;
        overflow_68474 = overflow_ret31;
        direct_page_68474 = dp_ret22;
        data_bank_68474 = db_ret22;
        goto shared_6847_3;
    } else {
        a_hi_6847 = (a_all34 & 0x4000) >> 8;
        x_6847 = x_ret49;
        y_6847 = y_ret26;
        carry_6847 = carry_ret31;
        overflow_6847 = overflow_ret31;
        direct_page_6847 = dp_ret22;
        data_bank_6847 = db_ret22;
        goto shared_6847;
    }
    shared_6847_1:;
    uint8_t value37 = BUS8_RDP(c, (data_bank_68472 << 0x10) + 0x1806);
    if (value37 != 0) {
        a_hi_68943 = a_hi_68472;
        x_68943 = x_68472;
        y_68943 = y_68472;
        carry_68943 = carry_68472;
        overflow_68943 = overflow_68472;
        direct_page_68943 = direct_page_68472;
        data_bank_68943 = data_bank_68472;
        goto shared_6894_2;
    }
    uint8_t value38 = BUS8_RDP(c, (data_bank_68472 << 0x10) + 0x1812);
    if (value38 != 0) {
        a_hi_68943 = a_hi_68472;
        x_68943 = x_68472;
        y_68943 = y_68472;
        carry_68943 = carry_68472;
        overflow_68943 = overflow_68472;
        direct_page_68943 = direct_page_68472;
        data_bank_68943 = data_bank_68472;
        goto shared_6894_2;
    }
    uint16_t value39 = BUS16_RDP(c, (data_bank_68472 << 0x10) + 0x1800);
    if ((value39 & 0x8000) == 0) {
        a_hi_68944 = value39 >> 8;
        x_68944 = x_68472;
        y_68944 = y_68472;
        carry_68944 = carry_68472;
        overflow_68944 = overflow_68472;
        direct_page_68944 = direct_page_68472;
        data_bank_68944 = data_bank_68472;
        goto shared_6894_3;
    }
    r->a = value39;
    r->x = x_68472;
    r->y = y_68472;
    r->c = carry_68472;
    r->z = (value39 & 0x8000) == 0;
    r->n = value39 & 0x8000;
    r->v = overflow_68472;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_68472;
    r->dp = direct_page_68472;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6860, 0xC06B4C); GUARD_JSL(c, sp_call, 0x6860); } /* persist_native_menu_category_row_and_equipment_rank */
    uint16_t a_all35 = r->a;
    uint16_t x_ret50 = r->x;
    bool carry_ret32 = r->c;
    bool overflow_ret32 = r->v;
    uint8_t value40 = BUS8_RDP(c, (data_bank_68472 << 0x10) + 0x1809);
    if ((uint8_t)(value40 - 1) != 0) {
        a_hi_68a7 = a_all35 >> 8;
        x_68a7 = x_ret50;
        y_68a7 = y_68472;
        carry_68a7 = carry_ret32;
        overflow_68a7 = overflow_ret32;
        direct_page_68a7 = direct_page_68472;
        data_bank_68a7 = data_bank_68472;
        goto shared_68A7;
    }
    uint8_t value41 = BUS8_RDP(c, (data_bank_68472 << 0x10) + 0x1803);
    if ((value41 & 0x80) != 0) {
        a_hi_68a7 = a_all35 >> 8;
        x_68a7 = x_ret50;
        y_68a7 = y_68472;
        carry_68a7 = carry_ret32;
        overflow_68a7 = value41 & 0x40;
        direct_page_68a7 = direct_page_68472;
        data_bank_68a7 = data_bank_68472;
        goto shared_68A7;
    }
    uint8_t value42 = BUS8_RDP(c, (data_bank_68472 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_68472 << 0x10) + 0x1803, value42 | 0x80);
    a_hi_6887 = a_all35 >> 8;
    x_6887 = x_ret50;
    y_6887 = y_68472;
    carry_6887 = carry_ret32;
    overflow_6887 = value41 & 0x40;
    direct_page_6887 = direct_page_68472;
    data_bank_6887 = data_bank_68472;
    goto shared_6887;
    shared_6847_2:;
    uint8_t value43 = BUS8_RDP(c, (data_bank_68473 << 0x10) + 0x1806);
    if (value43 != 0) {
        a_hi_6894 = a_hi_68473;
        x_6894 = x_68473;
        y_6894 = y_68473;
        carry_6894 = carry_68473;
        overflow_6894 = overflow_68473;
        direct_page_6894 = direct_page_68473;
        data_bank_6894 = data_bank_68473;
        goto shared_6894;
    }
    uint8_t value44 = BUS8_RDP(c, (data_bank_68473 << 0x10) + 0x1812);
    if (value44 != 0) {
        a_hi_6894 = a_hi_68473;
        x_6894 = x_68473;
        y_6894 = y_68473;
        carry_6894 = carry_68473;
        overflow_6894 = overflow_68473;
        direct_page_6894 = direct_page_68473;
        data_bank_6894 = data_bank_68473;
        goto shared_6894;
    }
    uint16_t value45 = BUS16_RDP(c, (data_bank_68473 << 0x10) + 0x1800);
    if ((value45 & 0x8000) == 0) {
        a_hi_68942 = value45 >> 8;
        x_68942 = x_68473;
        y_68942 = y_68473;
        carry_68942 = carry_68473;
        overflow_68942 = overflow_68473;
        direct_page_68942 = direct_page_68473;
        data_bank_68942 = data_bank_68473;
        goto shared_6894_1;
    }
    r->a = value45;
    r->x = x_68473;
    r->y = y_68473;
    r->c = carry_68473;
    r->z = (value45 & 0x8000) == 0;
    r->n = value45 & 0x8000;
    r->v = overflow_68473;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_68473;
    r->dp = direct_page_68473;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6860, 0xC06B4C); GUARD_JSL(c, sp_call, 0x6860); } /* persist_native_menu_category_row_and_equipment_rank */
    uint16_t a_all36 = r->a;
    uint16_t x_ret51 = r->x;
    bool carry_ret33 = r->c;
    bool overflow_ret33 = r->v;
    uint8_t value46 = BUS8_RDP(c, (data_bank_68473 << 0x10) + 0x1809);
    if ((uint8_t)(value46 - 1) != 0) {
        a_hi_68a7 = a_all36 >> 8;
        x_68a7 = x_ret51;
        y_68a7 = y_68473;
        carry_68a7 = carry_ret33;
        overflow_68a7 = overflow_ret33;
        direct_page_68a7 = direct_page_68473;
        data_bank_68a7 = data_bank_68473;
        goto shared_68A7;
    }
    uint8_t value47 = BUS8_RDP(c, (data_bank_68473 << 0x10) + 0x1803);
    if ((value47 & 0x80) != 0) {
        a_hi_68a7 = a_all36 >> 8;
        x_68a7 = x_ret51;
        y_68a7 = y_68473;
        carry_68a7 = carry_ret33;
        overflow_68a7 = value47 & 0x40;
        direct_page_68a7 = direct_page_68473;
        data_bank_68a7 = data_bank_68473;
        goto shared_68A7;
    }
    uint8_t value48 = BUS8_RDP(c, (data_bank_68473 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_68473 << 0x10) + 0x1803, value48 | 0x80);
    a_hi_6887 = a_all36 >> 8;
    x_6887 = x_ret51;
    y_6887 = y_68473;
    carry_6887 = carry_ret33;
    overflow_6887 = value47 & 0x40;
    direct_page_6887 = direct_page_68473;
    data_bank_6887 = data_bank_68473;
    goto shared_6887;
    shared_6894:;
    a_hi_68e0 = a_hi_6894;
    x_68e0 = x_6894;
    y_68e0 = y_6894;
    carry_68e0 = carry_6894;
    overflow_68e0 = overflow_6894;
    direct_page_68e0 = direct_page_6894;
    data_bank_68e0 = data_bank_6894;
    goto shared_68E0;
    shared_6894_1:;
    a_hi_68e02 = a_hi_68942;
    x_68e02 = x_68942;
    y_68e02 = y_68942;
    carry_68e02 = carry_68942;
    overflow_68e02 = overflow_68942;
    direct_page_68e02 = direct_page_68942;
    data_bank_68e02 = data_bank_68942;
    goto shared_68E0_1;
    shared_68A7:;
    r->a = (a_hi_68a7 << 8) | (uint8_t)a;
    r->x = x_68a7;
    r->y = y_68a7;
    r->c = carry_68a7;
    r->v = overflow_68a7;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_68a7;
    r->dp = direct_page_68a7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x68A9, 0xC071A2); GUARD_JSR(c, sp_call, 0x68A9); } /* dispatch_native_seven_category_ring_action_and_mark_equipment_pair */
    uint16_t dp_ret23 = r->dp;
    uint8_t db_ret23 = r->db;
    uint16_t a_all37 = r->a;
    uint16_t x_ret53 = r->x;
    uint16_t y_ret27 = r->y;
    bool carry_ret34 = r->c;
    uint8_t value49 = BUS8_RDP(c, (db_ret23 << 0x10) + 0x1826);
    if (value49 != 0) {
        uint8_t value50 = BUS8_RDP(c, (db_ret23 << 0x10) + 0x1804);
        if ((value50 & 0x40) != 0) {
            a_hi_68e03 = a_all37 >> 8;
            x_68e03 = (uint8_t)x_ret53;
            y_68e03 = (uint8_t)y_ret27;
            carry_68e03 = carry_ret34;
            overflow_68e03 = value50 & 0x40;
            direct_page_68e03 = dp_ret23;
            data_bank_68e03 = db_ret23;
            goto shared_68E0_2;
        }
        uint8_t value51 = BUS8_RDP(c, (db_ret23 << 0x10) + 0x1804);
        if ((value51 & 0x10) != 0) {
            a_hi_68d4 = a_all37 >> 8;
            x_68d4 = (uint8_t)x_ret53;
            y_68d4 = (uint8_t)y_ret27;
            overflow_68d4 = value51 & 0x40;
            direct_page_68d4 = dp_ret23;
            data_bank_68d4 = db_ret23;
            goto shared_68D4;
        }
        uint8_t value52 = BUS8_RDP(c, (db_ret23 << 0x10) + 0x1803);
        if ((value52 & 0x40) != 0) {
            a_hi_68d4 = a_all37 >> 8;
            x_68d4 = (uint8_t)x_ret53;
            y_68d4 = (uint8_t)y_ret27;
            overflow_68d4 = value51 & 0x40;
            direct_page_68d4 = dp_ret23;
            data_bank_68d4 = db_ret23;
            goto shared_68D4;
        }
        if ((value52 & 2) == 0) {
            r->a = (a_all37 >> 8 << 8) | value52;
            r->x = (uint8_t)x_ret53;
            r->y = (uint8_t)y_ret27;
            r->z = (value52 & 2) == 0;
            r->n = value52 & 0x80;
            r->v = value51 & 0x40;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0x6878, 0xD9FC90); GUARD_JSL(c, sp_call, 0x6878); } /* check_native_menu_inventory_availability */
            uint16_t a_all38 = r->a;
            uint16_t x_ret54 = r->x;
            uint16_t y_ret28 = r->y;
            bool carry_ret35 = r->c;
            bool zero_ret38 = r->z;
            if (!zero_ret38) {
                a_hi_6887 = a_all38 >> 8;
                x_6887 = x_ret54;
                y_6887 = y_ret28;
                carry_6887 = carry_ret35;
                overflow_6887 = value51 & 0x40;
                direct_page_6887 = dp_ret23;
                data_bank_6887 = db_ret23;
                goto shared_6887;
            }
            BUS8_SET(c, (db_ret23 << 0x10) + 0x1809, 2);
            uint8_t value53 = BUS8_RDP(c, (db_ret23 << 0x10) + 0x1803);
            BUS8_SET(c, (db_ret23 << 0x10) + 0x1803, value53 & 0x35);
            a_hi_6887 = a_all38 >> 8;
            x_6887 = x_ret54;
            y_6887 = y_ret28;
            carry_6887 = carry_ret35;
            overflow_6887 = value51 & 0x40;
            direct_page_6887 = dp_ret23;
            data_bank_6887 = db_ret23;
            goto shared_6887;
        }
        r->a = (a_all37 >> 8 << 8) | value52;
        r->x = (uint8_t)x_ret53;
        r->y = (uint8_t)y_ret27;
        r->z = (value52 & 2) == 0;
        r->n = value52 & 0x80;
        r->v = value51 & 0x40;
        r->mf = 1;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x68D1, 0xC06896); GUARD_JSR(c, sp_call, 0x68D1); } /* poll_and_update_native_ring_until_confirm_and_cancel_are_released */
        uint16_t dp_ret24 = r->dp;
        uint8_t db_ret24 = r->db;
        bool x_ret55 = r->xf;
        uint16_t a_all39 = r->a;
        uint16_t x_ret56 = r->x;
        uint16_t y_ret29 = r->y;
        bool carry_ret36 = r->c;
        bool overflow_ret35 = r->v;
        if (x_ret55) {
            a_hi_68e04 = a_all39 >> 8;
            x_68e04 = (uint8_t)x_ret56;
            y_68e04 = (uint8_t)y_ret29;
            carry_68e04 = carry_ret36;
            overflow_68e04 = overflow_ret35;
            direct_page_68e04 = dp_ret24;
            data_bank_68e04 = db_ret24;
            goto shared_68E0_3;
        } else {
            a_hi_68e02 = a_all39 >> 8;
            x_68e02 = x_ret56;
            y_68e02 = y_ret29;
            carry_68e02 = carry_ret36;
            overflow_68e02 = overflow_ret35;
            direct_page_68e02 = dp_ret24;
            data_bank_68e02 = db_ret24;
            goto shared_68E0_1;
        }
    }
    r->a = (a_all37 >> 8 << 8) | value49;
    r->x = (uint8_t)x_ret53;
    r->y = (uint8_t)y_ret27;
    r->z = value49 == 0;
    r->n = value49 & 0x80;
    r->mf = 1;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x68B4, 0xD0C83F); GUARD_JSL(c, sp_call, 0x68B4); } /* hide_native_menu_icon_oam_objects */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
    shared_6887:;
    r->x = x_6887;
    r->y = y_6887;
    r->c = carry_6887;
    r->v = overflow_6887;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_6887;
    r->dp = direct_page_6887;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6889, 0xC06906); GUARD_JSR(c, sp_call, 0x6889); } /* request_native_menu_ring_open_and_build_selected_list */
    uint8_t db_ret25 = r->db;
    uint16_t a_all41 = r->a;
    uint8_t value54 = BUS8_RDP(c, (db_ret25 << 0x10) + 0x1802);
    BUS8_SET(c, (db_ret25 << 0x10) + 0x1802, value54 | 4);
    r->a = (a_all41 >> 8 << 8) | 4;
    r->z = (value54 & 4) == 0;
    r->n = 0;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6893, 0xC06896); GUARD_JSR(c, sp_call, 0x6893); } /* poll_and_update_native_ring_until_confirm_and_cancel_are_released */
    uint16_t dp_ret26 = r->dp;
    uint8_t db_ret26 = r->db;
    bool x_ret60 = r->xf;
    uint16_t a_all42 = r->a;
    uint16_t x_ret61 = r->x;
    uint16_t y_ret31 = r->y;
    bool carry_ret39 = r->c;
    bool overflow_ret37 = r->v;
    if (x_ret60) {
        a_hi_68944 = a_all42 >> 8;
        x_68944 = (uint8_t)x_ret61;
        y_68944 = (uint8_t)y_ret31;
        carry_68944 = carry_ret39;
        overflow_68944 = overflow_ret37;
        direct_page_68944 = dp_ret26;
        data_bank_68944 = db_ret26;
        goto shared_6894_3;
    } else {
        a_hi_68942 = a_all42 >> 8;
        x_68942 = x_ret61;
        y_68942 = y_ret31;
        carry_68942 = carry_ret39;
        overflow_68942 = overflow_ret37;
        direct_page_68942 = dp_ret26;
        data_bank_68942 = db_ret26;
        goto shared_6894_1;
    }
    shared_6847_3:;
    uint8_t value55 = BUS8_RDP(c, (data_bank_68474 << 0x10) + 0x1806);
    if (value55 != 0) {
        a_hi_68943 = a_hi_68474;
        x_68943 = x_68474;
        y_68943 = y_68474;
        carry_68943 = carry_68474;
        overflow_68943 = overflow_68474;
        direct_page_68943 = direct_page_68474;
        data_bank_68943 = data_bank_68474;
        goto shared_6894_2;
    }
    uint8_t value56 = BUS8_RDP(c, (data_bank_68474 << 0x10) + 0x1812);
    if (value56 != 0) {
        a_hi_68943 = a_hi_68474;
        x_68943 = x_68474;
        y_68943 = y_68474;
        carry_68943 = carry_68474;
        overflow_68943 = overflow_68474;
        direct_page_68943 = direct_page_68474;
        data_bank_68943 = data_bank_68474;
        goto shared_6894_2;
    }
    uint16_t value57 = BUS16_RDP(c, (data_bank_68474 << 0x10) + 0x1800);
    if ((value57 & 0x8000) == 0) {
        a_hi_68944 = value57 >> 8;
        x_68944 = x_68474;
        y_68944 = y_68474;
        carry_68944 = carry_68474;
        overflow_68944 = overflow_68474;
        direct_page_68944 = direct_page_68474;
        data_bank_68944 = data_bank_68474;
        goto shared_6894_3;
    }
    r->a = value57;
    r->x = x_68474;
    r->y = y_68474;
    r->c = carry_68474;
    r->z = (value57 & 0x8000) == 0;
    r->n = value57 & 0x8000;
    r->v = overflow_68474;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_68474;
    r->dp = direct_page_68474;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6860, 0xC06B4C); GUARD_JSL(c, sp_call, 0x6860); } /* persist_native_menu_category_row_and_equipment_rank */
    uint16_t a_all43 = r->a;
    uint16_t x_ret62 = r->x;
    bool carry_ret40 = r->c;
    bool overflow_ret38 = r->v;
    uint8_t value58 = BUS8_RDP(c, (data_bank_68474 << 0x10) + 0x1809);
    if ((uint8_t)(value58 - 1) != 0) {
        a_hi_68a7 = a_all43 >> 8;
        x_68a7 = x_ret62;
        y_68a7 = y_68474;
        carry_68a7 = carry_ret40;
        overflow_68a7 = overflow_ret38;
        direct_page_68a7 = direct_page_68474;
        data_bank_68a7 = data_bank_68474;
        goto shared_68A7;
    }
    uint8_t value59 = BUS8_RDP(c, (data_bank_68474 << 0x10) + 0x1803);
    if ((value59 & 0x80) != 0) {
        a_hi_68a7 = a_all43 >> 8;
        x_68a7 = x_ret62;
        y_68a7 = y_68474;
        carry_68a7 = carry_ret40;
        overflow_68a7 = value59 & 0x40;
        direct_page_68a7 = direct_page_68474;
        data_bank_68a7 = data_bank_68474;
        goto shared_68A7;
    }
    uint8_t value60 = BUS8_RDP(c, (data_bank_68474 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_68474 << 0x10) + 0x1803, value60 | 0x80);
    a_hi_6887 = a_all43 >> 8;
    x_6887 = x_ret62;
    y_6887 = y_68474;
    carry_6887 = carry_ret40;
    overflow_6887 = value59 & 0x40;
    direct_page_6887 = direct_page_68474;
    data_bank_6887 = data_bank_68474;
    goto shared_6887;
    shared_680D_3:;
    a_hi_68474 = a_hi_680d4;
    x_68474 = x_680d4;
    y_68474 = y_680d4;
    carry_68474 = carry_680d4;
    overflow_68474 = overflow_680d4;
    direct_page_68474 = direct_page_680d4;
    data_bank_68474 = data_bank_680d4;
    goto shared_6847_3;
    shared_6894_2:;
    a_hi_68e03 = a_hi_68943;
    x_68e03 = x_68943;
    y_68e03 = y_68943;
    carry_68e03 = carry_68943;
    overflow_68e03 = overflow_68943;
    direct_page_68e03 = direct_page_68943;
    data_bank_68e03 = data_bank_68943;
    goto shared_68E0_2;
    shared_6894_3:;
    a_hi_68e04 = a_hi_68944;
    x_68e04 = x_68944;
    y_68e04 = y_68944;
    carry_68e04 = carry_68944;
    overflow_68e04 = overflow_68944;
    direct_page_68e04 = direct_page_68944;
    data_bank_68e04 = data_bank_68944;
    goto shared_68E0_3;
    shared_68E0:;
    uint8_t value61 = BUS8_RDP(c, (data_bank_68e0 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_68e0 << 0x10) + 0x1803, value61 & 0xFD);
    r->a = (a_hi_68e0 << 8) | 2;
    r->x = x_68e0;
    r->y = y_68e0;
    r->c = carry_68e0;
    r->v = overflow_68e0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_68e0;
    r->dp = direct_page_68e0;
    RETURN_RTS(c);
    shared_68E0_1:;
    uint8_t value62 = BUS8_RDP(c, (data_bank_68e02 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_68e02 << 0x10) + 0x1803, value62 & 0xFD);
    r->a = (a_hi_68e02 << 8) | 2;
    r->x = x_68e02;
    r->y = y_68e02;
    r->c = carry_68e02;
    r->v = overflow_68e02;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_68e02;
    r->dp = direct_page_68e02;
    RETURN_RTS(c);
    shared_68E0_2:;
    uint8_t value63 = BUS8_RDP(c, (data_bank_68e03 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_68e03 << 0x10) + 0x1803, value63 & 0xFD);
    r->a = (a_hi_68e03 << 8) | 2;
    r->x = x_68e03;
    r->y = y_68e03;
    r->c = carry_68e03;
    r->v = overflow_68e03;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_68e03;
    r->dp = direct_page_68e03;
    RETURN_RTS(c);
    shared_68D4:;
    uint8_t value64 = BUS8_RDP(c, (data_bank_68d4 << 0x10) + 0x19F0);
    if (value64 == 0xC0) {
        a_hi_68e03 = a_hi_68d4;
        x_68e03 = x_68d4;
        y_68e03 = y_68d4;
        carry_68e03 = value64 >= 0xC0;
        overflow_68e03 = overflow_68d4;
        direct_page_68e03 = direct_page_68d4;
        data_bank_68e03 = data_bank_68d4;
        goto shared_68E0_2;
    }
    r->a = (a_hi_68d4 << 8) | value64;
    r->x = x_68d4;
    r->y = y_68d4;
    r->c = value64 >= 0xC0;
    r->z = value64 == 0xC0;
    r->n = (uint8_t)(value64 - 0xC0) & 0x80;
    r->v = overflow_68d4;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_68d4;
    r->dp = direct_page_68d4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x68DF, 0xC06896); GUARD_JSR(c, sp_call, 0x68DF); } /* poll_and_update_native_ring_until_confirm_and_cancel_are_released */
    uint16_t dp_ret27 = r->dp;
    uint8_t db_ret27 = r->db;
    bool x_ret63 = r->xf;
    uint16_t a_all44 = r->a;
    uint16_t x_ret64 = r->x;
    uint16_t y_ret32 = r->y;
    bool carry_ret41 = r->c;
    bool overflow_ret39 = r->v;
    if (x_ret63) {
        a_hi_68e04 = a_all44 >> 8;
        x_68e04 = (uint8_t)x_ret64;
        y_68e04 = (uint8_t)y_ret32;
        carry_68e04 = carry_ret41;
        overflow_68e04 = overflow_ret39;
        direct_page_68e04 = dp_ret27;
        data_bank_68e04 = db_ret27;
        goto shared_68E0_3;
    } else {
        a_hi_68e02 = a_all44 >> 8;
        x_68e02 = x_ret64;
        y_68e02 = y_ret32;
        carry_68e02 = carry_ret41;
        overflow_68e02 = overflow_ret39;
        direct_page_68e02 = dp_ret27;
        data_bank_68e02 = db_ret27;
        goto shared_68E0_1;
    }
    shared_68E0_3:;
    uint8_t value65 = BUS8_RDP(c, (data_bank_68e04 << 0x10) + 0x1803);
    BUS8_SET(c, (data_bank_68e04 << 0x10) + 0x1803, value65 & 0xFD);
    r->a = (a_hi_68e04 << 8) | 2;
    r->x = x_68e04;
    r->y = y_68e04;
    r->c = carry_68e04;
    r->v = overflow_68e04;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_68e04;
    r->dp = direct_page_68e04;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06775, SOM_RTS, "gen", cycle_shop_actor_then_consume_held_actor_change_input, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, -1, 373, 142)
