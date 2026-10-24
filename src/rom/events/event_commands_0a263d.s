; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $263D
.include "src/rom/event_command_macros.inc"
event_4C8_command_263D:
    event_wait 8
