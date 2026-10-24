; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7EEF
.include "src/rom/event_command_macros.inc"
event_1DC_command_7EEF:
    event_wait 0
