; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E4E5
.include "src/rom/event_command_macros.inc"
event_3B6_command_E4E5:
    event_test_flag_range 58, 2, 2
event_3B6_command_E4E8:
    event_jump 957
