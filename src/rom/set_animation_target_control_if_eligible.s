; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $183A
set_animation_target_control_if_eligible:
    ldx $87
    lda a:$00A9,X
    .a16
    and #$00FF
    xba
    asl
    clc
    .a16
    adc #$E000
    tax
    lda a:$0190,X
    .a16
    and #$C568
    bne set_animation_target_control_if_eligible_c21868
    lda a:$0060,X
    .a16
    and #$00FF
    bne set_animation_target_control_if_eligible_c21868
    lda [$76],Y
    iny
    phy
    sep #$20
    sta a:$01E5,X
    rep #$20
    ply
    ldx $87
    rts
set_animation_target_control_if_eligible_c21868:
    iny
    ldx $87
    rts
