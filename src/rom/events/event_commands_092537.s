; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2537
.include "src/rom/event_command_macros.inc"
event_0FE_command_2537:
    event_test_flag_range 15, 1, 15
event_0FE_command_253A:
    event_jump 248
event_0FE_command_253C:
    event_call 1943
event_0FE_command_253E:
    event_call 1040
