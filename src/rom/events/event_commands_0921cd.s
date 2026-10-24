; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $21CD
.include "src/rom/event_command_macros.inc"
event_0F0_command_21CD:
    event_test_flag_range 15, 1, 15
event_0F0_command_21D0:
    event_jump 248
event_0F0_command_21D2:
    event_call 1943
event_0F0_command_21D4:
    event_call 1040
