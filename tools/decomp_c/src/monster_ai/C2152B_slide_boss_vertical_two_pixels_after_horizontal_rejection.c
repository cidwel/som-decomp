#include "som_c.h"

/* C2152B slide_boss_vertical_two_pixels_after_horizontal_rejection   [class B, 70 bytes, 29 instructions]
 * Source: src/rom/slide_boss_vertical_two_pixels_after_horizontal_rejection.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXY.
 */
static void slide_boss_vertical_two_pixels_after_horizontal_rejection(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    if ((RAM16(0x004E + x) & 2) != 0) {
        uint16_t value2 = RAM16(0x0032 + x);
        RAM16_SET(0x0032 + x, (uint16_t)(value2 + 0xFFFE));
        r->a = (uint16_t)(value2 + 0xFFFE);
        r->v = ((value2 ^ (uint16_t)(value2 + 0xFFFE)) & ((uint16_t)(value2 + 0xFFFE) ^ 0xFFFE) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x155E, 0xC215B7); GUARD_JSR(c, sp_call, 0x155E); } /* prepare_boss_object_terrain */
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        uint8_t a_hi2;
        uint16_t x1;
        uint16_t y1;
        if (carry_ret) {
            uint16_t value3 = RAM16(0x0032 + x_ret);
            RAM16_SET(0x0032 + x_ret, (uint16_t)(value3 - 0xFFFE));
            a_hi2 = (uint16_t)(value3 - 0xFFFE) >> 8;
            x1 = x_ret;
            y1 = y_ret;
        } else {
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1563, 0xC21723); GUARD_JSR(c, sp_call, 0x1563); } /* test_animation_movement_against_three_active_party_actors */
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            uint8_t a_hi1;
            if (!carry_ret2) {
                a_hi1 = a_all2 >> 8;
            } else {
                uint16_t value4 = RAM16(0x0032 + x_ret2);
                RAM16_SET(0x0032 + x_ret2, (uint16_t)(value4 - 0xFFFE));
                a_hi1 = (uint16_t)(value4 - 0xFFFE) >> 8;
            }
            a_hi2 = a_hi1;
            x1 = x_ret2;
            y1 = y_ret2;
        }
        r->a = (a_hi2 << 8) | (uint8_t)a;
        r->x = x1;
        r->y = y1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value5 = RAM16(0x0032 + x);
    RAM16_SET(0x0032 + x, (uint16_t)(value5 + 2));
    r->a = (uint16_t)(value5 + 2);
    r->v = ((value5 ^ (uint16_t)(value5 + 2)) & ((uint16_t)(value5 + 2) ^ 2) & 0x8000) != 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x153F, 0xC215B7); GUARD_JSR(c, sp_call, 0x153F); } /* prepare_boss_object_terrain */
    uint16_t x_ret3 = r->x;
    uint16_t y_ret3 = r->y;
    bool carry_ret3 = r->c;
    uint8_t a_hi4;
    uint16_t x2;
    uint16_t y2;
    if (carry_ret3) {
        uint16_t value6 = RAM16(0x0032 + x_ret3);
        RAM16_SET(0x0032 + x_ret3, (uint16_t)(value6 - 2));
        a_hi4 = (uint16_t)(value6 - 2) >> 8;
        x2 = x_ret3;
        y2 = y_ret3;
    } else {
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1544, 0xC21723); GUARD_JSR(c, sp_call, 0x1544); } /* test_animation_movement_against_three_active_party_actors */
        uint16_t a_all4 = r->a;
        uint16_t x_ret4 = r->x;
        uint16_t y_ret4 = r->y;
        bool carry_ret4 = r->c;
        uint8_t a_hi3;
        if (!carry_ret4) {
            a_hi3 = a_all4 >> 8;
        } else {
            uint16_t value7 = RAM16(0x0032 + x_ret4);
            RAM16_SET(0x0032 + x_ret4, (uint16_t)(value7 - 2));
            a_hi3 = (uint16_t)(value7 - 2) >> 8;
        }
        a_hi4 = a_hi3;
        x2 = x_ret4;
        y2 = y_ret4;
    }
    r->a = (a_hi4 << 8) | (uint8_t)a;
    r->x = x2;
    r->y = y2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2152B, SOM_RTS, "gen", slide_boss_vertical_two_pixels_after_horizontal_rejection, 0, L_B | L_X | L_Y, 1, 0, 0, 70, 29)
