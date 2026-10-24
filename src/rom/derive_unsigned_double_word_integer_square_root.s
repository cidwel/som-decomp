; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2DF9
derive_unsigned_double_word_integer_square_root:
    sep #$10
    stz $4E
    stz $4A
    .i8
    ldx #$10
derive_unsigned_double_word_integer_square_root_c22e01:
    lda $48
    .a16
    cmp #$4000
    lda $4A
    sbc $4E
    bcc derive_unsigned_double_word_integer_square_root_c22e16
    sta $4A
    lda $48
    .a16
    sbc #$4000
    sta $48
    sec
derive_unsigned_double_word_integer_square_root_c22e16:
    rol $4E
    asl $46
    rol $48
    rol $4A
    asl $46
    rol $48
    rol $4A
    dex
    bne derive_unsigned_double_word_integer_square_root_c22e01
    rep #$10
    rts
