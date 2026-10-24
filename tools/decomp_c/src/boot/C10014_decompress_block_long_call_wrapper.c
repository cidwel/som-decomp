#include "som_c.h"

/* C10014 decompress_block_long_call_wrapper   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/decompress_block_long_call_wrapper.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: XYCZNV.
 */
static void decompress_block_long_call_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x0016, 0xC14C30); /* decompress_block */
    RETURN_RTL(c);
}
SOM_REGISTER(0xC10014, SOM_RTL, "hand", decompress_block_long_call_wrapper, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 4, 2)
