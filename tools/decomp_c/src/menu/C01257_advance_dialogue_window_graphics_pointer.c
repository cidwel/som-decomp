#include "som_c.h"

/* C01257 advance_dialogue_window_graphics_pointer   [class A, 24 bytes, 11 instructions]
 * Source: src/rom/advance_dialogue_window_graphics_pointer.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: YV.
 */
static void advance_dialogue_window_graphics_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value2 = BUS16(c, 0xC01A3E + ((RAM16(0xA181) & 0xFF) << 1));
    uint16_t value3 = RAM16(0xA189);
    RAM16_SET(0xA189, (uint16_t)(value2 + value3));
    r->v = ((value2 ^ (uint16_t)(value2 + value3)) & (value3 ^ (uint16_t)(value2 + value3)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01257, SOM_RTS, "gen", advance_dialogue_window_graphics_pointer, 0, L_Y | L_V, 1, 1, 0, 24, 11)
