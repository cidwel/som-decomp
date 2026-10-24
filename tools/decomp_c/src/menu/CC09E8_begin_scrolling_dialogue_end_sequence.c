#include "som_c.h"

/* CC09E8 begin_scrolling_dialogue_end_sequence   [class A, 12 bytes, 6 instructions]
 * Source: src/rom/begin_scrolling_dialogue_end_sequence.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void begin_scrolling_dialogue_end_sequence(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM8(0xA161)++;
    RAM8(0xA171) = 0;
    JSR(c, 0x09F1, 0xCC0B37); /* advance_scrolling_dialogue_ring_cursor */
    r->y = (uint16_t)(y + 1);
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC09E8, SOM_RTS, "gen", begin_scrolling_dialogue_end_sequence, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 12, 6)
