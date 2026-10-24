; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4A12
.include "src/rom/event_command_macros.inc"
event_4EA_command_4A12:
    event_wait 0
