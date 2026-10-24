; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $631A
.include "src/rom/event_command_macros.inc"
event_1A2_command_631A:
    event_jump 1535
event_1A2_command_631C:
    event_end 
event_1A3_command_631D:
    event_test_flag_range 19, 7, 15
event_1A3_command_6320:
    event_jump 423
