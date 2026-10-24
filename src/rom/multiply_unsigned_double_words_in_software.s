; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2B2F
multiply_unsigned_double_words_in_software:
    php
    sep #$10
    stz $56
    stz $58
    stz $5A
    stz $5C
    .i8
    ldx #$20
multiply_unsigned_double_words_in_software_c22b3c:
    asl $56
    rol $58
    rol $5A
    rol $5C
    asl $4E
    rol $50
    bcc multiply_unsigned_double_words_in_software_c22b63
    lda $56
    clc
    adc $46
    sta $56
    lda $58
    adc $48
    sta $58
    lda $5A
    adc $C5
    sta $5A
    lda $5C
    adc $C5
    sta $5C
multiply_unsigned_double_words_in_software_c22b63:
    dex
    bne multiply_unsigned_double_words_in_software_c22b3c
    plp
    rts
