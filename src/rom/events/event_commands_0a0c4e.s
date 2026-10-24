; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0C4E
.include "src/rom/event_command_macros.inc"
event_400_command_0C4E:
    event_change_map 207
event_400_command_0C50:
    event_actor_walk 0, 3, 0
event_400_command_0C53:
    event_wait_idle 
event_400_command_0C54:
    event_actor_animation_loop 0, 139
event_400_command_0C57:
    event_wait_idle 
