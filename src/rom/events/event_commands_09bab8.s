; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BAB8
.include "src/rom/event_command_macros.inc"
event_2B8_command_BAB8:
    event_test_flag_range 41, 2, 15
event_2B8_command_BABB:
    event_jump 699
