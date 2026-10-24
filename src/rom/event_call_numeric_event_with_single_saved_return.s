; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-numeric-call.md.
.setcpu "65816"
.smart
.a8
.i16

accept_numeric_event_request = $E77B
dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $EBF2
event_call_numeric_event_with_single_saved_return:
    lda $D3
    sta $D8
    .a8
    lda #$FF
    sta $D0
    rep #$20
    lda $D1
    clc
    .a16
    adc #$0002
    sta $D6
    sep #$20
    lda $04
    .a8
    and #$07
    xba
    lda $05
    jsr accept_numeric_event_request
    sep #$20
    lda $D0
    bne event_call_numeric_event_with_single_saved_return_c1ec17
    rts
event_call_numeric_event_with_single_saved_return_c1ec17:
    brl dispatch_native_event_opcode_or_wait_state
