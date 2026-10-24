; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $DF12
.include "src/rom/event_command_macros.inc"
event_399_command_DF12:
    event_wait 0
