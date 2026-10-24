; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F310
event_wait_for_frame_count:
    dec $4F
    beq event_wait_for_frame_count_c1f315
    rts
event_wait_for_frame_count_c1f315:
    .a8
    lda #$01
    sta $D0
    brl dispatch_native_event_opcode_or_wait_state
