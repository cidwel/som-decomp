; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1E85
.include "src/rom/event_command_macros.inc"
event_0E1_command_1E85:
    event_test_flag_range 147, 1, 2
event_0E1_command_1E88:
    event_jump 227
