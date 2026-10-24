; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $2075
.include "src/rom/event_command_macros.inc"
event_0EA_command_2075:
    event_test_flag_range 15, 1, 15
event_0EA_command_2078:
    event_jump 248
event_0EA_command_207A:
    event_call 1943
event_0EA_command_207C:
    event_call 1040
