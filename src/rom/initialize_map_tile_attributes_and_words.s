; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

copy_map_tile_attribute_entries = $A043
decode_map_tile_word_layers = $A069

.segment "CODE"
.org $A000
initialize_map_tile_attributes_and_words:
    sep #$30
    phb
    .a8
    lda #$7F
    pha
    plb
    lda $1C
    .a8
    and #$3F
    xba
    .a8
    and #$00
    rep #$30
    sta $10
    lsr
    adc $10
    sta $10
    tax
    clc
    .a16
    adc #$00C0
    sta $12
    .a16
    lda #$B800
    sta $14
    bit $1B
    bvc initialize_map_tile_attributes_and_words_c2a029
    ldx $12
initialize_map_tile_attributes_and_words_c2a029:
    jsr copy_map_tile_attribute_entries
    .a16
    lda #$BC00
    sta $14
    ldx $12
    bit $1B
    bmi initialize_map_tile_attributes_and_words_c2a039
    ldx $10
initialize_map_tile_attributes_and_words_c2a039:
    jsr copy_map_tile_attribute_entries
    jsr decode_map_tile_word_layers
    sep #$30
    plb
    rtl
