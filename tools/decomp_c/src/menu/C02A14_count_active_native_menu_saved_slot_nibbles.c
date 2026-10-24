#include "som_c.h"

/* C02A14 count_active_native_menu_saved_slot_nibbles   [class A, 32 bytes, 19 instructions]
 * Source: src/rom/count_active_native_menu_saved_slot_nibbles.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: Y.
 */
static void count_active_native_menu_saved_slot_nibbles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t a1 = 4;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t value = BUS8(c, 0x3060CB + x1);
        RAM8(0x0000 + sp0) = value;
        uint16_t y2;
        if ((value & 0x0F) != 1) {
            y2 = y1;
        } else {
            y2 = (uint16_t)(y1 + 1);
        }
        uint16_t y3;
        if ((value & 0xF0) != 0x10) {
            y3 = y2;
        } else {
            y3 = (uint16_t)(y2 + 1);
        }
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value & 0xF0;
        x1 = (uint16_t)(x1 + 1);
        y1 = y3;
        if (!(a1 != 0)) break;
    }
    r->y = y1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC02A14, SOM_RTL, "gen", count_active_native_menu_saved_slot_nibbles, 0, L_Y, 1, 1, 0, 32, 19)
