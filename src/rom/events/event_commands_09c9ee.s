; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $C9EE
.include "src/rom/event_command_macros.inc"
event_2F9_command_C9EE:
    event_test_flag_range 41, 1, 15
event_2F9_command_C9F1:
    event_jump 1535
event_2F9_command_C9F3:
    event_wait 0
