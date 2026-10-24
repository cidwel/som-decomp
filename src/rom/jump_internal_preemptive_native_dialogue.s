; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-message-update.md.
.setcpu "65816"
.smart
.a8
.i16

preempt_native_dialogue_and_restore_temporary_window = $012C

.segment "CODE"
.org $0083
jump_internal_preemptive_native_dialogue:
    jmp preempt_native_dialogue_and_restore_temporary_window
