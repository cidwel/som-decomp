#include "som_c.h"

/* C265D9 return_native_clear_carry_without_other_effect   [class A, 2 bytes, 2 instructions]
 * Source: src/rom/return_native_clear_carry_without_other_effect.s
 * Documented in docs/boss-unused-native-leaves.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void return_native_clear_carry_without_other_effect(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC265D9, SOM_RTS, "gen", return_native_clear_carry_without_other_effect, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 2, 2)
