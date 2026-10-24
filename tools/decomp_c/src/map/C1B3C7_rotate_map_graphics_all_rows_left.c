#include "som_c.h"

/* C1B3C7 rotate_map_graphics_all_rows_left   [class A, 31 bytes, 17 instructions]
 * Source: src/rom/rotate_map_graphics_all_rows_left.s
 * Documented in docs/maps.md
 * Entry: M=any X=8 bit DB=$7F D=$0000.  Callers read: BX.
 */
static void rotate_map_graphics_all_rows_left(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    uint16_t value = RAM16(0x0006);
    RAM16_SET(0x0008, (uint16_t)(value + 0x20));
    uint8_t a_hi1 = (uint16_t)(value + 0x20) >> 8;
    uint8_t y1 = 0x1F;
    for (;;) {
        uint8_t value2 = BUS8(c, RAM16(0x0006) + 0x7F0000 + y1);
        BUS8_SET(c, RAM16(0x0008) + 0x7F0000 + y1, (uint8_t)((value2 << 1) | (value2 >= 0x80)));
        y1 = (uint8_t)(y1 - 1);
        if (!(!(y1 & 0x80))) break;
    }
    uint16_t value3 = RAM16(0x0008);
    RAM16_SET(0x0006, value3);
    r->a = value3;
    r->x = x;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B3C7, SOM_RTS, "gen", rotate_map_graphics_all_rows_left, 0, L_B | L_X, 1, -1, 1, 31, 17)
