; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8B33
.include "src/rom/event_command_macros.inc"
event_1F6_command_8B33:
    event_actor_animation_loop 3, 165
event_1F6_command_8B36:
    event_wait_idle 
