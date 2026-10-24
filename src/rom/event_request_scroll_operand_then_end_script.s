; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-map-transition-commands.md.
.setcpu "65816"
.smart
.a8
.i16

accept_numeric_event_request = $E77B
event_end_and_release_party_controls = $E9C4

.segment "CODE"
.org $EB19
event_request_scroll_operand_then_end_script:
    rep #$20
    inc $D1
    inc $D1
    lda $05
    .a16
    and #$00FF
    .a16
    ora #$0C00
    jsr accept_numeric_event_request
    sep #$20
    brl event_end_and_release_party_controls
