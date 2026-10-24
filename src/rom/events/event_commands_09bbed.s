; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $BBED
.include "src/rom/event_command_macros.inc"
event_2BE_command_BBED:
    event_wait 0
