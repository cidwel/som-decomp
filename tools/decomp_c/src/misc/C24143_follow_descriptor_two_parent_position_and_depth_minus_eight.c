#include "som_c.h"

/* C24143 follow_descriptor_two_parent_position_and_depth_minus_eight   [class A, 26 bytes, 10 instructions]
 * Source: src/rom/follow_descriptor_two_parent_position_and_depth_minus_eight.s
 * Documented in docs/boss-descriptor-two-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void follow_descriptor_two_parent_position_and_depth_minus_eight(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    RAM16_SET(0x002B + x, RAM16(0x002B + value));
    RAM16_SET(0x0032 + x, RAM16(0x0032 + value));
    uint16_t value4 = RAM16(0x0022 + value);
    RAM16_SET(0x0022 + x, (uint16_t)(value4 - 8));
    r->a = (uint16_t)(value4 - 8);
    r->y = value;
    r->c = value4 >= 8;
    r->z = (uint16_t)(value4 - 8) == 0;
    r->n = (uint16_t)(value4 - 8) & 0x8000;
    r->v = ((value4 ^ 8) & (value4 ^ (uint16_t)(value4 - 8)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24143, SOM_RTS, "gen", follow_descriptor_two_parent_position_and_depth_minus_eight, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 26, 10)
