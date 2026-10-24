; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $651D
.include "src/rom/event_command_macros.inc"
event_557_command_651D:
    event_wait 48
