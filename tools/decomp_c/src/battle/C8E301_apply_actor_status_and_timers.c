#include "som_c.h"

/* C8E301 apply_actor_status_and_timers   [class C, 320 bytes, 135 instructions]
 * Source: src/rom/apply_actor_status_and_timers.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void apply_actor_status_and_timers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a_hi_e34b = 0;
    uint16_t x_e34b = 0;
    uint16_t y_e34b = 0;
    RAM16_SET(0x0398, 0);
    RAM16_SET(0x0398, RAM16(0x039A) | RAM16(0x0398));
    uint16_t value3 = RAM16(ACTOR_STATUS_IMMUNITY + x);
    RAM16_SET(BATTLE_TEMP_A4, value3 ^ 0xFFFF);
    uint16_t value4 = RAM16(0x0398);
    RAM16_SET(0x0398, (value3 ^ 0xFFFF) & value4);
    RAM16_SET(0x039A, 0);
    RAM16_SET(ACTOR_STATUS + x, (((value3 ^ 0xFFFF) & value4) | RAM16(ACTOR_STATUS + x)) & RAM16(BATTLE_TEMP_A4));
    uint16_t value6 = RAM16(0xE1EE + x);
    RAM16_SET(BATTLE_TEMP_A6, value6);
    RAM16_SET(0x0398, ((value6 ^ 0xFFFC) & RAM16(ACTOR_STATUS + x)) | RAM16(0x0398));
    uint16_t value9 = RAM16(ACTOR_STATUS + x);
    uint16_t value10 = RAM16(0xE1EE + x);
    if ((value9 & 0xFFFC) != value10) {
        uint16_t value11 = RAM16(0xE1FA + x);
        RAM16_SET(0xE1FA + x, value11 | 2);
        a_hi_e34b = (value11 | 2) >> 8;
        x_e34b = x;
        y_e34b = y;
        goto shared_E34B;
    }
    uint16_t value12 = RAM16(0x0398);
    if (value12 != 0) {
        a_hi_e34b = value12 >> 8;
        x_e34b = x;
        y_e34b = y;
        goto shared_E34B;
    }
    r->a = value12;
    r->c = (value9 & 0xFFFC) >= value10;
    r->z = value12 == 0;
    r->n = value12 & 0x8000;
    RETURN_RTL(c);
    shared_E34B:;
    RAM16_SET(0x03B0, 0xFFFF);
    uint16_t value13 = RAM16(ACTOR_STATUS + x_e34b);
    uint16_t value14 = RAM16(0xE1EE + x_e34b);
    RAM16_SET(BATTLE_TEMP_AE, (value13 ^ 0xFFFF) & value14);
    bool x_flag;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    if (!((value13 ^ 0xFFFF) & value14 & 0x8000)) {
        x_flag = 0;
        a_hi1 = ((value13 ^ 0xFFFF) & value14) >> 8;
        x1 = x_e34b;
        y1 = y_e34b;
    } else {
        r->a = (value13 ^ 0xFFFF) & value14;
        r->x = x_e34b;
        r->y = y_e34b;
        r->z = ((value13 ^ 0xFFFF) & value14) == 0;
        r->n = (value13 ^ 0xFFFF) & value14 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0300;
        { const uint16_t sp_call = r->sp; JSR(c, 0xE35F, 0xC8E441); GUARD_JSR(c, sp_call, 0xE35F); } /* clear_recovered_actor_status_and_resume_hero_program */
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        x_flag = x_ret;
        a_hi1 = a_all >> 8;
        x1 = x_ret2;
        y1 = y_ret;
    }
    uint16_t value15 = RAM16(ACTOR_STATUS + x1);
    uint8_t a_hi2;
    if (!(value15 & 0x8000)) {
        a_hi2 = value15 >> 8;
    } else {
        RAM16_SET(ACTOR_STATUS + x1, value15 & 0x8000);
        uint16_t value16 = RAM16(0x0398);
        RAM16_SET(0x0398, value16 & 0x8000);
        a_hi2 = (value16 & 0x8000) >> 8;
    }
    uint16_t value17 = RAM16(0x0398);
    uint8_t a_hi3;
    if (!(value17 & 0x8000)) {
        a_hi3 = value17 >> 8;
    } else {
        RAM16_SET(0x0398, 0x8000);
        RAM16_SET(ACTOR_STATUS + x1, 0x8000);
        RAM16_SET(0x03B0, 0);
        a_hi3 = 0x80;
    }
    uint16_t value18 = RAM16(ACTOR_STATUS + x1);
    RAM16_SET(0xE1EE + x1, value18 & 0xFFFC);
    r->a = value18 & 0xFFFC;
    r->x = x1;
    r->y = y1;
    r->z = (value18 & 0xFFFC) == 0;
    r->n = value18 & 0xFFFC & 0x8000;
    r->mf = 0;
    r->xf = x_flag;
    r->db = 0x7E;
    r->dp = 0x0300;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE38D, 0xC8E487); GUARD_JSR(c, sp_call, 0xE38D); } /* filter_low_actor_statuses */
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE390, 0xC8E4D7); GUARD_JSR(c, sp_call, 0xE390); } /* filter_transformation_actor_statuses */
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE393, 0xC8E50F); GUARD_JSR(c, sp_call, 0xE393); } /* filter_damage_over_time_actor_statuses */
    bool x_ret5 = r->xf;
    uint16_t value19 = RAM16(0x0398);
    uint16_t value20 = RAM16(ACTOR_STATUS + x1);
    RAM16_SET(0x0398, value19 & value20);
    uint8_t a_hi4;
    if ((value19 & value20 & 0x4560) == 0) {
        a_hi4 = (value19 & value20) >> 8;
    } else {
        uint16_t value21 = RAM16(ACTOR_KIND_FLAGS + x1);
        RAM16_SET(ACTOR_KIND_FLAGS + x1, value21 | 2);
        a_hi4 = (value21 | 2) >> 8;
    }
    RAM16_SET(BATTLE_TEMP_A4, RAM16(ACTOR_MAGIC_DEFENSE + x1) >> 1);
    uint16_t value23 = RAM16(0x0396);
    uint16_t battle_temp_a42 = RAM16(BATTLE_TEMP_A4);
    uint8_t a1;
    if (!((uint16_t)((value23 >> 2) - battle_temp_a42) & 0x8000)) {
        a1 = (uint8_t)((value23 >> 2) - battle_temp_a42);
    } else {
        a1 = 0;
    }
    uint8_t a2;
    if (a1 >= 0x14) {
        a2 = a1;
    } else {
        a2 = 0x14;
    }
    RAM8(0x039C) = a2;
    uint8_t value24 = RAM8(0x0399);
    uint8_t a3;
    if ((value24 & 0x60) == 0) {
        a3 = value24;
    } else {
        RAM8(ACTOR_STATUS_DAMAGE_TIMER + x1) = RAM8(0x039C);
        a3 = RAM8(0x0399);
    }
    if ((a3 & 0x1C) != 0) {
        RAM8(ACTOR_TIMER_1B5 + x1) = RAM8(0x039C);
    }
    uint16_t value28 = RAM16(0x0398);
    if ((value28 & 0x0180) != 0) {
        RAM8(ACTOR_TIMER_1B3 + x1) = RAM8(0x039C);
    }
    if ((RAM8(0x0398) & 0x7C) != 0) {
        RAM8(ACTOR_LOW_STATUS_TIMER + x1) = RAM8(0x039C);
    }
    if (RAM8(0x03B0) == 0) {
        RAM8(0xE1E5 + x1) = 0xFF;
    }
    uint8_t battle_temp_ae = RAM8(BATTLE_TEMP_AE);
    bool x_flag2;
    uint8_t a_hi5;
    uint16_t y2;
    bool carry1;
    bool zero1;
    bool negative1;
    if (!(battle_temp_ae & 0x80)) {
        x_flag2 = x_ret5;
        a_hi5 = value28 >> 8;
        y2 = y1;
        carry1 = a1 >= 0x14;
        zero1 = battle_temp_ae == 0;
        negative1 = battle_temp_ae & 0x80;
    } else {
        r->a = (value28 >> 8 << 8) | battle_temp_ae;
        r->c = a1 >= 0x14;
        r->z = battle_temp_ae == 0;
        r->n = battle_temp_ae & 0x80;
        r->v = (((value23 >> 2) ^ battle_temp_a42) & ((value23 >> 2) ^ (uint16_t)((value23 >> 2) - battle_temp_a42)) & 0x8000) != 0;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xE405, 0xC03F28); GUARD_JSL(c, sp_call, 0xE405); } /* refresh_controller_status_public_call */
        bool x_ret6 = r->xf;
        uint16_t a_all5 = r->a;
        uint16_t y_ret2 = r->y;
        bool carry_ret3 = r->c;
        bool zero_ret5 = r->z;
        bool negative_ret5 = r->n;
        x_flag2 = x_ret6;
        a_hi5 = a_all5 >> 8;
        y2 = y_ret2;
        carry1 = carry_ret3;
        zero1 = zero_ret5;
        negative1 = negative_ret5;
    }
    r->a = (a_hi5 << 8) | a;
    r->y = y2;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = (((value23 >> 2) ^ battle_temp_a42) & ((value23 >> 2) ^ (uint16_t)((value23 >> 2) - battle_temp_a42)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = x_flag2;
    { const uint16_t sp_call = r->sp; JSL(c, 0xE409, 0xC04530); GUARD_JSL(c, sp_call, 0xE409); } /* rebuild_actor_attributes_native */
    uint8_t db_ret = r->db;
    uint16_t a_all6 = r->a;
    uint16_t x_ret8 = r->x;
    BUS8_SET(c, (db_ret << 0x10) + 0xE1B9 + x_ret8, 5);
    r->a = (a_all6 >> 8 << 8) | 5;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE413, 0xC8E52F); GUARD_JSR(c, sp_call, 0xE413); } /* select_actor_status_appearance */
    { const uint16_t sp_call = r->sp; JSR(c, 0xE416, 0xC8E5FF); GUARD_JSR(c, sp_call, 0xE416); } /* select_actor_status_attack_row */
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret11 = r->xf;
    uint16_t a_all8 = r->a;
    uint16_t x_ret12 = r->x;
    uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x80));
    BUS8_SET(c, (uint16_t)(dp_ret3 + 0x80), value33 | 0x40);
    uint8_t value34 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE000);
    if (value34 == 0) {
        uint8_t value35 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE200);
        if (value35 == 0) {
            uint8_t value36 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE400);
            if (value36 == 0) {
                SET_A8(r, value36);
                r->z = value36 == 0;
                r->n = value36 & 0x80;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTL(c);
            }
            if (x_ret11) {
                uint8_t value37 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE582);
                if (value37 != 0) {
                    r->a = (a_all8 >> 8 << 8) | value36;
                    r->x = (uint8_t)x_ret12;
                    r->y = value37;
                    r->z = value37 == 0;
                    r->n = value37 & 0x80;
                    r->xf = 1;
                    { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
                    r->mf = 1;
                    r->xf = 1;
                    RETURN_RTL(c);
                }
                SET_A8(r, value36);
                r->x = (uint8_t)x_ret12;
                r->y = value37;
                r->z = value37 == 0;
                r->n = value37 & 0x80;
                r->xf = 1;
                RETURN_RTL(c);
            } else {
                uint16_t value38 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xE582);
                if (value38 != 0) {
                    r->a = (a_all8 >> 8 << 8) | value36;
                    r->y = value38;
                    r->z = value38 == 0;
                    r->n = value38 & 0x8000;
                    r->xf = 0;
                    { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
                    r->mf = 1;
                    r->xf = 0;
                    RETURN_RTL(c);
                }
                SET_A8(r, value36);
                r->y = value38;
                r->z = value38 == 0;
                r->n = value38 & 0x8000;
                r->xf = 0;
                RETURN_RTL(c);
            }
        }
        if (x_ret11) {
            uint8_t value39 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE382);
            if (value39 != 0) {
                r->a = (a_all8 >> 8 << 8) | value35;
                r->x = (uint8_t)x_ret12;
                r->y = value39;
                r->z = value39 == 0;
                r->n = value39 & 0x80;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
                r->mf = 1;
                r->xf = 1;
                RETURN_RTL(c);
            }
            uint8_t value40 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE400);
            if (value40 == 0) {
                SET_A8(r, value40);
                r->x = (uint8_t)x_ret12;
                r->y = value39;
                r->z = value40 == 0;
                r->n = value40 & 0x80;
                r->xf = 1;
                RETURN_RTL(c);
            }
            uint8_t value41 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE582);
            if (value41 != 0) {
                r->a = (a_all8 >> 8 << 8) | value40;
                r->x = (uint8_t)x_ret12;
                r->y = value41;
                r->z = value41 == 0;
                r->n = value41 & 0x80;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
                r->mf = 1;
                r->xf = 1;
                RETURN_RTL(c);
            }
            SET_A8(r, value40);
            r->x = (uint8_t)x_ret12;
            r->y = value41;
            r->z = value41 == 0;
            r->n = value41 & 0x80;
            r->xf = 1;
            RETURN_RTL(c);
        } else {
            uint16_t value42 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xE382);
            if (value42 != 0) {
                r->a = (a_all8 >> 8 << 8) | value35;
                r->y = value42;
                r->z = value42 == 0;
                r->n = value42 & 0x8000;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            uint8_t value43 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE400);
            if (value43 == 0) {
                SET_A8(r, value43);
                r->y = value42;
                r->z = value43 == 0;
                r->n = value43 & 0x80;
                r->xf = 0;
                RETURN_RTL(c);
            }
            uint16_t value44 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xE582);
            if (value44 != 0) {
                r->a = (a_all8 >> 8 << 8) | value43;
                r->y = value44;
                r->z = value44 == 0;
                r->n = value44 & 0x8000;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            SET_A8(r, value43);
            r->y = value44;
            r->z = value44 == 0;
            r->n = value44 & 0x8000;
            r->xf = 0;
            RETURN_RTL(c);
        }
    }
    if (x_ret11) {
        uint8_t value45 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE182);
        if (value45 != 0) {
            r->a = (a_all8 >> 8 << 8) | value34;
            r->x = (uint8_t)x_ret12;
            r->y = value45;
            r->z = value45 == 0;
            r->n = value45 & 0x80;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
            r->mf = 1;
            r->xf = 1;
            RETURN_RTL(c);
        }
        uint8_t value46 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE200);
        if (value46 == 0) {
            uint8_t value47 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE400);
            if (value47 == 0) {
                SET_A8(r, value47);
                r->x = (uint8_t)x_ret12;
                r->y = value45;
                r->z = value47 == 0;
                r->n = value47 & 0x80;
                r->xf = 1;
                RETURN_RTL(c);
            }
            uint8_t value48 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE582);
            if (value48 != 0) {
                r->a = (a_all8 >> 8 << 8) | value47;
                r->x = (uint8_t)x_ret12;
                r->y = value48;
                r->z = value48 == 0;
                r->n = value48 & 0x80;
                r->xf = 1;
                { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
                r->mf = 1;
                r->xf = 1;
                RETURN_RTL(c);
            }
            SET_A8(r, value47);
            r->x = (uint8_t)x_ret12;
            r->y = value48;
            r->z = value48 == 0;
            r->n = value48 & 0x80;
            r->xf = 1;
            RETURN_RTL(c);
        }
        uint8_t value49 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE382);
        if (value49 != 0) {
            r->a = (a_all8 >> 8 << 8) | value46;
            r->x = (uint8_t)x_ret12;
            r->y = value49;
            r->z = value49 == 0;
            r->n = value49 & 0x80;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
            r->mf = 1;
            r->xf = 1;
            RETURN_RTL(c);
        }
        uint8_t value50 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE400);
        if (value50 == 0) {
            SET_A8(r, value50);
            r->x = (uint8_t)x_ret12;
            r->y = value49;
            r->z = value50 == 0;
            r->n = value50 & 0x80;
            r->xf = 1;
            RETURN_RTL(c);
        }
        uint8_t value51 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE582);
        if (value51 != 0) {
            r->a = (a_all8 >> 8 << 8) | value50;
            r->x = (uint8_t)x_ret12;
            r->y = value51;
            r->z = value51 == 0;
            r->n = value51 & 0x80;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
            r->mf = 1;
            r->xf = 1;
            RETURN_RTL(c);
        }
        SET_A8(r, value50);
        r->x = (uint8_t)x_ret12;
        r->y = value51;
        r->z = value51 == 0;
        r->n = value51 & 0x80;
        r->xf = 1;
        RETURN_RTL(c);
    } else {
        uint16_t value52 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xE182);
        if (value52 != 0) {
            r->a = (a_all8 >> 8 << 8) | value34;
            r->y = value52;
            r->z = value52 == 0;
            r->n = value52 & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint8_t value53 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE200);
        if (value53 == 0) {
            uint8_t value54 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE400);
            if (value54 == 0) {
                SET_A8(r, value54);
                r->y = value52;
                r->z = value54 == 0;
                r->n = value54 & 0x80;
                r->xf = 0;
                RETURN_RTL(c);
            }
            uint16_t value55 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xE582);
            if (value55 != 0) {
                r->a = (a_all8 >> 8 << 8) | value54;
                r->y = value55;
                r->z = value55 == 0;
                r->n = value55 & 0x8000;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            SET_A8(r, value54);
            r->y = value55;
            r->z = value55 == 0;
            r->n = value55 & 0x8000;
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint16_t value56 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xE382);
        if (value56 != 0) {
            r->a = (a_all8 >> 8 << 8) | value53;
            r->y = value56;
            r->z = value56 == 0;
            r->n = value56 & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint8_t value57 = BUS8_RDP(c, (db_ret3 << 0x10) + 0xE400);
        if (value57 == 0) {
            SET_A8(r, value57);
            r->y = value56;
            r->z = value57 == 0;
            r->n = value57 & 0x80;
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint16_t value58 = BUS16_RDP(c, (db_ret3 << 0x10) + 0xE582);
        if (value58 != 0) {
            r->a = (a_all8 >> 8 << 8) | value57;
            r->y = value58;
            r->z = value58 == 0;
            r->n = value58 & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xE43F, 0xC05A87); GUARD_JSL(c, sp_call, 0xE43F); } /* queue_actor_status_messages */
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        SET_A8(r, value57);
        r->y = value58;
        r->z = value58 == 0;
        r->n = value58 & 0x8000;
        r->xf = 0;
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0xC8E301, SOM_RTL, "gen", apply_actor_status_and_timers, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 320, 135)
