; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-byte-port-math.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2C2F
combine_two_signed_mode7_partial_products:
    sep #$20
    lda $46
    sta f:$00211B
    lda $47
    sta f:$00211B
    lda $4E
    sta f:$00211C
    lda f:$002134
    sta $56
    lda f:$002135
    sta $57
    lda f:$002136
    sta $58
    stz $59
    bpl combine_two_signed_mode7_partial_products_c22c5d
    .a8
    lda #$FF
    sta $59
combine_two_signed_mode7_partial_products_c22c5d:
    lda $46
    sta f:$00211B
    lda $47
    sta f:$00211B
    lda $4F
    sta f:$00211C
    clc
    lda $C5
    adc $56
    sta $56
    lda f:$002134
    adc $57
    sta $57
    lda f:$002135
    adc $58
    sta $58
    lda f:$002136
    adc $59
    sta $59
    rep #$20
    rts
