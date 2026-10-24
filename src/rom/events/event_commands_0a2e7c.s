; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2E7C
.include "src/rom/event_command_macros.inc"
event_4E1_command_2E7C:
    event_actor_animation 2, 140
event_4E1_command_2E7F:
    event_wait_idle 
event_4E1_command_2E80:
    event_call 92
event_4E1_command_2E82:
    event_actor_animation_loop 2, 128
event_4E1_command_2E85:
    event_wait_idle 
event_4E1_command_2E86:
    event_actor_walk 1, 0, 24
event_4E1_command_2E89:
    event_actor_walk 3, 0, 8
event_4E1_command_2E8C:
    event_wait_idle 
event_4E1_command_2E8D:
    event_actor_walk 1, 2, 16
event_4E1_command_2E90:
    event_actor_walk 3, 2, 0
event_4E1_command_2E93:
    event_wait_idle 
event_4E1_command_2E94:
    event_screen 8
