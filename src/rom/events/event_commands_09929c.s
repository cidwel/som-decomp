; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $929C
.include "src/rom/event_command_macros.inc"
event_20A_command_929C:
    event_wait 0
