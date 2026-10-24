#include "som_c.h"

/* C05437 multiply_byte_word_divide_by_100_long_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/multiply_byte_word_divide_by_100_long_wrapper.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void multiply_byte_word_divide_by_100_long_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSR(c, 0x5439, 0xC0543B); /* multiply_byte_word_divide_by_100 */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05437, SOM_RTL, "gen", multiply_byte_word_divide_by_100_long_wrapper, 0, L_X | L_Y, 1, 1, 0, 4, 2)
