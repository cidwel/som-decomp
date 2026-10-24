; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $332F
.include "src/rom/event_command_macros.inc"
event_112_command_332F:
    event_wait 0
