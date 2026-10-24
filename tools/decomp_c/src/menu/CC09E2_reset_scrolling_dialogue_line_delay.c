#include "som_c.h"

/* CC09E2 reset_scrolling_dialogue_line_delay   [class A, 6 bytes, 4 instructions]
 * Source: src/rom/reset_scrolling_dialogue_line_delay.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void reset_scrolling_dialogue_line_delay(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM8(0xA171) = 0;
    r->y = (uint16_t)(y + 1);
    r->c = 0;
    r->z = (uint16_t)(y + 1) == 0;
    r->n = (uint16_t)(y + 1) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC09E2, SOM_RTS, "gen", reset_scrolling_dialogue_line_delay, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 6, 4)
