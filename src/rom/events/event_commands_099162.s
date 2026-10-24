; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $9162
.include "src/rom/event_command_macros.inc"
event_206_command_9162:
    event_wait 0
