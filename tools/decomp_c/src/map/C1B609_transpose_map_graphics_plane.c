#include "som_c.h"

/* C1B609 transpose_map_graphics_plane   [class B, 101 bytes, 61 instructions]
 * Source: src/rom/transpose_map_graphics_plane.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: XY.
 */
static void transpose_map_graphics_plane(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t y = r->y;
    uint8_t value = BUS8(c, RAM16(0x0006) + 0x7F0000 + y);
    r->a = (a_hi << 8) | value;
    JSR(c, 0xB60D, 0xC1B66E); /* append_map_graphics_transpose_bits */
    uint16_t a_all = r->a;
    uint8_t value2 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 2));
    r->a = (a_all >> 8 << 8) | value2;
    r->y = (uint8_t)(y + 2);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB614, 0xC1B66E); /* append_map_graphics_transpose_bits */
    uint16_t a_all2 = r->a;
    uint8_t value3 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 4));
    r->a = (a_all2 >> 8 << 8) | value3;
    r->y = (uint8_t)(y + 4);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB61B, 0xC1B66E); /* append_map_graphics_transpose_bits */
    uint16_t a_all3 = r->a;
    uint8_t value4 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 6));
    r->a = (a_all3 >> 8 << 8) | value4;
    r->y = (uint8_t)(y + 6);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB622, 0xC1B66E); /* append_map_graphics_transpose_bits */
    uint16_t a_all4 = r->a;
    uint8_t value5 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 8));
    r->a = (a_all4 >> 8 << 8) | value5;
    r->y = (uint8_t)(y + 8);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB629, 0xC1B66E); /* append_map_graphics_transpose_bits */
    uint16_t a_all5 = r->a;
    uint8_t value6 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 0x0A));
    r->a = (a_all5 >> 8 << 8) | value6;
    r->y = (uint8_t)(y + 0x0A);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB630, 0xC1B66E); /* append_map_graphics_transpose_bits */
    uint16_t a_all6 = r->a;
    uint8_t value7 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 0x0C));
    r->a = (a_all6 >> 8 << 8) | value7;
    r->y = (uint8_t)(y + 0x0C);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB637, 0xC1B66E); /* append_map_graphics_transpose_bits */
    uint16_t a_all7 = r->a;
    uint8_t value8 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 0x0E));
    r->a = (a_all7 >> 8 << 8) | value8;
    r->y = (uint8_t)(y + 0x0E);
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0xB63E, 0xC1B66E); /* append_map_graphics_transpose_bits */
    BUS8_SET(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 0x0E), RAM8(0x000F));
    BUS8_SET(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 0x0C), RAM8(0x000E));
    BUS8_SET(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 0x0A), RAM8(0x000D));
    BUS8_SET(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 8), RAM8(0x000C));
    BUS8_SET(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 6), RAM8(0x000B));
    BUS8_SET(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 4), RAM8(0x000A));
    BUS8_SET(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 2), RAM8(0x0009));
    BUS8_SET(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y + 0), RAM8(0x0008));
    r->y = (uint8_t)(y + 0);
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B609, SOM_RTS, "gen", transpose_map_graphics_plane, 0, L_X | L_Y, 1, 1, 1, 101, 61)
