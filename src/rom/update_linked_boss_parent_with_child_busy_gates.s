; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-parent-update.md.
.setcpu "65816"
.smart
.a8
.i16

choose_linked_boss_child_attack_projectile_or_spell_after_hp_change = $581D
request_linked_child_recovery_status_or_death_modes = $5951
select_boss_nearest_target_animation_with_status_timer_guards = $579E
test_whether_either_linked_boss_child_has_state_word_81 = $578A

.segment "CODE"
.org $5775
update_linked_boss_parent_with_child_busy_gates:
    jsr select_boss_nearest_target_animation_with_status_timer_guards
    jsr test_whether_either_linked_boss_child_has_state_word_81
    bcs update_linked_boss_parent_with_child_busy_gates_c25788
    jsr choose_linked_boss_child_attack_projectile_or_spell_after_hp_change
    jsr test_whether_either_linked_boss_child_has_state_word_81
    bcs update_linked_boss_parent_with_child_busy_gates_c25788
    jsr request_linked_child_recovery_status_or_death_modes
update_linked_boss_parent_with_child_busy_gates_c25788:
    clc
    rts
