; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BE2A
.include "src/rom/event_command_macros.inc"
event_2CC_command_BE2A:
    event_jump 1535
event_2CC_command_BE2C:
    event_end 
event_2CD_command_BE2D:
    event_test_flag_range 38, 0, 5
event_2CD_command_BE30:
    event_jump 718
event_2CD_command_BE32:
    event_test_flag_range 147, 0, 2
event_2CD_command_BE35:
    event_jump 0
event_2CD_command_BE37:
    event_actor_walk 0, 0, 63
event_2CD_command_BE3A:
    event_wait_idle 
event_2CD_command_BE3B:
    event_call 1152
event_2CD_command_BE3D:
    event_set_flag 147, 0
event_2CD_command_BE40:
    event_refresh_objects 
