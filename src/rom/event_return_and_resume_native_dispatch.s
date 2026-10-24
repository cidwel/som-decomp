; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $E9EC
event_return_and_resume_native_dispatch:
    lda $D6
    sta $D1
    lda $D7
    sta $D2
    lda $D8
    sta $D3
    brl dispatch_native_event_opcode_or_wait_state
