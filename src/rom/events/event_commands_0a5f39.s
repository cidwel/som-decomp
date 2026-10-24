; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5F39
.include "src/rom/event_command_macros.inc"
event_52E_command_5F39:
    event_wait 0
