; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D977
.include "src/rom/event_command_macros.inc"
event_384_command_D977:
    event_wait 0
