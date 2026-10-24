#include "som_c.h"

/* D0D7E2 divide_menu_number_using_snes_arithmetic_registers   [class A, 23 bytes, 14 instructions]
 * Source: src/rom/divide_menu_number_using_snes_arithmetic_registers.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void divide_menu_number_using_snes_arithmetic_registers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t y = r->y;
    BUS16_SET(c, 0x004204, y);
    BUS8_SET(c, 0x004206, a);
    uint8_t value = BUS8(c, 0x004214);
    uint16_t value2 = BUS16(c, 0x004216);
    SET_A8(r, value);
    r->y = value2;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0D7E2, SOM_RTL, "gen", divide_menu_number_using_snes_arithmetic_registers, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 23, 14)
