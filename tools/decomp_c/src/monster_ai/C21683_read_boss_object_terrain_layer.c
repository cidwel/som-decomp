#include "som_c.h"

/* C21683 read_boss_object_terrain_layer   [class B, 51 bytes, 30 instructions]
 * Source: src/rom/read_boss_object_terrain_layer.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYV.
 */
static void read_boss_object_terrain_layer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x023E);
    RAM16_SET(0x0246, value >> 4);
    RAM16_SET(0x024E, 0x80);
    r->a = 0x80;
    r->c = value >> 3 & 0x01;
    r->mf = 1;
    JSR(c, 0x1694, 0xC22AA6); /* multiply_boss_terrain_row_stride */
    uint16_t value2 = RAM16(0x023C);
    uint16_t value3 = RAM16(0x0256);
    uint16_t value4;
    BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279) + (uint16_t)((value2 >> 4) + value3), value4);
    uint16_t value5;
    BUS16_OK(c, (RAM8(0x027E) << 0x10) + RAM16(0x027C) + ((value4 & 0xFF) << 1 << 1), value5);
    RAM8(0x000B + x) = value5 & 3;
    r->y = (value4 & 0xFF) << 1 << 1;
    r->v = (((value2 >> 4) ^ (uint16_t)((value2 >> 4) + value3)) & (value3 ^ (uint16_t)((value2 >> 4) + value3)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21683, SOM_RTS, "hand", read_boss_object_terrain_layer, 0, L_X | L_Y | L_V, 1, 0, 0, 51, 30)
