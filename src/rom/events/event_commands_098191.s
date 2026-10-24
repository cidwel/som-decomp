; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8191
.include "src/rom/event_command_macros.inc"
event_1DF_command_8191:
    event_jump 255
event_1DF_command_8193:
    event_jump 79
event_1DF_command_8195:
    event_jump 769
event_1DF_command_8197:
    event_jump 787
event_1DF_command_8199:
    event_end 
event_1E0_command_819A:
    event_test_flag_range 23, 0, 5
event_1E0_command_819D:
    event_jump 1808
event_1E0_command_819F:
    event_end 
event_1E1_command_81A0:
    event_freeze 
event_1E1_command_81A1:
    event_gather 
event_1E1_command_81A2:
    event_screen 8
