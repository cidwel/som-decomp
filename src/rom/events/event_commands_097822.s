; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7822
.include "src/rom/event_command_macros.inc"
event_1CE_command_7822:
    event_wait 0
