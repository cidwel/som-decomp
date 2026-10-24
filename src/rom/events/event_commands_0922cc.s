; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $22CC
.include "src/rom/event_command_macros.inc"
event_0F5_command_22CC:
    event_test_flag_range 15, 1, 15
event_0F5_command_22CF:
    event_jump 248
event_0F5_command_22D1:
    event_call 1943
event_0F5_command_22D3:
    event_call 1040
