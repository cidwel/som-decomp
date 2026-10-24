; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A19D
read_map_tile_absolute_word:
    lda $00
    sta $02
    rep #$20
    iny
    lda [$10],Y
    xba
    sta $00
    dey
    lda $10
    clc
    .a16
    adc #$0002
    sta $10
    bcc read_map_tile_absolute_word_c2a1b6
    inc $12
read_map_tile_absolute_word_c2a1b6:
    lda $01
    sta $04
    .i8
    cpx #$04
    bne read_map_tile_absolute_word_c2a1bf
    rts
read_map_tile_absolute_word_c2a1bf:
    .i8
    cpx #$03
    bne read_map_tile_absolute_word_c2a1de
    sep #$20
    xba
    lsr
    lsr
    xba
    rep #$20
    asl
    asl
    sta $04
    sep #$20
    asl $00
    rol
    asl $00
    rol
    .a8
    and #$03
    ora $04
    sta $04
    rts
read_map_tile_absolute_word_c2a1de:
    .i8
    cpx #$02
    bne read_map_tile_absolute_word_c2a204
    sep #$20
    xba
    lsr
    lsr
    lsr
    lsr
    xba
    rep #$20
    asl
    asl
    asl
    asl
    sta $04
    sep #$20
    lda $00
    asl
    rol
    rol
    rol
    sta $00
    rol
    .a8
    and #$0F
    ora $04
    sta $04
    rts
read_map_tile_absolute_word_c2a204:
    sep #$20
    xba
    asl
    rol
    rol
    xba
    rep #$20
    asl
    asl
    asl
    asl
    asl
    asl
    sta $04
    sep #$20
    lda $00
    lsr
    ror
    pha
    ror
    sta $00
    pla
    .a8
    and #$3F
    ora $04
    sta $04
    rts
