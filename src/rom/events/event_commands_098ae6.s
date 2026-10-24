; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $8AE6
.include "src/rom/event_command_macros.inc"
event_1F6_command_8AE6:
    event_wait 0
