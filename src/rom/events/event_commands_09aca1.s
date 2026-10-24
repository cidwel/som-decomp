; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $ACA1
.include "src/rom/event_command_macros.inc"
event_28F_command_ACA1:
    event_wait 0
