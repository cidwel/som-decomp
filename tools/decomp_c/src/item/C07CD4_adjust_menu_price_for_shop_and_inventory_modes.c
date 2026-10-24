#include "som_c.h"

/* C07CD4 adjust_menu_price_for_shop_and_inventory_modes   [class B, 57 bytes, 26 instructions]
 * Source: src/rom/adjust_menu_price_for_shop_and_inventory_modes.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYV.
 */
static void adjust_menu_price_for_shop_and_inventory_modes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    RAM16_SET(0x1822, a);
    uint8_t a_hi3;
    uint16_t y3;
    if (a == 0xFFFF) {
        a_hi3 = a >> 8;
        y3 = a;
    } else {
        uint8_t value = RAM8(0x1847);
        uint8_t a_hi2;
        uint16_t y2;
        if ((uint8_t)(value - 1) != 0) {
            uint8_t a_hi1;
            uint16_t y1;
            if ((uint8_t)(value - 2) != 0) {
                a_hi1 = a >> 8;
                y1 = a;
            } else {
                r->a = (a >> 8 << 8) | 3;
                r->y = a;
                r->c = a >= 0xFFFF;
                r->mf = 1;
                JSL(c, 0x7CFD, 0xD0D7E2); /* divide_menu_number_using_snes_arithmetic_registers */
                uint16_t y_ret = r->y;
                uint16_t value2 = BUS16(c, 0x004214);
                RAM16_SET(0x1822, (uint16_t)(value2 << 1));
                a_hi1 = (uint16_t)(value2 << 1) >> 8;
                y1 = y_ret;
            }
            a_hi2 = a_hi1;
            y2 = y1;
        } else {
            if (RAM8(0x185B) == 0x99) {
                RAM16_SET(0x1822, (uint16_t)(RAM16(0x1822) << 1));
            }
            a_hi2 = a >> 8;
            y2 = a;
        }
        a_hi3 = a_hi2;
        y3 = y2;
    }
    r->a = RAM16(0x1822);
    r->y = y3;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC07CD4, SOM_RTL, "gen", adjust_menu_price_for_shop_and_inventory_modes, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 57, 26)
