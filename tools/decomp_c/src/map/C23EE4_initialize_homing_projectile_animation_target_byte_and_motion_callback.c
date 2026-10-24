#include "som_c.h"

/* C23EE4 initialize_homing_projectile_animation_target_byte_and_motion_callback   [class B, 104 bytes, 42 instructions]
 * Source: src/rom/initialize_homing_projectile_animation_target_byte_and_motion_callback.s
 * Documented in docs/boss-actor-controller-pool.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_homing_projectile_animation_target_byte_and_motion_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->a = 0x17;
    r->x = value;
    JSR(c, 0x3EEE, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(0x00B2 + value, 0);
    RAM16_SET(0x0000 + value, 1);
    uint16_t value2 = RAM16(0x00A9 + value);
    RAM8(0x000B + value) = RAM8(0x000B + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000));
    RAM16_SET(0x0090 + value, 0x3F4C);
    uint16_t value4 = RAM16(0x0287);
    RAM16_SET(0x00B2 + value4, (uint16_t)(RAM16(0x00B2 + value4) + 1));
    uint16_t value5 = RAM16(0x00B2 + value4);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool overflow1;
    if (value5 >= 3) {
        a_hi1 = value5 >> 8;
        x1 = value4;
        y1 = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000);
        carry1 = value5 >= 3;
        overflow1 = (((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    } else {
        RAM16_SET(0x00B2 + value4, 0);
        r->a = RAM16(0x00A9 + value4);
        r->y = (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3F27, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
        uint16_t a_all2 = r->a;
        uint16_t value7 = RAM16(0x0287);
        RAM16_SET(0x00AB + value7, a_all2);
        RAM16_SET(0x021A, 4);
        RAM16_SET(0x020D, 0xDC00);
        RAM16_SET(0x020C, 0xE048);
        r->a = 0xE048;
        r->x = value7;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3F3E, 0xC232BC); /* add_direction_table_acceleration_and_clamp_boss_velocity */
        uint16_t a_all3 = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        a_hi1 = a_all3 >> 8;
        x1 = value7;
        y1 = y_ret;
        carry1 = carry_ret2;
        overflow1 = overflow_ret2;
    }
    uint16_t value8 = RAM16(0x0032 + x1);
    RAM16_SET(0x0022 + x1, value8);
    r->a = value8;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3F47, 0xC23F64); /* test_parent_status_or_projectile_collision */
    bool carry_ret3 = r->c;
    if (carry_ret3) {
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23EE4, SOM_RTS, "gen", initialize_homing_projectile_animation_target_byte_and_motion_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 104, 42)
