; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9885
.include "src/rom/event_command_macros.inc"
event_7FE_command_9885:
    event_wait 0
