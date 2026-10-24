; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9D13
.include "src/rom/event_command_macros.inc"
event_23A_command_9D13:
    event_wait 0
