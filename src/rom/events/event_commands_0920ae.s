; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $20AE
.include "src/rom/event_command_macros.inc"
event_0EB_command_20AE:
    event_test_flag_range 15, 1, 15
event_0EB_command_20B1:
    event_jump 248
event_0EB_command_20B3:
    event_call 1943
event_0EB_command_20B5:
    event_call 1040
