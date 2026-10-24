; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B1BA
.include "src/rom/event_command_macros.inc"
event_29C_command_B1BA:
    event_actor_walk 4, 0, 0
event_29C_command_B1BD:
    event_wait_idle 
event_29C_command_B1BE:
    event_actor_walk 4, 2, 0
event_29C_command_B1C1:
    event_wait_idle 
event_29C_command_B1C2:
    event_wait 0
