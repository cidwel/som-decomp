; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9795
.include "src/rom/event_command_macros.inc"
event_225_command_9795:
    event_test_flag_range 26, 8, 15
event_225_command_9798:
    event_jump 552
