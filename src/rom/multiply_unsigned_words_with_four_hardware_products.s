; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-unrecovered-55.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2AC3
multiply_unsigned_words_with_four_hardware_products:
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    stz $58
    stz $59
    lda $46
    sta a:$4202
    lda $4E
    sta a:$4203
    lda $47
    sta a:$4202
    nop
    lda a:$4216
    sta $56
    lda a:$4217
    sta $57
    lda $4E
    sta a:$4203
    lda $46
    sta a:$4202
    nop
    lda a:$4216
    clc
    adc $57
    sta $57
    lda a:$4217
    adc $58
    sta $58
    lda $4F
    sta a:$4203
    lda $47
    sta a:$4202
    nop
    lda a:$4216
    clc
    adc $57
    sta $57
    lda a:$4217
    adc $58
    sta $58
    lda $4F
    sta a:$4203
    plb
    rep #$20
    nop
    lda f:$004216
    clc
    adc $58
    sta $58
    rts
