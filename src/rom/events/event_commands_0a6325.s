; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6325
.include "src/rom/event_command_macros.inc"
event_555_command_6325:
    event_actor_walk 128, 1, 0
event_555_command_6328:
    event_wait_idle 
event_555_command_6329:
    event_call 2008
