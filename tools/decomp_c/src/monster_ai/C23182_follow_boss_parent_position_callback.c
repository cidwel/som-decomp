#include "som_c.h"

/* C23182 follow_boss_parent_position_callback   [class A, 21 bytes, 9 instructions]
 * Source: src/rom/follow_boss_parent_position_callback.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void follow_boss_parent_position_callback(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    RAM16_SET(0x002B + x, RAM16(0x002B + value));
    uint16_t value3 = RAM16(0x0032 + value);
    uint16_t value4 = RAM16(0x00A5 + value);
    RAM16_SET(0x0032 + x, (uint16_t)(value3 + value4));
    r->a = (uint16_t)(value3 + value4);
    r->y = value;
    r->c = value3 + value4 > 0xFFFF;
    r->z = (uint16_t)(value3 + value4) == 0;
    r->n = (uint16_t)(value3 + value4) & 0x8000;
    r->v = ((value3 ^ (uint16_t)(value3 + value4)) & (value4 ^ (uint16_t)(value3 + value4)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23182, SOM_RTS, "gen", follow_boss_parent_position_callback, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 21, 9)
