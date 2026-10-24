; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $61D0
set_boss_target_control_24_or_retry:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    lda a:$0060,Y
    bne set_boss_target_control_24_or_retry_c26202
    lda a:$000E,Y
    bne set_boss_target_control_24_or_retry_c26202
    lda a:$01E5,Y
    .a8
    cmp #$24
    beq set_boss_target_control_24_or_retry_c26202
    .a8
    lda #$24
    sta a:$01E5,Y
    .a8
    lda #$01
    ora a:$0190,Y
    sta a:$0190,Y
    .a8
    lda #$20
    sta a:$01B4,Y
    rep #$20
    rts
set_boss_target_control_24_or_retry_c26202:
    rep #$20
    inc $36
    .a16
    lda #$0001
    sta a:$007E,X
    rts
