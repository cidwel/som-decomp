; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $138E
.include "src/rom/event_command_macros.inc"
event_429_command_138E:
    event_actor_walk 2, 2, 0
event_429_command_1391:
    event_wait_idle 
event_429_command_1392:
    event_wait 32
event_429_command_1394:
    event_call 89
event_429_command_1396:
    event_wait 0
