; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $D2B4
.include "src/rom/event_command_macros.inc"
event_365_command_D2B4:
    event_wait 0
