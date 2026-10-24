#include "som_c.h"

/* C26D7D initialize_target_tracking_boss_child   [class B, 106 bytes, 42 instructions]
 * Source: src/rom/initialize_target_tracking_boss_child.s
 * Documented in docs/boss-native-child-definitions.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void initialize_target_tracking_boss_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
    r->a = 0xE5;
    r->x = battle_defence_work;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6D87, 0xC21394); GUARD_JSR(c, sp_call, 0x6D87); } /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x00B2 + battle_defence_work, 0);
    RAM16_SET(0x0066 + battle_defence_work, 0);
    RAM16_SET(0x0000 + battle_defence_work, 1);
    uint16_t value = RAM16(0x00A9 + battle_defence_work);
    RAM8(0x000B + battle_defence_work) = RAM8(0x000B + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    RAM16_SET(0x0090 + battle_defence_work, 0x3F4C);
    uint16_t battle_defence_work2 = RAM16(BATTLE_DEFENCE_WORK);
    RAM16_SET(0x00B2 + battle_defence_work2, (uint16_t)(RAM16(0x00B2 + battle_defence_work2) + 1));
    uint16_t value3 = RAM16(0x00B2 + battle_defence_work2);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if (value3 >= 3) {
        a_hi1 = value3 >> 8;
        x1 = battle_defence_work2;
        y1 = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
        carry1 = value3 >= 3;
        overflow1 = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    } else {
        RAM16_SET(0x00B2 + battle_defence_work2, 0);
        r->a = RAM16(0x00A9 + battle_defence_work2);
        r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6DC3, 0xC20941); GUARD_JSR(c, sp_call, 0x6DC3); } /* derive_eight_way_direction_to_low_byte_target */
        uint16_t a_all2 = r->a;
        uint16_t battle_defence_work3 = RAM16(BATTLE_DEFENCE_WORK);
        RAM16_SET(0x00AB + battle_defence_work3, a_all2);
        RAM16_SET(0x031A, 2);
        RAM16_SET(0x030D, 0xDC00);
        RAM16_SET(0x030C, 0xE440);
        r->a = 0xE440;
        r->x = battle_defence_work3;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x6DDA, 0xC232BC); GUARD_JSR(c, sp_call, 0x6DDA); } /* add_direction_table_acceleration_and_clamp_boss_velocity */
        uint16_t a_all3 = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        a_hi1 = a_all3 >> 8;
        x1 = battle_defence_work3;
        y1 = y_ret;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
    }
    uint16_t value5 = RAM16(0x0032 + x1);
    RAM16_SET(0x0022 + x1, value5);
    r->a = value5;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6DE3, 0xC23F64); GUARD_JSR(c, sp_call, 0x6DE3); } /* test_parent_status_or_projectile_collision */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26D7D, SOM_RTS, "gen", initialize_target_tracking_boss_child, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 106, 42)
