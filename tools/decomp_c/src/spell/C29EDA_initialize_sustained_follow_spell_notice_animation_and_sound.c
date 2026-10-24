#include "som_c.h"

/* C29EDA initialize_sustained_follow_spell_notice_animation_and_sound   [class B, 51 bytes, 20 instructions]
 * Source: src/rom/initialize_sustained_follow_spell_notice_animation_and_sound.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_sustained_follow_spell_notice_animation_and_sound(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B4 + value);
    r->a = value2;
    r->x = value;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0x9EE2, 0xC00027); GUARD_JSL(c, sp_call, 0x9EE2); } /* boss_attack_notice_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        if (m_ret) {
            uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xB4 + value3);
            uint8_t value5 = BUS8(c, 0xDCE6FF + (uint8_t)((a_all >> 8 << 8) | (uint8_t)(value4 << 1)));
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->a = (a_all >> 8 << 8) | value5;
            r->x = value6;
            r->y = (uint8_t)y_ret;
            r->c = value4 & 0x80;
            r->z = value6 == 0;
            r->n = value6 & 0x80;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9EF2, 0xC21394); GUARD_JSR(c, sp_call, 0x9EF2); } /* select_boss_animation_and_reset_frame_cursor */
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9EF5, 0xC29A2B); GUARD_JSR(c, sp_call, 0x9EF5); } /* request_status_spell_start_sound */
            if (r->mf != 0) { c->fail = 3; return; }
            uint16_t x_ret4 = r->x;
            uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x94 + x_ret4);
            BUS16_RMW_SET(c, (db_ret << 0x10) + 0x94 + x_ret4, (uint16_t)(value7 + 1));
            BUS16_SET(c, (db_ret << 0x10) + 0x22 + x_ret4, 0x07FF);
            uint16_t value8 = BUS16_RDP(c, (db_ret << 0x10) + 0x98 + x_ret4);
            BUS16_SET(c, (db_ret << 0x10) + 0x98 + x_ret4, value8 & 0x7FFF);
            r->a = value8 & 0x7FFF;
            r->z = (value8 & 0x7FFF) == 0;
            r->n = value8 & 0x7FFF & 0x8000;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9F0A, 0xC298DA); GUARD_JSR(c, sp_call, 0x9F0A); } /* activate_spell_child_and_clear_fractional_height */
            r->c = 0;
            r->mf = 0;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value9 = BUS16_RDP(c, (db_ret << 0x10) + 0xB4 + value3);
            uint16_t value10 = BUS16(c, 0xDCE6FF + (uint8_t)(value9 << 1));
            uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->a = value10;
            r->x = value11;
            r->y = (uint8_t)y_ret;
            r->c = value9 & 0x8000;
            r->z = value11 == 0;
            r->n = value11 & 0x80;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9EF2, 0xC21394); GUARD_JSR(c, sp_call, 0x9EF2); } /* select_boss_animation_and_reset_frame_cursor */
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9EF5, 0xC29A2B); GUARD_JSR(c, sp_call, 0x9EF5); } /* request_status_spell_start_sound */
            if (r->mf != 0) { c->fail = 3; return; }
            uint16_t x_ret7 = r->x;
            uint16_t value12 = BUS16_RDP(c, (db_ret << 0x10) + 0x94 + x_ret7);
            BUS16_RMW_SET(c, (db_ret << 0x10) + 0x94 + x_ret7, (uint16_t)(value12 + 1));
            BUS16_SET(c, (db_ret << 0x10) + 0x22 + x_ret7, 0x07FF);
            uint16_t value13 = BUS16_RDP(c, (db_ret << 0x10) + 0x98 + x_ret7);
            BUS16_SET(c, (db_ret << 0x10) + 0x98 + x_ret7, value13 & 0x7FFF);
            r->a = value13 & 0x7FFF;
            r->z = (value13 & 0x7FFF) == 0;
            r->n = value13 & 0x7FFF & 0x8000;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9F0A, 0xC298DA); GUARD_JSR(c, sp_call, 0x9F0A); } /* activate_spell_child_and_clear_fractional_height */
            r->c = 0;
            r->mf = 0;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    } else {
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        if (m_ret) {
            uint8_t value15 = BUS8_RDP(c, (db_ret << 0x10) + 0xB4 + value14);
            uint8_t value16 = BUS8(c, 0xDCE6FF + ((a_all >> 8 << 8) | (uint8_t)(value15 << 1)));
            uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->a = (a_all >> 8 << 8) | value16;
            r->x = value17;
            r->c = value15 & 0x80;
            r->z = value17 == 0;
            r->n = value17 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9EF2, 0xC21394); GUARD_JSR(c, sp_call, 0x9EF2); } /* select_boss_animation_and_reset_frame_cursor */
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9EF5, 0xC29A2B); GUARD_JSR(c, sp_call, 0x9EF5); } /* request_status_spell_start_sound */
            if (r->mf != 0) { c->fail = 3; return; }
            uint16_t x_ret10 = r->x;
            uint16_t value18 = BUS16_RDP(c, (db_ret << 0x10) + 0x94 + x_ret10);
            BUS16_RMW_SET(c, (db_ret << 0x10) + 0x94 + x_ret10, (uint16_t)(value18 + 1));
            BUS16_SET(c, (db_ret << 0x10) + 0x22 + x_ret10, 0x07FF);
            uint16_t value19 = BUS16_RDP(c, (db_ret << 0x10) + 0x98 + x_ret10);
            BUS16_SET(c, (db_ret << 0x10) + 0x98 + x_ret10, value19 & 0x7FFF);
            r->a = value19 & 0x7FFF;
            r->z = (value19 & 0x7FFF) == 0;
            r->n = value19 & 0x7FFF & 0x8000;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9F0A, 0xC298DA); GUARD_JSR(c, sp_call, 0x9F0A); } /* activate_spell_child_and_clear_fractional_height */
            r->c = 0;
            r->mf = 0;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value20 = BUS16_RDP(c, (db_ret << 0x10) + 0xB4 + value14);
            uint16_t value21 = BUS16(c, 0xDCE6FF + (uint16_t)(value20 << 1));
            uint16_t value22 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->a = value21;
            r->x = value22;
            r->c = value20 & 0x8000;
            r->z = value22 == 0;
            r->n = value22 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9EF2, 0xC21394); GUARD_JSR(c, sp_call, 0x9EF2); } /* select_boss_animation_and_reset_frame_cursor */
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9EF5, 0xC29A2B); GUARD_JSR(c, sp_call, 0x9EF5); } /* request_status_spell_start_sound */
            if (r->mf != 0) { c->fail = 3; return; }
            uint16_t x_ret13 = r->x;
            uint16_t value23 = BUS16_RDP(c, (db_ret << 0x10) + 0x94 + x_ret13);
            BUS16_RMW_SET(c, (db_ret << 0x10) + 0x94 + x_ret13, (uint16_t)(value23 + 1));
            BUS16_SET(c, (db_ret << 0x10) + 0x22 + x_ret13, 0x07FF);
            uint16_t value24 = BUS16_RDP(c, (db_ret << 0x10) + 0x98 + x_ret13);
            BUS16_SET(c, (db_ret << 0x10) + 0x98 + x_ret13, value24 & 0x7FFF);
            r->a = value24 & 0x7FFF;
            r->z = (value24 & 0x7FFF) == 0;
            r->n = value24 & 0x7FFF & 0x8000;
            { const uint16_t sp_call = r->sp; JSR(c, 0x9F0A, 0xC298DA); GUARD_JSR(c, sp_call, 0x9F0A); } /* activate_spell_child_and_clear_fractional_height */
            r->c = 0;
            r->mf = 0;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC29EDA, SOM_RTS, "gen", initialize_sustained_follow_spell_notice_animation_and_sound, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 51, 20)
