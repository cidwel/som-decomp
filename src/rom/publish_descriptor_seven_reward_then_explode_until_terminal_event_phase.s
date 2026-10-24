; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-seven-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

boss_external_actor_command_if_selected = $3963
mark_controller_and_request_numeric_boss_death_event = $0C11
public_actor_death_jump = $C0006F
rotate_fourteen_colors_in_each_selected_boss_palette = $0C89
routine_c20c3c = $0C3C

.segment "CODE"
.org $72C1
publish_descriptor_seven_reward_then_explode_until_terminal_event_phase:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bne publish_descriptor_seven_reward_then_explode_until_terminal_event_phase_c272dc
    .a16
    lda #$07F8
    jsr mark_controller_and_request_numeric_boss_death_event
    ldx $87
    jsl f:public_actor_death_jump
    ldx $87
    lda a:$0096,X
publish_descriptor_seven_reward_then_explode_until_terminal_event_phase_c272dc:
    .a16
    cmp #$0030
    bcs publish_descriptor_seven_reward_then_explode_until_terminal_event_phase_c272ee
    .a16
    and #$0003
    bne publish_descriptor_seven_reward_then_explode_until_terminal_event_phase_c272e9
    jsr routine_c20c3c
publish_descriptor_seven_reward_then_explode_until_terminal_event_phase_c272e9:
    jsr rotate_fourteen_colors_in_each_selected_boss_palette
    clc
    rts
publish_descriptor_seven_reward_then_explode_until_terminal_event_phase_c272ee:
    stz a:$00A7,X
    inc a:$0094,X
    stz a:$0096,X
    .a16
    lda #$8A00
    jsr boss_external_actor_command_if_selected
    clc
    rts
