; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2CFD
.include "src/rom/event_command_macros.inc"
event_10C_command_2CFD:
    event_freeze 
event_10C_command_2CFE:
    event_actor_walk 4, 2, 16
event_10C_command_2D01:
    event_actor_walk 5, 1, 0
event_10C_command_2D04:
    event_actor_walk 6, 2, 16
event_10C_command_2D07:
    event_wait_idle 
event_10C_command_2D08:
    event_actor_walk 4, 1, 14
event_10C_command_2D0B:
    event_actor_walk 6, 1, 0
event_10C_command_2D0E:
    event_wait_idle 
