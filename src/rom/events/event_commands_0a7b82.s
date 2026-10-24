; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7B82
.include "src/rom/event_command_macros.inc"
event_5F8_command_7B82:
    event_wait 64
