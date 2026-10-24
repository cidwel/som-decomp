#include "som_c.h"

/* C2C1D7 read_charge_effect_terrain_height   [class B, 74 bytes, 38 instructions]
 * Source: src/rom/read_charge_effect_terrain_height.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXY.
 */
static void read_charge_effect_terrain_height(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM16_SET(0x000A, 0xB800);
    uint8_t value = RAM8(0xD001 + y);
    uint16_t x1;
    if (!(value & 0x80)) {
        x1 = 0;
    } else {
        RAM16_SET(0x000A, 0xBC00);
        x1 = 0x4000;
    }
    RAM16_SET(0x000C, x1);
    RAM16_SET(0x000E, RAM16(0xD002 + y) >> 4);
    uint16_t value6 = BUS16(c, 0x7F0000 + (uint16_t)((((RAM16(0xD004 + y) & 0x0FF0) << 1 << 1 << 1) | RAM16(0x000E)) + RAM16(0x000C)));
    uint16_t value7 = RAM16(0x000A);
    r->a = (uint16_t)(((value6 & 0xFF) << 1 << 1) + value7) >> 8 << 8 | (RAM8(0x10000 + (uint16_t)(((value6 & 0xFF) << 1 << 1) + value7)) & 0x30);
    r->x = (uint16_t)(((value6 & 0xFF) << 1 << 1) + value7);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C1D7, SOM_RTS, "gen", read_charge_effect_terrain_height, 0, L_A | L_B | L_X | L_Y, 1, 1, 0, 74, 38)
