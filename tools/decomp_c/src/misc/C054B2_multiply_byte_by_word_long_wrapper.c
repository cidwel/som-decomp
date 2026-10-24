#include "som_c.h"

/* C054B2 multiply_byte_by_word_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/multiply_byte_by_word_long_wrapper.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XYV.
 */
static void multiply_byte_by_word_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSR(c, 0x54B4, 0xC054B6); /* multiply_byte_by_word */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC054B2, SOM_RTL, "gen", multiply_byte_by_word_long_wrapper, 0, L_X | L_Y | L_V, 1, 1, 0, 4, 2)
