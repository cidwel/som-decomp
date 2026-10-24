; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A307
.include "src/rom/event_command_macros.inc"
event_263_command_A307:
    event_test_flag_range 36, 8, 15
event_263_command_A30A:
    event_jump 960
