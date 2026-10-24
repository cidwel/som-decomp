#include "som_c.h"

/* C2A227 read_map_tile_six_bit_value   [class B, 91 bytes, 55 instructions]
 * Source: src/rom/read_map_tile_six_bit_value.s
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: AXY.
 */
static void read_map_tile_six_bit_value(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t x = r->x;
    const uint8_t y = r->y;
    if (x < 3) {
        uint8_t value = RAM8(0x0000);
        uint8_t a1;
        if (x == 2) {
            a1 = (value >> 2) & 0x3C;
        } else {
            a1 = (value >> 2) & 0x30;
        }
        RAM8(0x0002) = a1;
        RAM8(0x0010)++;
        if (RAM8(0x0010) == 0) {
            RAM8(0x0011)++;
            if (RAM8(0x0011) == 0) {
                RAM8(0x0012)++;
            }
        }
        uint8_t value2 = BUS8_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + y, RAM8(0x0012));
        RAM8(0x0000) = (uint8_t)(((uint8_t)(value2 << 1) << 1) | (value2 >> 7));
        uint8_t a2;
        uint8_t x1;
        if (x != 2) {
            uint8_t value3 = RAM8(0x0000);
            RAM8(0x0000) <<= 1;
            uint8_t value4 = RAM8(0x0000);
            RAM8(0x0000) <<= 1;
            a2 = (uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(value2 << 1) << 1) | (value2 >> 7)) << 1) | ((uint8_t)(value2 << 1) >> 7)) << 1) | (value3 >> 7)) << 1) | (value4 >> 7)) & 0x0F;
            x1 = 2;
        } else {
            a2 = (uint8_t)(((uint8_t)(((uint8_t)(value2 << 1) << 1) | (value2 >> 7)) << 1) | ((uint8_t)(value2 << 1) >> 7)) & 3;
            x1 = 3;
        }
        SET_A8(r, a2 | RAM8(0x0002));
        r->x = x1;
        RETURN_RTS(c);
    }
    uint8_t value6 = RAM8(0x0000);
    RAM8(0x0000 + sp0) = value6;
    RAM8(0x0000) = (((value6 >> 2) | ((value6 & 1) << 7)) >> 1) | (((value6 >> 1) & 1) << 7);
    uint8_t x2;
    if ((uint8_t)(x - 3) != 0) {
        x2 = (uint8_t)(x - 3);
    } else {
        RAM8(0x0010)++;
        if (RAM8(0x0010) == 0) {
            RAM8(0x0011)++;
            if (RAM8(0x0011) == 0) {
                RAM8(0x0012)++;
            }
        }
        uint8_t value7 = BUS8_RDL(c, (RAM8(0x0012) << 0x10) + RAM16(0x0010) + y, RAM8(0x0012));
        RAM8(0x0000) = value7;
        x2 = 4;
    }
    SET_A8(r, value6 >> 2);
    r->x = x2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A227, SOM_RTS, "gen", read_map_tile_six_bit_value, 0, L_A | L_X | L_Y, 1, 1, 1, 91, 55)
