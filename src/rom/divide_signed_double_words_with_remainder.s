; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16

divide_unsigned_double_words_in_software = $2CE6

.segment "CODE"
.org $2DA5
divide_signed_double_words_with_remainder:
    lda $48
    pha
    eor $50
    pha
    lda $48
    bpl divide_signed_double_words_with_remainder_c22dbc
    sec
    lda $C5
    sbc $46
    sta $46
    lda $C5
    sbc $48
    sta $48
divide_signed_double_words_with_remainder_c22dbc:
    lda $50
    bpl divide_signed_double_words_with_remainder_c22dcd
    sec
    lda $C5
    sbc $4E
    sta $4E
    lda $C5
    sbc $50
    sta $50
divide_signed_double_words_with_remainder_c22dcd:
    jsr divide_unsigned_double_words_in_software
    bne divide_signed_double_words_with_remainder_c22df3
    pla
    bpl divide_signed_double_words_with_remainder_c22de2
    sec
    lda $C5
    sbc $56
    sta $56
    lda $C5
    sbc $58
    sta $58
divide_signed_double_words_with_remainder_c22de2:
    pla
    bpl divide_signed_double_words_with_remainder_c22df2
    sec
    lda $C5
    sbc $5E
    sta $5E
    lda $C5
    sbc $60
    sta $60
divide_signed_double_words_with_remainder_c22df2:
    rts
divide_signed_double_words_with_remainder_c22df3:
    pla
    pla
    .a16
    lda #$FFFF
    rts
