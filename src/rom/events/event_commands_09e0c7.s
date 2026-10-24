; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $E0C7
.include "src/rom/event_command_macros.inc"
event_3A4_command_E0C7:
    event_wait 0
