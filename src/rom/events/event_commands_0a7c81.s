; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7C81
.include "src/rom/event_command_macros.inc"
event_5F8_command_7C81:
    event_wait 48
