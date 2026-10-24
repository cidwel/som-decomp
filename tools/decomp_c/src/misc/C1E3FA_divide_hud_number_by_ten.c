#include "som_c.h"

/* C1E3FA divide_hud_number_by_ten   [class A, 20 bytes, 13 instructions]
 * Source: src/rom/divide_hud_number_by_ten.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXY.
 */
static void divide_hud_number_by_ten(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    BUS16_SET(c, 0x004204, y);
    BUS8_SET(c, 0x004206, 0x0A);
    uint8_t value = BUS8(c, 0x004216);
    SET_A8(r, value);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E3FA, SOM_RTS, "gen", divide_hud_number_by_ten, 0, L_A | L_B | L_X | L_Y, 1, 1, 0, 20, 13)
