; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4E1D
.include "src/rom/event_command_macros.inc"
event_4FD_command_4E1D:
    event_wait 48
