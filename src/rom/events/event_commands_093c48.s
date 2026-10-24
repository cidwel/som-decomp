; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3C48
.include "src/rom/event_command_macros.inc"
event_130_command_3C48:
    event_wait 0
