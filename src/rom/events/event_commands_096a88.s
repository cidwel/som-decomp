; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6A88
.include "src/rom/event_command_macros.inc"
event_1B6_command_6A88:
    event_wait 0
