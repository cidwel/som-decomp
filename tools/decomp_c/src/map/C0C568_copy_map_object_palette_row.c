#include "som_c.h"

/* C0C568 copy_map_object_palette_row   [class B, 55 bytes, 27 instructions]
 * Source: src/rom/copy_map_object_palette_row.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void copy_map_object_palette_row(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    BUS8_SET(c, 0x004202, (uint8_t)a);
    BUS8_SET(c, 0x004203, 0x1E);
    RAM8(0x0000) = 0x0F;
    RAM8(0x0001) = 0;
    uint16_t value = RAM16(0x0098);
    uint8_t a_hi1;
    uint16_t y1;
    if (value == 0) {
        a_hi1 = value >> 8;
        y1 = y;
    } else {
        a_hi1 = (y ^ 0x80) >> 8;
        y1 = y ^ 0x80;
    }
    uint16_t value2 = BUS16(c, 0x004216);
    uint8_t a_hi2 = value2 >> 8;
    uint16_t x1 = value2;
    uint16_t y2 = y1;
    do {
        uint16_t value3 = BUS16(c, 0xC81000 + x1);
        RAM16_SET(0x0700 + y2, value3);
        RAM16_SET(0xDF00 + y2, value3);
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) - 1));
        a_hi2 = value3 >> 8;
        x1 = (uint16_t)(x1 + 2);
        y2 = (uint16_t)(y2 + 2);
    } while (RAM16(0x0000) != 0);
    r->x = x;
    r->y = y2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C568, SOM_RTS, "gen", copy_map_object_palette_row, 0, L_X | L_Y, 2, 0, 0, 55, 27)
