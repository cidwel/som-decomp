; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7FEF
.include "src/rom/event_command_macros.inc"
event_1DC_command_7FEF:
    event_wait 0
