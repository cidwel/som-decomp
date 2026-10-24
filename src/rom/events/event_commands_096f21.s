; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6F21
.include "src/rom/event_command_macros.inc"
event_1BD_command_6F21:
    event_wait 0
