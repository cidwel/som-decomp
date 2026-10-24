#include "som_c.h"

/* C08B05 long_call_prepare_destination_fade   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/long_call_prepare_destination_fade.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void long_call_prepare_destination_fade(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0x8B07, 0xC08B09); GUARD_JSR(c, sp_call, 0x8B07); } /* prepare_destination_fade */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC08B05, SOM_RTL, "gen", long_call_prepare_destination_fade, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 4, 2)
