; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-numeric-selection.md.
.setcpu "65816"
.smart
.a8
.i16

read_numeric_choice_controller_and_dispatch_button_actions = $1A96

.segment "CODE"
.org $1A76
poll_native_dialogue_numeric_selection:
    jsr read_numeric_choice_controller_and_dispatch_button_actions
    rts
