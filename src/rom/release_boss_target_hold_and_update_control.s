; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6242
release_boss_target_hold_and_update_control:
    .a16
    lda #$0001
    sta a:$007E,X
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    lda a:$0060,Y
    bne release_boss_target_hold_and_update_control_c26263
    lda a:$0190,X
    bmi release_boss_target_hold_and_update_control_c26263
    .a8
    lda #$0E
    sta a:$01E5,Y
release_boss_target_hold_and_update_control_c26263:
    .a8
    lda #$01
    sta a:$01B4,Y
    .a8
    lda #$7F
    and a:$000E,Y
    sta a:$000E,Y
    rep #$20
    rts
