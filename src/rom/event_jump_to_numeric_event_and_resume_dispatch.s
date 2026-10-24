; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-numeric-jump.md.
.setcpu "65816"
.smart
.a8
.i16

accept_numeric_event_request = $E77B
dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $EAF0
event_jump_to_numeric_event_and_resume_dispatch:
    stz $D0
    rep #$20
    lda $04
    xba
    .a16
    and #$07FF
    jsr accept_numeric_event_request
    sep #$20
    lda $D0
    bne event_jump_to_numeric_event_and_resume_dispatch_c1eb04
    rts
event_jump_to_numeric_event_and_resume_dispatch_c1eb04:
    brl dispatch_native_event_opcode_or_wait_state
