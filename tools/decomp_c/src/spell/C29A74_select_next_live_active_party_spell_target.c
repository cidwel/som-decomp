#include "som_c.h"

/* C29A74 select_next_live_active_party_spell_target   [class B, 59 bytes, 27 instructions]
 * Source: src/rom/select_next_live_active_party_spell_target.s
 * Documented in docs/boss-native-spell-follow-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void select_next_live_active_party_spell_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    uint8_t a_hi1 = a >> 8;
    for (;;) {
        uint16_t value = RAM16(0x0287);
        uint16_t value2 = RAM16(0x00B8 + value);
        if ((value2 & 4) == 0) {
            RETURN_RTS(c);
        }
        if (value2 >= 7) {
            RETURN_RTS(c);
        }
        RAM16_SET(0x00B2 + value, (uint16_t)(((((value2 & 3) << 8) | 0) << 1) + 0xE000));
        RAM16_SET(0x00B8 + value, (uint16_t)(RAM16(0x00B8 + value) + 1));
        uint16_t value3 = RAM16(0x0000 + (uint16_t)(((((value2 & 3) << 8) | 0) << 1) + 0xE000));
        if (value3 != 1) {
            a_hi1 = value3 >> 8;
            continue;
        }
        uint16_t value4 = RAM16(0x0190 + (uint16_t)(((((value2 & 3) << 8) | 0) << 1) + 0xE000));
        if (value4 & 0x8000) {
            a_hi1 = value4 >> 8;
            continue;
        }
        uint16_t value5 = RAM16(0x0287);
        RAM16_SET(OBJECT_AGE + value5, 0);
        r->x = value5;
        r->y = y;
        r->v = ((((((value2 & 3) << 8) | 0) << 1) ^ (uint16_t)(((((value2 & 3) << 8) | 0) << 1) + 0xE000)) & ((uint16_t)(((((value2 & 3) << 8) | 0) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9AA7, 0xC298DA); GUARD_JSR(c, sp_call, 0x9AA7); } /* activate_spell_child_and_clear_fractional_height */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x9AAA, 0xC29AAF); GUARD_JSR(c, sp_call, 0x9AAA); } /* seed_follow_spell_animation_sound_position_and_control */
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC29A74, SOM_RTS, "gen", select_next_live_active_party_spell_target, 0, 0, 1, 0, 0, 59, 27)
