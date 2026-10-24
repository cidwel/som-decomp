#include "som_c.h"

/* C2C806 snapshot_palette_for_event_color_transition   [class A, 26 bytes, 12 instructions]
 * Source: src/rom/snapshot_palette_for_event_color_transition.s
 * Documented in docs/event-vm-palette-transition.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: X.
 */
static void snapshot_palette_for_event_color_transition(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0x01FE;
    for (;;) {
        uint16_t value = RAM16(0x0600 + x1);
        RAM16_SET(0xBE00 + x1, value);
        a_hi1 = value >> 8;
        x1 = (uint16_t)(x1 - 2);
        if (!(!(x1 & 0x8000))) break;
    }
    RAM16_SET(0x0620, RAM16(0x0600));
    r->x = (uint8_t)x1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2C806, SOM_RTL, "gen", snapshot_palette_for_event_color_transition, 0, L_X, 1, 1, 1, 26, 12)
