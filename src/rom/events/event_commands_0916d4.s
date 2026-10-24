; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $16D4
.include "src/rom/event_command_macros.inc"
event_0B2_command_16D4:
    event_jump 1535
event_0B2_command_16D6:
    event_end 
event_0B3_command_16D7:
    event_test_flag_range 48, 2, 2
event_0B3_command_16DA:
    event_increment_flag 48
