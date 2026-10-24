; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5231
.include "src/rom/event_command_macros.inc"
event_16E_command_5231:
    event_wait 8
