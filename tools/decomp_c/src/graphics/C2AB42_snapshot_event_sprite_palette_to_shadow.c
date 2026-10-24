#include "som_c.h"

/* C2AB42 snapshot_event_sprite_palette_to_shadow   [class A, 18 bytes, 10 instructions]
 * Source: src/rom/snapshot_event_sprite_palette_to_shadow.s
 * Documented in docs/event-menu-actor-selection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void snapshot_event_sprite_palette_to_shadow(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = 0xFE;
    for (;;) {
        uint16_t value = RAM16(0x0700 + y1);
        RAM16_SET(0xC600 + y1, value);
        a_hi1 = value >> 8;
        y1 = (uint16_t)(y1 - 2);
        if (!(!(y1 & 0x8000))) break;
    }
    r->x = x;
    r->mf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2AB42, SOM_RTL, "gen", snapshot_event_sprite_palette_to_shadow, 0, L_X, 2, 1, 0, 18, 10)
