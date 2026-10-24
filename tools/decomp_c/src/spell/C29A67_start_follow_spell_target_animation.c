#include "som_c.h"

/* C29A67 start_follow_spell_target_animation   [class A, 13 bytes, 5 instructions]
 * Source: src/rom/start_follow_spell_target_animation.s
 * Documented in docs/boss-native-spell-follow-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void start_follow_spell_target_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x00B8 + x, (uint16_t)(RAM16(0x00B8 + x) + 1));
    RAM16_SET(OBJECT_AGE + x, 0);
    JSR(c, 0x9A6F, 0xC298DA); /* activate_spell_child_and_clear_fractional_height */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A72, 0xC29AAF); /* seed_follow_spell_animation_sound_position_and_control */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29A67, SOM_RTS, "gen", start_follow_spell_target_animation, 0, 0, 1, 0, 0, 13, 5)
