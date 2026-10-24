#include "som_c.h"

/* C1B411 shift_map_graphics_odd_columns_up   [class B, 103 bytes, 55 instructions]
 * Source: src/rom/shift_map_graphics_odd_columns_up.s
 * Documented in docs/maps.md
 * Entry: M=any X=8 bit DB=$7F D=$0000.  Callers read: BX.
 */
static void shift_map_graphics_odd_columns_up(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    RAM16_SET(0x0008, (uint16_t)(RAM16(0x0006) + 0x20));
    uint16_t value2 = BUS16(c, RAM16(0x0006) + 0x7F0000);
    RAM16_SET(0x000A, value2 & 0x5555);
    uint8_t a_hi1 = (value2 & 0x5555) >> 8;
    uint8_t y1 = 0;
    for (;;) {
        uint16_t value3 = BUS16(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 2));
        RAM16_SET(0x000C, value3 & 0x5555);
        uint16_t value4 = BUS16(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 0));
        uint16_t value5 = RAM16(0x000C);
        BUS16_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y1 + 0), (value4 & 0xAAAA) | value5);
        a_hi1 = ((value4 & 0xAAAA) | value5) >> 8;
        y1 = (uint8_t)(y1 + 2);
        if (!(y1 < 0x0E)) break;
    }
    uint16_t value6 = BUS16(c, RAM16(0x0006) + 0x7F0000 + y1);
    BUS16_SET(c, RAM16(0x0008) + 0x7F0000 + y1, (value6 & 0xAAAA) | RAM16(0x000A));
    uint16_t value8 = BUS16(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 2));
    RAM16_SET(0x000A, value8 & 0x5555);
    uint8_t a_hi2 = (value8 & 0x5555) >> 8;
    uint8_t y2 = (uint8_t)(y1 + 2);
    for (;;) {
        uint16_t value9 = BUS16(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y2 + 2));
        RAM16_SET(0x000C, value9 & 0x5555);
        uint16_t value10 = BUS16(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y2 + 0));
        uint16_t value11 = RAM16(0x000C);
        BUS16_SET(c, RAM16(0x0008) + 0x7F0000 + (uint8_t)(y2 + 0), (value10 & 0xAAAA) | value11);
        a_hi2 = ((value10 & 0xAAAA) | value11) >> 8;
        y2 = (uint8_t)(y2 + 2);
        if (!(y2 < 0x1E)) break;
    }
    uint16_t value12 = BUS16(c, RAM16(0x0006) + 0x7F0000 + y2);
    BUS16_SET(c, RAM16(0x0008) + 0x7F0000 + y2, (value12 & 0xAAAA) | RAM16(0x000A));
    uint16_t value14 = RAM16(0x0008);
    RAM16_SET(0x0006, value14);
    r->a = value14;
    r->x = x;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B411, SOM_RTS, "gen", shift_map_graphics_odd_columns_up, 0, L_B | L_X, 1, -1, 1, 103, 55)
