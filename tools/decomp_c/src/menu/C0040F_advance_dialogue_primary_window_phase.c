#include "som_c.h"

/* C0040F advance_dialogue_primary_window_phase   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/advance_dialogue_primary_window_phase.s
 * Documented in docs/event-dialogue-render-blend.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: B.
 */
static void advance_dialogue_primary_window_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0xA15C)++;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0040F, SOM_RTS, "gen", advance_dialogue_primary_window_phase, 0, L_B, 1, 1, 0, 4, 2)
