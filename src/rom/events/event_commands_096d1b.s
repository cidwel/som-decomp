; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6D1B
.include "src/rom/event_command_macros.inc"
event_1B9_command_6D1B:
    event_wait 0
