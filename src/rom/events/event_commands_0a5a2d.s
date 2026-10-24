; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5A2D
.include "src/rom/event_command_macros.inc"
event_511_command_5A2D:
    event_wait 0
