; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $61D5
.include "src/rom/event_command_macros.inc"
event_532_command_61D5:
    event_wait 0
