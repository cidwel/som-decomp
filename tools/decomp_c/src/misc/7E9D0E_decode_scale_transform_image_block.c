#include "som_c.h"

/* 7E9D0E decode_scale_transform_image_block   [class C, 16 bytes, 8 instructions]
 * Source: src/boot/decode_scale_transform_image_block.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$00 D=any.  Callers read: XYCZNV.
 */
static void decode_scale_transform_image_block(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0116);
    r->a = x;
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    JSR(c, 0x9D14, 0x7E995C); /* decode_diagonal_coefficient_block */
    uint16_t a_all = r->a;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x9D18, 0x7E9AA4); /* scale_image_coefficients */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x9D1B, 0x7E9AD4); /* transform_image_coefficients */
    r->sp += 2;
    r->x = a_all;
    r->z = a_all == 0;
    r->n = a_all & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9D0E, SOM_RTS, "gen", decode_scale_transform_image_block, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 16, 8)
