; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7F6C
.include "src/rom/event_command_macros.inc"
event_1DC_command_7F6C:
    event_wait 0
