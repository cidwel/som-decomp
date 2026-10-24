; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-phases.md.
.setcpu "65816"
.smart
.a8
.i16

boss_external_actor_command_if_selected = $3963
create_randomly_positioned_boss_death_explosion_actor = $0C33
mark_controller_and_request_numeric_boss_death_event = $0C11
public_actor_death_jump = $C0006F
rotate_fourteen_colors_in_each_selected_boss_palette = $0C89

.segment "CODE"
.org $0B8B
advance_boss_death_explosions_event_and_reward_phase:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bne advance_boss_death_explosions_event_and_reward_phase_c20ba6
    .a16
    lda #$07F8
    jsr mark_controller_and_request_numeric_boss_death_event
    ldx $87
    jsl f:public_actor_death_jump
    ldx $87
    lda a:$0096,X
advance_boss_death_explosions_event_and_reward_phase_c20ba6:
    .a16
    cmp #$0034
    bcs advance_boss_death_explosions_event_and_reward_phase_c20bb8
    .a16
    and #$0003
    bne advance_boss_death_explosions_event_and_reward_phase_c20bb3
    jsr create_randomly_positioned_boss_death_explosion_actor
advance_boss_death_explosions_event_and_reward_phase_c20bb3:
    jsr rotate_fourteen_colors_in_each_selected_boss_palette
    clc
    rts
advance_boss_death_explosions_event_and_reward_phase_c20bb8:
    stz a:$00A7,X
    inc a:$0094,X
    stz a:$0096,X
    .a16
    lda #$8A00
    jsr boss_external_actor_command_if_selected
    clc
    rts
