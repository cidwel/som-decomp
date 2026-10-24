; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6798
.include "src/rom/event_command_macros.inc"
event_559_command_6798:
    event_set_flag 50, 2
event_559_command_679B:
    event_end 
event_55A_command_679C:
    event_test_flag_range 45, 0, 4
event_55A_command_679F:
    event_jump 1373
event_55A_command_67A1:
    event_test_flag_range 45, 6, 15
event_55A_command_67A4:
    event_jump 1372
event_55A_command_67A6:
    event_change_map 334
event_55A_command_67A8:
    event_jump 1368
event_55A_command_67AA:
    event_end 
event_55B_command_67AB:
    event_test_flag_range 45, 0, 4
event_55B_command_67AE:
    event_jump 1373
event_55B_command_67B0:
    event_test_flag_range 45, 6, 15
event_55B_command_67B3:
    event_jump 1372
event_55B_command_67B5:
    event_change_map 159
event_55B_command_67B7:
    event_jump 1368
event_55B_command_67B9:
    event_end 
event_55C_command_67BA:
    event_freeze 
event_55C_command_67BB:
    event_gather 
event_55C_command_67BC:
    event_call 96
