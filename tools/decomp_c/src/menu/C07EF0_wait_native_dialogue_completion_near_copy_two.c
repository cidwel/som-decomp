#include "som_c.h"

/* C07EF0 wait_native_dialogue_completion_near_copy_two   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/wait_native_dialogue_completion_near_copy_two.s
 * Documented in docs/source-recovery-parallel-shop-wait-copies.md
 * Entry: M=8 bit X=16 bit DB=$00 D=any.  Callers read: ABXYCZNV.
 */
static void wait_native_dialogue_completion_near_copy_two(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x7EF3, 0xD0D5C1); GUARD_JSL(c, sp_call, 0x7EF3); } /* external */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07EF0, SOM_RTS, "hand", wait_native_dialogue_completion_near_copy_two, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)
