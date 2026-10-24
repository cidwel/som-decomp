; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3EFA
.include "src/rom/event_command_macros.inc"
event_138_command_3EFA:
    event_wait 0
