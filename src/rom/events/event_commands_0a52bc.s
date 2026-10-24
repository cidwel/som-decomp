; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $52BC
.include "src/rom/event_command_macros.inc"
event_4FD_command_52BC:
    event_change_map 345
event_4FD_command_52BE:
    event_actor_walk 2, 2, 8
event_4FD_command_52C1:
    event_wait_idle 
event_4FD_command_52C2:
    event_actor_walk 2, 1, 0
event_4FD_command_52C5:
    event_wait_idle 
