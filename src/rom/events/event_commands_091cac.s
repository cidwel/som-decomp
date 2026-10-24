; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $1CAC
.include "src/rom/event_command_macros.inc"
event_0D4_command_1CAC:
    event_wait 0
