; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $17CF
.include "src/rom/event_command_macros.inc"
event_4A0_command_17CF:
    event_jump 1535
event_4A0_command_17D1:
    event_end 
event_4A1_command_17D2:
    event_test_flag_range 68, 5, 15
event_4A1_command_17D5:
    event_jump 0
event_4A1_command_17D7:
    event_call 1151
