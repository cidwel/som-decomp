; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7D89
.include "src/rom/event_command_macros.inc"
event_5F8_command_7D89:
    event_actor_animation_loop 3, 166
event_5F8_command_7D8C:
    event_wait_idle 
