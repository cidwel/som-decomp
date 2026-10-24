#include "som_c.h"

/* CC0B00 copy_scrolling_dialogue_script_until_terminator   [class B, 55 bytes, 25 instructions]
 * Source: src/rom/copy_scrolling_dialogue_script_until_terminator.s
 * Documented in docs/event-dialogue-scroll.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void copy_scrolling_dialogue_script_until_terminator(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0xA173, 0);
    uint16_t value = RAM16(0x1D01);
    uint8_t value2 = RAM8(0x1D03);
    uint8_t a_hi1 = value >> 8;
    uint16_t x1 = 0;
    uint16_t y1 = value;
    for (;;) {
        uint8_t value3 = BUS8(c, (value2 << 0x10) + y1);
        RAM8(0x9000 + x1) = value3;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(value3 != 0x7E)) break;
    }
    RAM8(0x9000 + x1) = 0;
    RAM16_SET(0x1D01, y1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xCC0B00, SOM_RTS, "gen", copy_scrolling_dialogue_script_until_terminator, 0, 0, 2, 1, 0, 55, 25)
