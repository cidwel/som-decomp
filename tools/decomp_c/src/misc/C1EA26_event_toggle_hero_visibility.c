#include "som_c.h"

/* C1EA26 event_toggle_hero_visibility   [class A, 29 bytes, 12 instructions]
 * Source: src/rom/event_toggle_hero_visibility.s
 * Documented in docs/event-vm-control.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void event_toggle_hero_visibility(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xE00E) ^= 0x80;
    RAM8(0xE20E) ^= 0x80;
    uint8_t value3 = RAM8(0xE40E);
    RAM8(0xE40E) = value3 ^ 0x80;
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    r->a = (a_hi << 8) | (value3 ^ 0x80);
    r->z = RAM16(0x00D1) == 0;
    r->n = RAM16(0x00D1) & 0x8000;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EA26, SOM_RTS, "gen", event_toggle_hero_visibility, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 29, 12)
