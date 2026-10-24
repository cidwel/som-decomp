; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1A80
.include "src/rom/event_command_macros.inc"
event_0CD_command_1A80:
    event_test_flag_range 15, 1, 15
event_0CD_command_1A83:
    event_jump 248
event_0CD_command_1A85:
    event_call 1943
event_0CD_command_1A87:
    event_call 1040
