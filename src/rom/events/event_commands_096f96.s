; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F96
.include "src/rom/event_command_macros.inc"
event_1BE_command_6F96:
    event_wait 0
