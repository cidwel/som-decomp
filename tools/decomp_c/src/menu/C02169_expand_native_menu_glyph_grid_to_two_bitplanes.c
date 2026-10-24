#include "som_c.h"

/* C02169 expand_native_menu_glyph_grid_to_two_bitplanes   [class B, 40 bytes, 18 instructions]
 * Source: src/rom/expand_native_menu_glyph_grid_to_two_bitplanes.s
 * Documented in docs/event-menu-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void expand_native_menu_glyph_grid_to_two_bitplanes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xA176) = 0x1C;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    do {
        RAM8(0xA171) = 0x10;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        bool overflow2 = overflow1;
        do {
            r->a = (a_hi2 << 8) | a;
            r->x = x2;
            r->y = y2;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            JSR(c, 0x217B, 0xC02191); /* expand_packed_native_menu_glyph_byte_to_two_bitplanes */
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            bool overflow_ret = r->v;
            RAM8(0xA171)--;
            a_hi2 = a_all >> 8;
            x2 = x_ret;
            y2 = y_ret;
            overflow2 = overflow_ret;
        } while (RAM8(0xA171) != 0);
        RAM8(0xA176)--;
        a_hi1 = (uint16_t)(x2 + 0x10) >> 8;
        x1 = (uint16_t)(x2 + 0x10);
        y1 = y2;
        carry1 = x2 + 0x10 > 0xFFFF;
        overflow1 = ((x2 ^ (uint16_t)(x2 + 0x10)) & ((uint16_t)(x2 + 0x10) ^ 0x10) & 0x8000) != 0;
    } while (RAM8(0xA176) != 0);
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02169, SOM_RTS, "gen", expand_native_menu_glyph_grid_to_two_bitplanes, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 40, 18)
