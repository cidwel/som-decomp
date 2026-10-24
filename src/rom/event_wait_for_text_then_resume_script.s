; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F2F5
event_wait_for_text_then_resume_script:
    lda $48
    beq event_wait_for_text_then_resume_script_c1f2fa
    rts
event_wait_for_text_then_resume_script_c1f2fa:
    lda a:$1D01
    sta $D1
    lda a:$1D02
    sta $D2
    lda a:$1D03
    sta $D3
    .a8
    lda #$01
    sta $D0
    brl dispatch_native_event_opcode_or_wait_state
