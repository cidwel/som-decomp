; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A435
.include "src/rom/event_command_macros.inc"
event_265_command_A435:
    event_test_flag_range 36, 8, 15
event_265_command_A438:
    event_jump 961
