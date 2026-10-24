; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

divide_unsigned_word_by_word_in_software = $2CBF

.segment "CODE"
.org $2D69
divide_signed_word_by_word_with_remainder:
    lda $46
    pha
    eor $4E
    pha
    lda $46
    bpl divide_signed_word_by_word_with_remainder_c22d7a
    sec
    lda $C5
    sbc $46
    sta $46
divide_signed_word_by_word_with_remainder_c22d7a:
    lda $4E
    bpl divide_signed_word_by_word_with_remainder_c22d85
    sec
    lda $C5
    sbc $4E
    sta $4E
divide_signed_word_by_word_with_remainder_c22d85:
    jsr divide_unsigned_word_by_word_in_software
    bne divide_signed_word_by_word_with_remainder_c22d9f
    pla
    bpl divide_signed_word_by_word_with_remainder_c22d94
    sec
    lda $C5
    sbc $56
    sta $56
divide_signed_word_by_word_with_remainder_c22d94:
    pla
    bpl divide_signed_word_by_word_with_remainder_c22d9e
    sec
    lda $C5
    sbc $5E
    sta $5E
divide_signed_word_by_word_with_remainder_c22d9e:
    rts
divide_signed_word_by_word_with_remainder_c22d9f:
    pla
    pla
    .a16
    lda #$FFFF
    rts
