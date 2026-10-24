; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0DC1
.include "src/rom/event_command_macros.inc"
event_02F_command_0DC1:
    event_jump 1535
event_02F_command_0DC3:
    event_end 
event_030_command_0DC4:
    event_test_flag_range 77, 1, 15
event_030_command_0DC7:
    event_jump 47
event_030_command_0DC9:
    event_increment_flag 77
