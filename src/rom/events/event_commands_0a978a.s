; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $978A
.include "src/rom/event_command_macros.inc"
event_7F8_command_978A:
    event_call 1051
event_7F8_command_978C:
    event_wait 20
