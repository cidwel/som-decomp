#include "som_c.h"

/* 7E9DB6 decode_transform_image_group   [class B, 63 bytes, 27 instructions]
 * Source: src/boot/decode_transform_image_group.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XYCZNV.
 */
static void decode_transform_image_group(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    c->fail = 3; /* operand size does not fit the register width on this path */
    return;
}
SOM_REGISTER(0x7E9DB6, SOM_RTS, "gen", decode_transform_image_group, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 63, 27)
