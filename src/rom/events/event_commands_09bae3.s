; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BAE3
.include "src/rom/event_command_macros.inc"
event_2B9_command_BAE3:
    event_test_flag_range 39, 2, 15
event_2B9_command_BAE6:
    event_jump 701
