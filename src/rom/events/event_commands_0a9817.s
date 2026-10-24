; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9817
.include "src/rom/event_command_macros.inc"
event_7FD_command_9817:
    event_wait 0
