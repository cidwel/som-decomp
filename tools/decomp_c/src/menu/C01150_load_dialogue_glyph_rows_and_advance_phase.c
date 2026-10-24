#include "som_c.h"

/* C01150 load_dialogue_glyph_rows_and_advance_phase   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/load_dialogue_glyph_rows_and_advance_phase.s
 * Documented in docs/event-dialogue-font-rows.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void load_dialogue_glyph_rows_and_advance_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x1152, 0xC01664); /* load_dialogue_glyph_rows_or_advance_empty_line */
    RAM8(0xA15D)++;
    r->z = RAM8(0xA15D) == 0;
    r->n = RAM8(0xA15D) & 0x80;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01150, SOM_RTS, "gen", load_dialogue_glyph_rows_and_advance_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 7, 3)
