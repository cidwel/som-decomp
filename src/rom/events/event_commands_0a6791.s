; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6791
.include "src/rom/event_command_macros.inc"
event_559_command_6791:
    event_actor_walk 2, 1, 0
event_559_command_6794:
    event_wait_idle 
event_559_command_6795:
    event_wait 0
