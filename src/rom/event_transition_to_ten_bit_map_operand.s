; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-map-transition-commands.md.
.setcpu "65816"
.smart
.a8
.i16

accept_numeric_event_request = $E77B

.segment "CODE"
.org $EB07
event_transition_to_ten_bit_map_operand:
    rep #$20
    inc $D1
    inc $D1
    lda $04
    xba
    .a16
    and #$03FF
    .a16
    ora #$0800
    brl accept_numeric_event_request
