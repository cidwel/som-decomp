#include "som_c.h"

/* C00EBF reset_map_menu_state   [class A, 73 bytes, 31 instructions]
 * Source: src/rom/reset_map_menu_state.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCV.
 */
static void reset_map_menu_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    RAM8(0xA17C) = RAM8(0xA196);
    RAM8(0xA17D) = RAM8(0xA197);
    RAM16_SET(0xA17E, 0x0122);
    RAM8(0xA15C) = 0;
    RAM8(0xA15D) = 0;
    RAM8(0xA15E) = 0;
    RAM8(0xA15F) = 0;
    RAM8(0xA16D) = 0;
    RAM8(0xA160) = 0;
    RAM8(0xA170) = 0;
    RAM8(0xA181) = 0;
    RAM8(0xA1D0) = 0;
    RAM8(0xA1A4) = 0;
    RAM8(0x1D10) &= 0xFE;
    r->x = 0x0122;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC00EBF, SOM_RTL, "gen", reset_map_menu_state, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 73, 31)
