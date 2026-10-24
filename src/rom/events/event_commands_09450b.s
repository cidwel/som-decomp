; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $450B
.include "src/rom/event_command_macros.inc"
event_143_command_450B:
    event_test_flag_range 18, 0, 8
event_143_command_450E:
    event_jump 1535
