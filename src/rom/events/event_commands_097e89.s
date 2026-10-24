; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $7E89
.include "src/rom/event_command_macros.inc"
event_1DA_command_7E89:
    event_wait 0
