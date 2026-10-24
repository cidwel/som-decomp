; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5493
.include "src/rom/event_command_macros.inc"
event_173_command_5493:
    event_wait 0
