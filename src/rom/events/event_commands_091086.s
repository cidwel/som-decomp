; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1086
.include "src/rom/event_command_macros.inc"
event_042_command_1086:
    event_wait 20
event_042_command_1088:
    event_wait 0
