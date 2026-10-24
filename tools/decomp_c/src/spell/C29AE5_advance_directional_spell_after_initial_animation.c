#include "som_c.h"

/* C29AE5 advance_directional_spell_after_initial_animation   [class A, 18 bytes, 8 instructions]
 * Source: src/rom/advance_directional_spell_after_initial_animation.s
 * Documented in docs/boss-native-spell-projectile-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_directional_spell_after_initial_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x009E + value);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value2 != 0) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = value;
        y1 = y;
        zero1 = value2 == 0;
        negative1 = value2 & 0x8000;
        overflow1 = overflow;
    } else {
        RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
        RAM16_SET(0x000B + value, 0);
        r->a = value2;
        r->x = value;
        JSR(c, 0x9AF4, 0xC29AF7); /* seed_sixteen_direction_spell_velocity_animation_and_sound */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29AE5, SOM_RTS, "gen", advance_directional_spell_after_initial_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 18, 8)
