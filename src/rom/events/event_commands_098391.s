; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8391
.include "src/rom/event_command_macros.inc"
event_1E6_command_8391:
    event_wait 0
