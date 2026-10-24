#include "som_c.h"

/* C03C19 coordinate_actor_combat_status_and_buff_timers   [class B, 111 bytes, 44 instructions]
 * Source: src/rom/coordinate_actor_combat_status_and_buff_timers.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void coordinate_actor_combat_status_and_buff_timers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_3c35 = 0;
    uint16_t x_3c35 = 0;
    uint16_t y_3c35 = 0;
    bool carry_3c35 = 0;
    bool overflow_3c35 = 0;
    uint8_t a_hi_3c87 = 0;
    uint8_t y_3c87 = 0;
    bool carry_3c87 = 0;
    bool overflow_3c87 = 0;
    uint16_t direct_page_3c87 = 0;
    uint8_t data_bank_3c87 = 0;
    uint8_t a_hi_3c872 = 0;
    uint16_t y_3c872 = 0;
    bool carry_3c872 = 0;
    bool overflow_3c872 = 0;
    uint16_t direct_page_3c872 = 0;
    uint8_t data_bank_3c872 = 0;
    uint8_t a_hi_3c6c = 0;
    uint8_t x_3c6c = 0;
    uint8_t y_3c6c = 0;
    bool carry_3c6c = 0;
    bool overflow_3c6c = 0;
    uint16_t direct_page_3c6c = 0;
    uint8_t data_bank_3c6c = 0;
    uint8_t a_hi_3c6c2 = 0;
    uint16_t x_3c6c2 = 0;
    uint16_t y_3c6c2 = 0;
    bool carry_3c6c2 = 0;
    bool overflow_3c6c2 = 0;
    uint16_t direct_page_3c6c2 = 0;
    uint8_t data_bank_3c6c2 = 0;
    uint8_t a_hi_3c5f = 0;
    uint8_t x_3c5f = 0;
    uint8_t y_3c5f = 0;
    bool carry_3c5f = 0;
    bool overflow_3c5f = 0;
    uint16_t direct_page_3c5f = 0;
    uint8_t data_bank_3c5f = 0;
    uint8_t a_hi_3c5f2 = 0;
    uint16_t x_3c5f2 = 0;
    uint16_t y_3c5f2 = 0;
    bool carry_3c5f2 = 0;
    bool overflow_3c5f2 = 0;
    uint16_t direct_page_3c5f2 = 0;
    uint8_t data_bank_3c5f2 = 0;
    uint8_t a_hi_3c6c3 = 0;
    uint8_t x_3c6c3 = 0;
    uint8_t y_3c6c3 = 0;
    bool carry_3c6c3 = 0;
    bool overflow_3c6c3 = 0;
    uint16_t direct_page_3c6c3 = 0;
    uint8_t data_bank_3c6c3 = 0;
    uint8_t a_hi_3c6c4 = 0;
    uint16_t x_3c6c4 = 0;
    uint16_t y_3c6c4 = 0;
    bool carry_3c6c4 = 0;
    bool overflow_3c6c4 = 0;
    uint16_t direct_page_3c6c4 = 0;
    uint8_t data_bank_3c6c4 = 0;
    uint8_t a_hi_3c5f3 = 0;
    uint8_t x_3c5f3 = 0;
    uint8_t y_3c5f3 = 0;
    bool carry_3c5f3 = 0;
    bool overflow_3c5f3 = 0;
    uint16_t direct_page_3c5f3 = 0;
    uint8_t data_bank_3c5f3 = 0;
    uint8_t a_hi_3c5f4 = 0;
    uint16_t x_3c5f4 = 0;
    uint16_t y_3c5f4 = 0;
    bool carry_3c5f4 = 0;
    bool overflow_3c5f4 = 0;
    uint16_t direct_page_3c5f4 = 0;
    uint8_t data_bank_3c5f4 = 0;
    RAM8(0xE1B9 + x)--;
    if (RAM8(0xE1B9 + x) != 0) {
        a_hi_3c35 = a_hi;
        x_3c35 = x;
        y_3c35 = y;
        carry_3c35 = carry;
        overflow_3c35 = overflow;
        goto shared_3C35;
    }
    if (!(RAM8(ACTOR_STATUS_HIGH + x) & 0x80)) {
        a_hi_3c35 = a_hi;
        x_3c35 = x;
        y_3c35 = y;
        carry_3c35 = carry;
        overflow_3c35 = overflow;
        goto shared_3C35;
    }
    if (!(RAM8(ACTOR_KIND_FLAGS + x) & 0x80)) {
        a_hi_3c35 = a_hi;
        x_3c35 = x;
        y_3c35 = y;
        carry_3c35 = carry;
        overflow_3c35 = overflow;
        goto shared_3C35;
    }
    RAM8(0xE1FA + x) |= 4;
    RAM8(0xE1E3 + x) = 0xF1;
    a_hi_3c35 = a_hi;
    x_3c35 = x;
    y_3c35 = y;
    carry_3c35 = carry;
    overflow_3c35 = overflow;
    shared_3C35:;
    r->a = (a_hi_3c35 << 8) | a;
    r->x = x_3c35;
    r->y = y_3c35;
    r->c = carry_3c35;
    r->v = overflow_3c35;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3C37, 0xC03CA5); GUARD_JSR(c, sp_call, 0x3C37); } /* advance_actor_death_and_low_status_timer */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1B9 + x_ret2);
    if ((value4 & 3) != 0) {
        if (x_ret) {
            a_hi_3c87 = a_all >> 8;
            y_3c87 = (uint8_t)y_ret;
            carry_3c87 = carry_ret;
            overflow_3c87 = overflow_ret;
            direct_page_3c87 = dp_ret;
            data_bank_3c87 = db_ret;
            goto shared_3C87;
        } else {
            a_hi_3c872 = a_all >> 8;
            y_3c872 = y_ret;
            carry_3c872 = carry_ret;
            overflow_3c872 = overflow_ret;
            direct_page_3c872 = dp_ret;
            data_bank_3c872 = db_ret;
            goto shared_3C87_1;
        }
    }
    r->a = a_all >> 8 << 8 | (value4 & 3);
    r->z = (value4 & 3) == 0;
    r->n = value4 & 3 & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3C41, 0xC03D1C); GUARD_JSR(c, sp_call, 0x3C41); } /* expire_combat_low_status_group_timer */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3C44, 0xC03D31); GUARD_JSR(c, sp_call, 0x3C44); } /* expire_combat_mixed_status_group_timer */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3C47, 0xC03D4D); GUARD_JSR(c, sp_call, 0x3C47); } /* expire_combat_high_status_group_timer */
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3C4A, 0xC03D5F); GUARD_JSR(c, sp_call, 0x3C4A); } /* advance_status_damage_timer_and_apply_nonlethal_hp_loss */
    { const uint16_t sp_call = r->sp; JSR(c, 0x3C4D, 0xC03D91); GUARD_JSR(c, sp_call, 0x3C4D); } /* expire_four_combat_buff_pairs_and_enqueue_notice */
    bool m_ret2 = r->mf;
    bool x_ret8 = r->xf;
    uint16_t a_all6 = r->a;
    uint16_t x_ret9 = r->x;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    if (m_ret2) {
        uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x81));
        if (value5 != 0) {
            if (x_ret8) {
                a_hi_3c6c = a_all6 >> 8;
                x_3c6c = (uint8_t)x_ret9;
                y_3c6c = (uint8_t)y_ret3;
                carry_3c6c = carry_ret3;
                overflow_3c6c = overflow_ret3;
                direct_page_3c6c = dp_ret;
                data_bank_3c6c = db_ret;
                goto shared_3C6C;
            } else {
                a_hi_3c6c2 = a_all6 >> 8;
                x_3c6c2 = x_ret9;
                y_3c6c2 = y_ret3;
                carry_3c6c2 = carry_ret3;
                overflow_3c6c2 = overflow_ret3;
                direct_page_3c6c2 = dp_ret;
                data_bank_3c6c2 = db_ret;
                goto shared_3C6C_1;
            }
        }
        uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0xCC79);
        if (value6 == 0) {
            if (x_ret8) {
                a_hi_3c5f = a_all6 >> 8;
                x_3c5f = (uint8_t)x_ret9;
                y_3c5f = (uint8_t)y_ret3;
                carry_3c5f = carry_ret3;
                overflow_3c5f = overflow_ret3;
                direct_page_3c5f = dp_ret;
                data_bank_3c5f = db_ret;
                goto shared_3C5F;
            } else {
                a_hi_3c5f2 = a_all6 >> 8;
                x_3c5f2 = x_ret9;
                y_3c5f2 = y_ret3;
                carry_3c5f2 = carry_ret3;
                overflow_3c5f2 = overflow_ret3;
                direct_page_3c5f2 = dp_ret;
                data_bank_3c5f2 = db_ret;
                goto shared_3C5F_1;
            }
        }
        uint8_t value7 = BUS8_RDP(c, (db_ret << 0x10) + 0xCC79);
        BUS8_SET(c, (db_ret << 0x10) + 0xCC79, (uint8_t)(value7 - 1));
        if ((uint8_t)(value7 - 1) != 0) {
            if (x_ret8) {
                a_hi_3c5f = a_all6 >> 8;
                x_3c5f = (uint8_t)x_ret9;
                y_3c5f = (uint8_t)y_ret3;
                carry_3c5f = carry_ret3;
                overflow_3c5f = overflow_ret3;
                direct_page_3c5f = dp_ret;
                data_bank_3c5f = db_ret;
                goto shared_3C5F;
            } else {
                a_hi_3c5f2 = a_all6 >> 8;
                x_3c5f2 = x_ret9;
                y_3c5f2 = y_ret3;
                carry_3c5f2 = carry_ret3;
                overflow_3c5f2 = overflow_ret3;
                direct_page_3c5f2 = dp_ret;
                data_bank_3c5f2 = db_ret;
                goto shared_3C5F_1;
            }
        }
        r->a = (a_all6 >> 8 << 8) | value6;
        r->z = (uint8_t)(value7 - 1) == 0;
        r->n = (uint8_t)(value7 - 1) & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3C5E, 0xC03C88); GUARD_JSR(c, sp_call, 0x3C5E); } /* expire_party_mana_weapon_and_rebuild_attributes */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        bool x_ret10 = r->xf;
        uint16_t a_all7 = r->a;
        uint16_t x_ret11 = r->x;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        if (x_ret10) {
            a_hi_3c5f = a_all7 >> 8;
            x_3c5f = (uint8_t)x_ret11;
            y_3c5f = (uint8_t)y_ret4;
            carry_3c5f = carry_ret4;
            overflow_3c5f = overflow_ret4;
            direct_page_3c5f = dp_ret2;
            data_bank_3c5f = db_ret2;
            goto shared_3C5F;
        } else {
            a_hi_3c5f2 = a_all7 >> 8;
            x_3c5f2 = x_ret11;
            y_3c5f2 = y_ret4;
            carry_3c5f2 = carry_ret4;
            overflow_3c5f2 = overflow_ret4;
            direct_page_3c5f2 = dp_ret2;
            data_bank_3c5f2 = db_ret2;
            goto shared_3C5F_1;
        }
    } else {
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x81));
        if (value8 != 0) {
            if (x_ret8) {
                a_hi_3c6c3 = value8 >> 8;
                x_3c6c3 = (uint8_t)x_ret9;
                y_3c6c3 = (uint8_t)y_ret3;
                carry_3c6c3 = carry_ret3;
                overflow_3c6c3 = overflow_ret3;
                direct_page_3c6c3 = dp_ret;
                data_bank_3c6c3 = db_ret;
                goto shared_3C6C_2;
            } else {
                a_hi_3c6c4 = value8 >> 8;
                x_3c6c4 = x_ret9;
                y_3c6c4 = y_ret3;
                carry_3c6c4 = carry_ret3;
                overflow_3c6c4 = overflow_ret3;
                direct_page_3c6c4 = dp_ret;
                data_bank_3c6c4 = db_ret;
                goto shared_3C6C_3;
            }
        }
        uint16_t value9 = BUS16_RDP(c, (db_ret << 0x10) + 0xCC79);
        if (value9 == 0) {
            if (x_ret8) {
                a_hi_3c5f3 = value9 >> 8;
                x_3c5f3 = (uint8_t)x_ret9;
                y_3c5f3 = (uint8_t)y_ret3;
                carry_3c5f3 = carry_ret3;
                overflow_3c5f3 = overflow_ret3;
                direct_page_3c5f3 = dp_ret;
                data_bank_3c5f3 = db_ret;
                goto shared_3C5F_2;
            } else {
                a_hi_3c5f4 = value9 >> 8;
                x_3c5f4 = x_ret9;
                y_3c5f4 = y_ret3;
                carry_3c5f4 = carry_ret3;
                overflow_3c5f4 = overflow_ret3;
                direct_page_3c5f4 = dp_ret;
                data_bank_3c5f4 = db_ret;
                goto shared_3C5F_3;
            }
        }
        uint16_t value10 = BUS16_RDP(c, (db_ret << 0x10) + 0xCC79);
        BUS16_RMW_SET(c, (db_ret << 0x10) + 0xCC79, (uint16_t)(value10 - 1));
        if ((uint16_t)(value10 - 1) != 0) {
            if (x_ret8) {
                a_hi_3c5f3 = value9 >> 8;
                x_3c5f3 = (uint8_t)x_ret9;
                y_3c5f3 = (uint8_t)y_ret3;
                carry_3c5f3 = carry_ret3;
                overflow_3c5f3 = overflow_ret3;
                direct_page_3c5f3 = dp_ret;
                data_bank_3c5f3 = db_ret;
                goto shared_3C5F_2;
            } else {
                a_hi_3c5f4 = value9 >> 8;
                x_3c5f4 = x_ret9;
                y_3c5f4 = y_ret3;
                carry_3c5f4 = carry_ret3;
                overflow_3c5f4 = overflow_ret3;
                direct_page_3c5f4 = dp_ret;
                data_bank_3c5f4 = db_ret;
                goto shared_3C5F_3;
            }
        }
        r->a = value9;
        r->z = (uint16_t)(value10 - 1) == 0;
        r->n = (uint16_t)(value10 - 1) & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3C5E, 0xC03C88); GUARD_JSR(c, sp_call, 0x3C5E); } /* expire_party_mana_weapon_and_rebuild_attributes */
        uint16_t dp_ret3 = r->dp;
        uint8_t db_ret3 = r->db;
        bool x_ret12 = r->xf;
        uint16_t a_all8 = r->a;
        uint16_t x_ret13 = r->x;
        uint16_t y_ret5 = r->y;
        bool carry_ret5 = r->c;
        bool overflow_ret5 = r->v;
        if (x_ret12) {
            a_hi_3c5f = a_all8 >> 8;
            x_3c5f = (uint8_t)x_ret13;
            y_3c5f = (uint8_t)y_ret5;
            carry_3c5f = carry_ret5;
            overflow_3c5f = overflow_ret5;
            direct_page_3c5f = dp_ret3;
            data_bank_3c5f = db_ret3;
            goto shared_3C5F;
        } else {
            a_hi_3c5f2 = a_all8 >> 8;
            x_3c5f2 = x_ret13;
            y_3c5f2 = y_ret5;
            carry_3c5f2 = carry_ret5;
            overflow_3c5f2 = overflow_ret5;
            direct_page_3c5f2 = dp_ret3;
            data_bank_3c5f2 = db_ret3;
            goto shared_3C5F_1;
        }
    }
    shared_3C87:;
    r->a = (a_hi_3c87 << 8) | a;
    r->y = y_3c87;
    r->c = carry_3c87;
    r->v = overflow_3c87;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_3c87;
    r->dp = direct_page_3c87;
    RETURN_RTS(c);
    shared_3C87_1:;
    r->a = (a_hi_3c872 << 8) | a;
    r->y = y_3c872;
    r->c = carry_3c872;
    r->v = overflow_3c872;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_3c872;
    r->dp = direct_page_3c872;
    RETURN_RTS(c);
    shared_3C6C:;
    uint8_t value11 = BUS8_RDP(c, (data_bank_3c6c << 0x10) + 0xE1B1 + x_3c6c);
    if ((value11 & 4) == 0) {
        a_hi_3c87 = a_hi_3c6c;
        y_3c87 = y_3c6c;
        carry_3c87 = carry_3c6c;
        overflow_3c87 = overflow_3c6c;
        direct_page_3c87 = direct_page_3c6c;
        data_bank_3c87 = data_bank_3c6c;
        goto shared_3C87;
    }
    BUS8_SET(c, (data_bank_3c6c << 0x10) + 0xE1B1 + x_3c6c, value11 & 0xFB);
    uint16_t value12 = BUS16_RDP(c, (data_bank_3c6c << 0x10) + 0xE190 + x_3c6c);
    if (value12 == 0) {
        a_hi_3c87 = value12 >> 8;
        y_3c87 = y_3c6c;
        carry_3c87 = carry_3c6c;
        overflow_3c87 = overflow_3c6c;
        direct_page_3c87 = direct_page_3c6c;
        data_bank_3c87 = data_bank_3c6c;
        goto shared_3C87;
    }
    r->a = value12;
    r->x = x_3c6c;
    r->y = y_3c6c;
    r->c = carry_3c6c;
    r->z = value12 == 0;
    r->n = value12 & 0x8000;
    r->v = overflow_3c6c;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_3c6c;
    r->dp = direct_page_3c6c;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3C84, 0xC058AF); GUARD_JSL(c, sp_call, 0x3C84); } /* enqueue_generic_actor_status_notice */
    uint16_t a_all9 = r->a;
    uint8_t y_ret6 = r->y;
    bool carry_ret6 = r->c;
    uint8_t value13 = BUS8_RDP(c, (uint16_t)(direct_page_3c6c + 0x85));
    a_hi_3c87 = a_all9 >> 8;
    y_3c87 = y_ret6;
    carry_3c87 = carry_ret6;
    overflow_3c87 = overflow_3c6c;
    direct_page_3c87 = direct_page_3c6c;
    data_bank_3c87 = data_bank_3c6c;
    goto shared_3C87;
    shared_3C6C_1:;
    uint8_t value14 = BUS8_RDP(c, (data_bank_3c6c2 << 0x10) + 0xE1B1 + x_3c6c2);
    if ((value14 & 4) == 0) {
        a_hi_3c872 = a_hi_3c6c2;
        y_3c872 = y_3c6c2;
        carry_3c872 = carry_3c6c2;
        overflow_3c872 = overflow_3c6c2;
        direct_page_3c872 = direct_page_3c6c2;
        data_bank_3c872 = data_bank_3c6c2;
        goto shared_3C87_1;
    }
    BUS8_SET(c, (data_bank_3c6c2 << 0x10) + 0xE1B1 + x_3c6c2, value14 & 0xFB);
    uint16_t value15 = BUS16_RDP(c, (data_bank_3c6c2 << 0x10) + 0xE190 + x_3c6c2);
    if (value15 == 0) {
        a_hi_3c872 = value15 >> 8;
        y_3c872 = y_3c6c2;
        carry_3c872 = carry_3c6c2;
        overflow_3c872 = overflow_3c6c2;
        direct_page_3c872 = direct_page_3c6c2;
        data_bank_3c872 = data_bank_3c6c2;
        goto shared_3C87_1;
    }
    r->a = value15;
    r->x = x_3c6c2;
    r->y = y_3c6c2;
    r->c = carry_3c6c2;
    r->z = value15 == 0;
    r->n = value15 & 0x8000;
    r->v = overflow_3c6c2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_3c6c2;
    r->dp = direct_page_3c6c2;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3C84, 0xC058AF); GUARD_JSL(c, sp_call, 0x3C84); } /* enqueue_generic_actor_status_notice */
    uint16_t a_all10 = r->a;
    uint16_t y_ret7 = r->y;
    bool carry_ret7 = r->c;
    uint16_t value16 = BUS16_RDP(c, (uint16_t)(direct_page_3c6c2 + 0x85));
    a_hi_3c872 = a_all10 >> 8;
    y_3c872 = y_ret7;
    carry_3c872 = carry_ret7;
    overflow_3c872 = overflow_3c6c2;
    direct_page_3c872 = direct_page_3c6c2;
    data_bank_3c872 = data_bank_3c6c2;
    goto shared_3C87_1;
    shared_3C5F:;
    uint8_t value17 = BUS8_RDP(c, (data_bank_3c5f << 0x10) + 0xCC78);
    if (value17 == 0) {
        a_hi_3c6c = a_hi_3c5f;
        x_3c6c = x_3c5f;
        y_3c6c = y_3c5f;
        carry_3c6c = carry_3c5f;
        overflow_3c6c = overflow_3c5f;
        direct_page_3c6c = direct_page_3c5f;
        data_bank_3c6c = data_bank_3c5f;
        goto shared_3C6C;
    }
    uint8_t value18 = BUS8_RDP(c, (data_bank_3c5f << 0x10) + 0xCC78);
    BUS8_SET(c, (data_bank_3c5f << 0x10) + 0xCC78, (uint8_t)(value18 - 1));
    if ((uint8_t)(value18 - 1) != 0) {
        a_hi_3c6c = a_hi_3c5f;
        x_3c6c = x_3c5f;
        y_3c6c = y_3c5f;
        carry_3c6c = carry_3c5f;
        overflow_3c6c = overflow_3c5f;
        direct_page_3c6c = direct_page_3c5f;
        data_bank_3c6c = data_bank_3c5f;
        goto shared_3C6C;
    }
    r->a = (a_hi_3c5f << 8) | value17;
    r->x = x_3c5f;
    r->y = y_3c5f;
    r->c = carry_3c5f;
    r->z = (uint8_t)(value18 - 1) == 0;
    r->n = (uint8_t)(value18 - 1) & 0x80;
    r->v = overflow_3c5f;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_3c5f;
    r->dp = direct_page_3c5f;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3C6B, 0xC03C88); GUARD_JSR(c, sp_call, 0x3C6B); } /* expire_party_mana_weapon_and_rebuild_attributes */
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret4 = r->db;
    bool x_ret16 = r->xf;
    uint16_t a_all11 = r->a;
    uint16_t x_ret17 = r->x;
    uint16_t y_ret8 = r->y;
    bool carry_ret8 = r->c;
    bool overflow_ret6 = r->v;
    if (x_ret16) {
        a_hi_3c6c = a_all11 >> 8;
        x_3c6c = (uint8_t)x_ret17;
        y_3c6c = (uint8_t)y_ret8;
        carry_3c6c = carry_ret8;
        overflow_3c6c = overflow_ret6;
        direct_page_3c6c = dp_ret4;
        data_bank_3c6c = db_ret4;
        goto shared_3C6C;
    } else {
        a_hi_3c6c2 = a_all11 >> 8;
        x_3c6c2 = x_ret17;
        y_3c6c2 = y_ret8;
        carry_3c6c2 = carry_ret8;
        overflow_3c6c2 = overflow_ret6;
        direct_page_3c6c2 = dp_ret4;
        data_bank_3c6c2 = db_ret4;
        goto shared_3C6C_1;
    }
    shared_3C5F_1:;
    uint8_t value19 = BUS8_RDP(c, (data_bank_3c5f2 << 0x10) + 0xCC78);
    if (value19 == 0) {
        a_hi_3c6c2 = a_hi_3c5f2;
        x_3c6c2 = x_3c5f2;
        y_3c6c2 = y_3c5f2;
        carry_3c6c2 = carry_3c5f2;
        overflow_3c6c2 = overflow_3c5f2;
        direct_page_3c6c2 = direct_page_3c5f2;
        data_bank_3c6c2 = data_bank_3c5f2;
        goto shared_3C6C_1;
    }
    uint8_t value20 = BUS8_RDP(c, (data_bank_3c5f2 << 0x10) + 0xCC78);
    BUS8_SET(c, (data_bank_3c5f2 << 0x10) + 0xCC78, (uint8_t)(value20 - 1));
    if ((uint8_t)(value20 - 1) != 0) {
        a_hi_3c6c2 = a_hi_3c5f2;
        x_3c6c2 = x_3c5f2;
        y_3c6c2 = y_3c5f2;
        carry_3c6c2 = carry_3c5f2;
        overflow_3c6c2 = overflow_3c5f2;
        direct_page_3c6c2 = direct_page_3c5f2;
        data_bank_3c6c2 = data_bank_3c5f2;
        goto shared_3C6C_1;
    }
    r->a = (a_hi_3c5f2 << 8) | value19;
    r->x = x_3c5f2;
    r->y = y_3c5f2;
    r->c = carry_3c5f2;
    r->z = (uint8_t)(value20 - 1) == 0;
    r->n = (uint8_t)(value20 - 1) & 0x80;
    r->v = overflow_3c5f2;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_3c5f2;
    r->dp = direct_page_3c5f2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3C6B, 0xC03C88); GUARD_JSR(c, sp_call, 0x3C6B); } /* expire_party_mana_weapon_and_rebuild_attributes */
    uint16_t dp_ret5 = r->dp;
    uint8_t db_ret5 = r->db;
    bool x_ret18 = r->xf;
    uint16_t a_all12 = r->a;
    uint16_t x_ret19 = r->x;
    uint16_t y_ret9 = r->y;
    bool carry_ret9 = r->c;
    bool overflow_ret7 = r->v;
    if (x_ret18) {
        a_hi_3c6c = a_all12 >> 8;
        x_3c6c = (uint8_t)x_ret19;
        y_3c6c = (uint8_t)y_ret9;
        carry_3c6c = carry_ret9;
        overflow_3c6c = overflow_ret7;
        direct_page_3c6c = dp_ret5;
        data_bank_3c6c = db_ret5;
        goto shared_3C6C;
    } else {
        a_hi_3c6c2 = a_all12 >> 8;
        x_3c6c2 = x_ret19;
        y_3c6c2 = y_ret9;
        carry_3c6c2 = carry_ret9;
        overflow_3c6c2 = overflow_ret7;
        direct_page_3c6c2 = dp_ret5;
        data_bank_3c6c2 = db_ret5;
        goto shared_3C6C_1;
    }
    shared_3C6C_2:;
    uint16_t value21 = BUS16_RDP(c, (data_bank_3c6c3 << 0x10) + 0xE1B1 + x_3c6c3);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_3C6C_3:;
    uint16_t value22 = BUS16_RDP(c, (data_bank_3c6c4 << 0x10) + 0xE1B1 + x_3c6c4);
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
    shared_3C5F_2:;
    uint16_t value23 = BUS16_RDP(c, (data_bank_3c5f3 << 0x10) + 0xCC78);
    if (value23 == 0) {
        a_hi_3c6c3 = value23 >> 8;
        x_3c6c3 = x_3c5f3;
        y_3c6c3 = y_3c5f3;
        carry_3c6c3 = carry_3c5f3;
        overflow_3c6c3 = overflow_3c5f3;
        direct_page_3c6c3 = direct_page_3c5f3;
        data_bank_3c6c3 = data_bank_3c5f3;
        goto shared_3C6C_2;
    }
    uint16_t value24 = BUS16_RDP(c, (data_bank_3c5f3 << 0x10) + 0xCC78);
    BUS16_RMW_SET(c, (data_bank_3c5f3 << 0x10) + 0xCC78, (uint16_t)(value24 - 1));
    if ((uint16_t)(value24 - 1) != 0) {
        a_hi_3c6c3 = value23 >> 8;
        x_3c6c3 = x_3c5f3;
        y_3c6c3 = y_3c5f3;
        carry_3c6c3 = carry_3c5f3;
        overflow_3c6c3 = overflow_3c5f3;
        direct_page_3c6c3 = direct_page_3c5f3;
        data_bank_3c6c3 = data_bank_3c5f3;
        goto shared_3C6C_2;
    }
    r->a = value23;
    r->x = x_3c5f3;
    r->y = y_3c5f3;
    r->c = carry_3c5f3;
    r->z = (uint16_t)(value24 - 1) == 0;
    r->n = (uint16_t)(value24 - 1) & 0x8000;
    r->v = overflow_3c5f3;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_3c5f3;
    r->dp = direct_page_3c5f3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3C6B, 0xC03C88); GUARD_JSR(c, sp_call, 0x3C6B); } /* expire_party_mana_weapon_and_rebuild_attributes */
    uint16_t dp_ret6 = r->dp;
    uint8_t db_ret6 = r->db;
    bool x_ret20 = r->xf;
    uint16_t a_all13 = r->a;
    uint16_t x_ret21 = r->x;
    uint16_t y_ret10 = r->y;
    bool carry_ret10 = r->c;
    bool overflow_ret8 = r->v;
    if (x_ret20) {
        a_hi_3c6c = a_all13 >> 8;
        x_3c6c = (uint8_t)x_ret21;
        y_3c6c = (uint8_t)y_ret10;
        carry_3c6c = carry_ret10;
        overflow_3c6c = overflow_ret8;
        direct_page_3c6c = dp_ret6;
        data_bank_3c6c = db_ret6;
        goto shared_3C6C;
    } else {
        a_hi_3c6c2 = a_all13 >> 8;
        x_3c6c2 = x_ret21;
        y_3c6c2 = y_ret10;
        carry_3c6c2 = carry_ret10;
        overflow_3c6c2 = overflow_ret8;
        direct_page_3c6c2 = dp_ret6;
        data_bank_3c6c2 = db_ret6;
        goto shared_3C6C_1;
    }
    shared_3C5F_3:;
    uint16_t value25 = BUS16_RDP(c, (data_bank_3c5f4 << 0x10) + 0xCC78);
    if (value25 == 0) {
        a_hi_3c6c4 = value25 >> 8;
        x_3c6c4 = x_3c5f4;
        y_3c6c4 = y_3c5f4;
        carry_3c6c4 = carry_3c5f4;
        overflow_3c6c4 = overflow_3c5f4;
        direct_page_3c6c4 = direct_page_3c5f4;
        data_bank_3c6c4 = data_bank_3c5f4;
        goto shared_3C6C_3;
    }
    uint16_t value26 = BUS16_RDP(c, (data_bank_3c5f4 << 0x10) + 0xCC78);
    BUS16_RMW_SET(c, (data_bank_3c5f4 << 0x10) + 0xCC78, (uint16_t)(value26 - 1));
    if ((uint16_t)(value26 - 1) != 0) {
        a_hi_3c6c4 = value25 >> 8;
        x_3c6c4 = x_3c5f4;
        y_3c6c4 = y_3c5f4;
        carry_3c6c4 = carry_3c5f4;
        overflow_3c6c4 = overflow_3c5f4;
        direct_page_3c6c4 = direct_page_3c5f4;
        data_bank_3c6c4 = data_bank_3c5f4;
        goto shared_3C6C_3;
    }
    r->a = value25;
    r->x = x_3c5f4;
    r->y = y_3c5f4;
    r->c = carry_3c5f4;
    r->z = (uint16_t)(value26 - 1) == 0;
    r->n = (uint16_t)(value26 - 1) & 0x8000;
    r->v = overflow_3c5f4;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_3c5f4;
    r->dp = direct_page_3c5f4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3C6B, 0xC03C88); GUARD_JSR(c, sp_call, 0x3C6B); } /* expire_party_mana_weapon_and_rebuild_attributes */
    uint16_t dp_ret7 = r->dp;
    uint8_t db_ret7 = r->db;
    bool x_ret22 = r->xf;
    uint16_t a_all14 = r->a;
    uint16_t x_ret23 = r->x;
    uint16_t y_ret11 = r->y;
    bool carry_ret11 = r->c;
    bool overflow_ret9 = r->v;
    if (x_ret22) {
        a_hi_3c6c = a_all14 >> 8;
        x_3c6c = (uint8_t)x_ret23;
        y_3c6c = (uint8_t)y_ret11;
        carry_3c6c = carry_ret11;
        overflow_3c6c = overflow_ret9;
        direct_page_3c6c = dp_ret7;
        data_bank_3c6c = db_ret7;
        goto shared_3C6C;
    } else {
        a_hi_3c6c2 = a_all14 >> 8;
        x_3c6c2 = x_ret23;
        y_3c6c2 = y_ret11;
        carry_3c6c2 = carry_ret11;
        overflow_3c6c2 = overflow_ret9;
        direct_page_3c6c2 = dp_ret7;
        data_bank_3c6c2 = db_ret7;
        goto shared_3C6C_1;
    }
}
SOM_REGISTER(0xC03C19, SOM_RTS, "gen", coordinate_actor_combat_status_and_buff_timers, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 111, 44)
