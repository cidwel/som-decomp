#include "som_c.h"

/* C01936 set_dialogue_graphics_transfer_size_preserving_status   [class A, 9 bytes, 5 instructions]
 * Source: src/rom/set_dialogue_graphics_transfer_size_preserving_status.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void set_dialogue_graphics_transfer_size_preserving_status(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    RAM16_SET(0x1D08, a);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01936, SOM_RTS, "gen", set_dialogue_graphics_transfer_size_preserving_status, 0, L_B | L_X | L_Y | L_V, 1, -1, 0, 9, 5)
