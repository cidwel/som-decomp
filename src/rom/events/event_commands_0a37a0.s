; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $37A0
.include "src/rom/event_command_macros.inc"
event_4E3_command_37A0:
    event_wait 0
event_4E3_command_37A2:
    event_call 1854
event_4E3_command_37A4:
    event_wait 32
