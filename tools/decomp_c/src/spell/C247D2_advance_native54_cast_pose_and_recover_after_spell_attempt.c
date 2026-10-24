#include "som_c.h"

/* C247D2 advance_native54_cast_pose_and_recover_after_spell_attempt   [class B, 64 bytes, 28 instructions]
 * Source: src/rom/advance_native54_cast_pose_and_recover_after_spell_attempt.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_native54_cast_pose_and_recover_after_spell_attempt(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x47D6, 0xC24965); GUARD_JSR(c, sp_call, 0x47D6); } /* test_native54_negative_status_or_begin_hurt_shift */
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    if (carry_ret) {
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value2 = RAM16(OBJECT_AGE + x_ret);
    if (value2 < 0x18) {
        r->a = value2;
        r->c = value2 >= 0x18;
        r->z = value2 == 0x18;
        r->n = (uint16_t)(value2 - 0x18) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x480F, 0xC24865); GUARD_JSR(c, sp_call, 0x480F); } /* publish_native54_cast_pose_sine_oscillator_and_auxiliary_control */
        r->c = 0;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->a = value2;
    r->c = value2 >= 0x18;
    r->z = value2 == 0x18;
    r->n = (uint16_t)(value2 - 0x18) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x47E3, 0xC24812); GUARD_JSR(c, sp_call, 0x47E3); } /* choose_native54_hp_target_conditioned_spell_and_execute_success */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret4 = r->xf;
    if (x_ret4) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
        BUS16_SET(c, (db_ret << 0x10) + 0x94 + value3, 0x0C);
        BUS16_SET(c, (db_ret << 0x10) + 0x96 + value3, 0);
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x89));
        uint8_t value5 = BUS8_RDP(c, (db_ret << 0x10) + 0x7A + value3);
        BUS8_SET(c, (db_ret << 0x10) + 0xF811 + (uint8_t)(value4 - 0xF800), value5);
        uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0x7B + value3);
        BUS8_SET(c, (db_ret << 0x10) + 0xF80D + (uint8_t)(value4 - 0xF800), value6);
        BUS8_SET(c, (db_ret << 0x10) + 0xF813 + (uint8_t)(value4 - 0xF800), 0x40);
        r->a = ((uint16_t)(value4 - 0xF800) >> 8 << 8) | 0x40;
        r->x = value3;
        r->y = (uint8_t)(value4 - 0xF800);
        r->c = 0;
        r->z = 0;
        r->n = 0;
        r->v = ((value4 ^ 0xF800) & (value4 ^ (uint16_t)(value4 - 0xF800)) & 0x8000) != 0;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
        BUS16_SET(c, (db_ret << 0x10) + 0x94 + value7, 0x0C);
        BUS16_SET(c, (db_ret << 0x10) + 0x96 + value7, 0);
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x89));
        uint8_t value9 = BUS8_RDP(c, (db_ret << 0x10) + 0x7A + value7);
        BUS8_SET(c, (db_ret << 0x10) + 0xF811 + (uint16_t)(value8 - 0xF800), value9);
        uint8_t value10 = BUS8_RDP(c, (db_ret << 0x10) + 0x7B + value7);
        BUS8_SET(c, (db_ret << 0x10) + 0xF80D + (uint16_t)(value8 - 0xF800), value10);
        BUS8_SET(c, (db_ret << 0x10) + 0xF813 + (uint16_t)(value8 - 0xF800), 0x40);
        r->a = ((uint16_t)(value8 - 0xF800) >> 8 << 8) | 0x40;
        r->x = value7;
        r->y = (uint16_t)(value8 - 0xF800);
        r->c = 0;
        r->z = 0;
        r->n = 0;
        r->v = ((value8 ^ 0xF800) & (value8 ^ (uint16_t)(value8 - 0xF800)) & 0x8000) != 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC247D2, SOM_RTS, "gen", advance_native54_cast_pose_and_recover_after_spell_attempt, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 64, 28)
