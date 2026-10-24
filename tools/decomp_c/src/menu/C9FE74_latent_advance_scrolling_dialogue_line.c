#include "som_c.h"

/* C9FE74 latent_advance_scrolling_dialogue_line   [class A, 6 bytes, 4 instructions]
 * Source: src/rom/latent_advance_scrolling_dialogue_line.s
 * Documented in docs/source-recovery-parallel-latent-scroll-flow.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void latent_advance_scrolling_dialogue_line(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFE77, 0xC9FFB7); GUARD_JSR(c, sp_call, 0xFE77); } /* advance_latent_dialogue_ring_cursor */
    r->y = (uint16_t)(y + 1);
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC9FE74, SOM_RTS, "gen", latent_advance_scrolling_dialogue_line, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 6, 4)
