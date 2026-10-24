; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5B20
.include "src/rom/event_command_macros.inc"
event_187_command_5B20:
    event_wait 0
