; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8954
.include "src/rom/event_command_macros.inc"
event_658_command_8954:
    event_wait 0
