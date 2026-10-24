; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $1906
set_animation_target_motion_triplet:
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
    sta a:$0006,X
    lda [$76],Y
    iny
    sta a:$0007,X
    lda [$76],Y
    asl
    asl
    clc
    adc [$76],Y
    iny
    sta a:$000A,X
    rep #$20
    ldx $87
    rts
