; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $150B
.include "src/rom/event_command_macros.inc"
event_42D_command_150B:
    event_wait 32
