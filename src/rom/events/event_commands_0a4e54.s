; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4E54
.include "src/rom/event_command_macros.inc"
event_4FD_command_4E54:
    event_wait 48
