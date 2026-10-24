; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BA14
.include "src/rom/event_command_macros.inc"
event_2B6_command_BA14:
    event_test_flag_range 41, 2, 15
event_2B6_command_BA17:
    event_jump 698
