#include "som_c.h"

/* C236FF move_boss_fractional_axes_with_terrain_party_rejection_and_sliding   [class B, 103 bytes, 39 instructions]
 * Source: src/rom/move_boss_fractional_axes_with_terrain_party_rejection_and_sliding.s
 * Documented in docs/boss-descriptor-eleven-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void move_boss_fractional_axes_with_terrain_party_rejection_and_sliding(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0029 + x);
    uint16_t value2 = RAM16(0x003A + x);
    RAM16_SET(0x0029 + x, (uint16_t)(value + value2));
    uint16_t value3 = RAM16(0x002B + x);
    uint16_t value4 = RAM16(0x003C + x);
    RAM16_SET(0x002B + x, (uint16_t)(value3 + value4 + (value + value2 > 0xFFFF)));
    r->a = (uint16_t)(value3 + value4 + (value + value2 > 0xFFFF));
    r->v = ((value3 ^ (uint16_t)(value3 + value4 + (value + value2 > 0xFFFF))) & (value4 ^ (uint16_t)(value3 + value4 + (value + value2 > 0xFFFF))) & 0x8000) != 0;
    JSR(c, 0x3714, 0xC215B7); /* prepare_boss_object_terrain */
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    if (carry_ret) {
        uint16_t value5 = RAM16(0x0029 + x_ret);
        uint16_t value6 = RAM16(0x003A + x_ret);
        RAM16_SET(0x0029 + x_ret, (uint16_t)(value5 - value6));
        uint16_t value7 = RAM16(0x002B + x_ret);
        uint16_t value8 = RAM16(0x003C + x_ret);
        RAM16_SET(0x002B + x_ret, (uint16_t)(value7 - value8 - (value5 >= value6 ^ 1)));
        r->a = (uint16_t)(value7 - value8 - (value5 >= value6 ^ 1));
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3731, 0xC2152B); /* slide_boss_vertical_two_pixels_after_horizontal_rejection */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        a_hi2 = a_all2 >> 8;
        x2 = x_ret2;
        y2 = y_ret2;
    } else {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3719, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
        uint16_t a_all3 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        if (!carry_ret3) {
            a_hi1 = a_all3 >> 8;
            x1 = x_ret3;
            y1 = y_ret3;
        } else {
            uint16_t value9 = RAM16(0x0029 + x_ret3);
            uint16_t value10 = RAM16(0x003A + x_ret3);
            RAM16_SET(0x0029 + x_ret3, (uint16_t)(value9 - value10));
            uint16_t value11 = RAM16(0x002B + x_ret3);
            uint16_t value12 = RAM16(0x003C + x_ret3);
            RAM16_SET(0x002B + x_ret3, (uint16_t)(value11 - value12 - (value9 >= value10 ^ 1)));
            r->a = (uint16_t)(value11 - value12 - (value9 >= value10 ^ 1));
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x3731, 0xC2152B); /* slide_boss_vertical_two_pixels_after_horizontal_rejection */
            uint16_t a_all4 = r->a;
            uint16_t x_ret4 = r->x;
            uint16_t y_ret4 = r->y;
            a_hi1 = a_all4 >> 8;
            x1 = x_ret4;
            y1 = y_ret4;
        }
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
    }
    uint16_t value13 = RAM16(0x0030 + x2);
    uint16_t value14 = RAM16(0x003E + x2);
    RAM16_SET(0x0030 + x2, (uint16_t)(value13 + value14));
    uint16_t value15 = RAM16(0x0032 + x2);
    uint16_t value16 = RAM16(0x0040 + x2);
    RAM16_SET(0x0032 + x2, (uint16_t)(value15 + value16 + (value13 + value14 > 0xFFFF)));
    r->a = (uint16_t)(value15 + value16 + (value13 + value14 > 0xFFFF));
    r->x = x2;
    r->y = y2;
    r->v = ((value15 ^ (uint16_t)(value15 + value16 + (value13 + value14 > 0xFFFF))) & (value16 ^ (uint16_t)(value15 + value16 + (value13 + value14 > 0xFFFF))) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x3747, 0xC215B7); /* prepare_boss_object_terrain */
    uint16_t x_ret5 = r->x;
    bool carry_ret5 = r->c;
    if (carry_ret5) {
        uint16_t value17 = RAM16(0x0030 + x_ret5);
        uint16_t value18 = RAM16(0x003E + x_ret5);
        RAM16_SET(0x0030 + x_ret5, (uint16_t)(value17 - value18));
        uint16_t value19 = RAM16(0x0032 + x_ret5);
        uint16_t value20 = RAM16(0x0040 + x_ret5);
        RAM16_SET(0x0032 + x_ret5, (uint16_t)(value19 - value20 - (value17 >= value18 ^ 1)));
        r->a = (uint16_t)(value19 - value20 - (value17 >= value18 ^ 1));
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x3764, 0xC21571); /* slide_boss_horizontal_two_pixels_after_vertical_rejection */
    } else {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x374C, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
        uint16_t x_ret7 = r->x;
        bool carry_ret7 = r->c;
        if (carry_ret7) {
            uint16_t value21 = RAM16(0x0030 + x_ret7);
            uint16_t value22 = RAM16(0x003E + x_ret7);
            RAM16_SET(0x0030 + x_ret7, (uint16_t)(value21 - value22));
            uint16_t value23 = RAM16(0x0032 + x_ret7);
            uint16_t value24 = RAM16(0x0040 + x_ret7);
            RAM16_SET(0x0032 + x_ret7, (uint16_t)(value23 - value24 - (value21 >= value22 ^ 1)));
            r->a = (uint16_t)(value23 - value24 - (value21 >= value22 ^ 1));
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x3764, 0xC21571); /* slide_boss_horizontal_two_pixels_after_vertical_rejection */
        }
    }
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC236FF, SOM_RTS, "gen", move_boss_fractional_axes_with_terrain_party_rejection_and_sliding, 0, 0, 1, 0, 0, 103, 39)
