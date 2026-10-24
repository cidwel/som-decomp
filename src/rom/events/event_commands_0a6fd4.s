; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6FD4
.include "src/rom/event_command_macros.inc"
event_584_command_6FD4:
    event_wait 0
