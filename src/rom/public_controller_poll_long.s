; Recovered Secret of Mana USA routine; behaviour documented in docs/game-controller-poll.md.
.setcpu "65816"
.smart
.a8
.i16

poll_controllers_preserving_native_context = $939F

.segment "CODE"
.org $8000
public_controller_poll_long:
    jsr poll_controllers_preserving_native_context
    rtl
