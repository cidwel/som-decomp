; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4653
start_native54_auxiliary_lunge_after_animation:
    ldx $87
    lda a:$009E,X
    bne start_native54_auxiliary_lunge_after_animation_c24680
    inc a:$0094,X
    sep #$20
    .a8
    lda #$A0
    sta a:$F812,Y
    .a8
    lda #$D0
    sta a:$F80E,Y
    rep #$20
    stz a:$0096,X
    stz a:$003C,X
    stz a:$0040,X
    .a16
    lda #$A000
    sta a:$00B4,X
    .a16
    lda #$D000
    sta a:$00B6,X
start_native54_auxiliary_lunge_after_animation_c24680:
    clc
    rts
