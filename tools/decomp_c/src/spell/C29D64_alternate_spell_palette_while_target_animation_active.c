#include "som_c.h"

/* C29D64 alternate_spell_palette_while_target_animation_active   [class B, 47 bytes, 22 instructions]
 * Source: src/rom/alternate_spell_palette_while_target_animation_active.s
 * Documented in docs/boss-native-spell-palette-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void alternate_spell_palette_while_target_animation_active(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x9D68, 0xC29910); /* set_eligible_spell_target_status_and_timer */
    uint16_t value2 = RAM16(0x009E + value);
    if (value2 != 0) {
        RAM16_SET(0x0295, (uint16_t)(RAM16(0x00B6 + value) + 2));
        uint16_t value4 = RAM16(0x00BC + value);
        uint16_t value5 = RAM16(0x0295);
        uint8_t a1;
        uint8_t a_hi1;
        if ((uint16_t)(value4 + 1) < value5) {
            a1 = (uint8_t)(value4 + 1);
            a_hi1 = (uint16_t)(value4 + 1) >> 8;
        } else {
            uint16_t value6 = RAM16(0x00B6 + value);
            a1 = (uint8_t)(value6 - 1);
            a_hi1 = (uint16_t)(value6 - 1) >> 8;
        }
        RAM16_SET(0x00BC + value, (a_hi1 << 8) | a1);
        r->a = (a_hi1 << 8) | a1;
        r->x = 0x0F;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x9D90, 0xC226F9); /* copy_boss_palette_with_cpu_words */
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9D70, 0xC29FBD); /* clear_spell_status_and_mark_reciprocal_contacts */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9D73, 0xC29A74); /* select_next_live_active_party_spell_target */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29D64, SOM_RTS, "gen", alternate_spell_palette_while_target_animation_active, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 47, 22)
