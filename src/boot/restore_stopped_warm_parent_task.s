; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-scheduler-cycle.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $9364
restore_stopped_warm_parent_task:
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
    rtl
