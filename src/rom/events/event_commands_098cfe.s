; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8CFE
.include "src/rom/event_command_macros.inc"
event_200_command_8CFE:
    event_wait 0
