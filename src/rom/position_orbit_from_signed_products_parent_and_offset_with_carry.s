; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-three-orbit.md.
.setcpu "65816"
.smart
.a8
.i16

multiply_signed_words_to_double_word = $2B94

.segment "CODE"
.org $64BE
position_orbit_from_signed_products_parent_and_offset_with_carry:
    lda a:$00BA,X
    tax
    lda a:$002B,X
    sta $99
    lda a:$0032,X
    sta $9B
    ldx $87
    lda a:$00B4,X
    sta $46
    lda $95
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $57
    ldx $87
    clc
    adc a:$00B6,X
    adc $99
    sta a:$002B,X
    lda a:$00B4,X
    sta $46
    lda $97
    sta $4E
    jsr multiply_signed_words_to_double_word
    lda $57
    ldx $87
    clc
    adc a:$00B8,X
    adc $9B
    sta a:$0032,X
    rts
