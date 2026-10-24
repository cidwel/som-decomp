#include "som_c.h"

/* C1B35F rotate_map_graphics_odd_rows_left   [class B, 51 bytes, 29 instructions]
 * Source: src/rom/rotate_map_graphics_odd_rows_left.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$7F D=$0000.  Callers read: BX.
 */
static void rotate_map_graphics_odd_rows_left(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    uint16_t value = RAM16(0x0006);
    RAM16_SET(0x0008, (uint16_t)(value + 0x20));
    uint8_t a_hi1 = (uint16_t)(value + 0x20) >> 8;
    uint8_t y1 = 0;
    for (;;) {
        uint16_t value2 = BUS16(c, RAM16(0x0006) + 0x7F0000 + y1);
        BUS16_SET(c, RAM16(0x0008) + 0x7F0000 + y1, value2);
        uint8_t value3 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 2));
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y1 + 2), (uint8_t)((value3 << 1) | (value3 >= 0x80)));
        uint8_t value4 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 3));
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y1 + 3), (uint8_t)((value4 << 1) | (value4 >= 0x80)));
        a_hi1 = value2 >> 8;
        y1 = (uint8_t)(y1 + 4);
        if (!(y1 < 0x20)) break;
    }
    uint16_t value5 = RAM16(0x0008);
    RAM16_SET(0x0006, value5);
    r->a = value5;
    r->x = x;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B35F, SOM_RTS, "gen", rotate_map_graphics_odd_rows_left, 0, L_B | L_X, 1, 0, 1, 51, 29)
