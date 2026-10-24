; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5F7A
.include "src/rom/event_command_macros.inc"
event_193_command_5F7A:
    event_actor_walk 0, 3, 0
event_193_command_5F7D:
    event_wait_idle 
event_193_command_5F7E:
    event_actor_animation 0, 140
event_193_command_5F81:
    event_wait_idle 
event_193_command_5F82:
    event_actor_walk 6, 1, 32
event_193_command_5F85:
    event_actor_walk 5, 1, 32
event_193_command_5F88:
    event_wait_idle 
event_193_command_5F89:
    event_actor_walk 6, 3, 32
event_193_command_5F8C:
    event_actor_walk 5, 1, 32
event_193_command_5F8F:
    event_wait_idle 
event_193_command_5F90:
    event_actor_walk 6, 1, 32
event_193_command_5F93:
    event_actor_walk 5, 3, 32
event_193_command_5F96:
    event_wait_idle 
event_193_command_5F97:
    event_actor_walk 5, 1, 56
event_193_command_5F9A:
    event_wait_idle 
event_193_command_5F9B:
    event_set_flag 19, 3
event_193_command_5F9E:
    event_refresh_objects 
event_193_command_5F9F:
    event_end 
event_194_command_5FA0:
    event_actor_walk 5, 1, 0
event_194_command_5FA3:
    event_wait_idle 
