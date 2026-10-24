; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7A1A
.include "src/rom/event_command_macros.inc"
event_5F8_command_7A1A:
    event_wait 32
