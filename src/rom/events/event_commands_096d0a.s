; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6D0A
.include "src/rom/event_command_macros.inc"
event_1B9_command_6D0A:
    event_actor_animation_loop 4, 165
