#include "som_c.h"

/* D0D0DA locate_selected_armor_with_nonzero_level   [class B, 33 bytes, 17 instructions]
 * Source: src/rom/locate_selected_armor_with_nonzero_level.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYV.
 */
static void locate_selected_armor_with_nonzero_level(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint8_t a1 = (uint8_t)(RAM8(0x1875) + 1);
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = 0;
    for (;;) {
        RAM8(0x0000 + sp0) = a1;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        for (;;) {
            uint8_t value2 = RAM8(0xE5C8 + x2);
            x2 = (uint16_t)(x2 + 1);
            if (!((value2 & 7) == 0)) break;
        }
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = a_hi2;
        x1 = x2;
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | RAM8(0xE5C8 + (uint16_t)(x1 - 1));
    r->x = (uint16_t)(x1 - 1);
    r->y = y;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0D0DA, SOM_RTL, "gen", locate_selected_armor_with_nonzero_level, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 33, 17)
