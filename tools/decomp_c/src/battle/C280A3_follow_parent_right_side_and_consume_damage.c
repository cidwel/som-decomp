#include "som_c.h"

/* C280A3 follow_parent_right_side_and_consume_damage   [class B, 54 bytes, 23 instructions]
 * Source: src/rom/follow_parent_right_side_and_consume_damage.s
 * Documented in docs/boss-native58-right-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void follow_parent_right_side_and_consume_damage(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B0 + value);
    uint16_t value3 = RAM16(OBJECT_PHASE + value2);
    if (value3 == 6) {
        r->a = value3;
        r->x = value;
        r->y = value2;
        r->c = 1;
        r->z = value3 == 6;
        r->n = (uint16_t)(value3 - 6) & 0x8000;
        RETURN_RTS(c);
    }
    r->a = value3;
    r->x = value;
    r->y = value2;
    r->c = value3 >= 6;
    JSR(c, 0x80B2, 0xC27FE5); /* consume_child_action_damage_and_publish_hurt_animation */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (carry_ret) {
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow;
    } else {
        RAM16_SET(0x002B + x_ret, (uint16_t)(RAM16(0x002B + value2) + 0x40));
        uint16_t value5 = RAM16(0x0032 + value2);
        RAM16_SET(0x0032 + x_ret, (uint16_t)(value5 + 0x10));
        RAM16_SET(0x00A9 + x_ret, RAM16(0x00A9 + value2));
        uint16_t value7 = RAM16(0x00AB + value2);
        RAM16_SET(0x00AB + x_ret, value7);
        a1 = (uint8_t)value7;
        a_hi1 = value7 >> 8;
        zero1 = value7 == 0;
        negative1 = value7 & 0x8000;
        overflow1 = ((value5 ^ (uint16_t)(value5 + 0x10)) & ((uint16_t)(value5 + 0x10) ^ 0x10) & 0x8000) != 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC280A3, SOM_RTS, "gen", follow_parent_right_side_and_consume_damage, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 54, 23)
