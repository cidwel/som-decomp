#include "som_c.h"

/* C01431 publish_single_dialogue_glyph_tile   [class A, 31 bytes, 12 instructions]
 * Source: src/rom/publish_single_dialogue_glyph_tile.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void publish_single_dialogue_glyph_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x1433, 0xC0146A); /* copy_single_dialogue_glyph_tile_to_upload_buffer */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x1436, 0xC01450); /* advance_dialogue_graphics_origin_and_request_one_tile */
    uint16_t value = RAM16(0xA18C);
    RAM16_SET(0x1D06, value);
    uint16_t value2 = RAM16(0xA18E);
    RAM16_SET(0xA18C, (uint16_t)((value2 & 0xFF) + value));
    r->a = (r->a & 0x00FF) | (((uint16_t)((value2 & 0xFF) + value) >> 8) << 8);
    r->v = (((value2 & 0xFF) ^ (uint16_t)((value2 & 0xFF) + value)) & (value ^ (uint16_t)((value2 & 0xFF) + value)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01431, SOM_RTS, "gen", publish_single_dialogue_glyph_tile, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 31, 12)
