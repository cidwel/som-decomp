; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7745
.include "src/rom/event_command_macros.inc"
event_1CE_command_7745:
    event_wait 0
