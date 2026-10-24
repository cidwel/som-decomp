; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2034
.include "src/rom/event_command_macros.inc"
event_0E9_command_2034:
    event_test_flag_range 15, 1, 15
event_0E9_command_2037:
    event_jump 248
event_0E9_command_2039:
    event_call 1943
event_0E9_command_203B:
    event_call 1040
