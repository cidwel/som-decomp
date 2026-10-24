#include "som_c.h"
#include "som_hand_b.h"

/* C25775 update_linked_boss_parent_with_child_busy_gates   [class B, 21 bytes, 9 instructions]
 * Source: src/rom/update_linked_boss_parent_with_child_busy_gates.s
 * Documented in docs/boss-native-linked-parent-update.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void update_linked_boss_parent_with_child_busy_gates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR_CHK(c, 0x5777, 0xC2579E); /* select_boss_nearest_target_animation_with_status_timer_guards */
    JSR_CHK(c, 0x577A, 0xC2578A); /* test_whether_either_linked_boss_child_has_state_word_81 */
    if (!r->c) {
        JSR_CHK(c, 0x577F, 0xC2581D); /* choose_linked_boss_child_attack_projectile_or_spell_after_hp_change */
        JSR_CHK(c, 0x5782, 0xC2578A); /* test_whether_either_linked_boss_child_has_state_word_81 */
        if (!r->c) {
            JSR_CHK(c, 0x5787, 0xC25951); /* request_linked_child_recovery_status_or_death_modes */
        }
    }
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25775, SOM_RTS, "hand", update_linked_boss_parent_with_child_busy_gates, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 21, 9)
