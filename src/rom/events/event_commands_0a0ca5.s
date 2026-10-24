; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0CA5
.include "src/rom/event_command_macros.inc"
event_400_command_0CA5:
    event_wait 56
