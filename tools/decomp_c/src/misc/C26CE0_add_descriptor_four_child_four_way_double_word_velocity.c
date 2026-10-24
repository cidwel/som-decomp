#include "som_c.h"

/* C26CE0 add_descriptor_four_child_four_way_double_word_velocity   [class B, 79 bytes, 33 instructions]
 * Source: src/rom/add_descriptor_four_child_four_way_double_word_velocity.s
 * Documented in docs/boss-descriptor-four-child-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void add_descriptor_four_child_four_way_double_word_velocity(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    r->a = RAM16(0x00A9 + x);
    JSR(c, 0x6CE5, 0xC2091D); /* derive_four_way_direction_to_low_byte_target */
    uint16_t a_all = r->a;
    RAM16_SET(0x00AB + RAM16(0x0287), a_all);
    uint16_t value3 = BUS16(c, 0xDCE400 + (uint16_t)(a_all << 3));
    RAM16_SET(0x0295, value3);
    uint16_t value4 = BUS16(c, 0xDCE402 + (uint16_t)(a_all << 3));
    RAM16_SET(0x0297, value4);
    uint16_t value5 = BUS16(c, 0xDCE404 + (uint16_t)(a_all << 3));
    RAM16_SET(0x0299, value5);
    uint16_t value6 = BUS16(c, 0xDCE406 + (uint16_t)(a_all << 3));
    RAM16_SET(0x029B, value6);
    uint16_t value7 = RAM16(0x0287);
    uint16_t value8 = RAM16(0x003A + value7);
    uint16_t value9 = RAM16(0x0295);
    RAM16_SET(0x003A + value7, (uint16_t)(value8 + value9));
    RAM16_SET(0x003C + value7, (uint16_t)(RAM16(0x003C + value7) + RAM16(0x0297) + (value8 + value9 > 0xFFFF)));
    uint16_t value12 = RAM16(0x003E + value7);
    uint16_t value13 = RAM16(0x0299);
    RAM16_SET(0x003E + value7, (uint16_t)(value12 + value13));
    uint16_t value14 = RAM16(0x0040 + value7);
    uint16_t value15 = RAM16(0x029B);
    RAM16_SET(0x0040 + value7, (uint16_t)(value14 + value15 + (value12 + value13 > 0xFFFF)));
    r->a = (uint16_t)(value14 + value15 + (value12 + value13 > 0xFFFF));
    r->x = value7;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6D2D, 0xC236BC); /* move_boss_axes_with_rejected_axis_sliding */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26CE0, SOM_RTS, "gen", add_descriptor_four_child_four_way_double_word_velocity, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 79, 33)
