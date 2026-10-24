#include "som_c.h"

/* C25612 move_boss_axes_and_reflect_velocity_when_rejected   [class B, 81 bytes, 33 instructions]
 * Source: src/rom/move_boss_axes_and_reflect_velocity_when_rejected.s
 * Documented in docs/boss-native-rebound-landing.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void move_boss_axes_and_reflect_velocity_when_rejected(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x002B + x);
    uint16_t value2 = RAM16(0x003C + x);
    RAM16_SET(0x002B + x, (uint16_t)(value + value2));
    r->a = (uint16_t)(value + value2);
    r->v = ((value ^ (uint16_t)(value + value2)) & (value2 ^ (uint16_t)(value + value2)) & 0x8000) != 0;
    JSR(c, 0x561E, 0xC215B7); /* prepare_boss_object_terrain */
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    uint8_t a_hi2;
    uint16_t x1;
    uint16_t y1;
    if (carry_ret) {
        RAM16_SET(0x002B + x_ret, (uint16_t)(RAM16(0x002B + x_ret) - RAM16(0x003C + x_ret)));
        uint16_t value5 = RAM16(0x003C + x_ret);
        RAM16_SET(0x003C + x_ret, (uint16_t)((value5 ^ 0xFFFF) + 1));
        a_hi2 = (uint16_t)((value5 ^ 0xFFFF) + 1) >> 8;
        x1 = x_ret;
        y1 = y_ret;
    } else {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5623, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        uint8_t a_hi1;
        if (!carry_ret2) {
            a_hi1 = a_all2 >> 8;
        } else {
            RAM16_SET(0x002B + x_ret2, (uint16_t)(RAM16(0x002B + x_ret2) - RAM16(0x003C + x_ret2)));
            uint16_t value8 = RAM16(0x003C + x_ret2);
            RAM16_SET(0x003C + x_ret2, (uint16_t)((value8 ^ 0xFFFF) + 1));
            a_hi1 = (uint16_t)((value8 ^ 0xFFFF) + 1) >> 8;
        }
        a_hi2 = a_hi1;
        x1 = x_ret2;
        y1 = y_ret2;
    }
    uint16_t value9 = RAM16(0x0032 + x1);
    uint16_t value10 = RAM16(0x0040 + x1);
    RAM16_SET(0x0032 + x1, (uint16_t)(value9 + value10));
    r->a = (uint16_t)(value9 + value10);
    r->x = x1;
    r->y = y1;
    r->v = ((value9 ^ (uint16_t)(value9 + value10)) & (value10 ^ (uint16_t)(value9 + value10)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5646, 0xC215B7); /* prepare_boss_object_terrain */
    uint16_t x_ret3 = r->x;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    uint8_t a2;
    uint8_t a_hi4;
    uint16_t x2;
    uint16_t y2;
    bool carry2;
    bool zero2;
    bool negative2;
    bool overflow2;
    if (carry_ret3) {
        uint16_t value11 = RAM16(0x0032 + x_ret3);
        uint16_t value12 = RAM16(0x0040 + x_ret3);
        RAM16_SET(0x0032 + x_ret3, (uint16_t)(value11 - value12));
        uint16_t value13 = RAM16(0x0040 + x_ret3);
        RAM16_SET(0x0040 + x_ret3, (uint16_t)((value13 ^ 0xFFFF) + 1));
        a2 = (uint8_t)((value13 ^ 0xFFFF) + 1);
        a_hi4 = (uint16_t)((value13 ^ 0xFFFF) + 1) >> 8;
        x2 = x_ret3;
        y2 = y_ret3;
        carry2 = value11 >= value12;
        zero2 = (uint16_t)((value13 ^ 0xFFFF) + 1) == 0;
        negative2 = (uint16_t)((value13 ^ 0xFFFF) + 1) & 0x8000;
        overflow2 = ((value11 ^ value12) & (value11 ^ (uint16_t)(value11 - value12)) & 0x8000) != 0;
    } else {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x564B, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
        uint16_t a_all4 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        bool zero_ret4 = r->z;
        bool negative_ret4 = r->n;
        bool overflow_ret4 = r->v;
        uint8_t a1;
        uint8_t a_hi3;
        bool carry1;
        bool zero1;
        bool negative1;
        bool overflow1;
        if (!carry_ret4) {
            a1 = (uint8_t)a_all4;
            a_hi3 = a_all4 >> 8;
            carry1 = carry_ret4;
            zero1 = zero_ret4;
            negative1 = negative_ret4;
            overflow1 = overflow_ret4;
        } else {
            uint16_t value14 = RAM16(0x0032 + x_ret4);
            uint16_t value15 = RAM16(0x0040 + x_ret4);
            RAM16_SET(0x0032 + x_ret4, (uint16_t)(value14 - value15));
            uint16_t value16 = RAM16(0x0040 + x_ret4);
            RAM16_SET(0x0040 + x_ret4, (uint16_t)((value16 ^ 0xFFFF) + 1));
            a1 = (uint8_t)((value16 ^ 0xFFFF) + 1);
            a_hi3 = (uint16_t)((value16 ^ 0xFFFF) + 1) >> 8;
            carry1 = value14 >= value15;
            zero1 = (uint16_t)((value16 ^ 0xFFFF) + 1) == 0;
            negative1 = (uint16_t)((value16 ^ 0xFFFF) + 1) & 0x8000;
            overflow1 = ((value14 ^ value15) & (value14 ^ (uint16_t)(value14 - value15)) & 0x8000) != 0;
        }
        a2 = a1;
        a_hi4 = a_hi3;
        x2 = x_ret4;
        y2 = y_ret4;
        carry2 = carry1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
    }
    r->a = (a_hi4 << 8) | a2;
    r->x = x2;
    r->y = y2;
    r->c = carry2;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25612, SOM_RTS, "gen", move_boss_axes_and_reflect_velocity_when_rejected, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 81, 33)
