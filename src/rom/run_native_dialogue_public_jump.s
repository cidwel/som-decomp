; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-coordinator.md.
.setcpu "65816"
.smart
.a8
.i16

run_native_dialogue_with_normal_window_geometry = $0113

.segment "CODE"
.org $0092
run_native_dialogue_public_jump:
    jmp run_native_dialogue_with_normal_window_geometry
