; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5189
.include "src/rom/event_command_macros.inc"
event_4FD_command_5189:
    event_change_map 998
event_4FD_command_518B:
    event_actor_walk 1, 0, 8
event_4FD_command_518E:
    event_actor_walk 2, 0, 0
event_4FD_command_5191:
    event_wait_idle 
event_4FD_command_5192:
    event_actor_animation_loop 1, 137
event_4FD_command_5195:
    event_actor_animation_loop 2, 137
event_4FD_command_5198:
    event_wait_idle 
event_4FD_command_5199:
    event_wait 24
event_4FD_command_519B:
    event_call 82
event_4FD_command_519D:
    event_actor_walk 5, 1, 0
event_4FD_command_51A0:
    event_actor_walk 6, 1, 0
event_4FD_command_51A3:
    event_actor_walk 7, 1, 0
event_4FD_command_51A6:
    event_actor_walk 8, 1, 0
event_4FD_command_51A9:
    event_wait_idle 
