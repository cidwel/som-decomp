; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $21FE
.include "src/rom/event_command_macros.inc"
event_0F1_command_21FE:
    event_test_flag_range 15, 1, 15
event_0F1_command_2201:
    event_jump 248
event_0F1_command_2203:
    event_call 1943
event_0F1_command_2205:
    event_call 1040
