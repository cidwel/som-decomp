#include "som_c.h"

/* C2C7DD exchange_native_scene_and_event_transition_palettes_when_active   [class B, 41 bytes, 24 instructions]
 * Source: src/rom/exchange_native_scene_and_event_transition_palettes_when_active.s
 * Documented in docs/event-menu-palette-exchange.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void exchange_native_scene_and_event_transition_palettes_when_active(SomCtx *c)
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
    if (RAM8(0x002A) != 0) {
        uint8_t a_hi1 = a_hi;
        uint16_t y1 = 0x01FE;
        for (;;) {
            uint16_t value2 = RAM16(0xBE00 + y1);
            RAM16_SET(0xBE00 + y1, RAM16(0x0600 + y1));
            RAM16_SET(0x0600 + y1, value2);
            a_hi1 = value2 >> 8;
            y1 = (uint16_t)(y1 - 2);
            if (!(!(y1 & 0x8000))) break;
        }
        r->a = (a_hi1 << 8) | a;
        r->x = x;
        r->y = y;
        r->c = carry;
        r->v = overflow;
        RETURN_RTL(c);
    }
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2C7DD, SOM_RTL, "gen", exchange_native_scene_and_event_transition_palettes_when_active, 0, L_B | L_X | L_Y | L_C | L_V, 5, 1, 0, 41, 24)
