; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6719
.include "src/rom/event_command_macros.inc"
event_559_command_6719:
    event_actor_walk 2, 1, 8
event_559_command_671C:
    event_wait_idle 
event_559_command_671D:
    event_wait 16
event_559_command_671F:
    event_actor_animation_loop 2, 167
event_559_command_6722:
    event_wait_idle 
event_559_command_6723:
    event_wait 32
