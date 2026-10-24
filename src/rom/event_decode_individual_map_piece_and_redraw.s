; Recovered Secret of Mana USA routine; behaviour documented in docs/event-map-redraw.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00caff = $CAFF

.segment "CODE"
.org $F10E
event_decode_individual_map_piece_and_redraw:
    lda $05
    sta $00
    .i8
    ldy #$02
    lda [$D1],Y
    sta $01
    iny
    rep #$20
    lda [$D1],Y
    sta $02
    lda $D1
    clc
    .a16
    adc #$0005
    sta $D1
    lda $02
    sep #$20
    xba
    asl
    rep #$20
    .a16
    and #$7FFF
    bcc event_decode_individual_map_piece_and_redraw_c1f137
    .a16
    ora #$8000
event_decode_individual_map_piece_and_redraw_c1f137:
    lsr
    sta $12
    clc
    jsl f:routine_00caff
    rts
