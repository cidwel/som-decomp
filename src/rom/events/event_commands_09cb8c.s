; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CB8C
.include "src/rom/event_command_macros.inc"
event_2FD_command_CB8C:
    event_wait 0
