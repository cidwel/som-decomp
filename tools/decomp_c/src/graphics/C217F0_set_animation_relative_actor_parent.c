#include "som_c.h"

/* C217F0 set_animation_relative_actor_parent   [class A, 18 bytes, 12 instructions]
 * Source: src/rom/set_animation_relative_actor_parent.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void set_animation_relative_actor_parent(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t value;
    BUS8_OK(c, (RAM8(0x0078 + dp) << 0x10) + RAM16(0x0076 + dp) + y, value);
    uint8_t current_object_dp0 = RAM8(CURRENT_OBJECT_DP0 + dp);
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x0078 + dp) << 0x10) + RAM16(0x0076 + dp) + (uint16_t)(y + 2), value2);
    RAM8(0x00B0 + ((a_hi << 8) | (uint8_t)(value + current_object_dp0))) = value2;
    uint16_t current_object_dp02 = RAM16(CURRENT_OBJECT_DP0 + dp);
    SET_A8(r, value2);
    r->x = current_object_dp02;
    r->y = (uint16_t)(y + 4);
    r->c = value + current_object_dp0 > 0xFF;
    r->z = current_object_dp02 == 0;
    r->n = current_object_dp02 & 0x8000;
    r->v = ((value ^ (uint8_t)(value + current_object_dp0)) & (current_object_dp0 ^ (uint8_t)(value + current_object_dp0)) & 0x80) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC217F0, SOM_RTS, "hand", set_animation_relative_actor_parent, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 18, 12)
