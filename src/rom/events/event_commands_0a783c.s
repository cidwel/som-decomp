; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $783C
.include "src/rom/event_command_macros.inc"
event_5B2_command_783C:
    event_jump 1456
event_5B2_command_783E:
    event_end 
event_5B3_command_783F:
    event_test_flag_range 90, 0, 0
event_5B3_command_7842:
    event_jump 1457
event_5B3_command_7844:
    event_test_flag_range 90, 2, 15
event_5B3_command_7847:
    event_jump 1457
event_5B3_command_7849:
    event_increment_flag 90
