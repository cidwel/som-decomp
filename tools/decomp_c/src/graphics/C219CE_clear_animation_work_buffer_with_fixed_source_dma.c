#include "som_c.h"

/* C219CE clear_animation_work_buffer_with_fixed_source_dma   [class D, 56 bytes, 19 instructions]
 * Source: src/rom/clear_animation_work_buffer_with_fixed_source_dma.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void clear_animation_work_buffer_with_fixed_source_dma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    BUS16_SET(c, 0x002181, 0xBC00);
    BUS16_SET(c, 0x004372, 0x0D52);
    BUS16_SET(c, 0x004375, 0x0400);
    BUS8_SET(c, 0x002183, 1);
    BUS8_SET(c, 0x004370, 8);
    BUS8_SET(c, 0x004371, 0x80);
    BUS8_SET(c, 0x004374, 0xC2);
    BUS8_SET(c, 0x00420B, 0x80);
    r->a = 0x0480;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC219CE, SOM_RTS, "gen", clear_animation_work_buffer_with_fixed_source_dma, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 56, 19)
