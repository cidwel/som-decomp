#include "som_c.h"

/* C04004 apply_pending_actor_hp_mp_damage_and_healing   [class C, 339 bytes, 139 instructions]
 * Source: src/rom/apply_pending_actor_hp_mp_damage_and_healing.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void apply_pending_actor_hp_mp_damage_and_healing(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    if (!(RAM8(0xE1E5 + x) & 0x80)) {
        RETURN_RTS(c);
    }
    if (RAM8(0xE175 + x) != 0) {
        RETURN_RTS(c);
    }
    if ((RAM8(0xE060 + x) & 0xE0) != 0) {
        RETURN_RTS(c);
    }
    if (!(RAM8(ACTOR_STATUS_HIGH + x) & 0x80)) {
        uint16_t value5 = RAM16(ACTOR_PENDING_HP_HEAL + x);
        if (value5 == 0) {
            uint16_t value6 = RAM16(ACTOR_PENDING_HP_DAMAGE + x);
            if (value6 != 0) {
                if (value6 > 0x03E7) {
                    RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x, 0x03E7);
                }
                uint16_t value7 = RAM16(ACTOR_BUFF_FLAGS + x);
                if ((value7 & 0x1000) == 0) {
                    r->a = value7;
                    r->c = value6 <= 0x03E7;
                    r->z = (value7 & 0x1000) == 0;
                    r->n = value7 & 0x8000;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x40AF, 0xC04157); GUARD_JSR(c, sp_call, 0x40AF); } /* send_actor_impact_sound_with_facing_volume */
                    bool x_ret = r->xf;
                    uint16_t x_ret2 = r->x;
                    uint16_t y_ret = r->y;
                    uint16_t value8 = RAM16(ACTOR_HP + x_ret2);
                    uint16_t value9 = RAM16(ACTOR_PENDING_HP_DAMAGE + x_ret2);
                    uint8_t a1;
                    uint8_t a_hi1;
                    bool zero1;
                    if (value8 >= value9) {
                        a1 = (uint8_t)(value8 - value9);
                        a_hi1 = (uint16_t)(value8 - value9) >> 8;
                        zero1 = (uint16_t)(value8 - value9) == 0;
                    } else {
                        a1 = 0;
                        a_hi1 = 0;
                        zero1 = 1;
                    }
                    RAM16_SET(ACTOR_HP + x_ret2, (a_hi1 << 8) | a1);
                    bool m_flag;
                    bool x_flag;
                    uint8_t a_hi2;
                    uint16_t x1;
                    uint16_t y1;
                    bool carry1;
                    bool overflow1;
                    uint8_t data_bank;
                    uint16_t direct_page;
                    if (!zero1) {
                        m_flag = 0;
                        x_flag = x_ret;
                        a_hi2 = a_hi1;
                        x1 = x_ret2;
                        y1 = y_ret;
                        carry1 = value8 >= value9;
                        overflow1 = ((value8 ^ value9) & (value8 ^ (uint16_t)(value8 - value9)) & 0x8000) != 0;
                        data_bank = 0x7E;
                        direct_page = 0x0300;
                    } else {
                        r->a = (a_hi1 << 8) | a1;
                        r->c = value8 >= value9;
                        r->z = zero1;
                        r->v = ((value8 ^ value9) & (value8 ^ (uint16_t)(value8 - value9)) & 0x8000) != 0;
                        r->mf = 0;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x40C5, 0xC04203); GUARD_JSR(c, sp_call, 0x40C5); } /* process_actor_death_rewards_and_drop_conversion */
                        uint16_t dp_ret = r->dp;
                        uint8_t db_ret = r->db;
                        bool m_ret2 = r->mf;
                        bool x_ret3 = r->xf;
                        uint16_t a_all2 = r->a;
                        uint16_t x_ret4 = r->x;
                        uint16_t y_ret2 = r->y;
                        bool carry_ret2 = r->c;
                        bool overflow_ret2 = r->v;
                        m_flag = m_ret2;
                        x_flag = x_ret3;
                        a_hi2 = a_all2 >> 8;
                        x1 = x_ret4;
                        y1 = y_ret2;
                        carry1 = carry_ret2;
                        overflow1 = overflow_ret2;
                        data_bank = db_ret;
                        direct_page = dp_ret;
                    }
                    uint16_t value10 = BUS16_RDP(c, (data_bank << 0x10) + 0xE1F1 + x1);
                    BUS16_SET(c, (data_bank << 0x10) + 0xE17B + x1, value10);
                    BUS16_SET(c, (uint16_t)(direct_page + 0x89), value10);
                    BUS16_SET(c, (data_bank << 0x10) + 0xE1F1 + x1, 0);
                    r->a = value10;
                    r->x = x1;
                    r->y = y1;
                    r->c = carry1;
                    r->z = value10 == 0;
                    r->n = value10 & 0x8000;
                    r->v = overflow1;
                    r->mf = 1;
                    r->xf = x_flag;
                    r->db = data_bank;
                    r->dp = direct_page;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x40D7, 0xC04EBC); GUARD_JSR(c, sp_call, 0x40D7); } /* select_actor_hp_damage_impact_motion */
                    uint8_t db_ret2 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    BUS8_SET(c, (db_ret2 << 0x10) + 0xE175 + x1, 0xD0);
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                uint8_t value11 = RAM8(0xE1F0 + x);
                if (value11 & 0x80) {
                    r->a = (value7 >> 8 << 8) | value11;
                    r->c = value6 <= 0x03E7;
                    r->z = value11 == 0;
                    r->n = value11 & 0x80;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x40AF, 0xC04157); GUARD_JSR(c, sp_call, 0x40AF); } /* send_actor_impact_sound_with_facing_volume */
                    bool x_ret6 = r->xf;
                    uint16_t x_ret7 = r->x;
                    uint16_t y_ret3 = r->y;
                    uint16_t value12 = RAM16(ACTOR_HP + x_ret7);
                    uint16_t value13 = RAM16(ACTOR_PENDING_HP_DAMAGE + x_ret7);
                    uint8_t a2;
                    uint8_t a_hi3;
                    bool zero2;
                    if (value12 >= value13) {
                        a2 = (uint8_t)(value12 - value13);
                        a_hi3 = (uint16_t)(value12 - value13) >> 8;
                        zero2 = (uint16_t)(value12 - value13) == 0;
                    } else {
                        a2 = 0;
                        a_hi3 = 0;
                        zero2 = 1;
                    }
                    RAM16_SET(ACTOR_HP + x_ret7, (a_hi3 << 8) | a2);
                    bool m_flag2;
                    bool x_flag2;
                    uint8_t a_hi4;
                    uint16_t x2;
                    uint16_t y2;
                    bool carry2;
                    bool overflow2;
                    uint8_t data_bank2;
                    uint16_t direct_page2;
                    if (!zero2) {
                        m_flag2 = 0;
                        x_flag2 = x_ret6;
                        a_hi4 = a_hi3;
                        x2 = x_ret7;
                        y2 = y_ret3;
                        carry2 = value12 >= value13;
                        overflow2 = ((value12 ^ value13) & (value12 ^ (uint16_t)(value12 - value13)) & 0x8000) != 0;
                        data_bank2 = 0x7E;
                        direct_page2 = 0x0300;
                    } else {
                        r->a = (a_hi3 << 8) | a2;
                        r->c = value12 >= value13;
                        r->z = zero2;
                        r->v = ((value12 ^ value13) & (value12 ^ (uint16_t)(value12 - value13)) & 0x8000) != 0;
                        r->mf = 0;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x40C5, 0xC04203); GUARD_JSR(c, sp_call, 0x40C5); } /* process_actor_death_rewards_and_drop_conversion */
                        uint16_t dp_ret3 = r->dp;
                        uint8_t db_ret3 = r->db;
                        bool m_ret4 = r->mf;
                        bool x_ret8 = r->xf;
                        uint16_t a_all5 = r->a;
                        uint16_t x_ret9 = r->x;
                        uint16_t y_ret4 = r->y;
                        bool carry_ret5 = r->c;
                        bool overflow_ret4 = r->v;
                        m_flag2 = m_ret4;
                        x_flag2 = x_ret8;
                        a_hi4 = a_all5 >> 8;
                        x2 = x_ret9;
                        y2 = y_ret4;
                        carry2 = carry_ret5;
                        overflow2 = overflow_ret4;
                        data_bank2 = db_ret3;
                        direct_page2 = dp_ret3;
                    }
                    uint16_t value14 = BUS16_RDP(c, (data_bank2 << 0x10) + 0xE1F1 + x2);
                    BUS16_SET(c, (data_bank2 << 0x10) + 0xE17B + x2, value14);
                    BUS16_SET(c, (uint16_t)(direct_page2 + 0x89), value14);
                    BUS16_SET(c, (data_bank2 << 0x10) + 0xE1F1 + x2, 0);
                    r->a = value14;
                    r->x = x2;
                    r->y = y2;
                    r->c = carry2;
                    r->z = value14 == 0;
                    r->n = value14 & 0x8000;
                    r->v = overflow2;
                    r->mf = 1;
                    r->xf = x_flag2;
                    r->db = data_bank2;
                    r->dp = direct_page2;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x40D7, 0xC04EBC); GUARD_JSR(c, sp_call, 0x40D7); } /* select_actor_hp_damage_impact_motion */
                    uint8_t db_ret4 = r->db;
                    if (r->mf != 1) { c->fail = 3; return; }
                    BUS8_SET(c, (db_ret4 << 0x10) + 0xE175 + x2, 0xD0);
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                }
                RAM8(0x0000 + sp0) = RAM8(ACTOR_HIT_SOUND + x);
                RAM8(ACTOR_HIT_SOUND + x) = 0x2F;
                r->a = (value7 >> 8 << 8) | 0x2F;
                r->c = value6 <= 0x03E7;
                r->z = 0;
                r->n = 0;
                r->sp -= 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x4082, 0xC04157); GUARD_JSR(c, sp_call, 0x4082); } /* send_actor_impact_sound_with_facing_volume */
                r->sp += 1;
                bool m_ret5 = r->mf;
                uint16_t x_ret12 = r->x;
                if (m_ret5) {
                    RAM8(ACTOR_HIT_SOUND + x_ret12) = RAM8(0x0000 + sp0);
                    uint16_t value17 = RAM16(0xE1BD + x_ret12);
                    uint16_t value18 = RAM16(ACTOR_PENDING_HP_DAMAGE + x_ret12);
                    uint8_t a3;
                    uint8_t a_hi5;
                    bool zero3;
                    if (value17 >= value18) {
                        a3 = (uint8_t)(value17 - value18);
                        a_hi5 = (uint16_t)(value17 - value18) >> 8;
                        zero3 = (uint16_t)(value17 - value18) == 0;
                    } else {
                        a3 = 0;
                        a_hi5 = 0;
                        zero3 = 1;
                    }
                    RAM16_SET(0xE1BD + x_ret12, (a_hi5 << 8) | a3);
                    uint8_t a_hi6;
                    if (!zero3) {
                        a_hi6 = a_hi5;
                    } else {
                        uint16_t value19 = RAM16(ACTOR_BUFF_FLAGS + x_ret12);
                        RAM16_SET(ACTOR_BUFF_FLAGS + x_ret12, value19 & 0xEFFF);
                        a_hi6 = (value19 & 0xEFFF) >> 8;
                    }
                    RAM16_SET(ACTOR_PENDING_HP_DAMAGE + x_ret12, 0);
                    r->a = (r->a & 0x00FF) | (a_hi6 << 8);
                    r->c = value17 >= value18;
                    r->v = ((value17 ^ value18) & (value17 ^ (uint16_t)(value17 - value18)) & 0x8000) != 0;
                    r->mf = 1;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
            uint8_t value20 = RAM8(ACTOR_PENDING_MP_HEAL + x);
            if (value20 == 0) {
                uint8_t value21 = RAM8(ACTOR_PENDING_MP_DAMAGE + x);
                if (value21 == 0) {
                    r->a = (r->a & 0x00FF) | ((value6 >> 8) << 8);
                    RETURN_RTS(c);
                }
                if (value21 > 0x63) {
                    RAM8(ACTOR_PENDING_MP_DAMAGE + x) = 0x63;
                }
                RAM8(BATTLE_TEMP_A4) = RAM8(ACTOR_PENDING_MP_DAMAGE + x);
                uint8_t value23 = RAM8(ACTOR_MP + x);
                uint8_t battle_temp_a4 = RAM8(BATTLE_TEMP_A4);
                uint8_t a4;
                if (value23 >= battle_temp_a4) {
                    a4 = (uint8_t)(value23 - battle_temp_a4);
                } else {
                    a4 = 0;
                }
                RAM8(ACTOR_MP + x) = a4;
                uint8_t value24 = RAM8(ACTOR_PENDING_MP_DAMAGE + x);
                RAM8(BATTLE_DAMAGE) = value24;
                RAM8(0x038A) = 0;
                RAM8(0xE17B + x) = value24;
                RAM8(0xE17C + x) = 0;
                RAM8(ACTOR_PENDING_MP_DAMAGE + x) = 0;
                r->a = (value6 >> 8 << 8) | value24;
                r->c = value23 >= battle_temp_a4;
                r->z = value24 == 0;
                r->n = value24 & 0x80;
                r->v = ((value23 ^ battle_temp_a4) & (value23 ^ (uint8_t)(value23 - battle_temp_a4)) & 0x80) != 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x414F, 0xC04F1E); GUARD_JSR(c, sp_call, 0x414F); } /* select_actor_mp_damage_impact_motion */
                RAM8(0xE175 + x) = 0xE0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTS(c);
            }
            if (value20 > 0x63) {
                RAM8(ACTOR_PENDING_MP_HEAL + x) = 0x63;
            }
            uint8_t value25 = RAM8(ACTOR_PENDING_MP_HEAL + x);
            uint8_t value26 = RAM8(ACTOR_MP + x);
            uint8_t a5;
            if (value25 + value26 <= 0xFF) {
                a5 = (uint8_t)(value25 + value26);
            } else {
                a5 = 0x63;
            }
            uint8_t value27 = RAM8(ACTOR_MAX_MP + x);
            uint8_t a6;
            if (a5 < value27) {
                a6 = a5;
            } else {
                a6 = value27;
            }
            RAM8(ACTOR_MP + x) = a6;
            uint8_t value28 = RAM8(ACTOR_PENDING_MP_HEAL + x);
            RAM8(0xE17B + x) = value28;
            RAM8(0xE17C + x) = 0;
            RAM8(ACTOR_PENDING_MP_HEAL + x) = 0;
            r->a = (value6 >> 8 << 8) | value28;
            r->c = a5 >= value27;
            r->z = value28 == 0;
            r->n = value28 & 0x80;
            r->v = ((value25 ^ (uint8_t)(value25 + value26)) & (value26 ^ (uint8_t)(value25 + value26)) & 0x80) != 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x4115, 0xC04F4F); GUARD_JSR(c, sp_call, 0x4115); } /* select_actor_recovery_impact_motion */
            RAM8(0xE175 + x) = 0xE8;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if (value5 > 0x03E7) {
            RAM16_SET(ACTOR_PENDING_HP_HEAL + x, 0x03E7);
        }
        uint16_t value29 = RAM16(ACTOR_PENDING_HP_HEAL + x);
        uint16_t value30 = RAM16(ACTOR_HP + x);
        uint16_t value31 = RAM16(ACTOR_MAX_HP + x);
        uint8_t a7;
        uint8_t a_hi7;
        if ((uint16_t)(value29 + value30) < value31) {
            a7 = (uint8_t)(value29 + value30);
            a_hi7 = (uint16_t)(value29 + value30) >> 8;
        } else {
            a7 = (uint8_t)value31;
            a_hi7 = value31 >> 8;
        }
        RAM16_SET(ACTOR_HP + x, (a_hi7 << 8) | a7);
        uint16_t value32 = RAM16(ACTOR_PENDING_HP_HEAL + x);
        RAM16_SET(0xE17B + x, value32);
        RAM16_SET(ACTOR_PENDING_HP_HEAL + x, 0);
        r->a = value32;
        r->c = (uint16_t)(value29 + value30) >= value31;
        r->z = value32 == 0;
        r->n = value32 & 0x8000;
        r->v = ((value29 ^ (uint16_t)(value29 + value30)) & (value30 ^ (uint16_t)(value29 + value30)) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x404C, 0xC04F4F); GUARD_JSR(c, sp_call, 0x404C); } /* select_actor_recovery_impact_motion */
        RAM8(0xE175 + x) = 0xD8;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04004, SOM_RTS, "gen", apply_pending_actor_hp_mp_damage_and_healing, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 339, 139)
