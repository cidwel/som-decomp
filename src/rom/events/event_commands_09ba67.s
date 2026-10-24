; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BA67
.include "src/rom/event_command_macros.inc"
event_2B7_command_BA67:
    event_test_flag_range 147, 1, 2
event_2B7_command_BA6A:
    event_jump 687
