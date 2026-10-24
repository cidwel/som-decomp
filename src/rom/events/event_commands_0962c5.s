; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $62C5
.include "src/rom/event_command_macros.inc"
event_1A0_command_62C5:
    event_jump 1535
event_1A0_command_62C7:
    event_end 
event_1A1_command_62C8:
    event_test_flag_range 19, 7, 15
event_1A1_command_62CB:
    event_jump 422
