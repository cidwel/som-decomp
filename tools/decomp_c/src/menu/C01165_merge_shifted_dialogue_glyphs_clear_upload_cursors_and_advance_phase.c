#include "som_c.h"

/* C01165 merge_shifted_dialogue_glyphs_clear_upload_cursors_and_advance_phase   [class A, 16 bytes, 6 instructions]
 * Source: src/rom/merge_shifted_dialogue_glyphs_clear_upload_cursors_and_advance_phase.s
 * Documented in docs/event-dialogue-glyph-tiles.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void merge_shifted_dialogue_glyphs_clear_upload_cursors_and_advance_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x1167, 0xC0162C); /* merge_shifted_dialogue_glyph_bitmaps */
    RAM16_SET(0xA191, 0);
    RAM16_SET(0xA173, 0);
    RAM8(0xA15D)++;
    r->x = 0;
    r->z = RAM8(0xA15D) == 0;
    r->n = RAM8(0xA15D) & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01165, SOM_RTS, "gen", merge_shifted_dialogue_glyphs_clear_upload_cursors_and_advance_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 16, 6)
