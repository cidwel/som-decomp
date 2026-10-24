#include "som_c.h"

/* C24DDE grow_body_auxiliary_segment_and_publish_collision_geometry   [class B, 87 bytes, 40 instructions]
 * Source: src/rom/grow_body_auxiliary_segment_and_publish_collision_geometry.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void grow_body_auxiliary_segment_and_publish_collision_geometry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B8 + x);
    r->y = value;
    JSR(c, 0x4DE3, 0xC24E35); /* replace_previous_body_segment_shape */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x4DE6, 0xC24E4F); /* advance_body_velocity_by_segment_shape_and_flip_bits */
    r->mf = 0;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x4DEA, 0xC24E98); /* derive_body_segment_direction_shape_and_coordinates */
    r->sp += 2;
    uint16_t value2 = RAM16(0x028B);
    RAM16_SET(0xF800 + ((((uint8_t)value2 << 8) | (value2 >> 8)) >> 1), (uint16_t)(RAM16(0xF800 + ((((uint8_t)value2 << 8) | (value2 >> 8)) >> 1)) + 1));
    RAM8(0xF804 + ((((uint8_t)value2 << 8) | (value2 >> 8)) >> 1)) ^= 0x40;
    RAM8(0x0002 + value) = RAM8(0x0297);
    RAM8(0x0003 + value) = RAM8(0x0299);
    uint16_t value6 = RAM16(0x0287);
    RAM8(0x00C0 + value6) = (uint8_t)(RAM8(0x0297) + 8);
    RAM8(0x00C1 + value6) = (uint8_t)(RAM8(0x0299) + 8);
    RAM8(0x00C2 + value6) = 2;
    RAM8(0x00C3 + value6) = 2;
    RAM16_SET(0x0004 + value, RAM16(0x0295));
    RAM16_SET(0x00B8 + value6, (uint16_t)(value + 4));
    RAM16_SET(0x00B2 + value6, (uint16_t)(RAM16(0x00B2 + value6) + 1));
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24DDE, SOM_RTS, "gen", grow_body_auxiliary_segment_and_publish_collision_geometry, 0, 0, 2, 0, 0, 87, 40)
