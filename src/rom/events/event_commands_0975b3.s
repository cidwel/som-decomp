; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $75B3
.include "src/rom/event_command_macros.inc"
event_1CD_command_75B3:
    event_wait 0
