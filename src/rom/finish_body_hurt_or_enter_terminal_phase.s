; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

complete_boss_hurt_state_after_timeout_or_released_counter_status = $34B9
test_boss_negative_status_word = $34B0

.segment "CODE"
.org $4CEF
finish_body_hurt_or_enter_terminal_phase:
    ldx $87
    jsr complete_boss_hurt_state_after_timeout_or_released_counter_status
    bcc finish_body_hurt_or_enter_terminal_phase_c24d1e
    .a16
    lda #$0006
    sta a:$0094,X
    sta a:$00BC,X
    stz a:$0096,X
    jsr test_boss_negative_status_word
    bcs finish_body_hurt_or_enter_terminal_phase_c24d13
    lda a:$00B0,X
    tax
    lda a:$0094,X
    .a16
    cmp #$000F
    bne finish_body_hurt_or_enter_terminal_phase_c24d1e
finish_body_hurt_or_enter_terminal_phase_c24d13:
    ldx $87
    stz a:$0096,X
    .a16
    lda #$0009
    sta a:$0094,X
finish_body_hurt_or_enter_terminal_phase_c24d1e:
    clc
    rts
