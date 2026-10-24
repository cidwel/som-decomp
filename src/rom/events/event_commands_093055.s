; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3055
.include "src/rom/event_command_macros.inc"
event_10C_command_3055:
    event_call 1927
event_10C_command_3057:
    event_actor_animation 0, 140
event_10C_command_305A:
    event_actor_walk 4, 1, 16
event_10C_command_305D:
    event_wait_idle 
event_10C_command_305E:
    event_call 1927
event_10C_command_3060:
    event_actor_animation 0, 140
event_10C_command_3063:
    event_actor_walk 4, 1, 16
event_10C_command_3066:
    event_wait_idle 
