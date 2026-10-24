; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a16
.i16


.segment "CODE"
.org $B55A
clone_second_layer_trigger_tile:
    phy
    ldy $18
    lda a:$BC00,X
    sta a:$BF00,Y
    lda a:$BC02,X
    sta a:$BF02,Y
    txa
    asl
    tax
    tya
    asl
    tay
    lda a:$C800,X
    sta a:$CE00,Y
    lda a:$C802,X
    sta a:$CE02,Y
    lda a:$C804,X
    sta a:$CE04,Y
    lda a:$C806,X
    sta a:$CE06,Y
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
