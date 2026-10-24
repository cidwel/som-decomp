; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7EF8
.include "src/rom/event_command_macros.inc"
event_5F8_command_7EF8:
    event_wait 0
