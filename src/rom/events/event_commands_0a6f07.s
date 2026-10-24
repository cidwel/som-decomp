; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F07
.include "src/rom/event_command_macros.inc"
event_582_command_6F07:
    event_wait 0
