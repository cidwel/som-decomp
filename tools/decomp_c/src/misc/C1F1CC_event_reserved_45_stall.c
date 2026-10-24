#include "som_c.h"

/* C1F1CC event_reserved_45_stall   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/event_reserved_45_stall.s
 * Documented in docs/event-vm-composition.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void event_reserved_45_stall(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F1CC, SOM_RTS, "gen", event_reserved_45_stall, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 1, 1)
