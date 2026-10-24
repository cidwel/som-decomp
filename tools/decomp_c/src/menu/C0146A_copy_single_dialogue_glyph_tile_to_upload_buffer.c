#include "som_c.h"

/* C0146A copy_single_dialogue_glyph_tile_to_upload_buffer   [class A, 15 bytes, 6 instructions]
 * Source: src/rom/copy_single_dialogue_glyph_tile_to_upload_buffer.s
 * Documented in docs/event-dialogue-render-publication.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void copy_single_dialogue_glyph_tile_to_upload_buffer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA171) = 2;
    uint16_t value = RAM16(0xA189);
    r->a = (a_hi << 8) | 2;
    r->x = 0x9400;
    r->y = value;
    JSR(c, 0x1477, 0xC014C6); /* copy_requested_dialogue_rows_to_upload_buffer */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0146A, SOM_RTS, "gen", copy_single_dialogue_glyph_tile_to_upload_buffer, 0, L_X | L_Y, 1, 1, 0, 15, 6)
