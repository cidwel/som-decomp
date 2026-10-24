; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2855
.include "src/rom/event_command_macros.inc"
event_104_command_2855:
    event_jump 1535
event_104_command_2857:
    event_end 
event_105_command_2858:
    event_test_flag_range 16, 3, 15
event_105_command_285B:
    event_jump 0
event_105_command_285D:
    event_freeze 
event_105_command_285E:
    event_set_flag 16, 3
event_105_command_2861:
    event_call 1864
