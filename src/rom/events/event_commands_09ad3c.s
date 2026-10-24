; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $AD3C
.include "src/rom/event_command_macros.inc"
event_291_command_AD3C:
    event_wait 0
