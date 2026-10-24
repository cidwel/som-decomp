; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6409
.include "src/rom/event_command_macros.inc"
event_1A5_command_6409:
    event_wait 0
