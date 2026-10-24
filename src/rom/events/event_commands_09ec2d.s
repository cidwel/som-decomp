; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EC2D
.include "src/rom/event_command_macros.inc"
event_3DA_command_EC2D:
    event_wait 0
