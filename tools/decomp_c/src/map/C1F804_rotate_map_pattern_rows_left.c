#include "som_c.h"

/* C1F804 rotate_map_pattern_rows_left   [class A, 19 bytes, 11 instructions]
 * Source: src/rom/rotate_map_pattern_rows_left.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: BV.
 */
static void rotate_map_pattern_rows_left(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = x;
    uint8_t y1 = y;
    for (;;) {
        uint8_t value = RAM8(0x1FF00 + x1);
        RAM8(0x0000) = value;
        uint8_t value2 = RAM8(0x0000);
        RAM8(0x0000) >>= 1;
        RAM8(0x1FF00 + y1) = (uint8_t)(value << 1 | (value2 & 1));
        x1 = (uint8_t)(x1 + 1);
        y1 = (uint8_t)(y1 + 1);
        if (!((y1 & 0x0F) != 0)) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F804, SOM_RTS, "gen", rotate_map_pattern_rows_left, 0, L_B | L_V, 1, 1, 1, 19, 11)
