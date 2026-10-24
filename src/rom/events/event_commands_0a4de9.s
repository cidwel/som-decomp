; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4DE9
.include "src/rom/event_command_macros.inc"
event_4FD_command_4DE9:
    event_wait 48
