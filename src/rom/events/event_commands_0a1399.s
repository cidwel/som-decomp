; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1399
.include "src/rom/event_command_macros.inc"
event_429_command_1399:
    event_screen_word 6, 65535
event_429_command_139D:
    event_call 1849
event_429_command_139F:
    event_change_map 188
event_429_command_13A1:
    event_increment_flag 255
event_429_command_13A3:
    event_set_flag 11, 15
event_429_command_13A6:
    event_actor_walk 1, 0, 0
event_429_command_13A9:
    event_actor_walk 2, 3, 8
event_429_command_13AC:
    event_actor_walk 3, 2, 8
event_429_command_13AF:
    event_wait_idle 
event_429_command_13B0:
    event_actor_walk 1, 0, 0
event_429_command_13B3:
    event_actor_walk 2, 0, 0
event_429_command_13B6:
    event_actor_walk 3, 0, 0
event_429_command_13B9:
    event_wait_idle 
