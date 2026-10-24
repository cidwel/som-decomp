; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-child-capture.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6C77
advance_captured_boss_target_y_and_set_recovery:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    lda a:$0004,Y
    clc
    .a16
    adc #$0002
    sta a:$0004,Y
    sep #$20
    lda a:$0060,Y
    bne advance_captured_boss_target_y_and_set_recovery_c26c97
    .a8
    lda #$0E
    sta a:$01E5,Y
advance_captured_boss_target_y_and_set_recovery_c26c97:
    .a8
    lda #$01
    sta a:$01B4,Y
    rep #$20
    rts
