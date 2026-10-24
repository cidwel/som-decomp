#include "som_c.h"

/* CC0B37 advance_scrolling_dialogue_ring_cursor   [class A, 23 bytes, 10 instructions]
 * Source: src/rom/advance_scrolling_dialogue_ring_cursor.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void advance_scrolling_dialogue_ring_cursor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0xA18F);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)(value + 0x80) < 0x0800) {
        a1 = (uint8_t)(value + 0x80);
        a_hi1 = (uint16_t)(value + 0x80) >> 8;
    } else {
        a1 = 2;
        a_hi1 = 0;
    }
    RAM16_SET(0xA18F, (a_hi1 << 8) | a1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC0B37, SOM_RTS, "gen", advance_scrolling_dialogue_ring_cursor, 0, 0, 1, 1, 0, 23, 10)
