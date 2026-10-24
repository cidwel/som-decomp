; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $48DA
.include "src/rom/event_command_macros.inc"
event_4E9_command_48DA:
    event_wait 0
