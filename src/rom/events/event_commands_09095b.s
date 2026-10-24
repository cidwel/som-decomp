; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $095B
.include "src/rom/event_command_macros.inc"
event_013_command_095B:
    event_wait 0
event_013_command_095D:
    event_test_flag_range 13, 1, 1
event_013_command_0960:
    event_jump 383
