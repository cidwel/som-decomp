; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $56EC
.include "src/rom/event_command_macros.inc"
event_180_command_56EC:
    event_test_flag_range 17, 0, 11
event_180_command_56EF:
    event_call 17
event_180_command_56F1:
    event_test_flag_range 23, 6, 15
event_180_command_56F4:
    event_call 18
event_180_command_56F6:
    event_wait 0
