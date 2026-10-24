; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-fields-and-bindings.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3
set_event_actor_motion_after_charge_and_palette_cleanup = $EEAF

.segment "CODE"
.org $EFD1
event_set_actor_motion_and_pause_its_execution:
    jsr set_event_actor_motion_after_charge_and_palette_cleanup
    .a8
    lda #$30
    sta a:$E01C,X
    stz a:$E042,X
    brl dispatch_native_event_opcode_or_wait_state
