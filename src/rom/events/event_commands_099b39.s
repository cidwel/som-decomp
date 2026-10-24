; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9B39
.include "src/rom/event_command_macros.inc"
event_22F_command_9B39:
    event_wait 0
