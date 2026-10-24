; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-input-ownership.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A4D7
clear_native_boot_input_owner:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    stz a:$0097
    plb
    plp
    pld
    rts
