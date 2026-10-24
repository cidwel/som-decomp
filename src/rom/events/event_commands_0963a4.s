; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $63A4
.include "src/rom/event_command_macros.inc"
event_1A5_command_63A4:
    event_wait 0
