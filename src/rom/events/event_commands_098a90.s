; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8A90
.include "src/rom/event_command_macros.inc"
event_1F6_command_8A90:
    event_wait 0
