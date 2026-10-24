; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2CBF
divide_unsigned_word_by_word_in_software:
    lda $4E
    beq divide_unsigned_word_by_word_in_software_c22ce2
    php
    sep #$10
    stz $56
    lda $C5
    .i8
    ldx #$10
divide_unsigned_word_by_word_in_software_c22ccc:
    asl $56
    asl $46
    rol
    cmp $4E
    bcc divide_unsigned_word_by_word_in_software_c22cd9
    sbc $4E
    inc $56
divide_unsigned_word_by_word_in_software_c22cd9:
    dex
    bne divide_unsigned_word_by_word_in_software_c22ccc
    sta $5E
    plp
    lda $C5
    rts
divide_unsigned_word_by_word_in_software_c22ce2:
    .a16
    lda #$FFFF
    rts
