; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F13A
.include "src/rom/event_command_macros.inc"
event_3ED_command_F13A:
    event_wait 0
