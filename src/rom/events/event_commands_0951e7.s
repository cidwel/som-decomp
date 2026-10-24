; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $51E7
.include "src/rom/event_command_macros.inc"
event_16E_command_51E7:
    event_wait 0
