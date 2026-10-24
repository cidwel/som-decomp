; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $13AF
.include "src/rom/event_command_macros.inc"
event_082_command_13AF:
    event_jump 132
event_082_command_13B1:
    event_end 
event_083_command_13B2:
    event_freeze 
event_083_command_13B3:
    event_gather 
event_083_command_13B4:
    event_actor_walk 1, 1, 8
event_083_command_13B7:
    event_actor_walk 2, 1, 16
event_083_command_13BA:
    event_actor_walk 3, 1, 24
event_083_command_13BD:
    event_wait_idle 
