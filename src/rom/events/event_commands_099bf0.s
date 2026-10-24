; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9BF0
.include "src/rom/event_command_macros.inc"
event_236_command_9BF0:
    event_wait 0
