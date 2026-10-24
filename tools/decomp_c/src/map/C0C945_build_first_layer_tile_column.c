#include "som_c.h"

/* C0C945 build_first_layer_tile_column   [class B, 161 bytes, 90 instructions]
 * Source: src/rom/build_first_layer_tile_column.s
 * Entry: M=16 bit X=8 bit DB=$7F D=$0000.  Callers read: BXYV.
 */
static void build_first_layer_tile_column(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t y = r->y;
    uint16_t value = RAM16(0x00AA);
    RAM16_SET(0x0004, value & 0x07F0);
    RAM16_SET(0x0010, (uint16_t)(((value & 0x07F0) << 1 << 1 << 1) + RAM16(0x00C8) + ((value & 0x07F0) << 1 << 1 >> 0x0F)));
    RAM16_SET(0x0004, (uint16_t)(RAM16(0x00C2) - RAM16(0x0004)) >> 4);
    uint16_t value5 = RAM16(0x00A8);
    uint16_t value6 = RAM16(0x0000);
    uint16_t value7 = RAM16(0x00C0);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)(value5 + value6) < value7) {
        a1 = (uint8_t)(value5 + value6);
        a_hi1 = (uint16_t)(value5 + value6) >> 8;
    } else {
        a1 = (uint8_t)((uint16_t)(value5 + value6) - value7 - ((uint16_t)(value5 + value6) >= value7 ^ 1));
        a_hi1 = (uint16_t)((uint16_t)(value5 + value6) - value7 - ((uint16_t)(value5 + value6) >= value7 ^ 1)) >> 8;
    }
    RAM16_SET(0x001A, ((a_hi1 << 8) | a1) >> 4);
    RAM8(0x0010) = (uint8_t)(((a_hi1 << 8) | a1) >> 4) | RAM8(0x0010);
    uint16_t value9 = RAM16(0x00B0);
    RAM8(0x0078) = ((uint8_t)(value9 + value6) >> 3) & 0x1E;
    uint8_t a2;
    if (!((uint16_t)(value9 + value6) >> 8 & 0x01)) {
        a2 = 0x50;
    } else {
        a2 = 0x54;
    }
    RAM8(0x0079) = a2;
    RAM8(0x0000) = 0x10;
    RAM8(0x0001) = 0;
    uint8_t value10 = RAM8(0x00B2);
    uint8_t a_hi2 = ((uint8_t)(value9 + value6) >> 3) & 0x1E;
    uint16_t x1 = (uint8_t)((((uint8_t)(value9 + value6) >> 3) & 0x1E) << 8 | ((value10 >> 2) & 0xFC));
    uint16_t y1 = y;
    bool overflow1 = ((value9 ^ (uint16_t)(value9 + value6)) & (value6 ^ (uint16_t)(value9 + value6)) & 0x8000) != 0;
    do {
        uint16_t value11 = BUS16_RDP(c, RAM16(0x0010) + 0x7F0000);
        uint16_t value12 = RAM16(0x0010);
        RAM16_SET(0x0010, (uint16_t)(value12 + 0x80));
        RAM16_SET(0x0004, (uint16_t)(RAM16(0x0004) - 1));
        uint8_t a_hi3;
        if (RAM16(0x0004) != 0) {
            a_hi3 = (uint16_t)(value12 + 0x80) >> 8;
        } else {
            uint16_t value13 = RAM16(0x00C8);
            uint16_t value14 = RAM16(0x001A);
            RAM16_SET(0x0010, value13 | value14);
            a_hi3 = (value13 | value14) >> 8;
        }
        BUS16_SET(c, 0x7FD200 + x1, RAM16(0x1C000 + ((value11 & 0xFF) << 1 << 1 << 1)));
        BUS16_SET(c, 0x7FD240 + x1, RAM16(0x1C002 + ((value11 & 0xFF) << 1 << 1 << 1)));
        BUS16_SET(c, 0x7FD200 + (uint16_t)(x1 + 2), RAM16(0x1C004 + ((value11 & 0xFF) << 1 << 1 << 1)));
        uint16_t value18 = RAM16(0x1C006 + ((value11 & 0xFF) << 1 << 1 << 1));
        BUS16_SET(c, 0x7FD240 + (uint16_t)(x1 + 2), value18);
        uint16_t x2;
        if ((uint16_t)(x1 + 4) < 0x40) {
            x2 = (uint16_t)(x1 + 4);
        } else {
            x2 = 0;
        }
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) - 1));
        a_hi2 = value18 >> 8;
        x1 = x2;
        y1 = (value11 & 0xFF) << 1 << 1 << 1;
        overflow1 = ((value12 ^ (uint16_t)(value12 + 0x80)) & ((uint16_t)(value12 + 0x80) ^ 0x80) & 0x8000) != 0;
    } while (RAM16(0x0000) != 0);
    r->a = (a_hi2 << 8) | (uint8_t)a;
    r->x = x1;
    r->y = y1;
    r->v = overflow1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C945, SOM_RTS, "gen", build_first_layer_tile_column, 0, L_B | L_X | L_Y | L_V, 1, 0, 1, 161, 90)
