#include "som_c.h"

/* C28E92 follow_descriptor_eleven_parent_position_minus_half_height   [class A, 30 bytes, 13 instructions]
 * Source: src/rom/follow_descriptor_eleven_parent_position_minus_half_height.s
 * Documented in docs/boss-descriptor-eleven-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void follow_descriptor_eleven_parent_position_minus_half_height(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    RAM16_SET(0x002B + x, RAM16(0x002B + value));
    RAM16_SET(0x0032 + x, RAM16(0x0032 + value));
    uint16_t value4 = RAM16(0x0066 + value);
    uint16_t value5 = RAM16(0x02C7);
    uint16_t value6 = RAM16(0x0032 + x);
    RAM16_SET(0x0032 + x, (uint16_t)((uint16_t)(((value4 >> 1) ^ value5) + 1) + value6));
    r->a = (uint16_t)((uint16_t)(((value4 >> 1) ^ value5) + 1) + value6);
    r->y = value;
    r->c = (uint16_t)(((value4 >> 1) ^ value5) + 1) + value6 > 0xFFFF;
    r->z = (uint16_t)((uint16_t)(((value4 >> 1) ^ value5) + 1) + value6) == 0;
    r->n = (uint16_t)((uint16_t)(((value4 >> 1) ^ value5) + 1) + value6) & 0x8000;
    r->v = (((uint16_t)(((value4 >> 1) ^ value5) + 1) ^ (uint16_t)((uint16_t)(((value4 >> 1) ^ value5) + 1) + value6)) & (value6 ^ (uint16_t)((uint16_t)(((value4 >> 1) ^ value5) + 1) + value6)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28E92, SOM_RTS, "gen", follow_descriptor_eleven_parent_position_minus_half_height, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 30, 13)
