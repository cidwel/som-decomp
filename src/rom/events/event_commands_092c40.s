; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2C40
.include "src/rom/event_command_macros.inc"
event_10A_command_2C40:
    event_jump 1535
event_10A_command_2C42:
    event_end 
event_10B_command_2C43:
    event_test_flag_range 16, 10, 10
event_10B_command_2C46:
    event_jump 282
event_10B_command_2C48:
    event_test_flag_range 16, 11, 15
event_10B_command_2C4B:
    event_jump 283
