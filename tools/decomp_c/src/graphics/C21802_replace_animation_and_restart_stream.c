#include "som_c.h"

/* C21802 replace_animation_and_restart_stream   [class A, 24 bytes, 11 instructions]
 * Source: src/rom/replace_animation_and_restart_stream.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void replace_animation_and_restart_stream(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint16_t current_object_dp0 = RAM16(CURRENT_OBJECT_DP0 + dp);
    uint8_t value;
    BUS8_OK(c, (RAM8(0x0078 + dp) << 0x10) + RAM16(0x0076 + dp) + y, value);
    RAM8(0x009A + current_object_dp0) = value;
    RAM8(0x009C + current_object_dp0) = 0;
    uint8_t value2;
    BUS8_OK(c, 0xDBF9A8 + ((a_hi << 8) | (uint8_t)(value << 1)), value2);
    RAM8(0x0076 + dp) = value2;
    uint16_t current_object_dp02 = RAM16(CURRENT_OBJECT_DP0 + dp);
    SET_A8(r, value2);
    r->x = current_object_dp02;
    r->y = 0;
    r->c = value & 0x80;
    r->z = current_object_dp02 == 0;
    r->n = current_object_dp02 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21802, SOM_RTS, "hand", replace_animation_and_restart_stream, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 24, 11)
