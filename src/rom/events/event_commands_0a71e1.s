; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $71E1
.include "src/rom/event_command_macros.inc"
event_587_command_71E1:
    event_wait 0
