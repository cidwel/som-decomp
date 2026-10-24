; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

copy_and_submit_colour_tile = $BF2A
lookup_cached_colour_sample = $87C9

.segment "CODE"
.org $9D1E
convert_components_to_planar_tile:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$000B
    tcd
    tcs
    sep #$20
    stx $02
    txy
    .a8
    lda #$40
    sta $01
convert_components_to_planar_tile_9d32:
    phx
    phy
    jsr lookup_cached_colour_sample
    ply
    plx
    sta a:$0000,Y
    clc
    rep #$20
    txa
    .a16
    adc #$0004
    tax
    sep #$20
    iny
    dec $01
    bne convert_components_to_planar_tile_9d32
    ldx $02
    txy
    .a8
    lda #$08
    sta $09
convert_components_to_planar_tile_9d52:
    stx $04
    sty $06
    .a8
    lda #$04
    sta $08
convert_components_to_planar_tile_9d5a:
    ldx $04
    .a8
    lda #$08
    sta $0A
convert_components_to_planar_tile_9d60:
    lsr a:$0000,X
    rol
    inx
    dec $0A
    bne convert_components_to_planar_tile_9d60
    sta a:$00C0,Y
    iny
    ldx $04
    .a8
    lda #$08
    sta $0A
convert_components_to_planar_tile_9d73:
    lsr a:$0000,X
    rol
    inx
    dec $0A
    bne convert_components_to_planar_tile_9d73
    sta a:$00C0,Y
    clc
    rep #$20
    tya
    .a16
    adc #$000F
    tay
    sep #$20
    dec $08
    bne convert_components_to_planar_tile_9d5a
    rep #$20
    lda $04
    clc
    .a16
    adc #$0008
    tax
    ldy $06
    iny
    iny
    sep #$20
    dec $09
    bne convert_components_to_planar_tile_9d52
    lda $02
    clc
    .a8
    adc #$C0
    tax
    .a8
    lda #$00
    jsr copy_and_submit_colour_tile
    rep #$20
    tsc
    clc
    .a16
    adc #$000B
    tcs
    plp
    pld
    rts
