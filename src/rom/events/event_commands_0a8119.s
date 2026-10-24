; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8119
.include "src/rom/event_command_macros.inc"
event_5F8_command_8119:
    event_actor_animation_loop 1, 128
event_5F8_command_811C:
    event_wait_idle 
