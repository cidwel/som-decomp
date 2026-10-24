; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3ABC
.include "src/rom/event_command_macros.inc"
event_127_command_3ABC:
    event_actor_walk 6, 0, 60
event_127_command_3ABF:
    event_wait_idle 
event_127_command_3AC0:
    event_actor_walk 6, 2, 46
