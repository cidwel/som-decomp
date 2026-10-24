; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6BAD
.include "src/rom/event_command_macros.inc"
event_1B7_command_6BAD:
    event_wait 0
