; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6C8A
.include "src/rom/event_command_macros.inc"
event_1B9_command_6C8A:
    event_wait 0
