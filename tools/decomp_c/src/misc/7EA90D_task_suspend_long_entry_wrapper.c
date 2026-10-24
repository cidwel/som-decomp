#include "som_c.h"

/* 7EA90D task_suspend_long_entry_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/boot/source_recovery_parallel_boot_static_fragments_task_suspend_long_entry_wrapper.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void task_suspend_long_entry_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA90F, 0x7EA911); GUARD_JSR(c, sp_call, 0xA90F); } /* suspend_current_task */
    RETURN_RTL(c);
}
SOM_REGISTER(0x7EA90D, SOM_RTL, "hand", task_suspend_long_entry_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 4, 2)
