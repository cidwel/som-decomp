; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $44A4
.include "src/rom/event_command_macros.inc"
event_4E8_command_44A4:
    event_call 94
