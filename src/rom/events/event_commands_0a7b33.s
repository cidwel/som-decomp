; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7B33
.include "src/rom/event_command_macros.inc"
event_5F8_command_7B33:
    event_wait 48
