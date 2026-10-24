#include "som_c.h"

/* C01663 dialogue_glyph_phase_no_operation   [class A, 1 bytes, 1 instructions]
 * Source: src/rom/dialogue_glyph_phase_no_operation.s
 * Documented in docs/event-dialogue-glyph-tiles.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void dialogue_glyph_phase_no_operation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01663, SOM_RTS, "gen", dialogue_glyph_phase_no_operation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 1, 1)
