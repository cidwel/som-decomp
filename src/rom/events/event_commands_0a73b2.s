; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $73B2
.include "src/rom/event_command_macros.inc"
event_590_command_73B2:
    event_wait 0
