; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DE0B
.include "src/rom/event_command_macros.inc"
event_397_command_DE0B:
    event_jump 1805
event_397_command_DE0D:
    event_end 
event_398_command_DE0E:
    event_freeze 
event_398_command_DE0F:
    event_actor_walk 128, 0, 32
event_398_command_DE12:
    event_wait_idle 
event_398_command_DE13:
    event_increment_flag 48
event_398_command_DE15:
    event_refresh_objects 
event_398_command_DE16:
    event_end 
event_399_command_DE17:
    event_test_flag_range 48, 3, 3
event_399_command_DE1A:
    event_jump 919
event_399_command_DE1C:
    event_test_flag_range 48, 4, 15
event_399_command_DE1F:
    event_jump 918
