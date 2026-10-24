#include "som_c.h"

/* C21226 integrate_boss_vertical_position_and_velocity   [class A, 53 bytes, 20 instructions]
 * Source: src/rom/integrate_boss_vertical_position_and_velocity.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYV.
 */
static void integrate_boss_vertical_position_and_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00C4 + x);
    uint16_t value2 = RAM16(0x0064 + x);
    RAM16_SET(0x0064 + x, (uint16_t)(value + value2));
    uint16_t value3 = RAM16(0x00C6 + x);
    uint16_t value4 = RAM16(0x0066 + x);
    RAM16_SET(0x0066 + x, (uint16_t)(value3 + value4 + (value + value2 > 0xFFFF)));
    if ((uint16_t)(value3 + value4 + (value + value2 > 0xFFFF)) & 0x8000) {
        RAM16_SET(0x0064 + x, 0);
        RAM16_SET(0x0066 + x, 0);
        RAM16_SET(0x00C4 + x, 0);
        RAM16_SET(0x00C6 + x, 0);
    }
    uint16_t value5 = RAM16(0x00C4 + x);
    uint16_t value6 = RAM16(0x0FC0);
    RAM16_SET(0x00C4 + x, (uint16_t)(value5 + value6));
    uint16_t value7 = RAM16(0x00C6 + x);
    uint16_t value8 = RAM16(0x0FC2);
    RAM16_SET(0x00C6 + x, (uint16_t)(value7 + value8 + (value5 + value6 > 0xFFFF)));
    r->v = ((value7 ^ (uint16_t)(value7 + value8 + (value5 + value6 > 0xFFFF))) & (value8 ^ (uint16_t)(value7 + value8 + (value5 + value6 > 0xFFFF))) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21226, SOM_RTS, "gen", integrate_boss_vertical_position_and_velocity, 0, L_X | L_Y | L_V, 1, 0, 0, 53, 20)
