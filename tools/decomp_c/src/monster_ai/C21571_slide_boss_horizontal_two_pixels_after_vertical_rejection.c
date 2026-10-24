#include "som_c.h"

/* C21571 slide_boss_horizontal_two_pixels_after_vertical_rejection   [class B, 70 bytes, 29 instructions]
 * Source: src/rom/slide_boss_horizontal_two_pixels_after_vertical_rejection.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: X.
 */
static void slide_boss_horizontal_two_pixels_after_vertical_rejection(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if ((RAM16(0x004E + x) & 1) != 0) {
        uint16_t value2 = RAM16(0x002B + x);
        RAM16_SET(0x002B + x, (uint16_t)(value2 + 0xFFFE));
        r->a = (uint16_t)(value2 + 0xFFFE);
        r->v = ((value2 ^ (uint16_t)(value2 + 0xFFFE)) & ((uint16_t)(value2 + 0xFFFE) ^ 0xFFFE) & 0x8000) != 0;
        JSR(c, 0x15A4, 0xC215B7); /* prepare_boss_object_terrain */
        uint16_t x_ret = r->x;
        bool carry_ret = r->c;
        uint16_t x1;
        if (carry_ret) {
            RAM16_SET(0x002B + x_ret, (uint16_t)(RAM16(0x002B + x_ret) - 0xFFFE));
            x1 = x_ret;
        } else {
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x15A9, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
            uint16_t x_ret2 = r->x;
            bool carry_ret2 = r->c;
            if (carry_ret2) {
                RAM16_SET(0x002B + x_ret2, (uint16_t)(RAM16(0x002B + x_ret2) - 0xFFFE));
            }
            x1 = x_ret2;
        }
        r->x = x1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value5 = RAM16(0x002B + x);
    RAM16_SET(0x002B + x, (uint16_t)(value5 + 2));
    r->a = (uint16_t)(value5 + 2);
    r->v = ((value5 ^ (uint16_t)(value5 + 2)) & ((uint16_t)(value5 + 2) ^ 2) & 0x8000) != 0;
    JSR(c, 0x1585, 0xC215B7); /* prepare_boss_object_terrain */
    uint16_t x_ret3 = r->x;
    bool carry_ret3 = r->c;
    uint16_t x2;
    if (carry_ret3) {
        RAM16_SET(0x002B + x_ret3, (uint16_t)(RAM16(0x002B + x_ret3) - 2));
        x2 = x_ret3;
    } else {
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x158A, 0xC21723); /* test_animation_movement_against_three_active_party_actors */
        uint16_t x_ret4 = r->x;
        bool carry_ret4 = r->c;
        if (carry_ret4) {
            RAM16_SET(0x002B + x_ret4, (uint16_t)(RAM16(0x002B + x_ret4) - 2));
        }
        x2 = x_ret4;
    }
    r->x = x2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC21571, SOM_RTS, "gen", slide_boss_horizontal_two_pixels_after_vertical_rejection, 0, L_X, 1, 0, 0, 70, 29)
