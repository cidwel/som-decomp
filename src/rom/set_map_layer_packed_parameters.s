; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A7D5
set_map_layer_packed_parameters:
    rep #$20
    pha
    .a16
    and #$001F
    xba
    lsr
    lsr
    lsr
    sta a:$0A8A,Y
    pla
    sep #$20
    lsr
    lsr
    lsr
    lsr
    lsr
    inc
    sta a:$0A8C,Y
    xba
    rep #$20
    .a16
    and #$00FF
    inc
    sta a:$0A8E,Y
    .a16
    lda #$0000
    sta a:$0A86,Y
    sep #$20
    rts
