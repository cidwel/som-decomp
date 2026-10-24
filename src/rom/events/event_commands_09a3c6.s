; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $A3C6
.include "src/rom/event_command_macros.inc"
event_264_command_A3C6:
    event_wait 0
