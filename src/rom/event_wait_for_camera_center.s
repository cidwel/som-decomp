; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F37B
event_wait_for_camera_center:
    lda $E2
    .a8
    bit #$08
    beq event_wait_for_camera_center_c1f382
    rts
event_wait_for_camera_center_c1f382:
    .a8
    lda #$01
    sta $D0
    brl dispatch_native_event_opcode_or_wait_state
