; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $81E4
.include "src/rom/event_command_macros.inc"
event_1E1_command_81E4:
    event_actor_walk 128, 0, 16
event_1E1_command_81E7:
    event_wait_idle 
event_1E1_command_81E8:
    event_call 1935
event_1E1_command_81EA:
    event_set_flag 23, 3
event_1E1_command_81ED:
    event_refresh_objects 
event_1E1_command_81EE:
    event_end 
event_1E2_command_81EF:
    event_call 1286
event_1E2_command_81F1:
    event_increment_flag 83
event_1E2_command_81F3:
    event_set_flag 23, 6
event_1E2_command_81F6:
    event_change_map 315
event_1E2_command_81F8:
    event_jump 1812
event_1E2_command_81FA:
    event_end 
event_1E3_command_81FB:
    event_test_flag_range 23, 6, 6
event_1E3_command_81FE:
    event_jump 493
event_1E3_command_8200:
    event_test_flag_range 23, 7, 7
event_1E3_command_8203:
    event_jump 494
