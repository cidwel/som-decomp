; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $5E02
.include "src/rom/event_command_macros.inc"
event_192_command_5E02:
    event_wait 0
