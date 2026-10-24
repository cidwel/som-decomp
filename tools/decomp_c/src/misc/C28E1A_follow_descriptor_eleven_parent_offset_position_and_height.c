#include "som_c.h"

/* C28E1A follow_descriptor_eleven_parent_offset_position_and_height   [class A, 30 bytes, 12 instructions]
 * Source: src/rom/follow_descriptor_eleven_parent_offset_position_and_height.s
 * Documented in docs/boss-descriptor-eleven-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void follow_descriptor_eleven_parent_offset_position_and_height(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B0 + x);
    RAM16_SET(0x002B + x, (uint16_t)(RAM16(0x002B + value) + 8));
    uint16_t value3 = RAM16(0x0032 + value);
    RAM16_SET(0x0032 + x, (uint16_t)(value3 + 0x38));
    uint16_t value4 = RAM16(0x0066 + value);
    RAM16_SET(0x0066 + x, value4);
    r->a = value4;
    r->y = value;
    r->c = value3 + 0x38 > 0xFFFF;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->v = ((value3 ^ (uint16_t)(value3 + 0x38)) & ((uint16_t)(value3 + 0x38) ^ 0x38) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28E1A, SOM_RTS, "gen", follow_descriptor_eleven_parent_offset_position_and_height, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 30, 12)
