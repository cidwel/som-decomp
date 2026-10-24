; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-map-transition-commands.md.
.setcpu "65816"
.smart
.a8
.i16

accept_numeric_event_request = $E77B

.segment "CODE"
.org $EAB4
event_transition_to_remembered_map:
    rep #$20
    inc $D1
    lda a:$0108
    .a16
    ora #$0800
    brl accept_numeric_event_request
