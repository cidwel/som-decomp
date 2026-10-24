#include "som_c.h"

/* C24E98 derive_body_segment_direction_shape_and_coordinates   [class B, 138 bytes, 63 instructions]
 * Source: src/rom/derive_body_segment_direction_shape_and_coordinates.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: B.
 */
static void derive_body_segment_direction_shape_and_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0256, (uint16_t)(RAM16(0x002B + x) + RAM16(0x00B4 + x)));
    RAM16_SET(0x025E, (uint16_t)(RAM16(0x0032 + x) + RAM16(0x00B6 + x)));
    uint16_t value5 = RAM16(0x00A9 + x);
    RAM16_SET(0x0246, RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000)));
    uint16_t value7 = RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000));
    RAM16_SET(0x024E, value7);
    r->a = value7;
    r->x = (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000);
    r->v = (((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value5 << 8) | (value5 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    JSR(c, 0x4EC0, 0xC22E50); /* derive_eight_way_direction_from_coordinate_pairs */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x4EC3, 0xC24F22); /* turn_body_heading_one_step_toward_target_with_opposite_rng_tie */
    uint16_t a_all2 = r->a;
    uint16_t x_ret = r->x;
    RAM16_SET(0x00BA + x_ret, a_all2);
    uint8_t value8 = BUS8(c, 0xDCE62B + a_all2);
    RAM8(0x0295) = value8;
    uint8_t value9 = BUS8(c, 0xDCE63B + a_all2);
    RAM8(0x0296) = value9;
    uint8_t value10 = RAM8(0x0295);
    uint16_t value11 = BUS16(c, 0xDCE653 + ((a_all2 >> 8 << 8) | ((value10 & 0x0F) << 1)));
    RAM16_SET(0x0297, value11);
    uint16_t value12 = BUS16(c, 0xDCE655 + ((a_all2 >> 8 << 8) | ((value10 & 0x0F) << 1)));
    RAM16_SET(0x0299, value12);
    uint16_t value13 = RAM16(0x0295);
    uint8_t a_hi1;
    if ((value13 & 0x4000) == 0) {
        a_hi1 = value13 >> 8;
    } else {
        uint16_t value14 = RAM16(0x0297);
        RAM16_SET(0x0297, (uint16_t)(0xFFF0 - value14));
        a_hi1 = (uint16_t)(0xFFF0 - value14) >> 8;
    }
    uint8_t a_hi2;
    if ((value13 & 0x8000) == 0) {
        a_hi2 = value13 >> 8;
    } else {
        uint16_t value15 = RAM16(0x0299);
        RAM16_SET(0x0299, (uint16_t)(0xFFF0 - value15));
        a_hi2 = (uint16_t)(0xFFF0 - value15) >> 8;
    }
    RAM16_SET(0x0295, value13 | 0x1C00);
    uint16_t value16 = RAM16(0x0287);
    RAM16_SET(0x0297, (uint16_t)(RAM16(0x0297) + RAM16(0x00B4 + value16)));
    uint16_t value19 = RAM16(0x0299);
    uint16_t value20 = RAM16(0x00B6 + value16);
    RAM16_SET(0x0299, (uint16_t)(value19 + value20));
    r->a = (uint16_t)(value19 + value20);
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24E98, SOM_RTS, "gen", derive_body_segment_direction_shape_and_coordinates, 0, L_B, 1, 0, 0, 138, 63)
