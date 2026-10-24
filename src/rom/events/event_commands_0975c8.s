; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $75C8
.include "src/rom/event_command_macros.inc"
event_1CE_command_75C8:
    event_test_flag_range 15, 1, 15
event_1CE_command_75CB:
    event_jump 461
event_1CE_command_75CD:
    event_call 1943
event_1CE_command_75CF:
    event_increment_flag 47
event_1CE_command_75D1:
    event_freeze 
event_1CE_command_75D2:
    event_gather 
event_1CE_command_75D3:
    event_actor_walk 1, 0, 60
event_1CE_command_75D6:
    event_actor_walk 2, 0, 52
event_1CE_command_75D9:
    event_actor_walk 4, 0, 56
event_1CE_command_75DC:
    event_wait_idle 
event_1CE_command_75DD:
    event_actor_walk 1, 2, 8
event_1CE_command_75E0:
    event_actor_walk 2, 2, 0
event_1CE_command_75E3:
    event_actor_walk 4, 3, 0
event_1CE_command_75E6:
    event_wait_idle 
event_1CE_command_75E7:
    event_screen 8
