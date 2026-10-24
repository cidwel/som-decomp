; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F341
event_resume_dispatch_immediately:
    .a8
    lda #$01
    sta $D0
    brl dispatch_native_event_opcode_or_wait_state
