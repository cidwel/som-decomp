; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-task-access-wrappers.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AE28
reserved_native_bank_7f_near_api:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    plb
    plp
    pld
    rts
