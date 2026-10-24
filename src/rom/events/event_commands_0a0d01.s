; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0D01
.include "src/rom/event_command_macros.inc"
event_400_command_0D01:
    event_change_map 205
event_400_command_0D03:
    event_actor_walk 0, 2, 0
event_400_command_0D06:
    event_wait_idle 
event_400_command_0D07:
    event_actor_animation_loop 0, 139
event_400_command_0D0A:
    event_wait_idle 
