; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-target-control.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7A29
request_descriptor_ten_target_control_timer_and_animation_mode:
    ldx $87
    lda a:$00A9,X
    xba
    asl
    clc
    .a16
    adc #$E000
    tay
    sep #$20
    lda a:$0060,Y
    bne request_descriptor_ten_target_control_timer_and_animation_mode_c27a46
    lda a:$0190,X
    bmi request_descriptor_ten_target_control_timer_and_animation_mode_c27a46
    .a8
    lda #$0E
    sta a:$01E5,Y
request_descriptor_ten_target_control_timer_and_animation_mode_c27a46:
    .a8
    lda #$01
    sta a:$01B4,Y
    .a8
    lda #$7F
    and a:$000E,Y
    sta a:$000E,Y
    rep #$20
    rts
