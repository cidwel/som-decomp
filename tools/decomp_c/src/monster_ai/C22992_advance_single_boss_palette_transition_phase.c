#include "som_c.h"

/* C22992 advance_single_boss_palette_transition_phase   [class A, 7 bytes, 4 instructions]
 * Source: src/rom/advance_single_boss_palette_transition_phase.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_single_boss_palette_transition_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    r->x = value;
    r->c = 0;
    r->z = RAM16(OBJECT_PHASE + value) == 0;
    r->n = RAM16(OBJECT_PHASE + value) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22992, SOM_RTS, "gen", advance_single_boss_palette_transition_phase, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 7, 4)
