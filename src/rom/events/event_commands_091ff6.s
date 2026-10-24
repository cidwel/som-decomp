; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1FF6
.include "src/rom/event_command_macros.inc"
event_0E8_command_1FF6:
    event_test_flag_range 15, 1, 15
event_0E8_command_1FF9:
    event_jump 248
event_0E8_command_1FFB:
    event_call 1943
event_0E8_command_1FFD:
    event_call 1040
