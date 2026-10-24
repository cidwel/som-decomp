; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1095
.include "src/rom/event_command_macros.inc"
event_429_command_1095:
    event_actor_walk 1, 0, 0
event_429_command_1098:
    event_wait_idle 
