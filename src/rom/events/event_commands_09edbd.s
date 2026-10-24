; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $EDBD
.include "src/rom/event_command_macros.inc"
event_3DD_command_EDBD:
    event_wait 0
