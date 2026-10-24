; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16

consume_body_damage_or_parent_phase15_and_enter_hurt = $4DB9

.segment "CODE"
.org $4C43
enter_body_retraction_after_six_ticks:
    ldx $87
    lda a:$00B0,X
    tax
    inc a:$00BC,X
    ldx $87
    jsr consume_body_damage_or_parent_phase15_and_enter_hurt
    bcs enter_body_retraction_after_six_ticks_c24c72
    lda a:$0096,X
    .a16
    cmp #$0006
    bne enter_body_retraction_after_six_ticks_c24c72
    stz a:$0096,X
    .a16
    lda #$0006
    sta a:$0094,X
    lda a:$00B2,X
    asl
    asl
    clc
    .a16
    adc #$0003
    adc $89
    sta a:$00B8,X
enter_body_retraction_after_six_ticks_c24c72:
    clc
    rts
