; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2A82
.include "src/rom/event_command_macros.inc"
event_106_command_2A82:
    event_actor_walk 5, 3, 16
event_106_command_2A85:
    event_actor_walk 6, 3, 16
event_106_command_2A88:
    event_actor_walk 0, 0, 0
event_106_command_2A8B:
    event_wait_idle 
event_106_command_2A8C:
    event_actor_walk 5, 3, 16
event_106_command_2A8F:
    event_actor_walk 6, 3, 16
event_106_command_2A92:
    event_actor_animation_loop 0, 136
event_106_command_2A95:
    event_wait_idle 
