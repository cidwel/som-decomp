; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $318E
.include "src/rom/event_command_macros.inc"
event_4E1_command_318E:
    event_wait 0
