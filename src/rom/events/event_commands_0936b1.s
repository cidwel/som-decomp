; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $36B1
.include "src/rom/event_command_macros.inc"
event_114_command_36B1:
    event_test_flag_range 9, 1, 1
event_114_command_36B4:
    event_jump 1255
