; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4D47
.include "src/rom/event_command_macros.inc"
event_167_command_4D47:
    event_wait 0
