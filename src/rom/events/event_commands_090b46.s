; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $0B46
.include "src/rom/event_command_macros.inc"
event_024_command_0B46:
    event_wait 0
