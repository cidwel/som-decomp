; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6E8E
.include "src/rom/event_command_macros.inc"
event_1B9_command_6E8E:
    event_wait 0
