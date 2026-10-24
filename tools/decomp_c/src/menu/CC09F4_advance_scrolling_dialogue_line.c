#include "som_c.h"

/* CC09F4 advance_scrolling_dialogue_line   [class A, 6 bytes, 4 instructions]
 * Source: src/rom/advance_scrolling_dialogue_line.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void advance_scrolling_dialogue_line(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    JSR(c, 0x09F7, 0xCC0B37); /* advance_scrolling_dialogue_ring_cursor */
    r->y = (uint16_t)(y + 1);
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC09F4, SOM_RTS, "gen", advance_scrolling_dialogue_line, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 6, 4)
