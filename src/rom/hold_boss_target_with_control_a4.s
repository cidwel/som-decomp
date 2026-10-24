; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $620D
hold_boss_target_with_control_a4:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    lda a:$0060,Y
    bne hold_boss_target_with_control_a4_c2623f
    lda a:$0011,Y
    .a8
    cmp #$A4
    bne hold_boss_target_with_control_a4_c2623f
    lda a:$000E,Y
    bne hold_boss_target_with_control_a4_c2623f
    .a8
    lda #$80
    ora a:$000E,Y
    sta a:$000E,Y
    .a8
    lda #$01
    ora a:$0190,Y
    sta a:$0190,Y
    .a8
    lda #$20
    sta a:$01B4,Y
hold_boss_target_with_control_a4_c2623f:
    rep #$20
    rts
