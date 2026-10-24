#include "som_c.h"

/* C0389C random_byte_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/random_byte_long_wrapper.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCV.
 */
static void random_byte_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSR(c, 0x389E, 0xC038A0); /* advance_additive_random_generator */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0389C, SOM_RTL, "gen", random_byte_long_wrapper, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
