#include "som_c.h"

/* C24E4F advance_body_velocity_by_segment_shape_and_flip_bits   [class B, 73 bytes, 32 instructions]
 * Source: src/rom/advance_body_velocity_by_segment_shape_and_flip_bits.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXY.
 */
static void advance_body_velocity_by_segment_shape_and_flip_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0000 + y);
    uint16_t value2 = BUS16(c, 0xDCE643 + ((value & 0x0F) << 1));
    RAM16_SET(0x0295, value2);
    uint16_t value3 = BUS16(c, 0xDCE645 + ((value & 0x0F) << 1));
    RAM16_SET(0x0297, value3);
    uint16_t value4 = RAM16(0x0000 + y);
    uint8_t a_hi1;
    if ((value4 & 0x4000) == 0) {
        a_hi1 = value4 >> 8;
    } else {
        uint16_t value5 = RAM16(0x0295);
        RAM16_SET(0x0295, (uint16_t)((value5 ^ 0xFFFF) + 1));
        a_hi1 = (uint16_t)((value5 ^ 0xFFFF) + 1) >> 8;
    }
    uint16_t value6 = RAM16(0x0000 + y);
    uint8_t a_hi2;
    if ((value6 & 0x8000) == 0) {
        a_hi2 = value6 >> 8;
    } else {
        uint16_t value7 = RAM16(0x0297);
        RAM16_SET(0x0297, (uint16_t)((value7 ^ 0xFFFF) + 1));
        a_hi2 = (uint16_t)((value7 ^ 0xFFFF) + 1) >> 8;
    }
    uint16_t value8 = RAM16(0x0287);
    RAM16_SET(0x00B4 + value8, (uint16_t)(RAM16(0x00B4 + value8) + RAM16(0x0295)));
    uint16_t value11 = RAM16(0x00B6 + value8);
    uint16_t value12 = RAM16(0x0297);
    RAM16_SET(0x00B6 + value8, (uint16_t)(value11 + value12));
    r->a = (uint16_t)(value11 + value12);
    r->x = value8;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24E4F, SOM_RTS, "gen", advance_body_velocity_by_segment_shape_and_flip_bits, 0, L_B | L_X | L_Y, 1, 0, 0, 73, 32)
