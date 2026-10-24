; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F6D
.include "src/rom/event_command_macros.inc"
event_1BE_command_6F6D:
    event_wait 0
