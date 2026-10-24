#include "som_c.h"

/* 7E9364 restore_stopped_warm_parent_task   [class A, 15 bytes, 12 instructions]
 * Source: src/boot/restore_stopped_warm_parent_task.s
 * Documented in docs/boot-native-warm-scheduler-cycle.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void restore_stopped_warm_parent_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    SET_A8(r, 0x7F);
    r->z = 0;
    r->n = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0x7E9364, SOM_RTL, "gen", restore_stopped_warm_parent_task, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 15, 12)
