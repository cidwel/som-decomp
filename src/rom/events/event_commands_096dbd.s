; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6DBD
.include "src/rom/event_command_macros.inc"
event_1B9_command_6DBD:
    event_actor_walk 4, 1, 0
event_1B9_command_6DC0:
    event_wait_idle 
