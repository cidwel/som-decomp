; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DF40
.include "src/rom/event_command_macros.inc"
event_399_command_DF40:
    event_test_flag_range 48, 1, 1
event_399_command_DF43:
    event_increment_flag 48
event_399_command_DF45:
    event_jump 1535
event_399_command_DF47:
    event_end 
