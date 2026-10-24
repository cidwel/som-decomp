#include "som_c.h"

/* C214AA move_boss_from_animation_signed_offsets_with_collision_sliding   [class B, 129 bytes, 62 instructions]
 * Source: src/rom/move_boss_from_animation_signed_offsets_with_collision_sliding.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void move_boss_from_animation_signed_offsets_with_collision_sliding(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM8(0x0269) = 0;
    RAM8(0x026B) = 0;
    uint16_t value = RAM16(0x0287);
    uint8_t value2;
    BUS8_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + y, value2);
    RAM8(0x0268) = value2;
    if ((RAM8(0x0098 + value) & 0x40) != 0) {
        RAM8(0x0268) = (uint8_t)((RAM8(0x0268) ^ 0xFF) + 1);
    }
    uint8_t value5;
    BUS8_OK(c, (RAM8(0x0278) << 0x10) + RAM16(0x0276) + (uint16_t)(y + 1), value5);
    RAM8(0x026A) = value5;
    if ((RAM8(0x0098 + value) & 0x80) != 0) {
        RAM8(0x026A) = (uint8_t)((RAM8(0x026A) ^ 0xFF) + 1);
    }
    if (RAM8(0x0268) & 0x80) {
        RAM8(0x0269) = 0xFF;
    }
    if (RAM8(0x026A) & 0x80) {
        RAM8(0x026B) = 0xFF;
    }
    uint16_t value10 = RAM16(0x0268);
    uint16_t value11 = RAM16(0x002B + value);
    RAM16_SET(0x002B + value, (uint16_t)(value10 + value11));
    r->a = (uint16_t)(value10 + value11);
    r->x = value;
    r->y = (uint16_t)(y + 2);
    r->v = ((value10 ^ (uint16_t)(value10 + value11)) & (value11 ^ (uint16_t)(value10 + value11)) & 0x8000) != 0;
    r->sp -= 2;
    JSR(c, 0x14F6, 0xC215B7); /* prepare_boss_object_terrain */
    r->sp += 2;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    if (carry_ret) {
        uint16_t value12 = RAM16(0x002B + x_ret);
        uint16_t value13 = RAM16(0x0268);
        RAM16_SET(0x002B + x_ret, (uint16_t)(value12 - value13));
        r->a = (uint16_t)(value12 - value13);
        r->mf = 0;
        r->xf = 0;
        r->sp -= 2;
        JSR(c, 0x1509, 0xC2152B); /* slide_boss_vertical_two_pixels_after_horizontal_rejection */
        r->sp += 2;
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        a_hi2 = a_all2 >> 8;
        x2 = x_ret2;
        y2 = y_ret2;
    } else {
        r->mf = 0;
        r->xf = 0;
        r->sp -= 2;
        JSR(c, 0x14FB, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
        r->sp += 2;
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
            uint16_t value14 = RAM16(0x002B + x_ret3);
            uint16_t value15 = RAM16(0x0268);
            RAM16_SET(0x002B + x_ret3, (uint16_t)(value14 - value15));
            r->a = (uint16_t)(value14 - value15);
            r->mf = 0;
            r->xf = 0;
            r->sp -= 2;
            JSR(c, 0x1509, 0xC2152B); /* slide_boss_vertical_two_pixels_after_horizontal_rejection */
            r->sp += 2;
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
    uint16_t value16 = RAM16(0x026A);
    uint16_t value17 = RAM16(0x0032 + x2);
    RAM16_SET(0x0032 + x2, (uint16_t)(value16 + value17));
    r->a = (uint16_t)(value16 + value17);
    r->x = x2;
    r->y = y2;
    r->v = ((value16 ^ (uint16_t)(value16 + value17)) & (value17 ^ (uint16_t)(value16 + value17)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 2;
    JSR(c, 0x1515, 0xC215B7); /* prepare_boss_object_terrain */
    r->sp += 2;
    uint16_t x_ret5 = r->x;
    bool carry_ret5 = r->c;
    uint8_t a2;
    uint8_t a_hi4;
    uint16_t x4;
    bool carry2;
    bool overflow2;
    if (carry_ret5) {
        uint16_t value18 = RAM16(0x0032 + x_ret5);
        uint16_t value19 = RAM16(0x026A);
        RAM16_SET(0x0032 + x_ret5, (uint16_t)(value18 - value19));
        r->a = (uint16_t)(value18 - value19);
        r->mf = 0;
        r->xf = 0;
        r->sp -= 2;
        JSR(c, 0x1528, 0xC21571); /* slide_boss_horizontal_two_pixels_after_vertical_rejection */
        r->sp += 2;
        uint16_t a_all6 = r->a;
        uint16_t x_ret6 = r->x;
        bool carry_ret6 = r->c;
        bool overflow_ret6 = r->v;
        a2 = (uint8_t)a_all6;
        a_hi4 = a_all6 >> 8;
        x4 = x_ret6;
        carry2 = carry_ret6;
        overflow2 = overflow_ret6;
    } else {
        r->mf = 0;
        r->xf = 0;
        r->sp -= 2;
        JSR(c, 0x151A, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
        r->sp += 2;
        uint16_t a_all7 = r->a;
        uint16_t x_ret7 = r->x;
        bool carry_ret7 = r->c;
        bool overflow_ret7 = r->v;
        uint8_t a1;
        uint8_t a_hi3;
        uint16_t x3;
        bool carry1;
        bool overflow1;
        if (!carry_ret7) {
            a1 = (uint8_t)a_all7;
            a_hi3 = a_all7 >> 8;
            x3 = x_ret7;
            carry1 = carry_ret7;
            overflow1 = overflow_ret7;
        } else {
            uint16_t value20 = RAM16(0x0032 + x_ret7);
            uint16_t value21 = RAM16(0x026A);
            RAM16_SET(0x0032 + x_ret7, (uint16_t)(value20 - value21));
            r->a = (uint16_t)(value20 - value21);
            r->mf = 0;
            r->xf = 0;
            r->sp -= 2;
            JSR(c, 0x1528, 0xC21571); /* slide_boss_horizontal_two_pixels_after_vertical_rejection */
            r->sp += 2;
            uint16_t a_all8 = r->a;
            uint16_t x_ret8 = r->x;
            bool carry_ret8 = r->c;
            bool overflow_ret8 = r->v;
            a1 = (uint8_t)a_all8;
            a_hi3 = a_all8 >> 8;
            x3 = x_ret8;
            carry1 = carry_ret8;
            overflow1 = overflow_ret8;
        }
        a2 = a1;
        a_hi4 = a_hi3;
        x4 = x3;
        carry2 = carry1;
        overflow2 = overflow1;
    }
    r->a = (a_hi4 << 8) | a2;
    r->x = x4;
    r->y = (uint16_t)(y + 2);
    r->c = carry2;
    r->z = (uint16_t)(y + 2) == 0;
    r->n = (uint16_t)(y + 2) & 0x8000;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC214AA, SOM_RTS, "hand", move_boss_from_animation_signed_offsets_with_collision_sliding, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 129, 62)
