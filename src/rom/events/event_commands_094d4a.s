; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4D4A
.include "src/rom/event_command_macros.inc"
event_167_command_4D4A:
    event_call 1927
event_167_command_4D4C:
    event_actor_animation 2, 130
event_167_command_4D4F:
    event_call 1927
event_167_command_4D51:
    event_actor_walk 4, 0, 16
event_167_command_4D54:
    event_actor_walk 5, 0, 16
event_167_command_4D57:
    event_wait_idle 
event_167_command_4D58:
    event_actor_walk 2, 0, 8
event_167_command_4D5B:
    event_actor_walk 4, 0, 63
event_167_command_4D5E:
    event_actor_walk 5, 0, 63
event_167_command_4D61:
    event_wait_idle 
event_167_command_4D62:
    event_increment_flag 26
event_167_command_4D64:
    event_refresh_objects 
event_167_command_4D65:
    event_actor_walk 2, 1, 0
