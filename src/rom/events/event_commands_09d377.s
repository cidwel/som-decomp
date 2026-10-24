; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D377
.include "src/rom/event_command_macros.inc"
event_367_command_D377:
    event_test_flag_range 30, 1, 1
event_367_command_D37A:
    event_jump 868
event_367_command_D37C:
    event_test_flag_range 92, 0, 0
event_367_command_D37F:
    event_jump 1232
