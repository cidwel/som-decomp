; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5681
.include "src/rom/event_command_macros.inc"
event_180_command_5681:
    event_test_flag_range 23, 0, 5
event_180_command_5684:
    event_call 16
