; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1F88
.include "src/rom/event_command_macros.inc"
event_0E6_command_1F88:
    event_test_flag_range 15, 1, 15
event_0E6_command_1F8B:
    event_jump 248
event_0E6_command_1F8D:
    event_call 1943
event_0E6_command_1F8F:
    event_call 1040
