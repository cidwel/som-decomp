; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1AD0
.include "src/rom/event_command_macros.inc"
event_0CD_command_1AD0:
    event_wait 0
