; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7619
.include "src/rom/event_command_macros.inc"
event_1CE_command_7619:
    event_call 2006
