; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-movement.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3
set_event_actor_motion_after_charge_and_palette_cleanup = $EEAF

.segment "CODE"
.org $EEA9
event_set_actor_motion_and_resume_dispatch:
    jsr set_event_actor_motion_after_charge_and_palette_cleanup
    brl dispatch_native_event_opcode_or_wait_state
