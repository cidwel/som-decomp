; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9B81
.include "src/rom/event_command_macros.inc"
event_235_command_9B81:
    event_wait 8
