; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4878
.include "src/rom/event_command_macros.inc"
event_150_command_4878:
    event_jump 1535
event_150_command_487A:
    event_end 
event_151_command_487B:
    event_test_flag_range 18, 0, 8
event_151_command_487E:
    event_jump 334
