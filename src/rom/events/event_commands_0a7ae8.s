; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7AE8
.include "src/rom/event_command_macros.inc"
event_5F8_command_7AE8:
    event_wait 16
