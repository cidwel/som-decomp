#include "som_c.h"

/* C244A2 move_integer_boss_axes_using_native_zero_parameter   [class A, 6 bytes, 3 instructions]
 * Source: src/rom/move_integer_boss_axes_using_native_zero_parameter.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void move_integer_boss_axes_using_native_zero_parameter(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x02C5);
    r->a = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x44A6, 0xC20A47); GUARD_JSR(c, sp_call, 0x44A6); } /* move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC244A2, SOM_RTS, "gen", move_integer_boss_axes_using_native_zero_parameter, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 6, 3)
