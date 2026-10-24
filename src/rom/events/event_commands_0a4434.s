; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4434
.include "src/rom/event_command_macros.inc"
event_4E8_command_4434:
    event_wait 0
