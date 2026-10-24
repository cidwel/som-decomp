#include "som_c.h"

/* C1EA59 event_yield_until_all_actors_idle   [class A, 9 bytes, 5 instructions]
 * Source: src/rom/event_yield_until_all_actors_idle.s
 * Documented in docs/event-vm-control.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_yield_until_all_actors_idle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x00D0) = 0x85;
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->a = (a_hi << 8) | 0x85;
    r->z = RAM16(0x00D1) == 0;
    r->n = RAM16(0x00D1) & 0x8000;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EA59, SOM_RTS, "gen", event_yield_until_all_actors_idle, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 9, 5)
