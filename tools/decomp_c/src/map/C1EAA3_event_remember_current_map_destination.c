#include "som_c.h"

/* C1EAA3 event_remember_current_map_destination   [class C, 22 bytes, 10 instructions]
 * Source: src/rom/event_remember_current_map_destination.s
 * Documented in docs/event-vm-map-transition-commands.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_remember_current_map_destination(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x010E);
    RAM16_SET(0x0108, value);
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->a = value;
    r->z = RAM16(0x00D1) == 0;
    r->n = RAM16(0x00D1) & 0x8000;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EAA3, SOM_RTS, "gen", event_remember_current_map_destination, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 77, 10)
