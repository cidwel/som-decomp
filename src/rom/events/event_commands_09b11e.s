; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $B11E
.include "src/rom/event_command_macros.inc"
event_29C_command_B11E:
    event_actor_walk 4, 0, 0
event_29C_command_B121:
    event_wait_idle 
event_29C_command_B122:
    event_actor_walk 4, 2, 0
event_29C_command_B125:
    event_wait_idle 
event_29C_command_B126:
    event_wait 0
