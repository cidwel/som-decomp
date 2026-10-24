; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B147
append_map_scroll_animation_record:
    sta a:$8000,Y
    iny
    pha
    .a8
    lda #$00
    sta a:$8000,Y
    pla
    iny
    .a8
    and #$3F
    asl
    .a8
    ora #$80
    xba
    .a8
    lda #$00
    rep #$20
    sta a:$8000,Y
    iny
    iny
    lda $00
    .a16
    and #$0007
    xba
    lsr
    lsr
    clc
    .a16
    adc #$3600
    sta a:$8000,Y
    iny
    iny
    .a16
    lda #$0000
    sta a:$8000,Y
    iny
    iny
    sep #$20
    rts
