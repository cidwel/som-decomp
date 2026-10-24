; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16

invoke_state_callback = $36B3
publish_boss_actor_notification = $35B9
resolve_boss_hurt_death_timer_and_animation_completion = $362D

.segment "CODE"
.org $3594
update_boss_action_and_completion:
    ldx $87
    lda a:$0048,X
    beq update_boss_action_and_completion_c2359e
    jsr invoke_state_callback
update_boss_action_and_completion_c2359e:
    ldx $87
    jsr resolve_boss_hurt_death_timer_and_animation_completion
    bcc update_boss_action_and_completion_c235b7
    ldx $87
    lda a:$0080,X
    beq update_boss_action_and_completion_c235b4
    jsr publish_boss_actor_notification
    ldx $87
    stz a:$0080,X
update_boss_action_and_completion_c235b4:
    dec a:$0094,X
update_boss_action_and_completion_c235b7:
    clc
    rts
