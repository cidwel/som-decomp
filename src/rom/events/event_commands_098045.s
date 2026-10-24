; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8045
.include "src/rom/event_command_macros.inc"
event_1DC_command_8045:
    event_wait 0
