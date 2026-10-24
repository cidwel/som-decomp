; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $31B1
.include "src/rom/event_command_macros.inc"
event_4E1_command_31B1:
    event_decrement_flag 255
event_4E1_command_31B3:
    event_jump 1804
event_4E1_command_31B5:
    event_end 
event_4E2_command_31B6:
    event_freeze 
event_4E2_command_31B7:
    event_test_flag_range 33, 13, 14
event_4E2_command_31BA:
    event_jump 591
