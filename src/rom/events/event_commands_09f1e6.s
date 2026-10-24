; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F1E6
.include "src/rom/event_command_macros.inc"
event_3EE_command_F1E6:
    event_call 1951
