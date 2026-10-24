; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A50D
.include "src/rom/event_command_macros.inc"
event_26A_command_A50D:
    event_actor_walk 5, 0, 0
event_26A_command_A510:
    event_wait_idle 
event_26A_command_A511:
    event_jump 1535
event_26A_command_A513:
    event_end 
event_26B_command_A514:
    event_set_flag 10, 0
event_26B_command_A517:
    event_audio_request 241, 0, 0, 0
event_26B_command_A51C:
    event_return 
event_26B_command_A51D:
    event_end 
event_26C_command_A51E:
    event_test_flag_range 10, 1, 15
event_26C_command_A521:
    event_call 619
event_26C_command_A523:
    event_jump 1564
event_26C_command_A525:
    event_end 
