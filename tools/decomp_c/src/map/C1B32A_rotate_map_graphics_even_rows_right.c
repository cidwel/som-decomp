#include "som_c.h"

/* C1B32A rotate_map_graphics_even_rows_right   [class B, 53 bytes, 33 instructions]
 * Source: src/rom/rotate_map_graphics_even_rows_right.s
 * Documented in docs/maps.md
 * Entry: M=any X=8 bit DB=$7F D=$0000.  Callers read: BX.
 */
static void rotate_map_graphics_even_rows_right(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    uint16_t value = RAM16(0x0006);
    RAM16_SET(0x0008, (uint16_t)(value + 0x20));
    uint8_t a_hi1 = (uint16_t)(value + 0x20) >> 8;
    uint8_t y1 = 0;
    for (;;) {
        uint8_t value2 = BUS8(c, RAM16(0x0006) + 0x7F0000 + y1);
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + y1, (value2 >> 1) | ((value2 & 1) << 7));
        uint8_t value3 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 1));
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y1 + 1), (value3 >> 1) | ((value3 & 1) << 7));
        uint16_t value4 = BUS16(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 2));
        BUS16_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y1 + 2), value4);
        a_hi1 = value4 >> 8;
        y1 = (uint8_t)(y1 + 4);
        if (!(y1 < 0x20)) break;
    }
    uint16_t value5 = RAM16(0x0008);
    RAM16_SET(0x0006, value5);
    r->a = value5;
    r->x = x;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B32A, SOM_RTS, "gen", rotate_map_graphics_even_rows_right, 0, L_B | L_X, 1, -1, 1, 53, 33)
