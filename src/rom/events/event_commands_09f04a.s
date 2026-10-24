; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F04A
.include "src/rom/event_command_macros.inc"
event_3EA_command_F04A:
    event_call 1941
