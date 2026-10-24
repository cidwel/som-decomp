; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-pause-gate-header.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $C01E
read_native_current_program_header_pointer:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$02E2
    plb
    plp
    pld
    rts
