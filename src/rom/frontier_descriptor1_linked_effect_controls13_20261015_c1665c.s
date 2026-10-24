; Source-created linked-effect functional fields only.
.setcpu "65816"
.segment "RODATA"
.org $665C
linked_effect_control_span:
linked_effect_initial_frame_ticks = 0
    .byte linked_effect_initial_frame_ticks
.assert * - linked_effect_control_span = 1, error, "Exact control span"
