#include "som_c.h"

/* CC0B4E clear_scrolling_dialogue_ring_line   [class A, 13 bytes, 7 instructions]
 * Source: src/rom/clear_scrolling_dialogue_ring_line.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void clear_scrolling_dialogue_ring_line(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint16_t value = RAM16(0xA18F);
    uint8_t a1 = 0x40;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = value;
    for (;;) {
        RAM8(0x9400 + x1) = 0;
        a1 = (uint8_t)(a1 - 1);
        x1 = (uint16_t)(x1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC0B4E, SOM_RTS, "gen", clear_scrolling_dialogue_ring_line, 0, L_B, 1, 1, 0, 13, 7)
