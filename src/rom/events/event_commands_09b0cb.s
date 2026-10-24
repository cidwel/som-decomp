; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B0CB
.include "src/rom/event_command_macros.inc"
event_29B_command_B0CB:
    event_wait 8
event_29B_command_B0CD:
    event_actor_animation_loop 3, 165
event_29B_command_B0D0:
    event_wait 16
