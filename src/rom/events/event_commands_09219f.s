; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $219F
.include "src/rom/event_command_macros.inc"
event_0EF_command_219F:
    event_test_flag_range 15, 1, 15
event_0EF_command_21A2:
    event_jump 248
event_0EF_command_21A4:
    event_call 1943
event_0EF_command_21A6:
    event_call 1040
