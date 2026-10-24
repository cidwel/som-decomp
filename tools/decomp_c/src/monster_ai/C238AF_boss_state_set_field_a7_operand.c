#include "som_c.h"

/* C238AF boss_state_set_field_a7_operand   [class A, 10 bytes, 6 instructions]
 * Source: src/rom/boss_state_set_field_a7_operand.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void boss_state_set_field_a7_operand(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    uint16_t current_object_dp0 = RAM16(CURRENT_OBJECT_DP0 + dp);
    uint8_t value;
    BUS8_PTR(c, (RAM8(0x0032 + dp) << 0x10) + RAM16(0x0030 + dp) + y, RAM8(0x0032 + dp), value);
    RAM8(0x00A7 + current_object_dp0) = value;
    SET_A8(r, value);
    r->x = current_object_dp0;
    r->y = (uint16_t)(y + 2);
    r->z = (uint16_t)(y + 2) == 0;
    r->n = (uint16_t)(y + 2) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC238AF, SOM_RTS, "hand", boss_state_set_field_a7_operand, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 10, 6)
