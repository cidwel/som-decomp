#include "som_c.h"

/* C00092 run_native_dialogue_public_jump   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/run_native_dialogue_public_jump.s
 * Documented in docs/event-dialogue-coordinator.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void run_native_dialogue_public_jump(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC00113, SOM_RTL); /* run_native_dialogue_with_normal_window_geometry */
}
SOM_REGISTER(0xC00092, SOM_RTL, "gen", run_native_dialogue_public_jump, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 3, 1)
