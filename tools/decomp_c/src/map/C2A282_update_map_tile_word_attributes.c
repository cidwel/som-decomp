#include "som_c.h"

/* C2A282 update_map_tile_word_attributes   [class B, 102 bytes, 63 instructions]
 * Source: src/rom/update_map_tile_word_attributes.s
 * Entry: M=8 bit X=8 bit DB=any D=$0000.  Callers read: AXY.
 */
static void update_map_tile_word_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    uint8_t a1;
    uint8_t x2;
    if (x < 2) {
        uint8_t value = RAM8(0x0000);
        RAM8(0x0001) = (uint8_t)((uint8_t)(((uint8_t)(((uint8_t)(value << 1) << 1) | (value >> 7)) << 1) | ((uint8_t)(value << 1) >> 7)) << 2);
        RAM8(0x0010)++;
        if (RAM8(0x0010) == 0) {
            RAM8(0x0011)++;
            if (RAM8(0x0011) == 0) {
                RAM8(0x0012)++;
            }
        }
        uint8_t value2 = BUS8_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + y, RAM8(0x0012));
        RAM8(0x0000) = (uint8_t)(((uint8_t)(value2 << 1) << 1) | (value2 >> 7));
        a1 = ((uint8_t)(((uint8_t)(((uint8_t)(value2 << 1) << 1) | (value2 >> 7)) << 1) | ((uint8_t)(value2 << 1) >> 7)) & 3) | RAM8(0x0001);
        x2 = 3;
    } else {
        uint8_t value4 = RAM8(0x0000);
        RAM8(0x0000) = (uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(value4 << 1) << 1) | (value4 >> 7)) << 1) | ((uint8_t)(value4 << 1) >> 7)) << 1) | ((uint8_t)(((uint8_t)(value4 << 1) << 1) | (value4 >> 7)) >> 7));
        RAM8(0x0000 + sp0) = (uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(value4 << 1) << 1) | (value4 >> 7)) << 1) | ((uint8_t)(value4 << 1) >> 7)) << 1) | ((uint8_t)(((uint8_t)(value4 << 1) << 1) | (value4 >> 7)) >> 7)) << 1) | ((uint8_t)(((uint8_t)(((uint8_t)(value4 << 1) << 1) | (value4 >> 7)) << 1) | ((uint8_t)(value4 << 1) >> 7)) >> 7));
        uint8_t x1;
        if ((uint8_t)(x - 2) != 0) {
            x1 = (uint8_t)(x - 2);
        } else {
            RAM8(0x0010)++;
            if (RAM8(0x0010) == 0) {
                RAM8(0x0011)++;
                if (RAM8(0x0011) == 0) {
                    RAM8(0x0012)++;
                }
            }
            uint8_t value5 = BUS8_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + y, RAM8(0x0012));
            RAM8(0x0000) = value5;
            x1 = 4;
        }
        a1 = (uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(value4 << 1) << 1) | (value4 >> 7)) << 1) | ((uint8_t)(value4 << 1) >> 7)) << 1) | ((uint8_t)(((uint8_t)(value4 << 1) << 1) | (value4 >> 7)) >> 7)) << 1) | ((uint8_t)(((uint8_t)(((uint8_t)(value4 << 1) << 1) | (value4 >> 7)) << 1) | ((uint8_t)(value4 << 1) >> 7)) >> 7));
        x2 = x1;
    }
    if ((a1 & 0x0F) << 1 << 1 >= 0x20) {
        RAM8(0x0001) = (uint8_t)((a1 & 0x0F) << 1 << 1 << 1 << 1 << 1);
        uint8_t value6 = RAM8(0x0005);
        uint8_t value7 = RAM8(0x0001);
        RAM8(0x0005) = (value6 & 0x1F) | value7;
        SET_A8(r, (value6 & 0x1F) | value7);
        r->x = x2;
        RETURN_RTS(c);
    }
    RAM8(0x0001) = (a1 & 0x0F) << 1 << 1;
    uint8_t value8 = RAM8(0x0005);
    uint8_t value9 = RAM8(0x0001);
    RAM8(0x0005) = (value8 & 0xE3) | value9;
    SET_A8(r, (value8 & 0xE3) | value9);
    r->x = x2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A282, SOM_RTS, "gen", update_map_tile_word_attributes, 0, L_A | L_X | L_Y, 1, 1, 1, 102, 63)
