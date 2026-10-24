; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5018
.include "src/rom/event_command_macros.inc"
event_4FD_command_5018:
    event_change_map 1001
event_4FD_command_501A:
    event_actor_walk 1, 0, 16
event_4FD_command_501D:
    event_wait_idle 
event_4FD_command_501E:
    event_actor_walk 1, 0, 63
event_4FD_command_5021:
    event_actor_walk 2, 0, 63
event_4FD_command_5024:
    event_wait_idle 
event_4FD_command_5025:
    event_actor_walk 1, 0, 40
event_4FD_command_5028:
    event_actor_walk 2, 0, 40
event_4FD_command_502B:
    event_wait_idle 
event_4FD_command_502C:
    event_actor_walk 2, 3, 8
event_4FD_command_502F:
    event_actor_walk 4, 1, 8
event_4FD_command_5032:
    event_wait_idle 
event_4FD_command_5033:
    event_actor_walk 2, 0, 16
event_4FD_command_5036:
    event_wait_idle 
event_4FD_command_5037:
    event_wait 16
