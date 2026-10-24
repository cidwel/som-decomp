#include "som_c.h"

/* CC09CD set_scrolling_dialogue_line_indentation   [class A, 21 bytes, 11 instructions]
 * Source: src/rom/set_scrolling_dialogue_line_indentation.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void set_scrolling_dialogue_line_indentation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x9000 + (uint16_t)(y + 1));
    uint16_t value2 = RAM16(0xA18F);
    RAM16_SET(0xA19B, (uint16_t)(((value & 0xFF) << 1) + value2));
    r->a = (uint16_t)(((value & 0xFF) << 1) + value2);
    r->y = (uint16_t)(y + 2);
    r->c = ((value & 0xFF) << 1) + value2 > 0xFFFF;
    r->z = (uint16_t)(((value & 0xFF) << 1) + value2) == 0;
    r->n = (uint16_t)(((value & 0xFF) << 1) + value2) & 0x8000;
    r->v = ((((value & 0xFF) << 1) ^ (uint16_t)(((value & 0xFF) << 1) + value2)) & (value2 ^ (uint16_t)(((value & 0xFF) << 1) + value2)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC09CD, SOM_RTS, "gen", set_scrolling_dialogue_line_indentation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 21, 11)
