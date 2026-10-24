; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1444
.include "src/rom/event_command_macros.inc"
event_42D_command_1444:
    event_wait 0
