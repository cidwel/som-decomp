; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E7FD
.include "src/rom/event_command_macros.inc"
event_3C8_command_E7FD:
    event_wait 0
