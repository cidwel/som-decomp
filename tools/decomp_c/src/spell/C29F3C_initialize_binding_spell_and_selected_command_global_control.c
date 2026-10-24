#include "som_c.h"

/* C29F3C initialize_binding_spell_and_selected_command_global_control   [class B, 73 bytes, 27 instructions]
 * Source: src/rom/initialize_binding_spell_and_selected_command_global_control.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_binding_spell_and_selected_command_global_control(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = RAM16(0x00B4 + value);
    r->a = value2;
    r->x = value;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0x9F44, 0xC00027); GUARD_JSL(c, sp_call, 0x9F44); } /* boss_attack_notice_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->a = 0x0126;
        r->x = value3;
        r->y = (uint8_t)y_ret;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9F4C, 0xC21394); GUARD_JSR(c, sp_call, 0x9F4C); } /* select_boss_animation_and_reset_frame_cursor */
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x94 + value3);
        BUS16_RMW_SET(c, (db_ret << 0x10) + 0x94 + value3, (uint16_t)(value4 + 1));
        BUS16_SET(c, (db_ret << 0x10) + 0x66 + value3, 0x0200);
        BUS16_SET(c, (db_ret << 0x10) + 0x22 + value3, 0x07FF);
        uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0x98 + value3);
        BUS16_SET(c, (db_ret << 0x10) + 0x98 + value3, value5 & 0x7FFF);
        BUS16_SET(c, (db_ret << 0x10) + 0x70 + value3, 1);
        BUS16_SET(c, (db_ret << 0x10) + value3, 1);
        BUS8_SET(c, (db_ret << 0x10) + 0x0B + value3, 1);
        r->a = 1;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9F7C, 0xC29AD1); GUARD_JSR(c, sp_call, 0x9F7C); } /* request_follow_spell_target_sound */
        if (r->mf != 0) { c->fail = 3; return; }
        r->a = 0x8B00;
        r->z = 0;
        r->n = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9F82, 0xC23963); GUARD_JSR(c, sp_call, 0x9F82); } /* boss_external_actor_command_if_selected */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        r->a = 0x0126;
        r->x = value6;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9F4C, 0xC21394); GUARD_JSR(c, sp_call, 0x9F4C); } /* select_boss_animation_and_reset_frame_cursor */
        uint16_t value7 = BUS16_RDP(c, (db_ret << 0x10) + 0x94 + value6);
        BUS16_RMW_SET(c, (db_ret << 0x10) + 0x94 + value6, (uint16_t)(value7 + 1));
        BUS16_SET(c, (db_ret << 0x10) + 0x66 + value6, 0x0200);
        BUS16_SET(c, (db_ret << 0x10) + 0x22 + value6, 0x07FF);
        uint16_t value8 = BUS16_RDP(c, (db_ret << 0x10) + 0x98 + value6);
        BUS16_SET(c, (db_ret << 0x10) + 0x98 + value6, value8 & 0x7FFF);
        BUS16_SET(c, (db_ret << 0x10) + 0x70 + value6, 1);
        BUS16_SET(c, (db_ret << 0x10) + value6, 1);
        BUS8_SET(c, (db_ret << 0x10) + 0x0B + value6, 1);
        r->a = 1;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9F7C, 0xC29AD1); GUARD_JSR(c, sp_call, 0x9F7C); } /* request_follow_spell_target_sound */
        if (r->mf != 0) { c->fail = 3; return; }
        r->a = 0x8B00;
        r->z = 0;
        r->n = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9F82, 0xC23963); GUARD_JSR(c, sp_call, 0x9F82); } /* boss_external_actor_command_if_selected */
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC29F3C, SOM_RTS, "gen", initialize_binding_spell_and_selected_command_global_control, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 73, 27)
