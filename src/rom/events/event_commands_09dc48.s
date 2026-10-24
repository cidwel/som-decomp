; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DC48
.include "src/rom/event_command_macros.inc"
event_38E_command_DC48:
    event_test_flag_range 39, 0, 0
event_38E_command_DC4B:
    event_jump 1535
