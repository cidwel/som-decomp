; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4E20
.include "src/rom/event_command_macros.inc"
event_4FD_command_4E20:
    event_wait 32
event_4FD_command_4E22:
    event_actor_walk 1, 0, 0
event_4FD_command_4E25:
    event_actor_walk 2, 0, 0
event_4FD_command_4E28:
    event_wait_idle 
