#include "som_c.h"

/* C21906 set_animation_target_motion_triplet   [class B, 45 bytes, 25 instructions]
 * Source: src/rom/set_animation_target_motion_triplet.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void set_animation_target_motion_triplet(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x00A9 + RAM16(CURRENT_OBJECT_DP0 + dp));
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x0078 + dp) << 0x10) + RAM16(0x0076 + dp) + y, value2);
    RAM8(0x0006 + (uint16_t)((uint16_t)((((value & 0xFF) << 8) | 0) << 1) + 0xE000)) = value2;
    uint8_t value3;
    BUS8_OK(c, (RAM8(0x0078 + dp) << 0x10) + RAM16(0x0076 + dp) + (uint16_t)(y + 1), value3);
    RAM8(0x0007 + (uint16_t)((uint16_t)((((value & 0xFF) << 8) | 0) << 1) + 0xE000)) = value3;
    uint8_t value4;
    BUS8_OK(c, (RAM8(0x0078 + dp) << 0x10) + RAM16(0x0076 + dp) + (uint16_t)(y + 2), value4);
    uint8_t value5;
    BUS8_OK(c, (RAM8(0x0078 + dp) << 0x10) + RAM16(0x0076 + dp) + (uint16_t)(y + 2), value5);
    RAM8(0x000A + (uint16_t)((uint16_t)((((value & 0xFF) << 8) | 0) << 1) + 0xE000)) = (uint8_t)((uint8_t)(value4 << 2) + value5);
    uint16_t current_object_dp02 = RAM16(CURRENT_OBJECT_DP0 + dp);
    r->a = ((uint16_t)((uint16_t)((((value & 0xFF) << 8) | 0) << 1) + 0xE000) >> 8 << 8) | (uint8_t)((uint8_t)(value4 << 2) + value5);
    r->x = current_object_dp02;
    r->y = (uint16_t)(y + 3);
    r->c = (uint8_t)(value4 << 2) + value5 > 0xFF;
    r->z = current_object_dp02 == 0;
    r->n = current_object_dp02 & 0x8000;
    r->v = (((uint8_t)(value4 << 2) ^ (uint8_t)((uint8_t)(value4 << 2) + value5)) & (value5 ^ (uint8_t)((uint8_t)(value4 << 2) + value5)) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21906, SOM_RTS, "hand", set_animation_target_motion_triplet, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 45, 25)
