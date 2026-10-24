#include "som_c.h"

static void advance_hero_charge_gauge_status_and_visual_effect_worker(SomCtx *c);
static void advance_hero_charge_gauge_status_and_visual_effect_worker_v2(SomCtx *c);

/* C0EB18 advance_three_hero_charge_workers_after_link_preparation   [class B, 158 bytes, 65 instructions]
 * Source: src/rom/advance_three_hero_charge_workers_after_link_preparation.s
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void advance_three_hero_charge_workers_after_link_preparation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp_in = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x004E);
    bool m_flag;
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if (value == 0) {
        m_flag = 1;
        a1 = value;
        a_hi1 = a_hi;
        carry1 = carry;
        overflow1 = overflow;
    } else {
        r->a = (a_hi << 8) | value;
        r->z = value == 0;
        r->n = value & 0x80;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEB22, 0xC0F025); GUARD_JSR(c, sp_call, 0xEB22); } /* synchronize_linked_hero_fields_unless_native_byte_positions_differ */
        bool m_ret = r->mf;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = 0;
    r->c = carry1;
    r->z = 1;
    r->n = 0;
    r->v = overflow1;
    r->mf = m_flag;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xEB28, advance_hero_charge_gauge_status_and_visual_effect_worker, sp_in, 2); GUARD_JSR(c, sp_call, 0xEB28); }
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x0200;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xEB2E, advance_hero_charge_gauge_status_and_visual_effect_worker_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xEB2E); }
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x0400;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xEB34, advance_hero_charge_gauge_status_and_visual_effect_worker_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xEB34); }
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0EB18, SOM_RTS, "gen", advance_three_hero_charge_workers_after_link_preparation, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 9, 1, 1, 158, 65)

