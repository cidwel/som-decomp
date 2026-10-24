#include "som_c.h"

/* C2AB30 restore_event_sprite_palette_from_shadow   [class A, 18 bytes, 10 instructions]
 * Source: src/rom/restore_event_sprite_palette_from_shadow.s
 * Documented in docs/event-menu-actor-selection.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void restore_event_sprite_palette_from_shadow(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = 0xFE;
    for (;;) {
        uint16_t value = RAM16(0xC600 + y1);
        RAM16_SET(0x0700 + y1, value);
        a_hi1 = value >> 8;
        y1 = (uint16_t)(y1 - 2);
        if (!(!(y1 & 0x8000))) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    r->mf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2AB30, SOM_RTL, "gen", restore_event_sprite_palette_from_shadow, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 18, 10)
