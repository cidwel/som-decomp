#include "som_c.h"

/* 7E9AA4 scale_image_coefficients   [class D, 48 bytes, 27 instructions]
 * Source: src/boot/scale_image_coefficients.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$00 D=any.  Callers read: YCV.
 */
static void scale_image_coefficients(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    const uint16_t sp0 = r->sp; /* the prologue pushes are real stack bytes */
    RAM8(sp0 - 0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    const uint16_t dp = r->dp;
    uint8_t a_hi1 = 0x21;
    uint16_t x1 = (uint16_t)(dp - 0x2100);
    uint16_t y1 = 0x1D00;
    for (;;) {
        uint8_t value = BUS8(c, (uint16_t)(0x0000 + y1));
        if (value != 0) {
            BUS8_SET(c, 0x211B, value);
            BUS8_SET(c, 0x211B, 0);
            uint8_t value2 = BUS8(c, (uint16_t)(0x2100 + x1));
            BUS8_SET(c, 0x211C, value2);
            BUS8_SET(c, 0x211C, value2);
            BUS8_SET(c, (uint16_t)(0x2100 + x1), BUS8(c, 0x2134));
            BUS8_SET(c, (uint16_t)(0x2100 + (uint16_t)(x1 + 1)), BUS8(c, 0x2135));
            x1 = (uint16_t)(x1 + 2);
            y1 = (uint16_t)(y1 + 1);
            continue;
        }
        break;
    }
    r->y = y1;
    r->c = dp >= 0x2100;
    r->v = ((dp ^ 0x2100) & (dp ^ (uint16_t)(dp - 0x2100)) & 0x8000) != 0;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9AA4, SOM_RTS, "hand", scale_image_coefficients, 0, L_Y | L_C | L_V, 2, 0, 0, 48, 27)
