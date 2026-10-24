#include "som_c.h"

/* C9FE68 latent_begin_scrolling_dialogue_end_sequence   [class A, 12 bytes, 6 instructions]
 * Source: src/rom/latent_begin_scrolling_dialogue_end_sequence.s
 * Documented in docs/source-recovery-parallel-latent-scroll-flow.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void latent_begin_scrolling_dialogue_end_sequence(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM8(0xA161)++;
    RAM8(0xA171) = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFE71, 0xC9FFB7); GUARD_JSR(c, sp_call, 0xFE71); } /* advance_latent_dialogue_ring_cursor */
    r->y = (uint16_t)(y + 1);
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC9FE68, SOM_RTS, "gen", latent_begin_scrolling_dialogue_end_sequence, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 12, 6)
