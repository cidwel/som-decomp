; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller-pool.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $34B9
complete_boss_hurt_state_after_timeout_or_released_counter_status:
    lda a:$0096,X
    .a16
    cmp #$003C
    bcs complete_boss_hurt_state_after_timeout_or_released_counter_status_c234d4
    lda a:$0175,X
    .a16
    and #$00FF
    bne complete_boss_hurt_state_after_timeout_or_released_counter_status_c234d6
    lda a:$0060,X
    .a16
    and #$00FF
    .a16
    cmp #$0040
    beq complete_boss_hurt_state_after_timeout_or_released_counter_status_c234d6
complete_boss_hurt_state_after_timeout_or_released_counter_status_c234d4:
    sec
    rts
complete_boss_hurt_state_after_timeout_or_released_counter_status_c234d6:
    clc
    rts
