; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-setup.md.
.setcpu "65816"
.smart
.a8
.i16

divide_unsigned_double_words_in_software = $2CE6
multiply_unsigned_words_with_four_hardware_products = $2AC3

.segment "CODE"
.org $87C1
scale_native59_variant_one_child_from_current_hp_fraction:
    ldx $87
    stz $46
    stz $48
    stz $50
    lda a:$0182,X
    sta $47
    lda a:$0184,X
    sta $4E
    jsr divide_unsigned_double_words_in_software
    lda $56
    sta $95
    sta $46
    .a16
    lda #$00CC
    sta $4E
    jsr multiply_unsigned_words_with_four_hardware_products
    lda $57
    clc
    .a16
    adc #$0033
    sta $95
    ldx $87
    lda a:$00B4,X
    tax
    lda $95
    sta a:$00B8,X
    .a16
    lda #$0004
    sta $46
    lda $95
    sta $4E
    jsr multiply_unsigned_words_with_four_hardware_products
    lda $57
    .a16
    cmp #$0004
    bcc scale_native59_variant_one_child_from_current_hp_fraction_c2880d
    .a16
    lda #$0004
scale_native59_variant_one_child_from_current_hp_fraction_c2880d:
    ldx $87
    clc
    .a16
    adc #$000C
    sta a:$001E,X
    rts
