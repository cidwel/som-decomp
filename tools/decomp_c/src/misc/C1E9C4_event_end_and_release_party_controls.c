#include "som_c.h"

/* C1E9C4 event_end_and_release_party_controls   [class C, 200 bytes, 90 instructions]
 * Source: src/rom/event_end_and_release_party_controls.s
 * Documented in docs/event-vm-control.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_end_and_release_party_controls(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x00F1) = 0;
    RAM8(0x00D0) = 0;
    RAM8(0x004E) = 0;
    RAM8(0x003A) = 0;
    RAM8(0x003B) = 0;
    RAM8(0x00CC) = 0;
    RAM8(0x00CD) = 0;
    RAM8(0x00CE) = 0;
    RAM8(0x00D9) &= 0x7F;
    RAM8(0x00DA) &= 0x7F;
    uint8_t value3 = RAM8(0x00DB);
    RAM8(0x00DB) = value3 & 0x7F;
    SET_A8(r, value3 & 0x7F);
    r->z = (value3 & 0x7F) == 0;
    r->n = value3 & 0x7F & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E9C4, SOM_RTS, "gen", event_end_and_release_party_controls, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 558, 90)
