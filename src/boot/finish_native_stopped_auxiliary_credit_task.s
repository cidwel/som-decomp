; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-auxiliary-cleanup-abi.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7e8dac = $8DAC

.segment "CODE"
.org $8E94
finish_native_stopped_auxiliary_credit_task:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    jsr routine_7e8dac
    plb
    plp
    pld
    rtl
