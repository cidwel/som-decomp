; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4E4D
.include "src/rom/event_command_macros.inc"
event_4FD_command_4E4D:
    event_wait 32
