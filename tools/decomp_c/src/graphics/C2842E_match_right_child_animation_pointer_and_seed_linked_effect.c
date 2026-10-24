#include "som_c.h"

/* C2842E match_right_child_animation_pointer_and_seed_linked_effect   [class B, 39 bytes, 18 instructions]
 * Source: src/rom/match_right_child_animation_pointer_and_seed_linked_effect.s
 * Documented in docs/boss-native58-linked-effects.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void match_right_child_animation_pointer_and_seed_linked_effect_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x00B0 + x);
    uint16_t value2 = RAM16(0x00A0 + value);
    RAM16_SET(0x0295, value2);
    uint8_t a_hi1 = value2 >> 8;
    uint16_t x1 = 0;
    for (;;) {
        uint16_t value3 = BUS16(c, 0xC2F000 + x1);
        uint16_t value4 = RAM16(0x0295);
        if (value3 == value4) {
            uint16_t value5 = BUS16(c, 0xC2F006 + x1);
            uint16_t value6 = RAM16(0x0287);
            r->a = value5;
            r->x = value6;
            r->y = value;
            r->c = value3 >= value4;
            r->v = overflow;
            JSR(c, 0x8452, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if ((uint16_t)(x1 + 2) != 6) {
            a_hi1 = value3 >> 8;
            x1 = (uint16_t)(x1 + 2);
            continue;
        }
        RETURN_RTS(c);
    }
}

/* C2842E match_right_child_animation_pointer_and_seed_linked_effect   [class B, 39 bytes, 18 instructions]
 * Source: src/rom/match_right_child_animation_pointer_and_seed_linked_effect.s
 * Documented in docs/boss-native58-linked-effects.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void match_right_child_animation_pointer_and_seed_linked_effect_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x00B0 + x);
    RAM8(0x0295) = RAM8(0x00A0 + value);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    for (;;) {
        uint8_t value3 = BUS8(c, 0xC2F000 + x1);
        uint8_t value4 = RAM8(0x0295);
        if (value3 == value4) {
            uint8_t value5 = BUS8(c, 0xC2F006 + x1);
            uint16_t value6 = RAM16(0x0287);
            r->a = (a_hi1 << 8) | value5;
            r->x = value6;
            r->y = value;
            r->c = value3 >= value4;
            r->v = overflow;
            JSR(c, 0x8452, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if ((uint16_t)(x1 + 2) != 6) {
            x1 = (uint16_t)(x1 + 2);
            continue;
        }
        RETURN_RTS(c);
    }
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void match_right_child_animation_pointer_and_seed_linked_effect(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { match_right_child_animation_pointer_and_seed_linked_effect_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { match_right_child_animation_pointer_and_seed_linked_effect_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC2842E, SOM_RTS, "gen", match_right_child_animation_pointer_and_seed_linked_effect, 0, 0, 1, -1, -1, 39, 18)
