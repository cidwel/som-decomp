; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7D06
.include "src/rom/event_command_macros.inc"
event_5F8_command_7D06:
    event_wait 32
