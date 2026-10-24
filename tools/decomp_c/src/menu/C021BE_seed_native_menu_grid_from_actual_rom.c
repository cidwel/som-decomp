#include "som_c.h"

/* C021BE seed_native_menu_grid_from_actual_rom   [class A, 29 bytes, 14 instructions]
 * Source: src/rom/seed_native_menu_grid_from_actual_rom.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void seed_native_menu_grid_from_actual_rom(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xA171) = 0x1C;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    do {
        uint8_t a1 = 0x10;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        for (;;) {
            uint8_t value = BUS8(c, 0xD2D880 + x2);
            RAM8(0x9000 + x2) = value;
            a1 = (uint8_t)(a1 - 1);
            a_hi2 = value;
            x2 = (uint16_t)(x2 + 1);
            if (!(a1 != 0)) break;
        }
        RAM8(0xA171)--;
        a_hi1 = a_hi2;
        x1 = x2;
    } while (RAM8(0xA171) != 0);
    r->a = (a_hi1 << 8) | a;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC021BE, SOM_RTS, "gen", seed_native_menu_grid_from_actual_rom, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 29, 14)
