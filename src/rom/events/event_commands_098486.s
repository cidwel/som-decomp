; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8486
.include "src/rom/event_command_macros.inc"
event_1E7_command_8486:
    event_wait 0
