; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $52D9
.include "src/rom/event_command_macros.inc"
event_4FD_command_52D9:
    event_change_map 1007
event_4FD_command_52DB:
    event_actor_walk 2, 2, 8
event_4FD_command_52DE:
    event_wait_idle 
event_4FD_command_52DF:
    event_actor_walk 1, 0, 0
event_4FD_command_52E2:
    event_actor_walk 2, 0, 0
event_4FD_command_52E5:
    event_wait_idle 
event_4FD_command_52E6:
    event_actor_animation_loop 4, 129
event_4FD_command_52E9:
    event_actor_animation_loop 5, 129
event_4FD_command_52EC:
    event_actor_animation_loop 6, 129
event_4FD_command_52EF:
    event_wait_idle 
