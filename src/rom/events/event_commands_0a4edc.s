; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4EDC
.include "src/rom/event_command_macros.inc"
event_4FD_command_4EDC:
    event_wait 32
