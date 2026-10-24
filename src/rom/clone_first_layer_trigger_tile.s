; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a16
.i16


.segment "CODE"
.org $B517
clone_first_layer_trigger_tile:
    phy
    ldy $18
    lda a:$B800,X
    sta a:$BB00,Y
    lda a:$B802,X
    sta a:$BB02,Y
    txa
    asl
    tax
    tya
    asl
    tay
    lda a:$C000,X
    sta a:$C600,Y
    lda a:$C002,X
    sta a:$C602,Y
    lda a:$C004,X
    sta a:$C604,Y
    lda a:$C006,X
    sta a:$C606,Y
    ply
    sep #$20
    lda $18
    lsr
    lsr
    .a8
    ora #$C0
    sta ($10),Y
    rep #$20
    lda $18
    clc
    .a16
    adc #$0004
    sta $18
    rtl
