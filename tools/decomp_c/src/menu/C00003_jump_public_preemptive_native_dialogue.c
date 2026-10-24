#include "som_c.h"

/* C00003 jump_public_preemptive_native_dialogue   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_public_preemptive_native_dialogue.s
 * Documented in docs/event-party-message-update.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: XYV.
 */
static void jump_public_preemptive_native_dialogue(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC00083, SOM_RTL); /* jump_internal_preemptive_native_dialogue */
}
SOM_REGISTER(0xC00003, SOM_RTL, "gen", jump_public_preemptive_native_dialogue, 0, L_X | L_Y | L_V, 1, 1, 0, 3, 1)
