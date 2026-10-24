; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6D6B
.include "src/rom/event_command_macros.inc"
event_1B9_command_6D6B:
    event_wait 0
