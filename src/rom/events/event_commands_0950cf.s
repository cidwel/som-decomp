; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $50CF
.include "src/rom/event_command_macros.inc"
event_16D_command_50CF:
    event_wait 0
