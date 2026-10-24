; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $556E
.include "src/rom/event_command_macros.inc"
event_4FD_command_556E:
    event_change_map 67
event_4FD_command_5570:
    event_actor_walk 1, 0, 9
event_4FD_command_5573:
    event_actor_walk 2, 0, 17
event_4FD_command_5576:
    event_wait_idle 
event_4FD_command_5577:
    event_actor_walk 1, 2, 60
event_4FD_command_557A:
    event_actor_walk 2, 2, 60
event_4FD_command_557D:
    event_wait_idle 
event_4FD_command_557E:
    event_actor_walk 1, 2, 60
event_4FD_command_5581:
    event_actor_walk 2, 2, 60
event_4FD_command_5584:
    event_wait_idle 
event_4FD_command_5585:
    event_actor_walk 1, 2, 56
event_4FD_command_5588:
    event_actor_walk 2, 2, 56
event_4FD_command_558B:
    event_wait_idle 
event_4FD_command_558C:
    event_actor_walk 1, 0, 0
event_4FD_command_558F:
    event_actor_walk 4, 3, 8
event_4FD_command_5592:
    event_wait_idle 
