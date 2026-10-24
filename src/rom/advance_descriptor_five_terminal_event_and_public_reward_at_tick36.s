; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five-terminal.md.
.setcpu "65816"
.smart
.a8
.i16

mark_controller_and_request_numeric_boss_death_event = $0C11
public_actor_death_jump = $C0006F

.segment "CODE"
.org $5FF1
advance_descriptor_five_terminal_event_and_public_reward_at_tick36:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0024
    bne advance_descriptor_five_terminal_event_and_public_reward_at_tick36_c2600d
    stz a:$0096,X
    inc a:$0094,X
    lda a:$0072,X
    jsr mark_controller_and_request_numeric_boss_death_event
    ldx $87
    jsl f:public_actor_death_jump
advance_descriptor_five_terminal_event_and_public_reward_at_tick36_c2600d:
    clc
    rts
