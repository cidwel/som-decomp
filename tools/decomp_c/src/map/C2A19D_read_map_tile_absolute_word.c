#include "som_c.h"

/* C2A19D read_map_tile_absolute_word   [class B, 138 bytes, 92 instructions]
 * Source: src/rom/read_map_tile_absolute_word.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: XY.
 */
static void read_map_tile_absolute_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    RAM8(0x0002) = RAM8(0x0000);
    uint16_t value2 = BUS16_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + (uint8_t)(y + 1), RAM8(0x0012));
    RAM16_SET(0x0000, ((uint8_t)value2 << 8) | (value2 >> 8));
    uint16_t value3 = RAM16(0x0010);
    RAM16_SET(0x0010, (uint16_t)(value3 + 2));
    if (value3 + 2 > 0xFFFF) {
        RAM16_SET(0x0012, (uint16_t)(RAM16(0x0012) + 1));
    }
    uint16_t value4 = RAM16(0x0001);
    RAM16_SET(0x0004, value4);
    if (x != 4) {
        if (x != 3) {
            if (x != 2) {
                RAM16_SET(0x0004, (uint16_t)((((uint8_t)(((uint8_t)(((uint8_t)(value4 >> 8 << 1) << 1) | (value4 >> 0x0F)) << 1) | ((uint8_t)(value4 >> 8 << 1) >> 7)) << 8) | (uint8_t)value4) << 6));
                uint8_t value5 = RAM8(0x0000);
                RAM8(0x0000) = (((value5 >> 2) | ((value5 & 1) << 7)) >> 1) | (((value5 >> 1) & 1) << 7);
                RAM8(0x0004) = (((value5 >> 2) | ((value5 & 1) << 7)) & 0x3F) | RAM8(0x0004);
                r->y = (uint8_t)(y + 0);
                RETURN_RTS(c);
            }
            RAM16_SET(0x0004, ((value4 >> 0x0C << 8) | (uint8_t)value4) << 1 << 1 << 1 << 1);
            uint8_t value7 = RAM8(0x0000);
            RAM8(0x0000) = (uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(value7 << 1) << 1) | (value7 >> 7)) << 1) | ((uint8_t)(value7 << 1) >> 7)) << 1) | ((uint8_t)(((uint8_t)(value7 << 1) << 1) | (value7 >> 7)) >> 7));
            RAM8(0x0004) = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(value7 << 1) << 1) | (value7 >> 7)) << 1) | ((uint8_t)(value7 << 1) >> 7)) << 1) | ((uint8_t)(((uint8_t)(value7 << 1) << 1) | (value7 >> 7)) >> 7)) << 1) | ((uint8_t)(((uint8_t)(((uint8_t)(value7 << 1) << 1) | (value7 >> 7)) << 1) | ((uint8_t)(value7 << 1) >> 7)) >> 7)) & 0x0F) | RAM8(0x0004);
            r->y = (uint8_t)(y + 0);
            RETURN_RTS(c);
        }
        RAM16_SET(0x0004, ((value4 >> 0x0A << 8) | (uint8_t)value4) << 1 << 1);
        uint8_t value9 = RAM8(0x0000);
        RAM8(0x0000) <<= 1;
        uint8_t value10 = RAM8(0x0000);
        RAM8(0x0000) <<= 1;
        RAM8(0x0004) = ((uint8_t)(((uint8_t)(((uint8_t)(((value4 >> 0x0A << 8) | (uint8_t)value4) << 1 << 1) << 1) | (value9 >> 7)) << 1) | (value10 >> 7)) & 3) | RAM8(0x0004);
        RETURN_RTS(c);
    }
    r->y = (uint8_t)(y + 0);
    r->mf = false;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A19D, SOM_RTS, "hand", read_map_tile_absolute_word, 0, L_X | L_Y, 1, 1, 1, 138, 92)
