#include "som_c.h"

/* C1B66E append_map_graphics_transpose_bits   [class A, 25 bytes, 17 instructions]
 * Source: src/rom/append_map_graphics_transpose_bits.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: XY.
 */
static void append_map_graphics_transpose_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    RAM8(0x0008) = (uint8_t)((RAM8(0x0008) << 1) | (a >> 7));
    RAM8(0x0009) = (uint8_t)((RAM8(0x0009) << 1) | ((uint8_t)(a << 1) >> 7));
    RAM8(0x000A) = (uint8_t)((RAM8(0x000A) << 1) | ((uint8_t)(a << 2) >> 7));
    RAM8(0x000B) = (uint8_t)((RAM8(0x000B) << 1) | ((uint8_t)(a << 3) >> 7));
    RAM8(0x000C) = (uint8_t)((RAM8(0x000C) << 1) | ((uint8_t)(a << 4) >> 7));
    RAM8(0x000D) = (uint8_t)((RAM8(0x000D) << 1) | ((uint8_t)(a << 5) >> 7));
    RAM8(0x000E) = (uint8_t)((RAM8(0x000E) << 1) | ((uint8_t)(a << 6) >> 7));
    RAM8(0x000F) = (uint8_t)((RAM8(0x000F) << 1) | ((uint8_t)(a << 7) >> 7));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B66E, SOM_RTS, "gen", append_map_graphics_transpose_bits, 0, L_X | L_Y, 1, 1, 1, 25, 17)
