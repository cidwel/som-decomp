; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-setup.md.
.setcpu "65816"
.smart
.a8
.i16

divide_unsigned_double_words_in_software = $2CE6
multiply_unsigned_words_with_four_hardware_products = $2AC3

.segment "CODE"
.org $8778
scale_native59_variant_zero_child_from_missing_hp_fraction:
    ldx $87
    stz $46
    stz $48
    stz $50
    lda a:$0184,X
    sta $4E
    sec
    sbc a:$0182,X
    sta $47
    jsr divide_unsigned_double_words_in_software
    lda $56
    clc
    .a16
    adc #$0080
    sta $95
    ldx $87
    lda a:$00B4,X
    tax
    lda $95
    sta a:$00B8,X
    .a16
    lda #$0004
    sta $46
    lda $56
    sta $4E
    jsr multiply_unsigned_words_with_four_hardware_products
    lda $57
    .a16
    cmp #$0004
    bcc scale_native59_variant_zero_child_from_missing_hp_fraction_c287b7
    .a16
    lda #$0004
scale_native59_variant_zero_child_from_missing_hp_fraction_c287b7:
    ldx $87
    clc
    .a16
    adc #$0008
    sta a:$001E,X
    rts
