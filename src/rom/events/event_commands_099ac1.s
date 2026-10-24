; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9AC1
.include "src/rom/event_command_macros.inc"
event_22E_command_9AC1:
    event_actor_animation_loop 2, 166
event_22E_command_9AC4:
    event_wait_idle 
event_22E_command_9AC5:
    event_wait 0
