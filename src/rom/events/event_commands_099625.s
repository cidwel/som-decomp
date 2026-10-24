; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9625
.include "src/rom/event_command_macros.inc"
event_21D_command_9625:
    event_wait 0
