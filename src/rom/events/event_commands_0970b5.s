; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $70B5
.include "src/rom/event_command_macros.inc"
event_1C3_command_70B5:
    event_call 1925
event_1C3_command_70B7:
    event_screen 2
event_1C3_command_70B9:
    event_wait 16
event_1C3_command_70BB:
    event_screen 4
event_1C3_command_70BD:
    event_call 1928
