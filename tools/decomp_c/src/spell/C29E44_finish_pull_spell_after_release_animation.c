#include "som_c.h"

/* C29E44 finish_pull_spell_after_release_animation   [class A, 17 bytes, 9 instructions]
 * Source: src/rom/finish_pull_spell_after_release_animation.s
 * Documented in docs/boss-native-spell-pull-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 *
 * The fourth state of the pull-spell child table (C299ED).  Both callees (C29910 `AND #$C568`, C29FBD
 * `SBC #$E600`) are assembled for a 16-bit accumulator and so is the sibling state C29DC6 (`INC $0094,X`
 * on the state word), so the whole table runs with M=16; the `.a8` of the source file is only the
 * assembler default.  The word at +$9E selects the callee.
 */
static void finish_pull_spell_after_release_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t object = RAM16(CURRENT_OBJECT_DP0 + dp);
    const uint16_t value = RAM16(0x009E + object);
    r->a = value;
    r->x = object;
    if (value != 0) {
        { const uint16_t sp_call = r->sp; JSR(c, 0x9E52, 0xC29910); GUARD_JSR(c, sp_call, 0x9E52); } /* set_eligible_spell_target_status_and_timer */
        r->c = 0;
        RETURN_RTS(c);
    }
    { const uint16_t sp_call = r->sp; JSR(c, 0x9E4D, 0xC29FBD); GUARD_JSR(c, sp_call, 0x9E4D); } /* clear_spell_status_and_mark_reciprocal_contacts */
    r->c = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29E44, SOM_RTS, "hand", finish_pull_spell_after_release_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 17, 9)
