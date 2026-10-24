; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4BD3
.include "src/rom/event_command_macros.inc"
event_4EA_command_4BD3:
    event_wait 0
