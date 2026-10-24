#include "som_c.h"

/* C2539F follow_descriptor_fourteen_parent_position_depth_and_height   [class A, 30 bytes, 12 instructions]
 * Source: src/rom/follow_descriptor_fourteen_parent_position_depth_and_height.s
 * Documented in docs/boss-descriptor-fourteen-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void follow_descriptor_fourteen_parent_position_depth_and_height(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    RAM16_SET(0x0032 + x, (uint16_t)(RAM16(0x0032 + value) + 0x28));
    RAM16_SET(0x002B + x, RAM16(0x002B + value));
    uint16_t value4 = RAM16(0x0066 + value);
    RAM16_SET(0x0066 + x, (uint16_t)(value4 + 0x50));
    r->a = (uint16_t)(value4 + 0x50);
    r->y = value;
    r->c = value4 + 0x50 > 0xFFFF;
    r->z = (uint16_t)(value4 + 0x50) == 0;
    r->n = (uint16_t)(value4 + 0x50) & 0x8000;
    r->v = ((value4 ^ (uint16_t)(value4 + 0x50)) & ((uint16_t)(value4 + 0x50) ^ 0x50) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2539F, SOM_RTS, "gen", follow_descriptor_fourteen_parent_position_depth_and_height, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 30, 12)
