; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $CD8C
.include "src/rom/event_command_macros.inc"
event_318_command_CD8C:
    event_wait 0
