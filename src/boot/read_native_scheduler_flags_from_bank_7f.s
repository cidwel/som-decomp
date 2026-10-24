; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-scheduler-flags.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $A814
read_native_scheduler_flags_from_bank_7f:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    lda a:$0096
    plb
    plp
    pld
    rts
