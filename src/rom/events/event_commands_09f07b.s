; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F07B
.include "src/rom/event_command_macros.inc"
event_3EA_command_F07B:
    event_call 1941
