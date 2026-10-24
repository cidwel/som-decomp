; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-control.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $F2E9
event_wait_for_party_gather:
    lda $4E
    beq event_wait_for_party_gather_c1f2ee
    rts
event_wait_for_party_gather_c1f2ee:
    .a8
    lda #$01
    sta $D0
    brl dispatch_native_event_opcode_or_wait_state
