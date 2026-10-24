; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4D00
.include "src/rom/event_command_macros.inc"
event_167_command_4D00:
    event_wait 0
