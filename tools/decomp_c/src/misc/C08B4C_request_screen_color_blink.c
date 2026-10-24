#include "som_c.h"

/* C08B4C request_screen_color_blink   [class A, 17 bytes, 8 instructions]
 * Source: src/rom/request_screen_color_blink.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void request_screen_color_blink(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x1057) = 0x40;
    RAM8(0x1058) = RAM8(0x03E6);
    uint8_t value2 = RAM8(0x03E2);
    RAM8(0x03E2) |= 4;
    SET_A8(r, 4);
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->z = (value2 & 4) == 0;
    r->n = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC08B4C, SOM_RTS, "gen", request_screen_color_blink, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 17, 8)
