; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0C4B
.include "src/rom/event_command_macros.inc"
event_400_command_0C4B:
    event_wait 48
