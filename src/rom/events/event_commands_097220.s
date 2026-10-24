; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7220
.include "src/rom/event_command_macros.inc"
event_1C7_command_7220:
    event_wait 0
