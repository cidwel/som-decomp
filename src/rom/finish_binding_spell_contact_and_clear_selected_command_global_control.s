; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-spell-hold-child.md.
.setcpu "65816"
.smart
.a8
.i16

boss_external_actor_command_if_selected = $3963
clear_spell_status_and_mark_reciprocal_contacts = $9FBD
follow_spell_target_integer_position = $993D
mark_eligible_spell_target_control19 = $98F6
set_eligible_spell_target_status_and_timer = $9910

.segment "CODE"
.org $9FA0
finish_binding_spell_contact_and_clear_selected_command_global_control:
    ldx $87
    lda a:$009E,X
    bne finish_binding_spell_contact_and_clear_selected_command_global_control_c29fb2
    jsr clear_spell_status_and_mark_reciprocal_contacts
    .a16
    lda #$8A00
    jsr boss_external_actor_command_if_selected
    sec
    rts
finish_binding_spell_contact_and_clear_selected_command_global_control_c29fb2:
    jsr mark_eligible_spell_target_control19
    jsr set_eligible_spell_target_status_and_timer
    jsr follow_spell_target_integer_position
    clc
    rts