/* C0EB36 advance_hero_charge_gauge_status_and_visual_effect_worker   [class A, 129 bytes, 54 instructions]
 * Source: src/rom/advance_three_hero_charge_workers_after_link_preparation.s
 * Subroutine of advance_three_hero_charge_workers_after_link_preparation, translated in place.
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void advance_hero_charge_gauge_status_and_visual_effect_worker(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xE00F + x);
    if (value != 0) {
        SET_A8(r, value);
        r->z = value == 0;
        r->n = value & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value2 = RAM8(0xE000 + x);
    if (value2 == 0) {
        SET_A8(r, value2);
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (value2 & 0x80) {
        SET_A8(r, value2);
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0xE061 + x);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    if (value3 == 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a >> 8;
        x1 = x;
        y1 = y;
        carry1 = carry;
        overflow1 = overflow;
        data_bank = 0x7E;
    } else {
        r->a = (a >> 8 << 8) | value3;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEB4C, 0x02C221); GUARD_JSL(c, sp_call, 0xEB4C); } /* update_all_three_actor_charge_effect_records */
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
    }
    uint8_t value4 = BUS8_RDP(c, (data_bank << 0x10) + 0xE1ED + x1);
    bool x_flag3;
    uint8_t a_hi3;
    uint16_t y3;
    bool carry3;
    bool overflow3;
    if (value4 == 0) {
        x_flag3 = x_flag;
        a_hi3 = a_hi1;
        y3 = y1;
        carry3 = carry1;
        overflow3 = overflow1;
    } else {
        RAM8(0x0000) = value4;
        uint8_t value5 = BUS8_RDP(c, (data_bank << 0x10) + 0xE01C + x1);
        bool x_flag2;
        uint8_t a_hi2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if ((value5 & 0xA0) != 0) {
            x_flag2 = x_flag;
            a_hi2 = a_hi1;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            uint8_t value6 = RAM8(0x0000);
            BUS8_SET(c, (data_bank << 0x10) + 0xE1ED + x1, (uint8_t)(value6 - 1));
            r->a = (a_hi1 << 8) | (uint8_t)(value6 - 1);
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->z = (uint8_t)(value6 - 1) == 0;
            r->n = (uint8_t)(value6 - 1) & 0x80;
            r->v = overflow1;
            r->mf = 1;
            r->xf = x_flag;
            r->db = data_bank;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEB65, 0xC0EBB6); GUARD_JSR(c, sp_call, 0xEB65); } /* present_actor_charge_gauge_and_deferred_flash */
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            x_flag2 = x_ret3;
            a_hi2 = a_all2 >> 8;
            y2 = y_ret2;
            carry2 = carry_ret2;
            overflow2 = overflow_ret2;
        }
        x_flag3 = x_flag2;
        a_hi3 = a_hi2;
        y3 = y2;
        carry3 = carry2;
        overflow3 = overflow2;
    }
    uint8_t value7 = BUS8_RDP(c, (data_bank << 0x10) + 0xE100 + x1);
    bool x_flag4;
    uint8_t a_hi4;
    uint16_t y4;
    bool carry4;
    bool overflow4;
    if (!(value7 & 0x80)) {
        x_flag4 = x_flag3;
        a_hi4 = a_hi3;
        y4 = y3;
        carry4 = carry3;
        overflow4 = overflow3;
    } else {
        r->a = (a_hi3 << 8) | value7;
        r->x = x1;
        r->y = y3;
        r->c = carry3;
        r->z = value7 == 0;
        r->n = value7 & 0x80;
        r->v = overflow3;
        r->mf = 1;
        r->xf = x_flag3;
        r->db = data_bank;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEB6F, 0xC0ED08); GUARD_JSR(c, sp_call, 0xEB6F); } /* advance_actor_primary_status_palette */
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        x_flag4 = x_ret4;
        a_hi4 = a_all3 >> 8;
        y4 = y_ret3;
        carry4 = carry_ret3;
        overflow4 = overflow_ret3;
    }
    uint8_t value8 = BUS8_RDP(c, (data_bank << 0x10) + 0xE104 + x1);
    bool m_flag2;
    bool x_flag5;
    uint8_t a_hi5;
    uint16_t y5;
    bool carry5;
    bool overflow5;
    uint8_t data_bank2;
    uint16_t direct_page;
    if (!(value8 & 0x80)) {
        m_flag2 = 1;
        x_flag5 = x_flag4;
        a_hi5 = a_hi4;
        y5 = y4;
        carry5 = carry4;
        overflow5 = overflow4;
        data_bank2 = data_bank;
        direct_page = 0;
    } else {
        r->a = (a_hi4 << 8) | value8;
        r->x = x1;
        r->y = y4;
        r->c = carry4;
        r->z = value8 == 0;
        r->n = value8 & 0x80;
        r->v = overflow4;
        r->mf = 1;
        r->xf = x_flag4;
        r->db = data_bank;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEB77, 0xC0EDD7); GUARD_JSR(c, sp_call, 0xEB77); } /* advance_actor_secondary_status_palette */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret3 = r->mf;
        bool x_ret5 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        m_flag2 = m_ret3;
        x_flag5 = x_ret5;
        a_hi5 = a_all4 >> 8;
        y5 = y_ret4;
        carry5 = carry_ret4;
        overflow5 = overflow_ret4;
        data_bank2 = db_ret2;
        direct_page = dp_ret;
    }
    if (m_flag2) {
        uint8_t value9 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE060 + x1);
        if (value9 == 0) {
            uint8_t value10 = BUS8_RDP(c, (uint16_t)(direct_page + 0xF1));
            if (value10 & 0x40) {
                r->a = (a_hi5 << 8) | value9;
                r->x = x1;
                r->y = y5;
                r->c = carry5;
                r->z = (value9 & value10) == 0;
                r->n = value10 & 0x80;
                r->v = value10 & 0x40;
                r->mf = 1;
                r->xf = x_flag5;
                r->db = data_bank2;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value11 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE00A + x1);
            if (value11 == 0) {
                uint8_t value12 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE064 + x1);
                uint8_t a2;
                bool zero2;
                bool negative2;
                if (value12 & 0x80) {
                    a2 = value12;
                    zero2 = value12 == 0;
                    negative2 = value12 & 0x80;
                } else {
                    uint8_t value13 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE062 + x1);
                    uint8_t a1;
                    bool zero1;
                    bool negative1;
                    if (value13 == 0) {
                        a1 = value13;
                        zero1 = value13 == 0;
                        negative1 = value13 & 0x80;
                    } else {
                        BUS8_SET(c, (data_bank2 << 0x10) + 0xE062 + x1, (uint8_t)(value13 - 1));
                        a1 = (uint8_t)(value13 - 1);
                        zero1 = (uint8_t)(value13 - 1) == 0;
                        negative1 = (uint8_t)(value13 - 1) & 0x80;
                    }
                    a2 = a1;
                    zero2 = zero1;
                    negative2 = negative1;
                }
                r->a = (a_hi5 << 8) | a2;
                r->x = x1;
                r->y = y5;
                r->c = carry5;
                r->z = zero2;
                r->n = negative2;
                r->v = value10 & 0x40;
                r->mf = 1;
                r->xf = x_flag5;
                r->db = data_bank2;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            BUS8_SET(c, (data_bank2 << 0x10) + 0xE00A + x1, (uint8_t)(value11 - 1));
            if ((uint8_t)(value11 - 1) == 0) {
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE011 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE042 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE006 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE007 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE008 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE064 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE062 + x1, (uint8_t)(value11 - 1));
            }
            r->a = (a_hi5 << 8) | (uint8_t)(value11 - 1);
            r->x = x1;
            r->y = y5;
            r->c = carry5;
            r->z = (uint8_t)(value11 - 1) == 0;
            r->n = (uint8_t)(value11 - 1) & 0x80;
            r->v = value10 & 0x40;
            r->mf = 1;
            r->xf = x_flag5;
            r->db = data_bank2;
            r->dp = direct_page;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = (a_hi5 << 8) | value9;
        r->x = x1;
        r->y = y5;
        r->c = carry5;
        r->z = value9 == 0;
        r->n = value9 & 0x80;
        r->v = overflow5;
        r->mf = 1;
        r->xf = x_flag5;
        r->db = data_bank2;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEB80, 0x01833A); GUARD_JSL(c, sp_call, 0xEB80); } /* dispatch_actor_counter_or_spell_visual_effect_frame */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value14 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE060 + x1);
        if (value14 == 0) {
            uint16_t value15 = BUS16_RDP(c, (uint16_t)(direct_page + 0xF1));
            if (value15 & 0x4000) {
                r->a = value14;
                r->x = x1;
                r->y = y5;
                r->c = carry5;
                r->z = (value14 & value15) == 0;
                r->n = value15 & 0x8000;
                r->v = value15 & 0x4000;
                r->mf = 0;
                r->xf = x_flag5;
                r->db = data_bank2;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint16_t value16 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE00A + x1);
            if (value16 == 0) {
                uint16_t value17 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE064 + x1);
                uint8_t a4;
                uint8_t a_hi7;
                bool zero4;
                bool negative4;
                if (value17 & 0x8000) {
                    a4 = (uint8_t)value17;
                    a_hi7 = value17 >> 8;
                    zero4 = value17 == 0;
                    negative4 = value17 & 0x8000;
                } else {
                    uint16_t value18 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE062 + x1);
                    uint8_t a3;
                    uint8_t a_hi6;
                    bool zero3;
                    bool negative3;
                    if (value18 == 0) {
                        a3 = (uint8_t)value18;
                        a_hi6 = value18 >> 8;
                        zero3 = value18 == 0;
                        negative3 = value18 & 0x8000;
                    } else {
                        BUS16_SET(c, (data_bank2 << 0x10) + 0xE062 + x1, (uint16_t)(value18 - 1));
                        a3 = (uint8_t)(value18 - 1);
                        a_hi6 = (uint16_t)(value18 - 1) >> 8;
                        zero3 = (uint16_t)(value18 - 1) == 0;
                        negative3 = (uint16_t)(value18 - 1) & 0x8000;
                    }
                    a4 = a3;
                    a_hi7 = a_hi6;
                    zero4 = zero3;
                    negative4 = negative3;
                }
                r->a = (a_hi7 << 8) | a4;
                r->x = x1;
                r->y = y5;
                r->c = carry5;
                r->z = zero4;
                r->n = negative4;
                r->v = value15 & 0x4000;
                r->mf = 0;
                r->xf = x_flag5;
                r->db = data_bank2;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            BUS16_SET(c, (data_bank2 << 0x10) + 0xE00A + x1, (uint16_t)(value16 - 1));
            if ((uint16_t)(value16 - 1) == 0) {
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE011 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE042 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE006 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE007 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE008 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE064 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE062 + x1, (uint16_t)(value16 - 1));
            }
            r->a = (uint16_t)(value16 - 1);
            r->x = x1;
            r->y = y5;
            r->c = carry5;
            r->z = (uint16_t)(value16 - 1) == 0;
            r->n = (uint16_t)(value16 - 1) & 0x8000;
            r->v = value15 & 0x4000;
            r->mf = 0;
            r->xf = x_flag5;
            r->db = data_bank2;
            r->dp = direct_page;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = value14;
        r->x = x1;
        r->y = y5;
        r->c = carry5;
        r->z = value14 == 0;
        r->n = value14 & 0x8000;
        r->v = overflow5;
        r->mf = 0;
        r->xf = x_flag5;
        r->db = data_bank2;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEB80, 0x01833A); GUARD_JSL(c, sp_call, 0xEB80); } /* dispatch_actor_counter_or_spell_visual_effect_frame */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}

