#include "som_c.h"

/* C1E9E7 event_noop_advance_script   [class A, 5 bytes, 3 instructions]
 * Source: src/rom/event_noop_advance_script.s
 * Documented in docs/event-vm-control.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_noop_advance_script(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->z = RAM16(0x00D1) == 0;
    r->n = RAM16(0x00D1) & 0x8000;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E9E7, SOM_RTS, "gen", event_noop_advance_script, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 5, 3)
