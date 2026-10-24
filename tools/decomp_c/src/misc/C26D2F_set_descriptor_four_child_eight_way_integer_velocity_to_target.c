#include "som_c.h"

/* C26D2F set_descriptor_four_child_eight_way_integer_velocity_to_target   [class B, 64 bytes, 29 instructions]
 * Source: src/rom/set_descriptor_four_child_eight_way_integer_velocity_to_target.s
 * Documented in docs/boss-descriptor-four-child-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void set_descriptor_four_child_eight_way_integer_velocity_to_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00A9 + x);
    RAM16_SET(0x0246, RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)));
    RAM16_SET(0x024E, RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)));
    RAM16_SET(0x0256, RAM16(0x002B + x));
    uint16_t value5 = RAM16(0x0032 + x);
    RAM16_SET(0x025E, value5);
    r->a = value5;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->v = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    JSR(c, 0x6D4F, 0xC22E50); /* derive_eight_way_direction_from_coordinate_pairs */
    uint16_t a_all = r->a;
    uint16_t value6 = BUS16(c, 0xDCE420 + (uint16_t)(a_all << 2));
    RAM16_SET(0x0295, value6);
    uint16_t value7 = BUS16(c, 0xDCE422 + (uint16_t)(a_all << 2));
    RAM16_SET(0x0297, value7);
    uint16_t value8 = RAM16(0x0287);
    RAM16_SET(0x003C + value8, RAM16(0x0295));
    uint16_t value10 = RAM16(0x0297);
    RAM16_SET(0x0040 + value8, value10);
    r->a = value10;
    r->x = value8;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6D6D, 0xC236BC); /* move_boss_axes_with_rejected_axis_sliding */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26D2F, SOM_RTS, "gen", set_descriptor_four_child_eight_way_integer_velocity_to_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 64, 29)
