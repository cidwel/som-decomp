#include "som_c.h"

/* C22EA0 subtract_boss_direction_coordinate_pairs   [class A, 15 bytes, 9 instructions]
 * Source: src/rom/subtract_boss_direction_coordinate_pairs.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYV.
 */
static void subtract_boss_direction_coordinate_pairs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x0246, (uint16_t)(RAM16(0x0246) - RAM16(0x0256)));
    uint16_t value3 = RAM16(0x024E);
    uint16_t value4 = RAM16(0x025E);
    RAM16_SET(0x024E, (uint16_t)(value3 - value4));
    r->a = (uint16_t)(value3 - value4);
    r->v = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22EA0, SOM_RTS, "gen", subtract_boss_direction_coordinate_pairs, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 15, 9)
