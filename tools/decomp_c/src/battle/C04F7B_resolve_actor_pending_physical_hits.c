#include "som_c.h"

/* C04F7B resolve_actor_pending_physical_hits   [class B, 114 bytes, 50 instructions]
 * Source: src/rom/resolve_actor_pending_physical_hits.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void resolve_actor_pending_physical_hits(SomCtx *c)
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
    uint8_t a_hi_4f8c = 0;
    uint16_t x_4f8c = 0;
    uint16_t y_4f8c = 0;
    bool carry_4f8c = 0;
    bool overflow_4f8c = 0;
    uint8_t a_hi_4f9e = 0;
    uint16_t x_4f9e = 0;
    uint16_t y_4f9e = 0;
    bool overflow_4f9e = 0;
    uint16_t direct_page_4f9e = 0;
    uint8_t data_bank_4f9e = 0;
    uint8_t a_hi_4fb6 = 0;
    uint16_t x_4fb6 = 0;
    uint16_t direct_page_4fb6 = 0;
    uint8_t data_bank_4fb6 = 0;
    uint8_t a_hi_4fe8 = 0;
    uint16_t x_4fe8 = 0;
    uint16_t y_4fe8 = 0;
    bool carry_4fe8 = 0;
    bool overflow_4fe8 = 0;
    uint16_t direct_page_4fe8 = 0;
    uint8_t data_bank_4fe8 = 0;
    uint8_t a_hi_4fe4 = 0;
    uint16_t x_4fe4 = 0;
    uint16_t y_4fe4 = 0;
    bool carry_4fe4 = 0;
    bool overflow_4fe4 = 0;
    uint16_t direct_page_4fe4 = 0;
    uint8_t data_bank_4fe4 = 0;
    uint8_t a_hi_4fe42 = 0;
    uint8_t x_4fe42 = 0;
    uint8_t y_4fe42 = 0;
    bool carry_4fe42 = 0;
    bool overflow_4fe42 = 0;
    uint16_t direct_page_4fe42 = 0;
    uint8_t data_bank_4fe42 = 0;
    uint8_t a_hi_4fe43 = 0;
    uint8_t x_4fe43 = 0;
    uint8_t y_4fe43 = 0;
    bool carry_4fe43 = 0;
    bool overflow_4fe43 = 0;
    uint16_t direct_page_4fe43 = 0;
    uint8_t data_bank_4fe43 = 0;
    uint8_t a_hi_4fe44 = 0;
    uint16_t x_4fe44 = 0;
    uint16_t y_4fe44 = 0;
    bool carry_4fe44 = 0;
    bool overflow_4fe44 = 0;
    uint16_t direct_page_4fe44 = 0;
    uint8_t data_bank_4fe44 = 0;
    uint8_t a_hi_4f9e2 = 0;
    uint8_t x_4f9e2 = 0;
    uint8_t y_4f9e2 = 0;
    bool overflow_4f9e2 = 0;
    uint16_t direct_page_4f9e2 = 0;
    uint8_t data_bank_4f9e2 = 0;
    uint8_t a_hi_4fe82 = 0;
    uint8_t x_4fe82 = 0;
    uint8_t y_4fe82 = 0;
    bool carry_4fe82 = 0;
    bool overflow_4fe82 = 0;
    uint16_t direct_page_4fe82 = 0;
    uint8_t data_bank_4fe82 = 0;
    uint8_t a_hi_4f9e3 = 0;
    uint8_t x_4f9e3 = 0;
    uint8_t y_4f9e3 = 0;
    bool overflow_4f9e3 = 0;
    uint16_t direct_page_4f9e3 = 0;
    uint8_t data_bank_4f9e3 = 0;
    uint8_t a_hi_4fe83 = 0;
    uint8_t x_4fe83 = 0;
    uint8_t y_4fe83 = 0;
    bool carry_4fe83 = 0;
    bool overflow_4fe83 = 0;
    uint16_t direct_page_4fe83 = 0;
    uint8_t data_bank_4fe83 = 0;
    uint8_t a_hi_4f9e4 = 0;
    uint16_t x_4f9e4 = 0;
    uint16_t y_4f9e4 = 0;
    bool overflow_4f9e4 = 0;
    uint16_t direct_page_4f9e4 = 0;
    uint8_t data_bank_4f9e4 = 0;
    uint8_t a_hi_4fe84 = 0;
    uint16_t x_4fe84 = 0;
    uint16_t y_4fe84 = 0;
    bool carry_4fe84 = 0;
    bool overflow_4fe84 = 0;
    uint16_t direct_page_4fe84 = 0;
    uint8_t data_bank_4fe84 = 0;
    uint8_t a_hi_4fb62 = 0;
    uint8_t x_4fb62 = 0;
    uint16_t direct_page_4fb62 = 0;
    uint8_t data_bank_4fb62 = 0;
    if ((RAM8(ACTOR_STATUS_HIGH + x) & 4) != 0) {
        a_hi_4f8c = a_hi;
        x_4f8c = x;
        y_4f8c = y;
        carry_4f8c = carry;
        overflow_4f8c = overflow;
        goto shared_4F8C;
    }
    uint16_t value2 = RAM16(ACTOR_HP + x);
    if (value2 == 0) {
        a_hi_4f8c = a_hi;
        x_4f8c = x;
        y_4f8c = value2;
        carry_4f8c = carry;
        overflow_4f8c = overflow;
        goto shared_4F8C;
    }
    uint8_t hero_hit_mask = RAM8(HERO_HIT_MASK + x);
    if (hero_hit_mask != 0) {
        RAM8(0x0392) = hero_hit_mask;
        RAM8(HERO_HIT_MASK + x) = 0;
        r->a = (a_hi << 8) | hero_hit_mask;
        r->y = value2;
        r->z = hero_hit_mask == 0;
        r->n = hero_hit_mask & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4F97, 0xC04FED); GUARD_JSR(c, sp_call, 0x4F97); } /* calculate_physical_defence_terms */
        uint16_t a_all = r->a;
        bool overflow_ret = r->v;
        RAM8(0x0393) = 2;
        RAM8(BATTLE_ATTACKER_PTR) = 0;
        a_hi_4f9e = a_all >> 8;
        x_4f9e = x;
        y_4f9e = value2;
        overflow_4f9e = overflow_ret;
        direct_page_4f9e = 0x0300;
        data_bank_4f9e = 0x7E;
        goto shared_4F9E;
    }
    a_hi_4f8c = a_hi;
    x_4f8c = x;
    y_4f8c = value2;
    carry_4f8c = carry;
    overflow_4f8c = overflow;
    shared_4F8C:;
    RAM8(HERO_HIT_MASK + x_4f8c) = 0;
    r->a = (a_hi_4f8c << 8) | a;
    r->x = x_4f8c;
    r->y = y_4f8c;
    r->c = carry_4f8c;
    r->v = overflow_4f8c;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0300;
    RETURN_RTL(c);
    shared_4F9E:;
    uint8_t value3 = BUS8_RDP(c, (uint16_t)(direct_page_4f9e + 0x92));
    BUS8_SET(c, (uint16_t)(direct_page_4f9e + 0x92), value3 >> 1);
    if (value3 & 0x01) {
        BUS8_SET(c, (uint16_t)(direct_page_4f9e + 0xA4), 5);
        uint8_t value4 = BUS8_RDP(c, (data_bank_4f9e << 0x10) + 0xE1FB + x_4f9e);
        if (value4 & 0x80) {
            a_hi_4fb6 = a_hi_4f9e;
            x_4fb6 = x_4f9e;
            direct_page_4fb6 = direct_page_4f9e;
            data_bank_4fb6 = data_bank_4f9e;
            goto shared_4FB6;
        }
        BUS8_SET(c, (uint16_t)(direct_page_4f9e + 0xA4), 2);
        a_hi_4fb6 = a_hi_4f9e;
        x_4fb6 = x_4f9e;
        direct_page_4fb6 = direct_page_4f9e;
        data_bank_4fb6 = data_bank_4f9e;
        goto shared_4FB6;
    }
    uint8_t value5 = BUS8_RDP(c, (uint16_t)(direct_page_4f9e + 0x93));
    BUS8_SET(c, (uint16_t)(direct_page_4f9e + 0x93), (uint8_t)(value5 - 1));
    if (!((uint8_t)(value5 - 1) & 0x80)) {
        goto shared_4F9E;
    }
    a_hi_4fe8 = a_hi_4f9e;
    x_4fe8 = x_4f9e;
    y_4fe8 = y_4f9e;
    carry_4fe8 = value3 & 0x01;
    overflow_4fe8 = overflow_4f9e;
    direct_page_4fe8 = direct_page_4f9e;
    data_bank_4fe8 = data_bank_4f9e;
    goto shared_4FE8;
    shared_4FB6:;
    uint8_t value6 = BUS8_RDP(c, (uint16_t)(direct_page_4fb6 + 0xA4));
    uint8_t value7 = BUS8_RDP(c, (uint16_t)(direct_page_4fb6 + 0x93));
    BUS8_SET(c, (uint16_t)(direct_page_4fb6 + 0x82), (uint8_t)(value6 - value7));
    BUS8_SET(c, (uint16_t)(direct_page_4fb6 + 0x84), (uint8_t)((uint8_t)(value6 - value7) << 1));
    uint16_t value8 = BUS16_RDP(c, (uint16_t)(direct_page_4fb6 + 0x83));
    uint16_t value9 = BUS16_RDP(c, (data_bank_4fb6 << 0x10) + 0xE182 + value8);
    if (value9 == 0) {
        a_hi_4fe4 = value9 >> 8;
        x_4fe4 = x_4fb6;
        y_4fe4 = value8;
        carry_4fe4 = (uint8_t)(value6 - value7) & 0x80;
        overflow_4fe4 = ((value6 ^ value7) & (value6 ^ (uint8_t)(value6 - value7)) & 0x80) != 0;
        direct_page_4fe4 = direct_page_4fb6;
        data_bank_4fe4 = data_bank_4fb6;
        goto shared_4FE4;
    }
    r->a = value9;
    r->x = x_4fb6;
    r->y = value8;
    r->c = (uint8_t)(value6 - value7) & 0x80;
    r->z = value9 == 0;
    r->n = value9 & 0x8000;
    r->v = ((value6 ^ value7) & (value6 ^ (uint8_t)(value6 - value7)) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_4fb6;
    r->dp = direct_page_4fb6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4FCD, 0xC0505B); GUARD_JSR(c, sp_call, 0x4FCD); } /* test_physical_hit_accuracy */
    bool m_ret = r->mf;
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    bool carry_ret2 = r->c;
    if (!carry_ret2) {
        { const uint16_t sp_call = r->sp; JSL(c, 0x4FE3, 0xC04E6B); GUARD_JSL(c, sp_call, 0x4FE3); } /* select_actor_miss_reaction_long */
        bool m_ret2 = r->mf;
        bool x_ret3 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        if (m_ret2) {
            if (x_ret3) {
                a_hi_4fe42 = a_all3 >> 8;
                x_4fe42 = (uint8_t)x_ret4;
                y_4fe42 = (uint8_t)y_ret2;
                carry_4fe42 = carry_ret3;
                overflow_4fe42 = overflow_ret3;
                direct_page_4fe42 = direct_page_4fb6;
                data_bank_4fe42 = data_bank_4fb6;
                goto shared_4FE4_1;
            } else {
                a_hi_4fe4 = a_all3 >> 8;
                x_4fe4 = x_ret4;
                y_4fe4 = y_ret2;
                carry_4fe4 = carry_ret3;
                overflow_4fe4 = overflow_ret3;
                direct_page_4fe4 = direct_page_4fb6;
                data_bank_4fe4 = data_bank_4fb6;
                goto shared_4FE4;
            }
        } else {
            if (x_ret3) {
                a_hi_4fe43 = a_all3 >> 8;
                x_4fe43 = (uint8_t)x_ret4;
                y_4fe43 = (uint8_t)y_ret2;
                carry_4fe43 = carry_ret3;
                overflow_4fe43 = overflow_ret3;
                direct_page_4fe43 = direct_page_4fb6;
                data_bank_4fe43 = data_bank_4fb6;
                goto shared_4FE4_2;
            } else {
                a_hi_4fe44 = a_all3 >> 8;
                x_4fe44 = x_ret4;
                y_4fe44 = y_ret2;
                carry_4fe44 = carry_ret3;
                overflow_4fe44 = overflow_ret3;
                direct_page_4fe44 = direct_page_4fb6;
                data_bank_4fe44 = data_bank_4fb6;
                goto shared_4FE4_3;
            }
        }
    }
    if (m_ret) {
        uint8_t value10 = BUS8_RDP(c, (uint16_t)(direct_page_4fb6 + 0x82));
        BUS8_SET(c, (data_bank_4fb6 << 0x10) + 0xE1F0 + x_ret2, value10);
        r->a = (a_all2 >> 8 << 8) | value10;
        r->z = value10 == 0;
        r->n = value10 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FD7, 0xC050CA); GUARD_JSR(c, sp_call, 0x4FD7); } /* select_physical_element_and_expire_saber */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FDA, 0xC0514B); GUARD_JSR(c, sp_call, 0x4FDA); } /* resolve_and_queue_physical_damage */
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FDD, 0xC05119); GUARD_JSR(c, sp_call, 0x4FDD); } /* queue_physical_weapon_status_after_damage */
        bool x_ret9 = r->xf;
        uint16_t a_all6 = r->a;
        uint16_t x_ret10 = r->x;
        uint16_t y_ret5 = r->y;
        bool carry_ret6 = r->c;
        bool overflow_ret6 = r->v;
        if (x_ret9) {
            a_hi_4fe42 = a_all6 >> 8;
            x_4fe42 = (uint8_t)x_ret10;
            y_4fe42 = (uint8_t)y_ret5;
            carry_4fe42 = carry_ret6;
            overflow_4fe42 = overflow_ret6;
            direct_page_4fe42 = dp_ret;
            data_bank_4fe42 = db_ret;
            goto shared_4FE4_1;
        } else {
            a_hi_4fe4 = a_all6 >> 8;
            x_4fe4 = x_ret10;
            y_4fe4 = y_ret5;
            carry_4fe4 = carry_ret6;
            overflow_4fe4 = overflow_ret6;
            direct_page_4fe4 = dp_ret;
            data_bank_4fe4 = db_ret;
            goto shared_4FE4;
        }
    } else {
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(direct_page_4fb6 + 0x82));
        BUS16_SET(c, (data_bank_4fb6 << 0x10) + 0xE1F0 + x_ret2, value11);
        r->a = value11;
        r->z = value11 == 0;
        r->n = value11 & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FD7, 0xC050CA); GUARD_JSR(c, sp_call, 0x4FD7); } /* select_physical_element_and_expire_saber */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FDA, 0xC0514B); GUARD_JSR(c, sp_call, 0x4FDA); } /* resolve_and_queue_physical_damage */
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FDD, 0xC05119); GUARD_JSR(c, sp_call, 0x4FDD); } /* queue_physical_weapon_status_after_damage */
        bool x_ret15 = r->xf;
        uint16_t a_all9 = r->a;
        uint16_t x_ret16 = r->x;
        uint16_t y_ret8 = r->y;
        bool carry_ret9 = r->c;
        bool overflow_ret9 = r->v;
        if (x_ret15) {
            a_hi_4fe42 = a_all9 >> 8;
            x_4fe42 = (uint8_t)x_ret16;
            y_4fe42 = (uint8_t)y_ret8;
            carry_4fe42 = carry_ret9;
            overflow_4fe42 = overflow_ret9;
            direct_page_4fe42 = dp_ret2;
            data_bank_4fe42 = db_ret2;
            goto shared_4FE4_1;
        } else {
            a_hi_4fe4 = a_all9 >> 8;
            x_4fe4 = x_ret16;
            y_4fe4 = y_ret8;
            carry_4fe4 = carry_ret9;
            overflow_4fe4 = overflow_ret9;
            direct_page_4fe4 = dp_ret2;
            data_bank_4fe4 = db_ret2;
            goto shared_4FE4;
        }
    }
    shared_4FE8:;
    r->x = x_4fe8;
    r->y = y_4fe8;
    r->c = carry_4fe8;
    r->v = overflow_4fe8;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_4fe8;
    r->dp = direct_page_4fe8;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4FEB, 0xC8E301); GUARD_JSL(c, sp_call, 0x4FEB); } /* apply_actor_status_and_timers */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
    shared_4FE4:;
    uint8_t value12 = BUS8_RDP(c, (uint16_t)(direct_page_4fe4 + 0x93));
    BUS8_SET(c, (uint16_t)(direct_page_4fe4 + 0x93), (uint8_t)(value12 - 1));
    if (!((uint8_t)(value12 - 1) & 0x80)) {
        a_hi_4f9e = a_hi_4fe4;
        x_4f9e = x_4fe4;
        y_4f9e = y_4fe4;
        overflow_4f9e = overflow_4fe4;
        direct_page_4f9e = direct_page_4fe4;
        data_bank_4f9e = data_bank_4fe4;
        goto shared_4F9E;
    }
    a_hi_4fe8 = a_hi_4fe4;
    x_4fe8 = x_4fe4;
    y_4fe8 = y_4fe4;
    carry_4fe8 = carry_4fe4;
    overflow_4fe8 = overflow_4fe4;
    direct_page_4fe8 = direct_page_4fe4;
    data_bank_4fe8 = data_bank_4fe4;
    goto shared_4FE8;
    shared_4FE4_1:;
    uint8_t value13 = BUS8_RDP(c, (uint16_t)(direct_page_4fe42 + 0x93));
    BUS8_SET(c, (uint16_t)(direct_page_4fe42 + 0x93), (uint8_t)(value13 - 1));
    if (!((uint8_t)(value13 - 1) & 0x80)) {
        a_hi_4f9e2 = a_hi_4fe42;
        x_4f9e2 = x_4fe42;
        y_4f9e2 = y_4fe42;
        overflow_4f9e2 = overflow_4fe42;
        direct_page_4f9e2 = direct_page_4fe42;
        data_bank_4f9e2 = data_bank_4fe42;
        goto shared_4F9E_1;
    }
    a_hi_4fe82 = a_hi_4fe42;
    x_4fe82 = x_4fe42;
    y_4fe82 = y_4fe42;
    carry_4fe82 = carry_4fe42;
    overflow_4fe82 = overflow_4fe42;
    direct_page_4fe82 = direct_page_4fe42;
    data_bank_4fe82 = data_bank_4fe42;
    goto shared_4FE8_1;
    shared_4FE4_2:;
    uint16_t value14 = BUS16_RDP(c, (uint16_t)(direct_page_4fe43 + 0x93));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_4fe43 + 0x93), (uint16_t)(value14 - 1));
    if (!((uint16_t)(value14 - 1) & 0x8000)) {
        a_hi_4f9e3 = a_hi_4fe43;
        x_4f9e3 = x_4fe43;
        y_4f9e3 = y_4fe43;
        overflow_4f9e3 = overflow_4fe43;
        direct_page_4f9e3 = direct_page_4fe43;
        data_bank_4f9e3 = data_bank_4fe43;
        goto shared_4F9E_2;
    }
    a_hi_4fe83 = a_hi_4fe43;
    x_4fe83 = x_4fe43;
    y_4fe83 = y_4fe43;
    carry_4fe83 = carry_4fe43;
    overflow_4fe83 = overflow_4fe43;
    direct_page_4fe83 = direct_page_4fe43;
    data_bank_4fe83 = data_bank_4fe43;
    goto shared_4FE8_2;
    shared_4FE4_3:;
    uint16_t value15 = BUS16_RDP(c, (uint16_t)(direct_page_4fe44 + 0x93));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_4fe44 + 0x93), (uint16_t)(value15 - 1));
    if (!((uint16_t)(value15 - 1) & 0x8000)) {
        a_hi_4f9e4 = a_hi_4fe44;
        x_4f9e4 = x_4fe44;
        y_4f9e4 = y_4fe44;
        overflow_4f9e4 = overflow_4fe44;
        direct_page_4f9e4 = direct_page_4fe44;
        data_bank_4f9e4 = data_bank_4fe44;
        goto shared_4F9E_3;
    }
    a_hi_4fe84 = a_hi_4fe44;
    x_4fe84 = x_4fe44;
    y_4fe84 = y_4fe44;
    carry_4fe84 = carry_4fe44;
    overflow_4fe84 = overflow_4fe44;
    direct_page_4fe84 = direct_page_4fe44;
    data_bank_4fe84 = data_bank_4fe44;
    goto shared_4FE8_3;
    shared_4F9E_1:;
    uint8_t value16 = BUS8_RDP(c, (uint16_t)(direct_page_4f9e2 + 0x92));
    BUS8_SET(c, (uint16_t)(direct_page_4f9e2 + 0x92), value16 >> 1);
    if (value16 & 0x01) {
        BUS8_SET(c, (uint16_t)(direct_page_4f9e2 + 0xA4), 5);
        uint8_t value17 = BUS8_RDP(c, (data_bank_4f9e2 << 0x10) + 0xE1FB + x_4f9e2);
        if (value17 & 0x80) {
            a_hi_4fb62 = a_hi_4f9e2;
            x_4fb62 = x_4f9e2;
            direct_page_4fb62 = direct_page_4f9e2;
            data_bank_4fb62 = data_bank_4f9e2;
            goto shared_4FB6_1;
        }
        BUS8_SET(c, (uint16_t)(direct_page_4f9e2 + 0xA4), 2);
        a_hi_4fb62 = a_hi_4f9e2;
        x_4fb62 = x_4f9e2;
        direct_page_4fb62 = direct_page_4f9e2;
        data_bank_4fb62 = data_bank_4f9e2;
        goto shared_4FB6_1;
    }
    uint8_t value18 = BUS8_RDP(c, (uint16_t)(direct_page_4f9e2 + 0x93));
    BUS8_SET(c, (uint16_t)(direct_page_4f9e2 + 0x93), (uint8_t)(value18 - 1));
    if (!((uint8_t)(value18 - 1) & 0x80)) {
        goto shared_4F9E_1;
    }
    a_hi_4fe82 = a_hi_4f9e2;
    x_4fe82 = x_4f9e2;
    y_4fe82 = y_4f9e2;
    carry_4fe82 = value16 & 0x01;
    overflow_4fe82 = overflow_4f9e2;
    direct_page_4fe82 = direct_page_4f9e2;
    data_bank_4fe82 = data_bank_4f9e2;
    goto shared_4FE8_1;
    shared_4FE8_1:;
    r->x = x_4fe82;
    r->y = y_4fe82;
    r->c = carry_4fe82;
    r->v = overflow_4fe82;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_4fe82;
    r->dp = direct_page_4fe82;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4FEB, 0xC8E301); GUARD_JSL(c, sp_call, 0x4FEB); } /* apply_actor_status_and_timers */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
    shared_4F9E_2:;
    uint16_t value19 = BUS16_RDP(c, (uint16_t)(direct_page_4f9e3 + 0x92));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_4f9e3 + 0x92), value19 >> 1);
    if (value19 & 0x01) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    uint16_t value20 = BUS16_RDP(c, (uint16_t)(direct_page_4f9e3 + 0x93));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_4f9e3 + 0x93), (uint16_t)(value20 - 1));
    if (!((uint16_t)(value20 - 1) & 0x8000)) {
        goto shared_4F9E_2;
    }
    a_hi_4fe83 = a_hi_4f9e3;
    x_4fe83 = x_4f9e3;
    y_4fe83 = y_4f9e3;
    carry_4fe83 = value19 & 0x01;
    overflow_4fe83 = overflow_4f9e3;
    direct_page_4fe83 = direct_page_4f9e3;
    data_bank_4fe83 = data_bank_4f9e3;
    goto shared_4FE8_2;
    shared_4FE8_2:;
    r->x = x_4fe83;
    r->y = y_4fe83;
    r->c = carry_4fe83;
    r->v = overflow_4fe83;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_4fe83;
    r->dp = direct_page_4fe83;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4FEB, 0xC8E301); GUARD_JSL(c, sp_call, 0x4FEB); } /* apply_actor_status_and_timers */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
    shared_4F9E_3:;
    uint16_t value21 = BUS16_RDP(c, (uint16_t)(direct_page_4f9e4 + 0x92));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_4f9e4 + 0x92), value21 >> 1);
    if (value21 & 0x01) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    }
    uint16_t value22 = BUS16_RDP(c, (uint16_t)(direct_page_4f9e4 + 0x93));
    BUS16_RMW_SET(c, (uint16_t)(direct_page_4f9e4 + 0x93), (uint16_t)(value22 - 1));
    if (!((uint16_t)(value22 - 1) & 0x8000)) {
        goto shared_4F9E_3;
    }
    a_hi_4fe84 = a_hi_4f9e4;
    x_4fe84 = x_4f9e4;
    y_4fe84 = y_4f9e4;
    carry_4fe84 = value21 & 0x01;
    overflow_4fe84 = overflow_4f9e4;
    direct_page_4fe84 = direct_page_4f9e4;
    data_bank_4fe84 = data_bank_4f9e4;
    goto shared_4FE8_3;
    shared_4FE8_3:;
    r->x = x_4fe84;
    r->y = y_4fe84;
    r->c = carry_4fe84;
    r->v = overflow_4fe84;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_4fe84;
    r->dp = direct_page_4fe84;
    { const uint16_t sp_call = r->sp; JSL(c, 0x4FEB, 0xC8E301); GUARD_JSL(c, sp_call, 0x4FEB); } /* apply_actor_status_and_timers */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
    shared_4FB6_1:;
    uint8_t value23 = BUS8_RDP(c, (uint16_t)(direct_page_4fb62 + 0xA4));
    uint8_t value24 = BUS8_RDP(c, (uint16_t)(direct_page_4fb62 + 0x93));
    BUS8_SET(c, (uint16_t)(direct_page_4fb62 + 0x82), (uint8_t)(value23 - value24));
    BUS8_SET(c, (uint16_t)(direct_page_4fb62 + 0x84), (uint8_t)((uint8_t)(value23 - value24) << 1));
    uint8_t value25 = BUS8_RDP(c, (uint16_t)(direct_page_4fb62 + 0x83));
    uint16_t value26 = BUS16_RDP(c, (data_bank_4fb62 << 0x10) + 0xE182 + value25);
    if (value26 == 0) {
        a_hi_4fe42 = value26 >> 8;
        x_4fe42 = x_4fb62;
        y_4fe42 = value25;
        carry_4fe42 = (uint8_t)(value23 - value24) & 0x80;
        overflow_4fe42 = ((value23 ^ value24) & (value23 ^ (uint8_t)(value23 - value24)) & 0x80) != 0;
        direct_page_4fe42 = direct_page_4fb62;
        data_bank_4fe42 = data_bank_4fb62;
        goto shared_4FE4_1;
    }
    r->a = value26;
    r->x = x_4fb62;
    r->y = value25;
    r->c = (uint8_t)(value23 - value24) & 0x80;
    r->z = value26 == 0;
    r->n = value26 & 0x8000;
    r->v = ((value23 ^ value24) & (value23 ^ (uint8_t)(value23 - value24)) & 0x80) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_4fb62;
    r->dp = direct_page_4fb62;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4FCD, 0xC0505B); GUARD_JSR(c, sp_call, 0x4FCD); } /* test_physical_hit_accuracy */
    bool m_ret9 = r->mf;
    uint16_t a_all14 = r->a;
    uint16_t x_ret26 = r->x;
    bool carry_ret14 = r->c;
    if (!carry_ret14) {
        { const uint16_t sp_call = r->sp; JSL(c, 0x4FE3, 0xC04E6B); GUARD_JSL(c, sp_call, 0x4FE3); } /* select_actor_miss_reaction_long */
        bool m_ret10 = r->mf;
        bool x_ret27 = r->xf;
        uint16_t a_all15 = r->a;
        uint16_t x_ret28 = r->x;
        uint16_t y_ret14 = r->y;
        bool carry_ret15 = r->c;
        bool overflow_ret15 = r->v;
        if (m_ret10) {
            if (x_ret27) {
                a_hi_4fe42 = a_all15 >> 8;
                x_4fe42 = (uint8_t)x_ret28;
                y_4fe42 = (uint8_t)y_ret14;
                carry_4fe42 = carry_ret15;
                overflow_4fe42 = overflow_ret15;
                direct_page_4fe42 = direct_page_4fb62;
                data_bank_4fe42 = data_bank_4fb62;
                goto shared_4FE4_1;
            } else {
                a_hi_4fe4 = a_all15 >> 8;
                x_4fe4 = x_ret28;
                y_4fe4 = y_ret14;
                carry_4fe4 = carry_ret15;
                overflow_4fe4 = overflow_ret15;
                direct_page_4fe4 = direct_page_4fb62;
                data_bank_4fe4 = data_bank_4fb62;
                goto shared_4FE4;
            }
        } else {
            if (x_ret27) {
                a_hi_4fe43 = a_all15 >> 8;
                x_4fe43 = (uint8_t)x_ret28;
                y_4fe43 = (uint8_t)y_ret14;
                carry_4fe43 = carry_ret15;
                overflow_4fe43 = overflow_ret15;
                direct_page_4fe43 = direct_page_4fb62;
                data_bank_4fe43 = data_bank_4fb62;
                goto shared_4FE4_2;
            } else {
                a_hi_4fe44 = a_all15 >> 8;
                x_4fe44 = x_ret28;
                y_4fe44 = y_ret14;
                carry_4fe44 = carry_ret15;
                overflow_4fe44 = overflow_ret15;
                direct_page_4fe44 = direct_page_4fb62;
                data_bank_4fe44 = data_bank_4fb62;
                goto shared_4FE4_3;
            }
        }
    }
    if (m_ret9) {
        uint8_t value27 = BUS8_RDP(c, (uint16_t)(direct_page_4fb62 + 0x82));
        BUS8_SET(c, (data_bank_4fb62 << 0x10) + 0xE1F0 + x_ret26, value27);
        r->a = (a_all14 >> 8 << 8) | value27;
        r->z = value27 == 0;
        r->n = value27 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FD7, 0xC050CA); GUARD_JSR(c, sp_call, 0x4FD7); } /* select_physical_element_and_expire_saber */
        uint16_t dp_ret7 = r->dp;
        uint8_t db_ret7 = r->db;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FDA, 0xC0514B); GUARD_JSR(c, sp_call, 0x4FDA); } /* resolve_and_queue_physical_damage */
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FDD, 0xC05119); GUARD_JSR(c, sp_call, 0x4FDD); } /* queue_physical_weapon_status_after_damage */
        bool x_ret33 = r->xf;
        uint16_t a_all18 = r->a;
        uint16_t x_ret34 = r->x;
        uint16_t y_ret17 = r->y;
        bool carry_ret18 = r->c;
        bool overflow_ret18 = r->v;
        if (x_ret33) {
            a_hi_4fe42 = a_all18 >> 8;
            x_4fe42 = (uint8_t)x_ret34;
            y_4fe42 = (uint8_t)y_ret17;
            carry_4fe42 = carry_ret18;
            overflow_4fe42 = overflow_ret18;
            direct_page_4fe42 = dp_ret7;
            data_bank_4fe42 = db_ret7;
            goto shared_4FE4_1;
        } else {
            a_hi_4fe4 = a_all18 >> 8;
            x_4fe4 = x_ret34;
            y_4fe4 = y_ret17;
            carry_4fe4 = carry_ret18;
            overflow_4fe4 = overflow_ret18;
            direct_page_4fe4 = dp_ret7;
            data_bank_4fe4 = db_ret7;
            goto shared_4FE4;
        }
    } else {
        uint16_t value28 = BUS16_RDP(c, (uint16_t)(direct_page_4fb62 + 0x82));
        BUS16_SET(c, (data_bank_4fb62 << 0x10) + 0xE1F0 + x_ret26, value28);
        r->a = value28;
        r->z = value28 == 0;
        r->n = value28 & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FD7, 0xC050CA); GUARD_JSR(c, sp_call, 0x4FD7); } /* select_physical_element_and_expire_saber */
        uint16_t dp_ret8 = r->dp;
        uint8_t db_ret8 = r->db;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FDA, 0xC0514B); GUARD_JSR(c, sp_call, 0x4FDA); } /* resolve_and_queue_physical_damage */
        { const uint16_t sp_call = r->sp; JSR(c, 0x4FDD, 0xC05119); GUARD_JSR(c, sp_call, 0x4FDD); } /* queue_physical_weapon_status_after_damage */
        bool x_ret39 = r->xf;
        uint16_t a_all21 = r->a;
        uint16_t x_ret40 = r->x;
        uint16_t y_ret20 = r->y;
        bool carry_ret21 = r->c;
        bool overflow_ret21 = r->v;
        if (x_ret39) {
            a_hi_4fe42 = a_all21 >> 8;
            x_4fe42 = (uint8_t)x_ret40;
            y_4fe42 = (uint8_t)y_ret20;
            carry_4fe42 = carry_ret21;
            overflow_4fe42 = overflow_ret21;
            direct_page_4fe42 = dp_ret8;
            data_bank_4fe42 = db_ret8;
            goto shared_4FE4_1;
        } else {
            a_hi_4fe4 = a_all21 >> 8;
            x_4fe4 = x_ret40;
            y_4fe4 = y_ret20;
            carry_4fe4 = carry_ret21;
            overflow_4fe4 = overflow_ret21;
            direct_page_4fe4 = dp_ret8;
            data_bank_4fe4 = db_ret8;
            goto shared_4FE4;
        }
    }
}
SOM_REGISTER(0xC04F7B, SOM_RTL, "gen", resolve_actor_pending_physical_hits, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 114, 50)
