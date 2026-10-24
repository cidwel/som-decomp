#include "som_c.h"

/* C1000C wait_for_controller_two_signal_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/wait_for_controller_two_signal_long_wrapper.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void wait_for_controller_two_signal_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x000E, 0xC10040); GUARD_JSR(c, sp_call, 0x000E); } /* wait_for_controller_two_signal_and_unpack_saved_registers */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1000C, SOM_RTL, "gen", wait_for_controller_two_signal_long_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 4, 2)
