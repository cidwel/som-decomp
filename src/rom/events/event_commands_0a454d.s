; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $454D
.include "src/rom/event_command_macros.inc"
event_4E8_command_454D:
    event_wait 0
