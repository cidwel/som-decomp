; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $4CA5
.include "src/rom/event_command_macros.inc"
event_167_command_4CA5:
    event_wait 0
