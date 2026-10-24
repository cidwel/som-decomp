; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2D27
.include "src/rom/event_command_macros.inc"
event_4E1_command_2D27:
    event_actor_walk 2, 0, 16
event_4E1_command_2D2A:
    event_wait_idle 
event_4E1_command_2D2B:
    event_actor_walk 2, 2, 8
event_4E1_command_2D2E:
    event_actor_walk 4, 2, 32
event_4E1_command_2D31:
    event_wait_idle 
event_4E1_command_2D32:
    event_actor_walk 2, 3, 0
event_4E1_command_2D35:
    event_actor_walk 4, 1, 0
event_4E1_command_2D38:
    event_wait_idle 
event_4E1_command_2D39:
    event_actor_animation 2, 0
event_4E1_command_2D3C:
    event_wait_idle 
event_4E1_command_2D3D:
    event_screen 0
event_4E1_command_2D3F:
    event_call 1934
event_4E1_command_2D41:
    event_screen 1
