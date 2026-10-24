; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-rectangle-intersection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C621
intersect_native_unsigned_rectangles_into_bank_7f_buffer:
    phd
    php
    rep #$30
    pha
    tsc
    sec
    .a16
    sbc #$0008
    tcd
    tcs
    lda $09,S
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    sta $01
    lda a:$0004,X
    cmp a:$0004,Y
    bcc intersect_native_unsigned_rectangles_into_bank_7f_buffer_c647
    lda a:$0004,Y
intersect_native_unsigned_rectangles_into_bank_7f_buffer_c647:
    sta $07
    lda a:$0006,X
    cmp a:$0006,Y
    bcc intersect_native_unsigned_rectangles_into_bank_7f_buffer_c654
    lda a:$0006,Y
intersect_native_unsigned_rectangles_into_bank_7f_buffer_c654:
    sta $09
    lda a:$0000,X
    cmp a:$0000,Y
    bcs intersect_native_unsigned_rectangles_into_bank_7f_buffer_c661
    lda a:$0000,Y
intersect_native_unsigned_rectangles_into_bank_7f_buffer_c661:
    cmp $07
    bcs intersect_native_unsigned_rectangles_into_bank_7f_buffer_c693
    sta $03
    lda a:$0002,X
    cmp a:$0002,Y
    bcs intersect_native_unsigned_rectangles_into_bank_7f_buffer_c672
    lda a:$0002,Y
intersect_native_unsigned_rectangles_into_bank_7f_buffer_c672:
    cmp $09
    bcs intersect_native_unsigned_rectangles_into_bank_7f_buffer_c693
    sta $05
    ldx $01
    lda $03
    sta a:$0000,X
    lda $05
    sta a:$0002,X
    lda $07
    sta a:$0004,X
    lda $09
    sta a:$0006,X
    .a16
    lda #$0001
    bra intersect_native_unsigned_rectangles_into_bank_7f_buffer_c6a4
intersect_native_unsigned_rectangles_into_bank_7f_buffer_c693:
    ldx $01
    stz a:$0000,X
    stz a:$0002,X
    stz a:$0004,X
    stz a:$0006,X
    .a16
    lda #$0000
intersect_native_unsigned_rectangles_into_bank_7f_buffer_c6a4:
    plb
    sta $09,S
    tsc
    clc
    .a16
    adc #$0008
    tcs
    pla
    plp
    pld
    rts
