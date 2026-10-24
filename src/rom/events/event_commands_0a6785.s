; Native event command span; docs/event-command-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $6785
.include "src/rom/event_command_macros.inc"
event_559_command_6785:
    event_call 92
