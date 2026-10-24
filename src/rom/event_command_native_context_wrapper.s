; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

accept_numeric_event_request = $E77B

.segment "CODE"
.org $E753
event_command_native_context_wrapper:
    php
    phd
    phb
    rep #$20
    pha
    .a16
    lda #$0000
    tcd
    sep #$20
    .a8
    lda #$7E
    pha
    plb
    rep #$20
    pla
    jsr accept_numeric_event_request
    plb
    pld
    plp
    rtl
