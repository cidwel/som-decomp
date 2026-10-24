; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $3F46
.include "src/rom/event_command_macros.inc"
event_138_command_3F46:
    event_wait 0
