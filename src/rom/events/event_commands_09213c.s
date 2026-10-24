; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $213C
.include "src/rom/event_command_macros.inc"
event_0ED_command_213C:
    event_test_flag_range 15, 1, 15
event_0ED_command_213F:
    event_jump 248
event_0ED_command_2141:
    event_call 1943
event_0ED_command_2143:
    event_call 1040
