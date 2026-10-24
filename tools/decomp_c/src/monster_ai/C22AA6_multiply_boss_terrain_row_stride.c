#include "som_c.h"

/* C22AA6 multiply_boss_terrain_row_stride   [class A, 29 bytes, 13 instructions]
 * Source: src/rom/multiply_boss_terrain_row_stride.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=any DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void multiply_boss_terrain_row_stride(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, -1)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    BUS8_SET(c, 0x004202, RAM8(0x0246));
    BUS8_SET(c, 0x004203, RAM8(0x024E));
    uint8_t value3 = BUS8(c, 0x004216);
    RAM8(0x0256) = value3;
    uint8_t value4 = BUS8(c, 0x004217);
    RAM8(0x0257) = value4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22AA6, SOM_RTS, "gen", multiply_boss_terrain_row_stride, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, -1, 29, 13)
