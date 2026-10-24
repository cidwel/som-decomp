; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1FC9
.include "src/rom/event_command_macros.inc"
event_0E7_command_1FC9:
    event_test_flag_range 15, 1, 15
event_0E7_command_1FCC:
    event_jump 248
event_0E7_command_1FCE:
    event_call 1943
event_0E7_command_1FD0:
    event_call 1040
