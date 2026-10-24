; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

configure_eight_tile_dma_channels_and_publish_row = $FC49
copy_character_palette_strip_and_clear_unused_geometry = $FCA3

.segment "CODE"
.org $FBDC
upload_two_rows_of_eight_character_tiles:
    rep #$30
    ldx $14
    ldy a:$E06E,X
    lda a:$E08A,X
    .a16
    and #$01FF
    asl
    asl
    asl
    asl
    clc
    .a16
    adc #$6000
    sta $00
    lda a:$E082,X
    sep #$20
    xba
    .a8
    lda #$00
    phb
    pha
    plb
    xba
    sta a:$4304
    sta a:$4314
    sta a:$4324
    sta a:$4334
    sta a:$4344
    sta a:$4354
    sta a:$4364
    sta a:$4374
    .a8
    lda #$80
    sta a:$2115
    rep #$20
    .a16
    lda #$1801
    sta a:$4300
    sta a:$4310
    sta a:$4320
    sta a:$4330
    sta a:$4340
    sta a:$4350
    sta a:$4360
    sta a:$4370
    jsr configure_eight_tile_dma_channels_and_publish_row
    inc $01
    iny
    iny
    iny
    iny
    jsr configure_eight_tile_dma_channels_and_publish_row
    plb
    jmp copy_character_palette_strip_and_clear_unused_geometry
