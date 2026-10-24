; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

copy_or_swap_character_attribute_row = $FAAF

.segment "CODE"
.org $FA10
snapshot_tile_attributes_and_apply_character_row_exchange:
    sep #$30
    .a8
    lda #$80
    sta a:$2115
    .a8
    lda #$7E
    sta a:$4374
    rep #$20
    .a16
    lda #$3A80
    sta a:$4370
    .a16
    lda #$1000
    sta a:$4375
    .a16
    lda #$F000
    sta a:$4372
    .a16
    lda #$2C00
    sta a:$2116
    sep #$20
    lda a:$213A
    .a8
    lda #$80
    sta a:$420B
    rep #$20
    .a16
    lda #$0400
    sta a:$4375
    .a16
    lda #$E800
    sta a:$4372
    .a16
    lda #$3C00
    bit $E2
    bpl snapshot_tile_attributes_and_apply_character_row_exchange_c1fa58
    .a16
    lda #$2800
snapshot_tile_attributes_and_apply_character_row_exchange_c1fa58:
    sta a:$2116
    sep #$20
    lda a:$213A
    .a8
    lda #$80
    sta a:$420B
    rep #$20
    .a16
    lda #$0400
    sta a:$4375
    .a16
    lda #$EC00
    sta a:$4372
    .a16
    lda #$2800
    bit $E2
    bpl snapshot_tile_attributes_and_apply_character_row_exchange_c1fa7d
    .a16
    lda #$3C00
snapshot_tile_attributes_and_apply_character_row_exchange_c1fa7d:
    sta a:$2116
    sep #$20
    lda a:$213A
    .a8
    lda #$80
    sta a:$420B
    jsr copy_or_swap_character_attribute_row
    rep #$20
    .a16
    lda #$1900
    sta a:$4370
    .a16
    lda #$0400
    sta a:$4375
    .a16
    lda #$EC00
    sta a:$4372
    .a16
    lda #$2800
    sta a:$2116
    sep #$20
    .a8
    lda #$80
    sta a:$420B
    rts
