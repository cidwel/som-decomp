#include "som_c.h"

/* C02191 expand_packed_native_menu_glyph_byte_to_two_bitplanes   [class A, 45 bytes, 27 instructions]
 * Source: src/rom/expand_packed_native_menu_glyph_byte_to_two_bitplanes.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void expand_packed_native_menu_glyph_byte_to_two_bitplanes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0x9400 + x) = 0;
    RAM8(0x9410 + x) = 0;
    uint8_t value = RAM8(0x9000 + y);
    uint8_t a1 = 4;
    uint8_t a_hi1 = value;
    bool overflow1 = overflow;
    for (;;) {
        RAM8(0x9410 + x) = (RAM8(0x9410 + x) >> 1) | ((a_hi1 & 1) << 7);
        RAM8(0x9410 + x) = (RAM8(0x9410 + x) >> 1) | ((a_hi1 & 1) << 7);
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = a_hi1 >> 1;
        if (!(a1 != 0)) break;
    }
    uint8_t a2 = 4;
    uint8_t a_hi2 = a_hi1;
    bool overflow2 = overflow1;
    for (;;) {
        RAM8(0x9400 + x) = (RAM8(0x9400 + x) >> 1) | ((a_hi2 & 1) << 7);
        RAM8(0x9400 + x) = (RAM8(0x9400 + x) >> 1) | ((a_hi2 & 1) << 7);
        a2 = (uint8_t)(a2 - 1);
        a_hi2 = a_hi2 >> 1;
        if (!(a2 != 0)) break;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = (uint16_t)(x + 1);
    r->y = (uint16_t)(y + 1);
    r->v = overflow2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02191, SOM_RTS, "gen", expand_packed_native_menu_glyph_byte_to_two_bitplanes, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 45, 27)
