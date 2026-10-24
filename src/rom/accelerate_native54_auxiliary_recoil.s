; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $492C
accelerate_native54_auxiliary_recoil:
    lda a:$003C,X
    clc
    .a16
    adc #$0600
    sta a:$003C,X
    lda a:$0040,X
    clc
    .a16
    adc #$0400
    sta a:$0040,X
    lda a:$00B4,X
    clc
    adc a:$003C,X
    sta a:$00B4,X
    lda a:$00B6,X
    clc
    adc a:$0040,X
    sta a:$00B6,X
    sep #$20
    lda a:$00B5,X
    sta a:$F812,Y
    lda a:$00B7,X
    sta a:$F80E,Y
    rep #$20
    rts
