#include "som_c.h"

/* C236BC move_boss_axes_with_rejected_axis_sliding   [class B, 67 bytes, 27 instructions]
 * Source: src/rom/move_boss_axes_with_rejected_axis_sliding.s
 * Documented in docs/boss-native-rebound-landing.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void move_boss_axes_with_rejected_axis_sliding(SomCtx *c)
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
    JSR(c, 0x36C8, 0xC215B7); /* prepare_boss_object_terrain */
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    if (carry_ret) {
        uint16_t value3 = RAM16(0x002B + x_ret);
        uint16_t value4 = RAM16(0x003C + x_ret);
        RAM16_SET(0x002B + x_ret, (uint16_t)(value3 - value4));
        r->a = (uint16_t)(value3 - value4);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x36DC, 0xC2152B); /* slide_boss_vertical_two_pixels_after_horizontal_rejection */
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        a_hi2 = a_all2 >> 8;
        x2 = x_ret2;
        y2 = y_ret2;
    } else {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x36CD, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
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
            uint16_t value5 = RAM16(0x002B + x_ret3);
            uint16_t value6 = RAM16(0x003C + x_ret3);
            RAM16_SET(0x002B + x_ret3, (uint16_t)(value5 - value6));
            r->a = (uint16_t)(value5 - value6);
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x36DC, 0xC2152B); /* slide_boss_vertical_two_pixels_after_horizontal_rejection */
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
    uint16_t value7 = RAM16(0x0032 + x2);
    uint16_t value8 = RAM16(0x0040 + x2);
    RAM16_SET(0x0032 + x2, (uint16_t)(value7 + value8));
    r->a = (uint16_t)(value7 + value8);
    r->x = x2;
    r->y = y2;
    r->v = ((value7 ^ (uint16_t)(value7 + value8)) & (value8 ^ (uint16_t)(value7 + value8)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x36E9, 0xC215B7); /* prepare_boss_object_terrain */
    uint16_t x_ret5 = r->x;
    bool carry_ret5 = r->c;
    if (carry_ret5) {
        uint16_t value9 = RAM16(0x0032 + x_ret5);
        uint16_t value10 = RAM16(0x0040 + x_ret5);
        RAM16_SET(0x0032 + x_ret5, (uint16_t)(value9 - value10));
        r->a = (uint16_t)(value9 - value10);
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x36FD, 0xC21571); /* slide_boss_horizontal_two_pixels_after_vertical_rejection */
    } else {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x36EE, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
        uint16_t x_ret7 = r->x;
        bool carry_ret7 = r->c;
        if (carry_ret7) {
            uint16_t value11 = RAM16(0x0032 + x_ret7);
            uint16_t value12 = RAM16(0x0040 + x_ret7);
            RAM16_SET(0x0032 + x_ret7, (uint16_t)(value11 - value12));
            r->a = (uint16_t)(value11 - value12);
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x36FD, 0xC21571); /* slide_boss_horizontal_two_pixels_after_vertical_rejection */
        }
    }
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC236BC, SOM_RTS, "gen", move_boss_axes_with_rejected_axis_sliding, 0, 0, 1, 0, 0, 67, 27)
