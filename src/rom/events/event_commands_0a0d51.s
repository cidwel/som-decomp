; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0D51
.include "src/rom/event_command_macros.inc"
event_400_command_0D51:
    event_change_map 204
event_400_command_0D53:
    event_actor_walk 0, 1, 0
event_400_command_0D56:
    event_wait_idle 
event_400_command_0D57:
    event_actor_animation_loop 0, 139
event_400_command_0D5A:
    event_wait_idle 
