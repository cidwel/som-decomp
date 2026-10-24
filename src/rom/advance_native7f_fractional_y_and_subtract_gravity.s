; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-entrance-chain.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9158
advance_native7f_fractional_y_and_subtract_gravity:
    lda a:$0030,X
    clc
    adc a:$003E,X
    sta a:$0030,X
    lda a:$0032,X
    adc a:$0040,X
    sta a:$0032,X
    lda a:$003E,X
    sec
    .a16
    sbc #$0100
    sta a:$003E,X
    lda a:$0040,X
    .a16
    sbc #$0000
    sta a:$0040,X
    rts