/* C0EB36 advance_hero_charge_gauge_status_and_visual_effect_worker_v2   [class A, 129 bytes, 54 instructions]
 * Source: src/rom/advance_three_hero_charge_workers_after_link_preparation.s
 * Subroutine of advance_three_hero_charge_workers_after_link_preparation, translated in place.
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void advance_hero_charge_gauge_status_and_visual_effect_worker_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0xE00F + x);
    if (value != 0) {
        SET_A8(r, value);
        r->z = value == 0;
        r->n = value & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0xE000 + x);
    if (value2 == 0) {
        SET_A8(r, value2);
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (value2 & 0x80) {
        SET_A8(r, value2);
        r->z = value2 == 0;
        r->n = value2 & 0x80;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0xE061 + x);
    bool m_flag;
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    uint8_t data_bank;
    if (value3 == 0) {
        m_flag = 1;
        x_flag = 0;
        a_hi1 = a >> 8;
        x1 = x;
        y1 = y;
        carry1 = carry;
        overflow1 = overflow;
        data_bank = db;
    } else {
        r->a = (a >> 8 << 8) | value3;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEB4C, 0x02C221); GUARD_JSL(c, sp_call, 0xEB4C); } /* update_all_three_actor_charge_effect_records */
        uint8_t db_ret = r->db;
        bool m_ret = r->mf;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        m_flag = m_ret;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
    }
    uint8_t value4 = BUS8_RDP(c, (data_bank << 0x10) + 0xE1ED + x1);
    bool x_flag3;
    uint8_t a_hi3;
    uint16_t y3;
    bool carry3;
    bool overflow3;
    if (value4 == 0) {
        x_flag3 = x_flag;
        a_hi3 = a_hi1;
        y3 = y1;
        carry3 = carry1;
        overflow3 = overflow1;
    } else {
        BUS8_SET(c, dp, value4);
        uint8_t value5 = BUS8_RDP(c, (data_bank << 0x10) + 0xE01C + x1);
        bool x_flag2;
        uint8_t a_hi2;
        uint16_t y2;
        bool carry2;
        bool overflow2;
        if ((value5 & 0xA0) != 0) {
            x_flag2 = x_flag;
            a_hi2 = a_hi1;
            y2 = y1;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            uint8_t value6 = BUS8_RDP(c, dp);
            BUS8_SET(c, (data_bank << 0x10) + 0xE1ED + x1, (uint8_t)(value6 - 1));
            r->a = (a_hi1 << 8) | (uint8_t)(value6 - 1);
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->z = (uint8_t)(value6 - 1) == 0;
            r->n = (uint8_t)(value6 - 1) & 0x80;
            r->v = overflow1;
            r->mf = 1;
            r->xf = x_flag;
            r->db = data_bank;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEB65, 0xC0EBB6); GUARD_JSR(c, sp_call, 0xEB65); } /* present_actor_charge_gauge_and_deferred_flash */
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            x_flag2 = x_ret3;
            a_hi2 = a_all2 >> 8;
            y2 = y_ret2;
            carry2 = carry_ret2;
            overflow2 = overflow_ret2;
        }
        x_flag3 = x_flag2;
        a_hi3 = a_hi2;
        y3 = y2;
        carry3 = carry2;
        overflow3 = overflow2;
    }
    uint8_t value7 = BUS8_RDP(c, (data_bank << 0x10) + 0xE100 + x1);
    bool x_flag4;
    uint8_t a_hi4;
    uint16_t y4;
    bool carry4;
    bool overflow4;
    if (!(value7 & 0x80)) {
        x_flag4 = x_flag3;
        a_hi4 = a_hi3;
        y4 = y3;
        carry4 = carry3;
        overflow4 = overflow3;
    } else {
        r->a = (a_hi3 << 8) | value7;
        r->x = x1;
        r->y = y3;
        r->c = carry3;
        r->z = value7 == 0;
        r->n = value7 & 0x80;
        r->v = overflow3;
        r->mf = 1;
        r->xf = x_flag3;
        r->db = data_bank;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEB6F, 0xC0ED08); GUARD_JSR(c, sp_call, 0xEB6F); } /* advance_actor_primary_status_palette */
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        x_flag4 = x_ret4;
        a_hi4 = a_all3 >> 8;
        y4 = y_ret3;
        carry4 = carry_ret3;
        overflow4 = overflow_ret3;
    }
    uint8_t value8 = BUS8_RDP(c, (data_bank << 0x10) + 0xE104 + x1);
    bool m_flag2;
    bool x_flag5;
    uint8_t a_hi5;
    uint16_t y5;
    bool carry5;
    bool overflow5;
    uint8_t data_bank2;
    uint16_t direct_page;
    if (!(value8 & 0x80)) {
        m_flag2 = 1;
        x_flag5 = x_flag4;
        a_hi5 = a_hi4;
        y5 = y4;
        carry5 = carry4;
        overflow5 = overflow4;
        data_bank2 = data_bank;
        direct_page = dp;
    } else {
        r->a = (a_hi4 << 8) | value8;
        r->x = x1;
        r->y = y4;
        r->c = carry4;
        r->z = value8 == 0;
        r->n = value8 & 0x80;
        r->v = overflow4;
        r->mf = 1;
        r->xf = x_flag4;
        r->db = data_bank;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEB77, 0xC0EDD7); GUARD_JSR(c, sp_call, 0xEB77); } /* advance_actor_secondary_status_palette */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret2 = r->db;
        bool m_ret3 = r->mf;
        bool x_ret5 = r->xf;
        uint16_t a_all4 = r->a;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool overflow_ret4 = r->v;
        m_flag2 = m_ret3;
        x_flag5 = x_ret5;
        a_hi5 = a_all4 >> 8;
        y5 = y_ret4;
        carry5 = carry_ret4;
        overflow5 = overflow_ret4;
        data_bank2 = db_ret2;
        direct_page = dp_ret;
    }
    if (m_flag2) {
        uint8_t value9 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE060 + x1);
        if (value9 == 0) {
            uint8_t value10 = BUS8_RDP(c, (uint16_t)(direct_page + 0xF1));
            if (value10 & 0x40) {
                r->a = (a_hi5 << 8) | value9;
                r->x = x1;
                r->y = y5;
                r->c = carry5;
                r->z = (value9 & value10) == 0;
                r->n = value10 & 0x80;
                r->v = value10 & 0x40;
                r->mf = 1;
                r->xf = x_flag5;
                r->db = data_bank2;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value11 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE00A + x1);
            if (value11 == 0) {
                uint8_t value12 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE064 + x1);
                uint8_t a2;
                bool zero2;
                bool negative2;
                if (value12 & 0x80) {
                    a2 = value12;
                    zero2 = value12 == 0;
                    negative2 = value12 & 0x80;
                } else {
                    uint8_t value13 = BUS8_RDP(c, (data_bank2 << 0x10) + 0xE062 + x1);
                    uint8_t a1;
                    bool zero1;
                    bool negative1;
                    if (value13 == 0) {
                        a1 = value13;
                        zero1 = value13 == 0;
                        negative1 = value13 & 0x80;
                    } else {
                        BUS8_SET(c, (data_bank2 << 0x10) + 0xE062 + x1, (uint8_t)(value13 - 1));
                        a1 = (uint8_t)(value13 - 1);
                        zero1 = (uint8_t)(value13 - 1) == 0;
                        negative1 = (uint8_t)(value13 - 1) & 0x80;
                    }
                    a2 = a1;
                    zero2 = zero1;
                    negative2 = negative1;
                }
                r->a = (a_hi5 << 8) | a2;
                r->x = x1;
                r->y = y5;
                r->c = carry5;
                r->z = zero2;
                r->n = negative2;
                r->v = value10 & 0x40;
                r->mf = 1;
                r->xf = x_flag5;
                r->db = data_bank2;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            BUS8_SET(c, (data_bank2 << 0x10) + 0xE00A + x1, (uint8_t)(value11 - 1));
            if ((uint8_t)(value11 - 1) == 0) {
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE011 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE042 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE006 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE007 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE008 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE064 + x1, (uint8_t)(value11 - 1));
                BUS8_SET(c, (data_bank2 << 0x10) + 0xE062 + x1, (uint8_t)(value11 - 1));
            }
            r->a = (a_hi5 << 8) | (uint8_t)(value11 - 1);
            r->x = x1;
            r->y = y5;
            r->c = carry5;
            r->z = (uint8_t)(value11 - 1) == 0;
            r->n = (uint8_t)(value11 - 1) & 0x80;
            r->v = value10 & 0x40;
            r->mf = 1;
            r->xf = x_flag5;
            r->db = data_bank2;
            r->dp = direct_page;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = (a_hi5 << 8) | value9;
        r->x = x1;
        r->y = y5;
        r->c = carry5;
        r->z = value9 == 0;
        r->n = value9 & 0x80;
        r->v = overflow5;
        r->mf = 1;
        r->xf = x_flag5;
        r->db = data_bank2;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEB80, 0x01833A); GUARD_JSL(c, sp_call, 0xEB80); } /* dispatch_actor_counter_or_spell_visual_effect_frame */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value14 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE060 + x1);
        if (value14 == 0) {
            uint16_t value15 = BUS16_RDP(c, (uint16_t)(direct_page + 0xF1));
            if (value15 & 0x4000) {
                r->a = value14;
                r->x = x1;
                r->y = y5;
                r->c = carry5;
                r->z = (value14 & value15) == 0;
                r->n = value15 & 0x8000;
                r->v = value15 & 0x4000;
                r->mf = 0;
                r->xf = x_flag5;
                r->db = data_bank2;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint16_t value16 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE00A + x1);
            if (value16 == 0) {
                uint16_t value17 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE064 + x1);
                uint8_t a4;
                uint8_t a_hi7;
                bool zero4;
                bool negative4;
                if (value17 & 0x8000) {
                    a4 = (uint8_t)value17;
                    a_hi7 = value17 >> 8;
                    zero4 = value17 == 0;
                    negative4 = value17 & 0x8000;
                } else {
                    uint16_t value18 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE062 + x1);
                    uint8_t a3;
                    uint8_t a_hi6;
                    bool zero3;
                    bool negative3;
                    if (value18 == 0) {
                        a3 = (uint8_t)value18;
                        a_hi6 = value18 >> 8;
                        zero3 = value18 == 0;
                        negative3 = value18 & 0x8000;
                    } else {
                        BUS16_SET(c, (data_bank2 << 0x10) + 0xE062 + x1, (uint16_t)(value18 - 1));
                        a3 = (uint8_t)(value18 - 1);
                        a_hi6 = (uint16_t)(value18 - 1) >> 8;
                        zero3 = (uint16_t)(value18 - 1) == 0;
                        negative3 = (uint16_t)(value18 - 1) & 0x8000;
                    }
                    a4 = a3;
                    a_hi7 = a_hi6;
                    zero4 = zero3;
                    negative4 = negative3;
                }
                r->a = (a_hi7 << 8) | a4;
                r->x = x1;
                r->y = y5;
                r->c = carry5;
                r->z = zero4;
                r->n = negative4;
                r->v = value15 & 0x4000;
                r->mf = 0;
                r->xf = x_flag5;
                r->db = data_bank2;
                r->dp = direct_page;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            BUS16_SET(c, (data_bank2 << 0x10) + 0xE00A + x1, (uint16_t)(value16 - 1));
            if ((uint16_t)(value16 - 1) == 0) {
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE011 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE042 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE006 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE007 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE008 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE064 + x1, (uint16_t)(value16 - 1));
                BUS16_SET(c, (data_bank2 << 0x10) + 0xE062 + x1, (uint16_t)(value16 - 1));
            }
            r->a = (uint16_t)(value16 - 1);
            r->x = x1;
            r->y = y5;
            r->c = carry5;
            r->z = (uint16_t)(value16 - 1) == 0;
            r->n = (uint16_t)(value16 - 1) & 0x8000;
            r->v = value15 & 0x4000;
            r->mf = 0;
            r->xf = x_flag5;
            r->db = data_bank2;
            r->dp = direct_page;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = value14;
        r->x = x1;
        r->y = y5;
        r->c = carry5;
        r->z = value14 == 0;
        r->n = value14 & 0x8000;
        r->v = overflow5;
        r->mf = 0;
        r->xf = x_flag5;
        r->db = data_bank2;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEB80, 0x01833A); GUARD_JSL(c, sp_call, 0xEB80); } /* dispatch_actor_counter_or_spell_visual_effect_frame */
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
