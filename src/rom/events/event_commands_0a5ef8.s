; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5EF8
.include "src/rom/event_command_macros.inc"
event_52E_command_5EF8:
    event_wait 0
