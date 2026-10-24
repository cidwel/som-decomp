; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FAAF
copy_or_swap_character_attribute_row:
    lda $E3
    .a8
    cmp #$80
    beq copy_or_swap_character_attribute_row_c1fac1
    .a8
    cmp #$84
    beq copy_or_swap_character_attribute_row_c1fae5
    .a8
    cmp #$02
    beq copy_or_swap_character_attribute_row_c1fad3
    .a8
    cmp #$40
    bne copy_or_swap_character_attribute_row_c1fad2
copy_or_swap_character_attribute_row_c1fac1:
    rep #$30
    .i16
    ldx #$003E
copy_or_swap_character_attribute_row_c1fac6:
    lda f:$7EEBC0,X
    sta f:$7EEFC0,X
    dex
    dex
    bpl copy_or_swap_character_attribute_row_c1fac6
copy_or_swap_character_attribute_row_c1fad2:
    rts
copy_or_swap_character_attribute_row_c1fad3:
    rep #$30
    .i16
    ldx #$003E
copy_or_swap_character_attribute_row_c1fad8:
    lda f:$7EEFC0,X
    sta f:$7EEBC0,X
    dex
    dex
    bpl copy_or_swap_character_attribute_row_c1fad8
    rts
copy_or_swap_character_attribute_row_c1fae5:
    rep #$30
    .i16
    ldx #$003E
copy_or_swap_character_attribute_row_c1faea:
    lda f:$7EEFC0,X
    pha
    lda f:$7EEBC0,X
    sta f:$7EEFC0,X
    pla
    sta f:$7EEBC0,X
    dex
    dex
    bpl copy_or_swap_character_attribute_row_c1faea
    rts
