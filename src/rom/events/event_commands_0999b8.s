; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $99B8
.include "src/rom/event_command_macros.inc"
event_22E_command_99B8:
    event_wait 0
