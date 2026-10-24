; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BC96
.include "src/rom/event_command_macros.inc"
event_2C1_command_BC96:
    event_test_flag_range 59, 0, 0
event_2C1_command_BC99:
    event_call 707
