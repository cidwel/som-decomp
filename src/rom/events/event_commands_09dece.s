; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DECE
.include "src/rom/event_command_macros.inc"
event_399_command_DECE:
    event_wait 0
