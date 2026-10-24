; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

accept_numeric_event_request = $E77B

.segment "CODE"
.org $E76D
event_command_map_context_entry:
    sep #$20
    phb
    pha
    .a8
    lda #$7E
    pha
    plb
    pla
    jsr accept_numeric_event_request
    plb
    rtl
