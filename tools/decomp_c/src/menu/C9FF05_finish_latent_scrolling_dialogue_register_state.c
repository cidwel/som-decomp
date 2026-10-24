#include "som_c.h"

/* C9FF05 finish_latent_scrolling_dialogue_register_state   [class A, 28 bytes, 10 instructions]
 * Source: src/rom/finish_latent_scrolling_dialogue_register_state.s
 * Documented in docs/source-recovery-parallel-latent-scroll-registers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void finish_latent_scrolling_dialogue_register_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    RAM8(0xA170) = 0;
    RAM8(0xA161) = 0;
    RAM8(0x1D11) = 0;
    RAM8(0x0040) = 0;
    RAM16_SET(0x1D1A, 0x0536);
    r->a = 0x0536;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC9FF05, SOM_RTS, "gen", finish_latent_scrolling_dialogue_register_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 28, 10)
