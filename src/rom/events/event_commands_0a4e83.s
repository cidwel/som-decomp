; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4E83
.include "src/rom/event_command_macros.inc"
event_4FD_command_4E83:
    event_wait 48
