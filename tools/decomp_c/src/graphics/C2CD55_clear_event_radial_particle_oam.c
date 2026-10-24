#include "som_c.h"

/* C2CD55 clear_event_radial_particle_oam   [class A, 18 bytes, 10 instructions]
 * Source: src/rom/clear_event_radial_particle_oam.s
 * Documented in docs/event-menu-effect-preparation.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void clear_event_radial_particle_oam(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t x1 = 0x4C;
    for (;;) {
        RAM16_SET(0x0900 + x1, 0xE0FF);
        x1 = (uint16_t)(x1 - 4);
        if (!(!(x1 & 0x8000))) break;
    }
    r->a = 0xE0FF;
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2CD55, SOM_RTS, "gen", clear_event_radial_particle_oam, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 18, 10)
