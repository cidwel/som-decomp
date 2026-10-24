; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9FB1
.include "src/rom/event_command_macros.inc"
event_24F_command_9FB1:
    event_jump 1535
event_24F_command_9FB3:
    event_end 
event_250_command_9FB4:
    event_test_flag_range 34, 1, 1
event_250_command_9FB7:
    event_jump 1796
event_250_command_9FB9:
    event_test_flag_range 34, 2, 15
event_250_command_9FBC:
    event_jump 1995
event_250_command_9FBE:
    event_increment_flag 34
event_250_command_9FC0:
    event_call 1150
