#include "som_c.h"

/* C01450 advance_dialogue_graphics_origin_and_request_one_tile   [class A, 26 bytes, 11 instructions]
 * Source: src/rom/advance_dialogue_graphics_origin_and_request_one_tile.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void advance_dialogue_graphics_origin_and_request_one_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0xA189);
    RAM16_SET(0xA189, (uint16_t)(value + 0x20));
    r->a = 0x20;
    r->c = value + 0x20 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((value ^ (uint16_t)(value + 0x20)) & ((uint16_t)(value + 0x20) ^ 0x20) & 0x8000) != 0;
    JSR(c, 0x1463, 0xC01936); /* set_dialogue_graphics_transfer_size_preserving_status */
    RAM8(0xA18E) = 0x10;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01450, SOM_RTS, "gen", advance_dialogue_graphics_origin_and_request_one_tile, 0, L_X | L_Y, 1, 1, 0, 26, 11)
