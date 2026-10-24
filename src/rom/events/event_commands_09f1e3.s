; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $F1E3
.include "src/rom/event_command_macros.inc"
event_3EE_command_F1E3:
    event_wait 0
