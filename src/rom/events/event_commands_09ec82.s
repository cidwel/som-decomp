; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EC82
.include "src/rom/event_command_macros.inc"
event_3DB_command_EC82:
    event_wait 0
