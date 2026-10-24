; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-fields-and-bindings.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3

.segment "CODE"
.org $EFFA
event_branch_on_current_actor_slot:
    rep #$10
    sta $00
    ldy $D1
    iny
    iny
    lda $D5
    lsr
    cmp $05
    beq event_branch_on_current_actor_slot_c1f00b
    iny
    iny
event_branch_on_current_actor_slot_c1f00b:
    sty $D1
    brl dispatch_native_event_opcode_or_wait_state
