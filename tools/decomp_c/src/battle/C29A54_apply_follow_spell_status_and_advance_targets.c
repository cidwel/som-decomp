#include "som_c.h"

/* C29A54 apply_follow_spell_status_and_advance_targets   [class B, 19 bytes, 9 instructions]
 * Source: src/rom/apply_follow_spell_status_and_advance_targets.s
 * Documented in docs/boss-native-spell-follow-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void apply_follow_spell_status_and_advance_targets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    r->x = value;
    JSR(c, 0x9A58, 0xC29910); /* set_eligible_spell_target_status_and_timer */
    uint16_t value2 = RAM16(0x009E + value);
    if (value2 != 0) {
        r->a = value2;
        r->c = 0;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A60, 0xC29FBD); /* clear_spell_status_and_mark_reciprocal_contacts */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x9A63, 0xC29A74); /* select_next_live_active_party_spell_target */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29A54, SOM_RTS, "gen", apply_follow_spell_status_and_advance_targets, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 19, 9)
