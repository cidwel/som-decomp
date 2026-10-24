; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-axis-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $76E3
immobilize_idle_descriptor_ten_target_with_status_and_timer:
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    lda a:$0060,Y
    bne immobilize_idle_descriptor_ten_target_with_status_and_timer_c27713
    lda a:$000E,Y
    bne immobilize_idle_descriptor_ten_target_with_status_and_timer_c27713
    .a8
    lda #$24
    sta a:$01E5,Y
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
immobilize_idle_descriptor_ten_target_with_status_and_timer_c27713:
    rep #$20
    rts
