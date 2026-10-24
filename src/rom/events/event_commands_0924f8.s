; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $24F8
.include "src/rom/event_command_macros.inc"
event_0FD_command_24F8:
    event_test_flag_range 15, 1, 15
event_0FD_command_24FB:
    event_jump 248
event_0FD_command_24FD:
    event_call 1943
event_0FD_command_24FF:
    event_call 1040
