; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $18D6
set_animation_target_motion_pair_and_rate:
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
    sep #$20
    lda [$76],Y
    iny
    sta a:$0040,X
    lda [$76],Y
    sta a:$0041,X
    asl
    asl
    clc
    adc [$76],Y
    iny
    sta a:$000A,X
    stz a:$0006,X
    stz a:$0007,X
    rep #$20
    ldx $87
    rts
