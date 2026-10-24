; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $225E
.include "src/rom/event_command_macros.inc"
event_0F3_command_225E:
    event_test_flag_range 15, 1, 15
event_0F3_command_2261:
    event_jump 248
event_0F3_command_2263:
    event_call 1943
event_0F3_command_2265:
    event_call 1040
