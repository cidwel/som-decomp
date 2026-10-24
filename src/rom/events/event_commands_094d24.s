; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4D24
.include "src/rom/event_command_macros.inc"
event_167_command_4D24:
    event_actor_walk 1, 0, 0
event_167_command_4D27:
    event_actor_walk 2, 0, 16
event_167_command_4D2A:
    event_actor_walk 3, 0, 0
event_167_command_4D2D:
    event_wait_idle 
event_167_command_4D2E:
    event_screen 8
event_167_command_4D30:
    event_wait 8
