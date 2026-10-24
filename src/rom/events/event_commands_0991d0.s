; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $91D0
.include "src/rom/event_command_macros.inc"
event_20A_command_91D0:
    event_test_flag_range 91, 1, 15
event_20A_command_91D3:
    event_jump 1088
event_20A_command_91D5:
    event_increment_flag 91
