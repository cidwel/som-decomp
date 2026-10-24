; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $216F
.include "src/rom/event_command_macros.inc"
event_0EE_command_216F:
    event_test_flag_range 15, 1, 15
event_0EE_command_2172:
    event_jump 248
event_0EE_command_2174:
    event_call 1943
event_0EE_command_2176:
    event_call 1040
