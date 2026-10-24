#include "som_c.h"

/* C26A98 follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth   [class B, 123 bytes, 55 instructions]
 * Source: src/rom/follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth.s
 * Documented in docs/boss-descriptor-thirteen-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B0 + value);
    uint16_t value3 = RAM16(0x00B2 + value);
    RAM16_SET(0x0295, RAM16(0x002B + value2));
    RAM16_SET(0x0297, RAM16(0x0032 + value2));
    RAM16_SET(0x0299, RAM16(0x0066 + value2));
    RAM16_SET(0x029B, RAM16(0x0022 + value2));
    uint16_t value8 = BUS16(c, 0xC26B13 + (uint16_t)(value3 << 2));
    RAM16_SET(0x029D, value8);
    uint16_t value9 = BUS16(c, 0xC26B15 + (uint16_t)(value3 << 2));
    RAM16_SET(0x029F, value9);
    uint16_t value10 = RAM16(0x0098 + value2);
    uint8_t a_hi1;
    if ((value10 & 0x40) == 0) {
        a_hi1 = value10 >> 8;
    } else {
        uint16_t value11 = RAM16(0x029D);
        uint16_t value12 = RAM16(0x02C7);
        RAM16_SET(0x029D, (uint16_t)((value11 ^ value12) + 1));
        a_hi1 = (uint16_t)((value11 ^ value12) + 1) >> 8;
    }
    RAM8(0x02A2) = 0;
    RAM8(0x02A1) = RAM8(0x0089 + value2);
    RAM16_SET(0x002B + value, (uint16_t)(RAM16(0x0295) + RAM16(0x029D)));
    uint16_t value16 = RAM16(0x0297);
    uint16_t value17 = RAM16(0x029F);
    RAM16_SET(0x0032 + value, (uint16_t)((uint16_t)(value16 + value17) + RAM16(0x02A1) + (value16 + value17 > 0xFFFF)));
    RAM16_SET(0x0066 + value, RAM16(0x0299));
    RAM16_SET(0x000B + value, RAM16(0x000B + value2));
    uint16_t value21 = RAM16(0x00B2 + value);
    uint8_t a1;
    uint8_t a_hi2;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value21 != 0) {
        uint16_t value22 = RAM16(0x029B);
        a1 = (uint8_t)(value22 - 8);
        a_hi2 = (uint16_t)(value22 - 8) >> 8;
        carry1 = value22 >= 8;
        zero1 = (uint16_t)(value22 - 8) == 0;
        negative1 = (uint16_t)(value22 - 8) & 0x8000;
        overflow1 = ((value22 ^ 8) & (value22 ^ (uint16_t)(value22 - 8)) & 0x8000) != 0;
    } else {
        uint16_t value23 = RAM16(0x029B);
        a1 = (uint8_t)(value23 + 8);
        a_hi2 = (uint16_t)(value23 + 8) >> 8;
        carry1 = value23 + 8 > 0xFFFF;
        zero1 = (uint16_t)(value23 + 8) == 0;
        negative1 = (uint16_t)(value23 + 8) & 0x8000;
        overflow1 = ((value23 ^ (uint16_t)(value23 + 8)) & ((uint16_t)(value23 + 8) ^ 8) & 0x8000) != 0;
    }
    RAM16_SET(0x0022 + value, (a_hi2 << 8) | a1);
    r->a = (a_hi2 << 8) | a1;
    r->x = value;
    r->y = value2;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26A98, SOM_RTS, "gen", follow_descriptor_thirteen_parent_mirrored_offsets_height_and_depth, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 123, 55)
