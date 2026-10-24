; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1491
.include "src/rom/event_command_macros.inc"
event_42D_command_1491:
    event_wait 0
