; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6DD6
.include "src/rom/event_command_macros.inc"
event_1B9_command_6DD6:
    event_actor_animation_loop 4, 130
