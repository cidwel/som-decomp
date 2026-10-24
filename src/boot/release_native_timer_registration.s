; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-protocol-messages.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CBCA
release_native_timer_registration:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    stz a:$0000,X
    plb
    plp
    pld
    rts
