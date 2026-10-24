#include "som_c.h"

/* C20A47 move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding   [class B, 83 bytes, 34 instructions]
 * Source: src/rom/move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding.s
 * Documented in docs/boss-native54-projectiles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: X.
 */
static void move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM16_SET(0x02C3, a);
    uint16_t value = RAM16(0x002B + x);
    uint16_t value2 = RAM16(0x003C + x);
    RAM16_SET(0x002B + x, (uint16_t)(value + value2));
    r->a = (uint16_t)(value + value2);
    r->v = ((value ^ (uint16_t)(value + value2)) & (value2 ^ (uint16_t)(value + value2)) & 0x8000) != 0;
    JSR(c, 0x0A55, 0xC215B7); /* prepare_boss_object_terrain */
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    uint8_t a_hi4;
    uint16_t x4;
    uint16_t y4;
    if (carry_ret) {
        RAM16_SET(0x002B + x_ret, (uint16_t)(RAM16(0x002B + x_ret) - RAM16(0x003C + x_ret)));
        uint16_t value5 = RAM16(0x02C3);
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        if ((value5 & 1) != 0) {
            a_hi1 = value5 >> 8;
            x1 = x_ret;
            y1 = y_ret;
        } else {
            r->a = value5;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x0A70, 0xC2152B); /* slide_boss_vertical_two_pixels_after_horizontal_rejection */
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            a_hi1 = a_all2 >> 8;
            x1 = x_ret2;
            y1 = y_ret2;
        }
        a_hi4 = a_hi1;
        x4 = x1;
        y4 = y1;
    } else {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x0A5A, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
        uint16_t a_all3 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        uint8_t a_hi3;
        uint16_t x3;
        uint16_t y3;
        if (!carry_ret3) {
            a_hi3 = a_all3 >> 8;
            x3 = x_ret3;
            y3 = y_ret3;
        } else {
            RAM16_SET(0x002B + x_ret3, (uint16_t)(RAM16(0x002B + x_ret3) - RAM16(0x003C + x_ret3)));
            uint16_t value8 = RAM16(0x02C3);
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            if ((value8 & 1) != 0) {
                a_hi2 = value8 >> 8;
                x2 = x_ret3;
                y2 = y_ret3;
            } else {
                r->a = value8;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x0A70, 0xC2152B); /* slide_boss_vertical_two_pixels_after_horizontal_rejection */
                uint16_t a_all4 = r->a;
                uint16_t x_ret4 = r->x;
                uint16_t y_ret4 = r->y;
                a_hi2 = a_all4 >> 8;
                x2 = x_ret4;
                y2 = y_ret4;
            }
            a_hi3 = a_hi2;
            x3 = x2;
            y3 = y2;
        }
        a_hi4 = a_hi3;
        x4 = x3;
        y4 = y3;
    }
    uint16_t value9 = RAM16(0x0032 + x4);
    uint16_t value10 = RAM16(0x0040 + x4);
    RAM16_SET(0x0032 + x4, (uint16_t)(value9 + value10));
    r->a = (uint16_t)(value9 + value10);
    r->x = x4;
    r->y = y4;
    r->v = ((value9 ^ (uint16_t)(value9 + value10)) & (value10 ^ (uint16_t)(value9 + value10)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x0A7D, 0xC215B7); /* prepare_boss_object_terrain */
    uint16_t x_ret5 = r->x;
    bool carry_ret5 = r->c;
    uint16_t x8;
    if (carry_ret5) {
        RAM16_SET(0x0032 + x_ret5, (uint16_t)(RAM16(0x0032 + x_ret5) - RAM16(0x0040 + x_ret5)));
        uint16_t value13 = RAM16(0x02C3);
        uint16_t x5;
        if ((value13 & 1) != 0) {
            x5 = x_ret5;
        } else {
            r->a = value13;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x0A98, 0xC21571); /* slide_boss_horizontal_two_pixels_after_vertical_rejection */
            uint16_t x_ret6 = r->x;
            x5 = x_ret6;
        }
        x8 = x5;
    } else {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x0A82, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
        uint16_t x_ret7 = r->x;
        bool carry_ret7 = r->c;
        uint16_t x7;
        if (!carry_ret7) {
            x7 = x_ret7;
        } else {
            RAM16_SET(0x0032 + x_ret7, (uint16_t)(RAM16(0x0032 + x_ret7) - RAM16(0x0040 + x_ret7)));
            uint16_t value16 = RAM16(0x02C3);
            uint16_t x6;
            if ((value16 & 1) != 0) {
                x6 = x_ret7;
            } else {
                r->a = value16;
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x0A98, 0xC21571); /* slide_boss_horizontal_two_pixels_after_vertical_rejection */
                uint16_t x_ret8 = r->x;
                x6 = x_ret8;
            }
            x7 = x6;
        }
        x8 = x7;
    }
    r->x = x8;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20A47, SOM_RTS, "gen", move_boss_integer_axes_with_terrain_party_rejection_and_optional_sliding, 0, L_X, 1, 0, 0, 83, 34)
