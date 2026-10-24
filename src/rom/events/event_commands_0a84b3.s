; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $84B3
.include "src/rom/event_command_macros.inc"
event_5F8_command_84B3:
    event_actor_animation_loop 3, 171
event_5F8_command_84B6:
    event_wait_idle 
