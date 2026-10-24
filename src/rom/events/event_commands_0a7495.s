; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7495
.include "src/rom/event_command_macros.inc"
event_592_command_7495:
    event_actor_animation_loop 3, 166
event_592_command_7498:
    event_wait_idle 
event_592_command_7499:
    event_wait 24
