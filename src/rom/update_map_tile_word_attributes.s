; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A282
update_map_tile_word_attributes:
    .i8
    cpx #$02
    bcc update_map_tile_word_attributes_c2a2c6
    lda $00
    asl
    rol
    rol
    rol
    sta $00
    rol
    pha
    dex
    dex
    bne update_map_tile_word_attributes_c2a2a4
    .i8
    ldx #$04
    inc $10
    bne update_map_tile_word_attributes_c2a2a0
    inc $11
    bne update_map_tile_word_attributes_c2a2a0
    inc $12
update_map_tile_word_attributes_c2a2a0:
    lda [$10],Y
    sta $00
update_map_tile_word_attributes_c2a2a4:
    pla
update_map_tile_word_attributes_c2a2a5:
    .a8
    and #$0F
    asl
    asl
    .a8
    cmp #$20
    bcs update_map_tile_word_attributes_c2a2b8
    sta $01
    lda $05
    .a8
    and #$E3
    ora $01
    sta $05
    rts
update_map_tile_word_attributes_c2a2b8:
    asl
    asl
    asl
    sta $01
    lda $05
    .a8
    and #$1F
    ora $01
    sta $05
    rts
update_map_tile_word_attributes_c2a2c6:
    lda $00
    asl
    rol
    rol
    asl
    asl
    sta $01
    inc $10
    bne update_map_tile_word_attributes_c2a2d9
    inc $11
    bne update_map_tile_word_attributes_c2a2d9
    inc $12
update_map_tile_word_attributes_c2a2d9:
    lda [$10],Y
    asl
    rol
    sta $00
    rol
    .a8
    and #$03
    .i8
    ldx #$03
    ora $01
    bra update_map_tile_word_attributes_c2a2a5
