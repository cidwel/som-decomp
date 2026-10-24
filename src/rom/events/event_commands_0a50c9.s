; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $50C9
.include "src/rom/event_command_macros.inc"
event_4FD_command_50C9:
    event_change_map 623
event_4FD_command_50CB:
    event_actor_animation_loop 1, 139
event_4FD_command_50CE:
    event_actor_animation_loop 2, 139
event_4FD_command_50D1:
    event_actor_animation_loop 4, 129
event_4FD_command_50D4:
    event_wait_idle 
