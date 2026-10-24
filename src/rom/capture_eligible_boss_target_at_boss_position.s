; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-child-capture.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6C35
capture_eligible_boss_target_at_boss_position:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0190,Y
    .a16
    and #$C568
    bne capture_eligible_boss_target_at_boss_position_c26c74
    sep #$20
    lda a:$0060,Y
    bne capture_eligible_boss_target_at_boss_position_c26c74
    .a8
    lda #$19
    sta a:$01E5,Y
    .a8
    lda #$01
    ora a:$0190,Y
    sta a:$0190,Y
    .a8
    lda #$20
    sta a:$01B4,Y
    .a8
    lda #$18
    sta a:$0045,Y
    rep #$20
    lda a:$002B,X
    sta a:$0002,Y
    lda a:$0032,X
    inc
    sta a:$0004,Y
capture_eligible_boss_target_at_boss_position_c26c74:
    rep #$20
    rts
