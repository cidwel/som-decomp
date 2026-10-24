; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A227
read_map_tile_six_bit_value:
    .i8
    cpx #$03
    bcc read_map_tile_six_bit_value_c2a24c
    lda $00
    pha
    lsr
    ror
    ror
    sta $00
    dex
    dex
    dex
    bne read_map_tile_six_bit_value_c2a248
    .i8
    ldx #$04
    inc $10
    bne read_map_tile_six_bit_value_c2a244
    inc $11
    bne read_map_tile_six_bit_value_c2a244
    inc $12
read_map_tile_six_bit_value_c2a244:
    lda [$10],Y
    sta $00
read_map_tile_six_bit_value_c2a248:
    pla
    lsr
    lsr
    rts
read_map_tile_six_bit_value_c2a24c:
    lda $00
    lsr
    lsr
    .a8
    and #$3C
    .i8
    cpx #$02
    beq read_map_tile_six_bit_value_c2a258
    .a8
    and #$30
read_map_tile_six_bit_value_c2a258:
    sta $02
    inc $10
    bne read_map_tile_six_bit_value_c2a264
    inc $11
    bne read_map_tile_six_bit_value_c2a264
    inc $12
read_map_tile_six_bit_value_c2a264:
    lda [$10],Y
    asl
    rol
    sta $00
    rol
    .i8
    cpx #$02
    bne read_map_tile_six_bit_value_c2a275
    .a8
    and #$03
    .i8
    ldx #$03
    bra read_map_tile_six_bit_value_c2a27f
read_map_tile_six_bit_value_c2a275:
    asl $00
    rol
    asl $00
    rol
    .a8
    and #$0F
    .i8
    ldx #$02
read_map_tile_six_bit_value_c2a27f:
    ora $02
    rts
