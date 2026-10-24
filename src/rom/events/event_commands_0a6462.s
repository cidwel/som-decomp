; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6462
.include "src/rom/event_command_macros.inc"
event_555_command_6462:
    event_actor_walk 1, 0, 8
event_555_command_6465:
    event_wait_idle 
event_555_command_6466:
    event_actor_walk 1, 2, 0
event_555_command_6469:
    event_wait_idle 
event_555_command_646A:
    event_actor_animation 1, 0
event_555_command_646D:
    event_wait_idle 
event_555_command_646E:
    event_call 1927
event_555_command_6470:
    event_actor_walk 128, 0, 32
event_555_command_6473:
    event_wait_idle 
event_555_command_6474:
    event_actor_walk 1, 0, 0
event_555_command_6477:
    event_actor_walk 3, 0, 8
event_555_command_647A:
    event_wait_idle 
event_555_command_647B:
    event_actor_walk 128, 1, 0
event_555_command_647E:
    event_wait_idle 
