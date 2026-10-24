; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2CE6
divide_unsigned_double_words_in_software:
    lda $4E
    ora $50
    beq divide_unsigned_double_words_in_software_c22d2a
    php
    sep #$10
    stz $56
    stz $58
    stz $5E
    stz $60
    .i8
    ldx #$20
divide_unsigned_double_words_in_software_c22cf9:
    asl $56
    rol $58
    asl $46
    rol $48
    rol $5E
    rol $60
    sec
    lda $5E
    sbc $4E
    lda $60
    sbc $50
    bcc divide_unsigned_double_words_in_software_c22d23
    sec
    lda $5E
    sbc $4E
    sta $5E
    lda $60
    sbc $50
    sta $60
    inc $56
    bne divide_unsigned_double_words_in_software_c22d23
    inc $58
divide_unsigned_double_words_in_software_c22d23:
    dex
    bne divide_unsigned_double_words_in_software_c22cf9
    plp
    lda $C5
    rts
divide_unsigned_double_words_in_software_c22d2a:
    .a16
    lda #$FFFF
    rts
