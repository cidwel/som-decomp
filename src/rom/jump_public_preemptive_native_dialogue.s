; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-message-update.md.
.setcpu "65816"
.smart
.a8
.i16

jump_internal_preemptive_native_dialogue = $0083

.segment "CODE"
.org $0003
jump_public_preemptive_native_dialogue:
    jmp jump_internal_preemptive_native_dialogue
