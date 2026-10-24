#include "som_c.h"

/* C08B3D request_directional_screen_mosaic   [class A, 15 bytes, 8 instructions]
 * Source: src/rom/request_directional_screen_mosaic.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void request_directional_screen_mosaic(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    RAM8(0x1057) = (carry << 7) ^ 0x80;
    uint8_t value = RAM8(0x03E2);
    RAM8(0x03E2) |= 2;
    SET_A8(r, 2);
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->c = 0;
    r->z = (value & 2) == 0;
    r->n = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08B3D, SOM_RTS, "gen", request_directional_screen_mosaic, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 15, 8)
