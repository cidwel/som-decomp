; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $55A2
place_eligible_boss_target_at_offset_and_set_control_07:
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
    bne place_eligible_boss_target_at_offset_and_set_control_07_c255e0
    sep #$20
    lda a:$0060,Y
    bne place_eligible_boss_target_at_offset_and_set_control_07_c255e0
    .a8
    lda #$07
    sta a:$01E5,Y
    .a8
    lda #$01
    ora a:$0190,Y
    sta a:$0190,Y
    .a8
    lda #$20
    sta a:$01B4,Y
    rep #$20
    lda a:$002B,X
    clc
    .a16
    adc #$0010
    sta a:$0002,Y
    lda a:$0032,X
    inc
    sta a:$0004,Y
place_eligible_boss_target_at_offset_and_set_control_07_c255e0:
    rep #$20
    rts
