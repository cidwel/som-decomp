; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-flags.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F1BE
event_skip_five_script_bytes_and_resume_dispatch:
    rep #$20
    lda $D1
    clc
    .a16
    adc #$0005
    sta $D1
    brl dispatch_native_event_opcode_or_wait_state
