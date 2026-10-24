#include "som_c.h"
#include "som_hand_b.h"

/* C29AAF seed_follow_spell_animation_sound_position_and_control   [class B, 34 bytes, 14 instructions]
 * Source: src/rom/seed_follow_spell_animation_sound_position_and_control.s
 * Documented in docs/boss-native-spell-follow-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void seed_follow_spell_animation_sound_position_and_control(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t x = RAM16(0x0287);
    uint16_t animation = RAM16(0x00B4 + x);
    r->c = animation >> 15; /* ASL */
    uint16_t table = (uint16_t)(animation << 1);
    r->a = BUS16(c, 0xDCE73D + table);
    hand_nz16(r, r->a);
    r->x = RAM16(0x0287);
    JSR_CHK(c, 0x9ABE, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    JSR_CHK(c, 0x9AC1, 0xC29AD1); /* request_follow_spell_target_sound */
    JSR_CHK(c, 0x9AC4, 0xC2993D); /* follow_spell_target_integer_position */
    /* The accumulator width after the calls comes from the callee. */
    if (r->mf) {
        uint8_t value = RAM8(0x00B6 + r->x);
        r->a = (r->a & 0xFF00) | value;
        hand_nz8(r, value);
        RAM8(0x00BC + r->x) = value;
    } else {
        uint16_t value = RAM16(0x00B6 + r->x);
        r->a = value;
        hand_nz16(r, value);
        RAM16_SET(0x00BC + r->x, value);
    }
    JSR_CHK(c, 0x9ACD, 0xC298F6); /* mark_eligible_spell_target_control19 */
    if (r->xf) { r->x = RAM8(0x0287); hand_nz8(r, (uint8_t)r->x); } /* LDX $87 in the callee's index width */
    else { r->x = RAM16(0x0287); hand_nz16(r, r->x); }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29AAF, SOM_RTS, "hand", seed_follow_spell_animation_sound_position_and_control, 0, 0, 1, 0, 0, 34, 14)
